package maze;

/**
 * <p>Title: Strategy</p>
 * <p>Description: An abstract class that defines a strategy for performing an algorithm on a maze</p>
 * <p>Copyright: Copyright (c) 2002</p>
 * <p>Company: </p>
 * @author Zoran Budimlic
 * @version 1.0
 */

public abstract class Strategy {

  public Strategy() {

  }

  /**
   * A strategy method. You should define this method in the subclasses to execute
   * a particular algorithm on a maze - maze generation, DFS, BFS or A* traversal
   */
  abstract public void execute(Maze maze);

  /**
   * A Singleton for depth-first search strategy. Instead of initializing DFS to Clear,
   * you should change this assignment to assign a new instance of whatever class you
   * design to implement the depth-first search.
   */
  static public final Strategy DFS = new Clear();

  /**
   * A Singleton for breadth-first search strategy. Instead of initializing BFS to Clear,
   * you should change this assignment to assign a new instance of whatever class you
   * design to implement the breadth-first search.
   */
  static public final Strategy BFS = new Clear();

    /**
   * A Singleton for A* search strategy. Instead of initializing AStar to Clear,
   * you should change this assignment to assign a new instance of whatever class you
   * design to implement the A* search.
   */
  static public final Strategy AStar = new Clear();
  
  /**
   * A Singleton for maze generation strategy. Instead of initializing MazeGen to Clear,
   * you should change this assignment to assign a new instance of whatever class you
   * design to implement the completely connected maze generation.
   */
  static public final Strategy MazeGen = new Clear();
  /**
   * A Singleton for clearing the maze. This is an example of a strategy that is already implemented.
   * You should initialize the other strategy singletons in a similar manner.
   */
  static public final Strategy Clear = new Clear();


}
