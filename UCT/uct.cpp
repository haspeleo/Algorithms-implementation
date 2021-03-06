#include "uct.h"

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>

Node::Node(Value uct_constant) : move(new Move()), father(NULL), uct_constant(uct_constant), nb(0), value(0), simulation_value(0), mode(NORMAL) {}
Node::Node(const Move *move,Value uct_constant,Node *father) :  move(move), father(father), uct_constant(uct_constant), nb(0), value(0), simulation_value(0), mode(NORMAL) {}

Node::~Node() {
    delete move;

    for (Nodes::iterator iter=children.begin(); iter!=children.end(); iter++) {
        Node *child = *iter;
        delete child;
    }

    for (Moves::iterator iter=unexplored_moves.begin(); iter!=unexplored_moves.end(); iter++) {
        Move *move=*iter;
        delete move;
    }
}

Node * Node::advance_and_detach(const Move *move) {
	assert(! father);
	Node *new_root=NULL;
	for (Nodes::iterator iter=children.begin();iter!=children.end();iter++) {
		if ((*iter)->move->compare(*move)) {
			new_root=*iter;
			new_root->father=NULL;
			this->children.erase(iter);
			break;
        }
	}

    Value old_uct_constant = uct_constant; 
    delete this;
	if (new_root) return new_root;
    else return new Node(old_uct_constant);
}


void Node::print() const {
    std::cout<<"[";
    if (! father) std::cout<<"ROOT,";

    std::cout<<children.size()<<" children,"<<unexplored_moves.size()<<" unexplored,";

    move->print();
    std::cout<<",";
    switch (mode) {
    case NORMAL:
        std::cout<<"NORMAL";
        break;
    case WINNER:
        std::cout<<"WINNER";
        break;
    case LOOSER:
        std::cout<<"LOOSER";
        break;
    }

    std::cout<<" ,uct_constant="<<uct_constant<<",nb="<<nb;
    if (nb > 0 && father) std::cout<<",score="<<get_score();
    if (nb > 0) std::cout<<" ,value="<<value<<" ,prop="<<get_winning_probability();

    std::cout<<"]";
}

void Node::print_tree(int indent,int maxindent) const {
    if (maxindent >= 0 && indent > maxindent) return;

    for (int k=0; k<indent; k++) std::cout<<"-";
    print();
    std::cout<<std::endl;

    for (Nodes::const_iterator iter=children.begin(); iter!=children.end(); iter++) {
        const Node *child=*iter;
        child->print_tree(indent+1,maxindent);
    }
}

void Node::print_best_branch_down() const {
    print_branch(get_best_branch_down());
}

void Node::print_branch_up() const {
    print_branch(get_branch_up());
}

Value Node::get_winning_probability() const {
        assert(nb);
	return value / nb;
}

Mode Node::get_mode() const {
	return mode;
}

Count Node::get_nb() const {
    return nb;
}

Value Node::get_score() const {
    assert(father);
    return value / nb + uct_constant * sqrt(2 * log(father->nb)/nb);
}

const Move *Node::get_move() const {
	return move;
}

Value Node::get_uct_constant() const {
    return uct_constant;
}

const Node *Node::get_best_child() const {
	if (children.empty()) return NULL;

	Value best_score=0;
	const Node *best_child=NULL;

	for (Nodes::const_iterator iter=children.begin(); iter!=children.end(); iter++) {
		Node *child=*iter;

		if (child->mode==WINNER) return child;

		if (child->mode==NORMAL && (! best_child || best_score<child->value/child->nb)) {
			best_score=child->value/child->nb;
			best_child=child;
		}
	}

	if (best_child) return best_child;

	//no non-losing move, all move moves are marked loosing...
	assert(mode==WINNER); //if all child are loosing then this is a winner node
	int selected=rand() % children.size();

	//std::cout<<"SEPUKU!!!"<<children.size()<<" "<<selected<<std::endl;
	//print_tree();

	Nodes::const_iterator selected_iter=children.begin();
	while (selected>0 && selected_iter!=children.end()) {
		selected--;
		selected_iter++;
	}
	return *selected_iter;
}

