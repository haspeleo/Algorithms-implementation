/*
 * File:   MouseHandler.java
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
 * Created on 02/04/2010, 21:22
 */

package code.reddy.ai.pathfinder;

import java.awt.event.*;

/**
 *
 * A Mouse event listener and handler that sets and resets nodes based on what
 * the user is clicking. This is where we set up start/goal/battery nodes etc.
 *
 * @author Bharat Reddy
 */
public class MouseHandler extends MouseAdapter
{

    @Override
    public void mouseClicked(MouseEvent e)
    {
        Node currNode=(Node)e.getSource();
        Grid parentGrid=(Grid)currNode.getParent();
        if(parentGrid.isLocked())
            return;
        switch(e.getButton())
        {
            case MouseEvent.BUTTON1:
                if(e.isShiftDown())
                    currNode.setGoal();
                else
                    currNode.setStart();
                break;
            case MouseEvent.BUTTON3:
                if(e.isShiftDown())
                    if(currNode.getStatus()==3)
                        currNode.setNormal();
                    else
                        currNode.setBattery();
                else
                    if(currNode.getStatus()==4)
                        currNode.setNormal();
                    else
                        currNode.setBlocked();
                break;
            default:
                currNode.setNormal();
                break;
        }
    }
}
