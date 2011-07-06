/*
 * File:   Grid.java
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
 * Created on 31/03/2010, 09:54
 */

package code.reddy.ai.pathfinder;

import javax.swing.*;
import java.util.*;
import java.awt.*;

/**
 * The Grid class is a Panel that acts as the grid/maze that will then contain
 * a prespecified by user (this is where the quad. dimension comes in) number
 * of 'Nodes', defined by the Node class. In this case, each node is also a
 * Panel. It has been implemented this way to save code and the need to plan a
 * different solution, but is probably a little heavier on time and memory than
 * it should be.
 *
 * This class contains the A* algorithm, and all of the setup routines of the
 * program (i.e. check that there are goals to seek etc.)
 * 
 * @author Bharat Reddy
 */

public class Grid extends JPanel implements Runnable
{

    //Create a safe number of nodes
    Node m_xNode[][]=new Node[200][200];
    
    //Set up Node variables to keep a handle on the important nodes.
    Node m_xEpicStart,m_xGoal,m_xStart,m_xBattery;
    
    //The dimension of the maze
    int m_iMazeX;

    //A lock that dictates whether it is safe to modify the maze
    boolean m_bGridLock;

    /**
     * Renders a maze of a supplied size by spawning an appropriate number
     * of JPanels into a GridLayout. Also sets an x and y axis reference for
     * the JPanels (or Nodes).
     *
     * @param dim The dimension of the quadratic maze
     */
    void renderMaze(int dim)
    {
        m_bGridLock=false;
        m_iMazeX=dim;
        setLayout(new GridLayout(dim,dim));
        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++)
            {
                m_xNode[i][j]=new Node(i,j);
                add(m_xNode[i][j]);
            }
    }

    /**
     * Maze lock checker
     *
     * @return TRUE if the maze lock is set, FALSE otherwise
     */
    boolean isLocked()
    {
        return m_bGridLock;
    }

    /**
     * Clears the maze of all information, and resets any variables that might
     * have been set during the course of the program (including start and end
     * points etc.)
     *
     */
    void clearNodes()
    {
        for(int i=0;i<m_iMazeX;i++)
            for(int j=0;j<m_iMazeX;j++)
                    m_xNode[i][j].resetNode();
        m_xEpicStart=null;
        m_xGoal=null;
        m_xStart=null;
        m_xBattery=null;
        m_bGridLock=false;
    }

    /**
     * Only clears the nodes in the maze that have the status setting that is
     * supplied.
     *
     * Status Indicators: 0 - Normal, 1 - Start, 2 - Goal, 3 - Battery, 4 - Blocked
     *
     * @param mod The status of the nodes that need to be reset
     */
    void clearNodes(int mod)
    {
        for(int i=0;i<m_iMazeX;i++)
            for(int j=0;j<m_iMazeX;j++)
                if(m_xNode[i][j].getStatus()==mod)
                    m_xNode[i][j].resetNode();
    }

    /**
     * Checks for any problems with the maze (including a lack of initialisation
     * of start/end points etc.) before calling seek to solve the problem using
     * the A* algorithm. It also checks whether we need to divert our route
     * to a battery node.
     *
     * Most of the gridlocks (and their removals) are set up here.
     */
    void solve()
    {
        //Go through the entire maze and set up the start/end/battery nodes
        for(int i=0;i<m_iMazeX;i++)
            for(int j=0;j<m_iMazeX;j++)
            {
                if(m_xNode[i][j].getStatus()!=0)
                {
                    if(m_xNode[i][j].getStatus()==1)
                        m_xStart=m_xNode[i][j];
                    else if(m_xNode[i][j].getStatus()==2)
                        m_xGoal=m_xNode[i][j];
                    else if(m_xNode[i][j].getStatus()==3)
                        m_xBattery=m_xNode[i][j];
                }
            }

        //If we weren't able to find any of the important nodes, return an error
        if(m_xStart==null||m_xGoal==null)
        {
            JOptionPane.showMessageDialog(null,"You must specify a start and end point",
                            "Error",JOptionPane.ERROR_MESSAGE);
            return;
        }

        m_xEpicStart=m_xStart;  //Save the start point for later
        Node handle;

        if(m_xBattery!=null)    //If there is a battery to trace to
        {
            handle=seek(m_xStart,m_xBattery);
            if(handle==null)
            {
                JOptionPane.showMessageDialog(null,"Unable to reach battery",
                            "Error",JOptionPane.ERROR_MESSAGE);
                m_bGridLock=false;
                return;
            }
            processRoute(m_xStart,handle);

            for(int i=0;i<m_iMazeX;i++)
                for(int j=0;j<m_iMazeX;j++)
                    if(m_xNode[i][j].getStatus()!=4)
                        m_xNode[i][j].clear();  //Reset the maze
            m_xStart.setStart();        //Reset all the colours because they've
            m_xBattery.setBattery();    //been reset
            m_xGoal.setGoal();
            m_xStart=m_xBattery;
            //Now pretend that we need to route from here and seek to the end.
        }

        handle=seek(m_xStart,m_xGoal);
        if(handle==null)
        {
            JOptionPane.showMessageDialog(null,"Unable to reach goal",
                            "Error",JOptionPane.ERROR_MESSAGE);
            m_bGridLock=false;
            return;
        }
        processRoute(m_xStart,handle);
    }

    /**
     * A method to set up child nodes in a path so that we can trace the path
     * through from the start node to the end.
     *
     * This method is seperate because we can only get an A* optimal path once
     * the algorithm has reached the goal node. This is because the algorithm
     * sometimes finds better paths, and changes the parent of the current node
     * while processing.
     *
     * @param xGoal The node we will trace backwards till.
     * @param handle The node we start the tracing from.
     */
    void processRoute(Node xGoal,Node handle)
    {
        Node prevNode=null;
        while(handle!=xGoal)
            {
                prevNode=handle;
                handle=handle.getParentNode();
                handle.setChildNode(prevNode);
            }
    }

    /**
     * The A* algorithm.
     *
     * This algorithm uses best-first search in an attempt to find an optimal
     * path from a supplied start node to a supplied end node.
     *
     * Understanding and being able to write my algorithm was largely due to
     * Patrick Lester at <http://www.policyalmanac.org/games/aStarTutorial.htm>
     * and Amit at <http://www-cs-students.stanford.edu/~amitp/gameprog.html#Paths>
     *
     * Please look at these pages for the algorithm, because I'm too lazy to
     * document the algorithm here.
     *
     * @param xCurrent The start node
     * @param xGoal The goal node
     * @return NULL if no route was found, the goal node otherwise.
     */
    Node seek(Node xCurrent,Node xGoal)
    {
        int i,j,iX,iY,iG;

        m_bGridLock=true;

        /*
         * Use a PriorityQueue because we only care about the first element
         * on the list. The comparator for this PQ is the f-cost.
         */
        PriorityQueue<Node> m_qOpenList=new PriorityQueue<Node>();
        ArrayList<Node> m_qClosedList=new ArrayList<Node>(100);

        //Prescore
        xCurrent.score(xCurrent, xGoal);

        do
        {
            //Get the references (NOT the actual GUI X,Y co-ordinates)
            iX=xCurrent.getXCo();
            iY=xCurrent.getYCo();

            for(i=iX-1;i<iX+2;i++)
            {
                for(j=iY-1;j<iY+2;j++)
                {
                    if(!(i<0||j<0||i>=m_iMazeX||j>=m_iMazeX||(i==iX&&j==iY)||
                            m_xNode[i][j].getStatus()==4))
                    {
                        iG=xCurrent.getG()+m_xNode[i][j].gCalc(xCurrent);
                        if(m_qOpenList.contains(m_xNode[i][j]))
                        {
                            if(iG<m_xNode[i][j].getG())
                                m_qOpenList.remove(m_xNode[i][j]);
                        }
                        if(m_qClosedList.contains(m_xNode[i][j]))
                        {
                            if(iG<m_xNode[i][j].getG())
                                m_qClosedList.remove(m_xNode[i][j]);
                        }
                        if(!m_qOpenList.contains(m_xNode[i][j])&&!m_qClosedList.contains(m_xNode[i][j]))
                        {
                            m_xNode[i][j].score(xCurrent, xGoal);
                            m_xNode[i][j].setParentNode(xCurrent);
                            m_qOpenList.offer(m_xNode[i][j]);
                        }
                    }
                }
            }
            m_qClosedList.add(xCurrent);
            xCurrent=m_qOpenList.poll();
            if(xCurrent==xGoal)
                return xCurrent;
        }while(!(m_qOpenList.isEmpty()));
        return null;
    }

    /**
     * The run method for thread control.
     *
     * This is simply a 'pretty-printer' method of sorts in that it exists
     * to simulate the route from start to end with pauses so that the user
     * thinks the mapping is happening in real time. It simply uses a preset
     * start node and runs through it's children to get to the end, setting
     * background colours as it goes.
     */
    public void run()
    {
        if(m_xEpicStart==null)
            return;
        m_bGridLock=true;
        Node handle=m_xEpicStart;
        while(handle.getChildNode()!=null)
        {
            try{
                Thread.sleep(250);
            }catch(InterruptedException ie){}
            handle.setBackground(Color.red);
            handle=handle.getChildNode();
        }
        m_bGridLock=false;
    }
}
