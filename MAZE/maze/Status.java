package maze;

/**
 * <p>Title: Status</p>
 * <p>Description: Constants for the maze cell status</p>
 * <p>Copyright: Copyright (c) 2002</p>
 * <p>Company: </p>
 * @author Zoran Budimlic
 * @version 1.0
 */

public final class Status {

  /**
   * A status of a cell that is not yet visited
   */
  public final static Status NotVisited = new Status();
  /**
   * A status of a cell that is currently on the considered path to the target
   */
  public final static Status OnPath = new Status();
  /**
   * A status of a cell that is abandoned as a cell on a path to the target
   */
  public final static Status Abandoned = new Status();

  private Status() {
  }
}
