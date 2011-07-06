package maze;

/**
 * <p>Title: Maze</p>
 * <p>Description: An abstract class that defines the maze interface</p>
 * <p>Copyright: Copyright (c) 2002</p>
 * <p>Company: </p>
 * @author Zoran Budimlic
 * @version 1.0
 */

public abstract class Maze implements Runnable{

  /**
   * The corresponding View design patter for this maze
   */
  MazeWindow window = null;

  /**
   * The Strategy design patter for different operations on a maze
   */
  Strategy strategy = null;

  /**
   * A Factory method for generating a new maze. You should generate a new instance of your
   * concrete class that implements the maze data structure here.
   * @param rows Number of rows of the new maze
   * @param cols Number of coloumns of the new maze
   * @param window The MazeWindow that will draw this new maze to the user
   * @return The newly generated maze
   */
  public static Maze generateNewMaze(int rows, int cols, MazeWindow window){
     Maze maze = new RandomMaze(rows,cols,window);
     return maze;
  }

  /**
   * We have to run the maze in a thread to enable "animated" maze operations
   * Don't worry about this
   */
  Thread maze;


   /**
   * Return the status of a cell in a maze. The following codes should be used
   * for cell status:
   * Status.NotVisited - the cell has not been visited
   * Status.OnPath - the cell has been visited and it is on the currently researched path
   * Status.Abandoned - the cell has been visited and it is abandoned as a possible path to the destination
   * @param x The x coordinate of the cell in the maze
   * @param y The y coordinate of the cell in the maze
   * @return The current status of the cell in question
   */
  public abstract Status getStatus(int x, int y);

   /**
   * Set the status of a cell in a maze. The following codes should be used
   * for cell status:
   * Status.NotVisited - the cell has not been visited
   * Status.OnPath - the cell has been visited and it is on the currently researched path
   * Status.Abandoned - the cell has been visited and it is abandoned as a possible path to the destination
   * @param x The x coordinate of the cell in the maze
   * @param y The y coordinate of the cell in the maze
   * @param s The new status of the cell in question
   */
  public abstract void setStatus(int x, int y, Status s);

  /**
   * A query to tell whether there is a wall between two cells in a maze
   * @param x1
   * @param x2
   * @param y1
   * @param y2
   * @return
   */
  public abstract boolean isThereAWall(int x1, int y1, int x2, int y2);

/**
 * Remove a wall between two cells in a maze
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 */
  public abstract void removeWall(int x1, int y1, int x2, int y2);

/**
 * Put a wall between two cells in a maze
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 */
  public abstract void putWall(int x1, int y1, int x2, int y2);

   /**
   * Clear the status of all maze cells. The status of all cells should be reset to Status.NotVisited
   */
  public abstract void clear();


  /**
   * Set the coordinates of the starting point in the maze
   * @param x
   * @param y
   */
  public abstract void setStart(int x, int y);

  /**
   * Set the coordinates of the end point in the maze
   * @param x
   * @param y
   */
  public abstract void setEnd(int x, int y);

   /**
   *
   * @return The X coordinate of the starting point
   */
  public abstract int startX();

  /**
   *
   * @return The Y coordinate of the starting point
   */
  public abstract int startY();

  /**
   *
   * @return The X coordinate of the end point
   */
  public abstract int endX();

  /**
   *
   * @return The Y coordinate of the end point
   */
  public abstract int endY();

/**
 *
 * @return The number of rows in the maze
 */
  public abstract int rows();

/**
 *
 * @return The number of coloumns in the maze
 */
  public abstract int cols();


  /**
   * A waiting routine. This is called whenever MazeWindow.repaintAndRefresh routine is called. Don't worry about this.
   * @param ms
   */
  public synchronized void pause(int ms){
    try{
      wait(ms);
    }catch(Exception e){
      ;
    }
  }

  /**
   * Run the apropriate strategy on this maze. Don't worry about this.
   */

public synchronized void run(){
        strategy.execute(this);

  }
  /**
   * Start the maze thread. Don't worry about this.
   */
  public synchronized void start(){
     maze = new Thread(this);
     maze.start();
  }

  /**
   * Stop the maze thread. Don't worry about this
   */
  public synchronized void stop(){
     if(maze!=null) {
     	maze.stop();
     	while(maze.isAlive()) {
     		try {
	     		wait(100);
     		}
     		catch(InterruptedException e) {
     		}
     	}
     }
     maze = null;
     notify();
  }



}

