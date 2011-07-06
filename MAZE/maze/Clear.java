package maze;

/**
 * <p>Title: Clear</p>
 * <p>Description: A simple strategy to clear the maze. Just traverse all the cells and set their status to Not Visited </p>
 * <p>Copyright: Copyright (c) 2002</p>
 * <p>Company: </p>
 * @author Zoran Budimlic
 * @version 1.0
 */
public class Clear extends Strategy {

  public Clear() {
  }

  /**
   * This is an example of a strategy that you should implement. To "animate" the execution of
   * you strategy, you have to call the refreshAndRepaint method after you change the status of a cell
   * @param maze - The Maze object on which to execute our algorithm
   */
  public void execute(Maze maze) {
    for(int i = 0; i < maze.cols(); i++){
       for(int j = 0; j < maze.rows(); j++){
          maze.setStatus(i,j,Status.NotVisited);
          maze.window.refreshAndRepaint(i,j);
       }
    }
  }
}
