
/*
 * Created on Jan 24, 2005
 * Ryan Prichard
 */
package maze;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Rectangle;

import javax.swing.JComponent;


/**
 * Paints the actual maze grid.
 */
public class MazeGrid extends JComponent {
    
    private MazeWindow _window;

    /**
     * @param window
     */
    MazeGrid(MazeWindow window) {
        this._window = window;
    }

    public void refresh(int x, int y) {
        this.setOpaque(false);
        
        int t = this._window.wallthickness;
        int dt = t / 2;
        
        repaint(1, x*this._window.dx - dt - 5, y*this._window.dy - dt - 5, this._window.dx + t + 10, this._window.dy + t + 10);
    }
    
    public void paint(Graphics g) {
        super.paint(g);

       if(this._window.maze !=null) {

       Color color = null;
       int i,j;

       int t=this._window.wallthickness;

       int dt = t/2;

        int xStart = dt;
        int yStart = dt;
        int xEnd = xStart + this._window.COLS*this._window.dx;
        int yEnd = yStart + this._window.ROWS*this._window.dy;
        

       //xStart = yStart = 0;

       // Get the clip boundary.
       int clipFirstX = 0;
       int clipFirstY = 0;
       int clipLastX = this._window.COLS-1;
       int clipLastY = this._window.ROWS-1;
       Rectangle r = g.getClipBounds();
       if (r != null) {
          clipFirstX = (((int)r.getX() - 1) - xStart) / this._window.dx;
          clipFirstY = (((int)r.getY() - 1) - yStart) / this._window.dy;
          clipLastX = (((int)(r.getX() + r.width) - 1) - xStart) / this._window.dx;
          clipLastY = (((int)(r.getY() + r.height) - 1) - yStart) / this._window.dy;
          clipFirstX = Math.max(0, clipFirstX-1);
          clipFirstY = Math.max(0, clipFirstY-1);
          clipLastX = Math.min(this._window.COLS-1, clipLastX+1);
          clipLastY = Math.min(this._window.ROWS-1, clipLastY+1);
       }

       //draw the cells
       for (i = clipFirstX; i <= clipLastX; i++)
          for(j = clipFirstY; j <= clipLastY; j++){
             g.setColor(this._window.getColor(i,j));
             g.fillRect(xStart + i*this._window.dx, yStart + j*this._window.dy,this._window.dx,this._window.dy);
             if(this._window.maze.isThereAWall(i-1,j,i,j)){
                g.setColor(Color.black);
                g.fillRect(xStart + i*this._window.dx-dt, yStart + j*this._window.dy , t, this._window.dy);
             }
             if(this._window.maze.isThereAWall(i,j-1,i,j)){
                g.setColor(Color.black);
                g.fillRect(xStart + i*this._window.dx, yStart + j*this._window.dy-dt , this._window.dx, t);
             }

       }

        // draw a wall around the maze
       g.setColor(Color.black);
       g.fillRect(xStart,yStart-dt,xEnd-xStart,t);    // top
       g.fillRect(xStart,yEnd-dt,xEnd-xStart,t);      // bottom
       g.fillRect(xStart-dt,yStart,t,yEnd-yStart);    // left
       g.fillRect(xEnd-dt,yStart,t,yEnd-yStart);      // right

       // don't fill the whole cell with a circle for starting and ending points, make it a little smaller
       int off = this._window.dx/4;
       if (this._window.dx - 2*off <= 4 || this._window.dy - 2*off <=4) off = 0;

       // draw starting point
       g.setColor(Color.blue);
       g.fillOval(xStart + this._window.dx*this._window.maze.startX()+off,yStart+this._window.dy*this._window.maze.startY()+off,this._window.dx-2*off,this._window.dy-2*off);

        // draw ending point
       g.setColor(Color.blue);
       g.fillOval(xStart + this._window.dx*this._window.maze.endX() +off,yStart+this._window.dy*this._window.maze.endY()+off,this._window.dx-2*off,this._window.dy-2*off);

        
    }
    }
    
    public Dimension getPreferredSize() {
        return getMinimumSize();
    }
    
public Dimension getMinimumSize() {
        return new Dimension(
                this._window.COLS*this._window.dx + this._window.wallthickness,
                this._window.ROWS*this._window.dy + this._window.wallthickness);
    }

}



