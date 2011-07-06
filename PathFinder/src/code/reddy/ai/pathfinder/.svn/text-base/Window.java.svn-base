/*
 * File:   Window.java
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
 * Created on 30/03/2010, 15:12
 */

package code.reddy.ai.pathfinder;

import javax.swing.*;
import javax.swing.Timer;
import java.awt.*;
import java.awt.event.*;

/**
 * This is a Frame for displaying the grid along with the GUI controls for the
 * pathfinder.
 * 
 * @author Bharat Reddy
 */

public class Window extends JFrame implements ActionListener
{
    Grid m_xGrid=new Grid();
    Thread exec;
    Timer exectimer;

    /**
     * A constructor to create the frame that will hold the grid and
     * buttons. Supply a single parameter for the size of the maze.
     * 
     * @param dim The size of the quadratic maze
     */
    public Window(int dim)
    {
        JPanel m_jpCPanel=new JPanel();

        /*
         * Set the frame to dispose on close since we want to keep the
         * application running even if this grid is closed. The user can then
         * create another maze (different dimension) if they want to.
         */
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(new BorderLayout());

        //Create and set up GUI controls
        JButton m_jbSeek=new JButton("Seek");
        JButton m_jbHelp=new JButton("Instructions");
        JButton m_jbClear=new JButton("Clear");

        m_jbSeek.setActionCommand("seek");
        m_jbHelp.setActionCommand("help");
        m_jbClear.setActionCommand("cls");

        m_jbSeek.addActionListener(this);
        m_jbHelp.addActionListener(this);
        m_jbClear.addActionListener(this);

        m_jpCPanel.add(m_jbSeek);
        m_jpCPanel.add(m_jbHelp);
        m_jpCPanel.add(m_jbClear);

        //Render a square grid of size dim.
        m_xGrid.renderMaze(dim);

        //CPanel contains the buttons. Putting the panel on top of the grid.
        add(m_jpCPanel,BorderLayout.NORTH);
        add(m_xGrid,BorderLayout.CENTER);
        
    }

    public void actionPerformed(ActionEvent e)
    {
        //If the user needs help
        if("help".equals(e.getActionCommand()))
        {
            String instr="LMB= Left Mouse Button \nRMB= Right Mouse Button" +
                    "\n\nLMB : Set start square \nShift+LMB : Set goal square" +
                    "\n\nRMB : Set/Clear blocked square\nShift+RMB : Set/Clear battery" +
                    "\n\nAny other button : Clear";
            JOptionPane.showMessageDialog(null,instr,"Instructions",
                    JOptionPane.INFORMATION_MESSAGE);
        }
        //If the user activates the seeker
        if("seek".equals(e.getActionCommand()))
        {
            //As long as the grid hasn't been locked by the solve method
            if(!m_xGrid.isLocked())
            {
                m_xGrid.solve();

                /*
                 * The solution to the problem has been found at this point by
                 * the solve() method. The thread in m_xGrid exists to animate
                 * the solution and make it seem as though the solution is
                 * under investigation when, in fact, it is following a
                 * preset path.
                 */
                
                new Thread(m_xGrid).start();
            }
        }

        //If the user wants to clear the grid
        if("cls".equals(e.getActionCommand()))
        {
            //Ensure that we're not interfering, and do so.
            if(!m_xGrid.isLocked())
                m_xGrid.clearNodes();
        }
    }
}