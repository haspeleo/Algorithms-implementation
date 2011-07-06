/*
 * File:   PathFinder.java
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
 *
 * Created on 30/03/2010, 12:44
 */

package code.reddy.ai.pathfinder;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.JFrame;

/**
 * This is the main control class, being the user's first point of
 * contact, and the window that dictates the shutdown of the application.
 *
 * PathFinder has been designed as a modular system from this stage on, with a
 * view to increase it's functionality at a later stage (by possibly adding
 * other windows with other routing algorithms). Currently, the system
 * incorporates an A* algorithm router. You can launch
 *
 * @author Bharat Reddy
 */

public class PathFinder implements ActionListener
{
    /**
     * The maze dimension field.
     * This field takes input for the user as the dimension of the maze.
     * There is only one field as we are using a quadratic maze.
     */

    private JTextField m_jtDim=new JTextField(3);

    /**
     * Sets up the GUI for the maze size request field
     */

    void Initialise()
    {
        System.out.println("Initialising Program");
        
        JFrame m_xSolnUI=new JFrame("PathFinder v0.1");
        JPanel m_jpInt=new JPanel();

        m_jpInt.setLayout(new BorderLayout(10,10));
        m_xSolnUI.setContentPane(m_jpInt);

        JLabel m_jlDim=new JLabel("Enter maze width");
        JButton m_jbLaunch=new JButton("Launch");

        m_jbLaunch.addActionListener(this);
        m_jbLaunch.setActionCommand("launch");

        m_jpInt.add(m_jlDim, BorderLayout.WEST);
        m_jpInt.add(m_jtDim, BorderLayout.EAST);
        m_jpInt.add(m_jbLaunch, BorderLayout.SOUTH);
        m_jpInt.setBorder(BorderFactory.createEmptyBorder(20, 40, 20, 40));

        m_xSolnUI.pack();
        m_xSolnUI.setMinimumSize(new Dimension(200, 20));
        m_xSolnUI.setLocationRelativeTo(null);
        m_xSolnUI.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        m_xSolnUI.setVisible(true);
    }

    /**
     * Spawns a new window that contains the grid and the buttons that are
     * needed to control it.
     *
     * @param dim The size of the quadratic maze.
     */
    void spawnWindow(int dim)
    {
        System.out.println("Setting maze environment");

        Window m_xSolnWin=new Window(dim);

        m_xSolnWin.pack();
        m_xSolnWin.setLocationRelativeTo(null);
        m_xSolnWin.setVisible(true);
    }

    public void actionPerformed(ActionEvent e)
    {
        //If the launch button was pressed
        if("launch".equals(e.getActionCommand()))
        {
            //Check that the maze size wasn't empty
            if(m_jtDim.getText().isEmpty())
                JOptionPane.showMessageDialog(null,"You must specify a size",
                            "Error",JOptionPane.ERROR_MESSAGE);
            else
            {
                try
                {
                    //Make sure it's actually an integer.
                    int dim=Integer.parseInt(m_jtDim.getText());
                    //Also make sure that the dimension isn't out of range
                    if(dim<2||dim>100)
                    {
                        JOptionPane.showMessageDialog(null,"Dimension must be " +
                                "between 2 and 100","Error",JOptionPane.ERROR_MESSAGE);
                        return;
                    }
                    //And if everything is okay, go ahead and spawn
                    spawnWindow(dim);
                }
                catch(NumberFormatException nfe)
                {
                    JOptionPane.showMessageDialog(null,"Dimension must be an integer",
                            "Error",JOptionPane.ERROR_MESSAGE);
                    return;
                }
            }
        }
    }

}
