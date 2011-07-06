/*
 * File:   Node.java
 * Author: Bharat Reddy
 * Package: PathFinder v0.1
 *
 * COPYRIGHT 2010 Bharat Reddy
 * Contact: bharat411@gmail.com
 *
 * This file is part of PathFinder.
 *
 * PathFinder is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PathFinder is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PathFinder. If not, see <http://www.gnu.org/licenses/>.
 *
 * Created on 31/03/2010, 17:25
 */

package code.reddy.ai.pathfinder;

import java.awt.*;
import javax.swing.*;

/**
 * The Node class is where most of our lower level processing goes on for the
 * A* algorithm. It includes methods to calculate the costs and score the node.
 * It also has pointers to the previous and next nodes so that we can create a
 * virtual list of the route.
 *
 * Node implements a comparator, which means it can be compared to any other
 * node using equals (this is done by using the f-score).
 * 
 * @author Bharat
 */
public class Node extends JPanel implements Comparable<Node>
{
    private int m_iF,m_iG,m_iH,m_iX,m_iY;
    private int m_iStatus; //0 - Normal, 1 - Start, 2 - Goal, 3 - Battery, 4 - Blocked
    private Node m_xParent,m_xNext;

    /**
     * Sets up a new node and its MouseListener. Add this node to your grid.
     *
     * @param posX The user reference X(NOT the GUI x co-ordinate)
     * @param posY The user reference Y(NOT the GUI y co-ordinate)
     */
    Node(int posX,int posY)
    {
        super();
        m_iX=posX;
        m_iY=posY;
        setBackground(Color.WHITE);
        setBorder(BorderFactory.createLineBorder(Color.BLACK));
        addMouseListener(new MouseHandler());
    }

    /**
     * The compare method. Compares f-costs of nodes. This is useful for
     * PriorityQueues (and really any comparision of nodes).
     *
     * @param o The node we are comparing to
     * @return  The result of the comparision
     */
    public int compareTo(Node o)
    {
        if(m_iF<o.m_iF)
            return -1;
        if(m_iF>o.m_iF)
            return 1;
        return 0;
    }

    /**
     * Sets this node's status to 0 (Normal)
     *
     * Status Indicators: 0 - Normal, 1 - Start, 2 - Goal, 3 - Battery, 4 - Blocked
     */
    void setNormal()
    {
        m_iStatus=0;
        setBackground(Color.WHITE);
    }

    /**
     * Sets this node's status to 4 (Blocked)
     *
     * Status Indicators: 0 - Normal, 1 - Start, 2 - Goal, 3 - Battery, 4 - Blocked
     */
    void setBlocked()
    {
        m_iStatus=4;
        setBackground(Color.BLACK);
    }

    /**
     * Sets this node's status to 1 (Start). Also clears any other start nodes
     * in the parent grid.
     *
     * Status Indicators: 0 - Normal, 1 - Start, 2 - Goal, 3 - Battery, 4 - Blocked
     */
    void setStart()
    {
        Grid parentGrid=(Grid)getParent();
        parentGrid.clearNodes(1);
        m_iStatus=1;
        setBackground(Color.BLUE);
    }

    /**
     * Sets this node's status to 2 (Goal). Also clears any other goal nodes
     * in the parent grid.
     *
     * Status Indicators: 0 - Normal, 1 - Start, 2 - Goal, 3 - Battery, 4 - Blocked
     */

    void setGoal()
    {
        Grid parentGrid=(Grid)getParent();
        parentGrid.clearNodes(2);
        m_iStatus=2;
        setBackground(Color.GREEN);
    }


    /**
     * Sets this node's status to 3 (Battery). Also clears any other batt nodes
     * in the parent grid.
     *
     * Status Indicators: 0 - Normal, 1 - Start, 2 - Goal, 3 - Battery, 4 - Blocked
     */

    void setBattery()
    {
        Grid parentGrid=(Grid)getParent();
        parentGrid.clearNodes(3);
        m_iStatus=3;
        setBackground(Color.MAGENTA);
    }

    /**
     * Sets the parent node of this node. Useful for tracing back the route from
     * the end.
     *
     * @param xParent The node that leads to this node
     */
    void setParentNode(Node xParent)
    {
        m_xParent=xParent;
    }

    /**
     * Sets the child node of this node. Useful for tracing forwards for when
     * we want to simulate real time routing (pretty useless)
     *
     * @param xChild The node that this node leads to
     */
    void setChildNode(Node xChild)
    {
        m_xNext=xChild;
    }

    /**
     * A clear method that removes all information this node contains pertaining
     * to the A* routing
     */
    void clear()
    {
        m_iG=0;
        m_iH=0;
        m_iF=0;
        m_iStatus=0;
        m_xParent=null;
    }

    /**
     * A harder reset than clear. Also sets this node to WHITE - 0 - Normal
     */
    void resetNode()
    {
        clear();
        m_xNext=null;
        setNormal();
    }

    /**
     * Calculates and assigns score for this node
     *
     * @param prevNode The node that leads here
     * @param goalNode The end point (for heuristic)
     */
    void score(Node prevNode, Node goalNode)
    {
        m_iG=gCalc(prevNode);
        m_iH=hCalc(goalNode);
        m_iF=fCalc();
    }

    /**
     * Calculates the g-cost or travel cost to this node from the previous node.
     *
     * Diagonal distances cost more than straight distances, but travelling
     * diagonally costs less than travelling at right angles.
     * 
     * @param prevNode The node the leads here
     * @return The g-cost/travel cost from the previous node
     */
    int gCalc(Node prevNode)
    {
        if(m_iX!=prevNode.m_iX&&m_iY!=prevNode.m_iY)
            return prevNode.m_iG+14;
        return prevNode.m_iG+10;
    }

    /**
     * Calculates the h-cost or the heuristic for travelling from this node
     * to the goal node. Uses the maximum possible straight line distance and
     * multiplies it so that the h-cost is always greater than the g-cost.
     *
     * This makes the A* algorithm a best-first search.
     *
     * For more information go here:
     * <http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html#S1>
     *
     * @param goalNode The goal node
     * @return  The estimated cost of travelling to the goal node
     */
    int hCalc(Node goalNode)
    {
        return 20*Math.max(Math.abs(m_iX-goalNode.m_iX),Math.abs(m_iY-goalNode.m_iY));
    }

    /**
     * The f-cost calculator. Combines g and h costs.
     * 
     * @return The f-score of the node
     */
    int fCalc()
    {
        return m_iG+m_iH;
    }

    /**
     * Status Indicators: 0 - Normal, 1 - Start, 2 - Goal, 3 - Battery, 4 - Blocked
     *
     * @return The status of the current node
     */
    int getStatus()
    {
        return m_iStatus;
    }

    /**
     *
     * @return The parent node if set
     */
    Node getParentNode()
    {
        return m_xParent;
    }

    /**
     *
     * @return The child node if set
     */
    Node getChildNode()
    {
        return m_xNext;
    }

    /**
     * @return The user reference X co-ordinate
     */
    int getXCo()
    {
        return m_iX;
    }

    /**
     * @return The user reference Y co-ordinate
     */
    int getYCo()
    {
        return m_iY;
    }


    /**
     * @return The f-score for this node
     */
    int getF()
    {
        return m_iF;
    }

    /**
     * @return The g-cost for this node
     */

    int getG()
    {
        return m_iG;
    }
}
