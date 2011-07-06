/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 27 janvier 2011, 13:03
 */

#include <cstdlib>
#include<time.h>
#include <ios>
#include<iostream>

#include"board.h"
#include"player.h"
#include"utils.h"
#include"boardc4.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

//    //TESTING BOARD
//    srand(time(NULL));
//
//	Board *board=choose_game(OTHELLO);
//	board->play_random_move(PLAYER_1);
//        board->print();
//
//    Board *copy = board->deepcopy();
//    Token winner = board->play_random_game(PLAYER_2);
//    if (winner == NOT_PLAYED) std::cout<<"draw"<<std::endl;
//    else std::cout<<"player "<<winner<<" won"<<std::endl;
//    board->print();
//	delete board;
//
//    copy->play_random_move(PLAYER_2);
//    copy->print();
//    delete copy;

//TESTING UCT

    cout.precision(2);
    cout.setf(std::ios::fixed,std::ios::floatfield);
    srand(time(NULL));

    Board *board = new BoardC4();

    Player *player_a = new PlayerBot(PLAYER_1,1,100);
    Player *player_b = new PlayerBot(PLAYER_2,3,100);

    play_game(player_a, player_b, board, 6);

    delete board;
    delete player_a;
    delete player_b;

    return 0;
}