Token Node::play_random_game(Board *board,Token player) {
    
    const Value loose_value=0., draw_value=.5, win_value=1.;

    if (father) assert(player == other_player(move->player));
    //else assert(move->player==NOT_PLAYED);

    assert(mode==NORMAL);

    if (father) board->play_move(*move); //root as no move

    if (father) {
        Token winner=board->check_for_win();
        if (winner!=NOT_PLAYED) {
            //std::cout<<"win situation detected"<<std::endl;
            //move->print();
            //std::cout<<std::endl;

            //Token winner=board->check_for_win();
            if (winner==move->player) propagate_winning_to_granpa();
            else propagate_loosing_to_daddy();

            return winner;
        }
    }

    if (! nb) {
        Token winner;
        unexplored_moves=board->get_possible_moves(player);
        winner=board->play_random_game(player);

        assert(! value);
        if (winner==NOT_PLAYED) value=draw_value;
        else if (winner==move->player) value=win_value;
        else value=loose_value;
        simulation_value=value;

        nb=1;

        update_father(value);
        return winner;
    }

    if (! unexplored_moves.empty()) {
        Move *move=unexplored_moves.back();
        unexplored_moves.pop_back();

        Node *child=new Node(move,uct_constant,this);
        children.push_back(child);
        return child->play_random_game(board,other_player(player));
    }

    Value best_score=0;
    Node *best_child=NULL;
    for (Nodes::iterator iter=children.begin(); iter!=children.end(); iter++) {
        Node *child=*iter;

        if (! child->mode == LOOSER && (! best_child ||best_score<child->get_score())) {
             best_score = child->get_score();
             best_child = child;
        }
    }

    if (! best_child) {
        //std::cout<<"no child move possible"<<std::endl;
        value+=draw_value;
        nb++;
        return NOT_PLAYED;
    }

    return best_child->play_random_game(board,other_player(player));
}

void Node::print_branch(const ConstNodes &branch) {
    for (ConstNodes::const_iterator iter=branch.begin(); iter!=branch.end(); iter++) {
        const Node *node=*iter;
        node->print();
        //std::cout<<" ";
        std::cout<<std::endl;
    }
}

ConstNodes Node::get_best_branch_down() const {
    ConstNodes branch;
    const Node *current=this;

    while (current && ! current->mode == WINNER) {
        branch.push_back(current);
        current = current->get_best_child();
    }

    return branch;
}

ConstNodes Node::get_branch_up() const {
    ConstNodes branch;
    const Node *current=this;

    while (current->father) {
        branch.push_back(current);
        current = current->father;
    }

    return branch;
}

void Node::update_father(Value value) {
    if (father) {
        father->nb++;
        father->value+=1.-value;
        father->update_father(1.-value);
    }
}

void Node::propagate_winning_to_granpa() {
    mode=WINNER;

    if (father) {
        father->mode = LOOSER;
        if (father->father) {
            father->father->tell_granpa_dad_is_a_looser(father);
        }
    }
}

void Node::propagate_loosing_to_daddy() {
    mode = LOOSER;

    if (father) {
		father->tell_granpa_dad_is_a_looser(this);
    }
}
void Node::recompute_inheritance() {
    nb=1;
    value=simulation_value;
    for (Nodes::const_iterator iter=children.begin(); iter!=children.end(); iter++) {
        const Node *child=*iter;

        if (! child->mode == LOOSER) {
            nb+=child->nb;
            value+=child->nb-child->value;
        }
    }

    if (father) father->recompute_inheritance();
}

void Node::tell_granpa_dad_is_a_looser(const Node *dad) {
    Count new_nb=1;
    Value new_value=simulation_value;
    for (Nodes::const_iterator iter=children.begin(); iter!=children.end(); iter++) {
        const Node *child=*iter;

        if (! child->mode == LOOSER) {
            new_nb+=child->nb;
            new_value+=child->nb-child->value;
        }
    }

    if (new_nb == 1) { //all child are loosers
        propagate_winning_to_granpa();
    } else {
        nb=new_nb;
        value=new_value;

        if (father) {
            father->recompute_inheritance();
        }
    }
}
