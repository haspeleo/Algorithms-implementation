package maze;

/**
 * <p>Title: RandomMaze</p>
 * <p>Description: A random generated maze. This is a very simple example of a maze.</p>
 * <p>Copyright: Copyright (c) 2002</p>
 * <p>Company: </p>
 * @author Zoran Budimlic
 * @version 1.0
 */

public class RandomMaze extends Maze {

  /**
   * A two-dimensional array to hold the status of the maze cells
   */
  Status M[][];
  /**
   * A four-dimensional array to hold the adjacency matrix of the maze walls
   */
  boolean walls[][][][];

  /**
   * Coordinates of the starting and ending point in the maze
   */
  int startX,startY,endX,endY;


  /**
   * Set the coordinates of the start point in the maze
   * @param x
   * @param y
   */
  public void setStart(int x, int y){
    startX = x; startY = y;
  }

  /**
   * Set the coordinates of the end point in the maze
   * @param x
   * @param y
   */
  public void setEnd(int x, int y){
    endX = x; endY = y;
  }

  /**
   *
   * @return the number of coloumns in the maze
   */
  public int cols(){return M.length;}

  /**
   *
   * @return The number of rows in the maze
   */
  public int rows(){return M[0].length;}

  /**
   * Generate a new maze with random status of each cell and random walls between cells
   * @param rows Number of rows
   * @param cols Number of coloumns
   */
  public RandomMaze(int rows, int cols, MazeWindow window) {
     this.window = window;
     M = new Status[cols][rows];
     walls = new boolean[cols][rows][cols][rows];
     int x1,y1,x2,y2;
     for(x1 = 0; x1<cols; x1++)
       for(y1 = 0; y1<rows; y1++){
          int status = (int)Math.round(Math.random()*3 - 0.5);
          switch(status){
            case 0 : M[x1][y1] = Status.NotVisited;break;
            case 1 : M[x1][y1] = Status.OnPath;break;
            case 2 : M[x1][y1] = Status.Abandoned;break;
          }
        }
     for(x1=0; x1<cols; x1++)
       for(y1=0;y1<rows;y1++)
         for(x2=0;x2<cols;x2++)
           for(y2=0;y2<rows;y2++)
              walls[x1][y1][x2][y2] = (Math.random()>0.5)? true:false;
     startX = 0; endX = cols - 1;
     startY = (int)Math.round(Math.random()*rows - 0.5);
     endY = (int)Math.round(Math.random()*rows - 0.5);
  }

  /**
   *
   * @param x X coordinate of the cell
   * @param y Y coordinate of the cell
   * @return The status of the cell
   */
  public Status getStatus(int x, int y){
       return M[x][y];
  }

  /**
   * Change the status of a cell in the maze
   * @param x X coordinate of the cell
   * @param y Y coordiante of teh cell
   * @param s New status of the cell
   */
  public void setStatus(int x, int y, Status s){
       M[x][y] = s;
  }

  /**
   * Is there a wall between cells (x1,y1) and (x2,y2)?
   * @param x1
   * @param y1
   * @param x2
   * @param y2
   * @return
   */
  public boolean isThereAWall(int x1, int y1, int x2, int y2){
     int cols = walls.length, rows = walls[0].length;
     if(x1<0 || x2<0 || y1<0 || y2<0 || x1>=cols || y1>=rows || x2>=cols || y2>=rows) return false;
     return walls[x1][y1][x2][y2];
  }

  /**
   * Put a wall between cells (x1,y1) and (x2,y2)
   * @param x1
   * @param y1
   * @param x2
   * @param y2
   */
  public void putWall(int x1, int y1, int x2, int y2){
     setWall(x1,y1,x2,y2,true);
  }

  /**
   * Remove a wall between cells (x1,y1) and (x2,y2)
   * @param x1
   * @param y1
   * @param x2
   * @param y2
   */
  public void removeWall(int x1, int y1, int x2, int y2){
     setWall(x1,y1,x2,y2,false);
  }

  /**
   * Set a wall between cells (x1,y1) and (x2,y2) to have the value value
   * @param x1
   * @param y1
   * @param x2
   * @param y2
   * @param value True if there should be a wall, false otherwise
   */
  void setWall(int x1, int y1, int x2, int y2, boolean value){
     int cols = walls.length, rows = walls[0].length;
     if(x1<0 || x2<0 || y1<0 || y2<0 || x1>=cols || y1>=rows || x2>=cols || y2>=rows) return;
     walls[x1][y1][x2][y2] = value;
  }

  /**
   * Clear the maze. Reset all the cells to status NotVisited
   */
  public void clear(){
  }

  /**
   *
   * @return The X coordinate of the starting point in the maze
   */
  public int startX(){
     return startX;
  }

  /**
   *
   * @return The Y coordinate of the starting point in the maze
   */
  public int startY(){
     return startY;
  }

  /**
   *
   * @return The X coordinate of the end point in the maze
   */
  public int endX(){
     return endX;
  }

  /**
   *
   * @return The Y coordinate of the end point in the maze
   */
  public int endY(){
     return endY;
  }

  /**
   * Ensure that the maze is a fully connnected one, i.e. that there is a path
   * between any two cells in the maze
   */
  public void connectMaze(){
  }

}
