
package maze;

import java.awt.*;
import java.awt.event.*;
import java.util.*;

import javax.swing.*;
import javax.swing.event.*;

/**
 * <p>Title: Maze Window</p>
 * <p>Description: A View-Control design pattern that shows the maze and implements the control to
 *    perform various operations on a maze</p>
 * <p>Copyright: Copyright (c) 2002</p>
 * <p>Company: </p>
 * @author Zoran Budimlic
 * @version 1.0
 */

public class MazeWindow extends JFrame {

    MazeGrid mazeGrid = new MazeGrid(this);
    JPanel mazeGridPanel = new JPanel();
    
    
  JPanel contentPane;
  JMenuBar jMenuBar1 = new JMenuBar();
  JMenu jMenuFile = new JMenu();
  JMenuItem jMenuFileExit = new JMenuItem();
  JMenu jMenuHelp = new JMenu();
  JMenuItem jMenuHelpAbout = new JMenuItem();
  BorderLayout borderLayout1 = new BorderLayout();
  JButton NewMaze = new JButton();
  JButton DepthFirst = new JButton();
  JButton ClearMaze = new JButton();
  JPanel jPanel1 = new JPanel();
  JButton BreadthFirst = new JButton();
  JButton AStar = new JButton();

  /**
   * The Maze for which this View is set up
   */
  Maze maze;

  /**
   * Number of rows in the maze
   */
  int ROWS = 50;
  /**
   * Number of coloumns in the maze
   */
  int COLS = 50;
  /**
   * The X coordinate of the starting point for drawing the maze
   */
  int xStart = 100;
  /**
   * The X coordinate of the end point for drawing the maze
   */
  int xEnd = 500;
  /**
   * The Y coordinate of the starting point for drawing the maze
   */
  int yStart = 150;
  /**
   * The Y coordinate of the end point for drawing the maze
   */
  int yEnd = 550;
  /**
   * The cell size on the X axis in pixels
   */
  int dx = (xEnd - xStart)/COLS;
  /**
   * The cell size on the Y axis in pixels
   */
  int dy = (yEnd - yStart)/ROWS;

    // Wall thickness
    int wallthickness;

  /**
   * The amount of time (in miliseconds) to pause when the pause() method is called
   */
  int PAUSE_MS = 10;

  JSlider Speed = new JSlider(JSlider.HORIZONTAL,1,10,5);
  JMenu Setup = new JMenu();
  JMenuItem SetSize = new JMenuItem();


  //Construct the frame
  public MazeWindow() {
    enableEvents(AWTEvent.WINDOW_EVENT_MASK);
    try {
      jbInit();
    }
    catch(Exception e) {
      e.printStackTrace();
    }
  }
  //Component initialization
  private void jbInit() throws Exception  {
    //setIconImage(Toolkit.getDefaultToolkit().createImage(MazeWindow.class.getResource("[Your Icon]")));

    setMazeSize(50, 50);

    contentPane = (JPanel) this.getContentPane();
    contentPane.setLayout(borderLayout1);
    this.setSize(new Dimension(591, 577));
    this.setTitle("Frame Title");
    jMenuFile.setText("File");
    jMenuFileExit.setText("Exit");
    jMenuFileExit.addActionListener(new ActionListener()  {
      public void actionPerformed(ActionEvent e) {
        jMenuFileExit_actionPerformed(e);
      }
    });
    jMenuHelp.setText("Help");
    jMenuHelpAbout.setText("About");
    jMenuHelpAbout.addActionListener(new ActionListener()  {
      public void actionPerformed(ActionEvent e) {
        jMenuHelpAbout_actionPerformed(e);
      }
    });
    NewMaze.setHorizontalAlignment(SwingConstants.LEFT);
    NewMaze.setText("New");
    NewMaze.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        NewMaze_actionPerformed(e);
      }
    });
    DepthFirst.setHorizontalAlignment(SwingConstants.LEFT);
    DepthFirst.setText("Depth-First");
    DepthFirst.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        DepthFirst_actionPerformed(e);
      }
    });
    ClearMaze.setHorizontalAlignment(SwingConstants.LEFT);
    ClearMaze.setText("Clear");
    ClearMaze.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        ClearMaze_actionPerformed(e);
      }
    });
    BreadthFirst.setText("Breadth-First");
    BreadthFirst.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        BreadthFirst_actionPerformed(e);
      }
    });
    AStar.setText("A*");
    AStar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        AStar_actionPerformed(e);
      }
    });
    Setup.setText("Setup");
    SetSize.setText("Set Size");
    SetSize.addActionListener(new ActionListener()  {
      public void actionPerformed(ActionEvent e) {
        SetSize_actionPerformed(e);
      }
    });    jMenuFile.add(jMenuFileExit);
    jMenuHelp.add(jMenuHelpAbout);
    jMenuBar1.add(jMenuFile);
    jMenuBar1.add(Setup);
    jMenuBar1.add(jMenuHelp);
    this.setJMenuBar(jMenuBar1);
    contentPane.add(jPanel1, BorderLayout.NORTH);
    jPanel1.add(NewMaze, null);
    jPanel1.add(ClearMaze, null);
    jPanel1.add(DepthFirst, null);
    jPanel1.add(BreadthFirst, null);
    jPanel1.add(AStar, null);
    Speed.addChangeListener(new SliderListener());
    Speed.setMajorTickSpacing(10);
    Speed.setMinorTickSpacing(1);
    Speed.setPaintTicks(true);
    //Create the label table
    Hashtable labelTable = new Hashtable();
    labelTable.put( new Integer( 0 ), new JLabel("Slow") );
    labelTable.put( new Integer( 10 ), new JLabel("Fast") );
    Speed.setLabelTable( labelTable );

    Speed.setPaintLabels(true);
    Speed.setBorder(BorderFactory.createEmptyBorder(0,0,10,0));

    jPanel1.add(Speed, null);
    Setup.add(SetSize);
    
    // Add the mazegrid.
    mazeGridPanel.add(mazeGrid);
    mazeGridPanel.setLayout(new FlowLayout());    
    contentPane.add(mazeGridPanel, BorderLayout.CENTER);    
 }
  //File | Exit action performed
  public void jMenuFileExit_actionPerformed(ActionEvent e) {
    System.exit(0);
  }
  //Help | About action performed
  public void jMenuHelpAbout_actionPerformed(ActionEvent e) {
  }
  //Overridden so we can exit when window is closed
  protected void processWindowEvent(WindowEvent e) {
    super.processWindowEvent(e);
    if (e.getID() == WindowEvent.WINDOW_CLOSING) {
      jMenuFileExit_actionPerformed(null);
    }
  }

  /**
   * Compute the appropriate color for the cell in the maze based on the
   * status of the cell. If the cell is not visited, the color will be green, if it is
   * on the path, the color will be red, if it is abandoned, the color will be gray
   * @param x The X coordinate of the cell
   * @param y The Y coordinate of the cell
   * @return
   */
  Color getColor(int x, int y){
     Color color = null;
     Status status = maze.getStatus(x,y);
     if(status == Status.NotVisited)
       color = Color.green;
     else if(status == Status.OnPath)
       color = Color.red;
     else if (status == Status.Abandoned)
       color = Color.lightGray;
     else
        color = null;
     return color;
  }

  /**
   * What happends when the user does something with the New button
   * @param e
   */
  void NewMaze_actionPerformed(ActionEvent e) {
     if(this.maze == null)
         this.maze = Maze.generateNewMaze(ROWS, COLS, this);
     maze.stop();
     maze.strategy = Strategy.MazeGen;
     repaint();
     maze.start();
  }

   /**
   * What happends when the user does something with the Clear button
   * @param e The event (click) that is being dispatched
   */
  void ClearMaze_actionPerformed(ActionEvent e) {
     if(maze==null) return;
     maze.stop();
     maze.strategy = Strategy.Clear;
     maze.start();
  }

   /**
   * What happends when the user does something with the DepthFirst button
   * @param e The event (click) that is being dispatched
   */
  void DepthFirst_actionPerformed(ActionEvent e) {
     if(this.maze==null) return;
     maze.stop();
     maze.clear();
     repaint();
     maze.strategy = Strategy.DFS;
     maze.start();
  }

  /**
   * What happends when the user does something with the BreadthFirst button
   * @param e The event (click) that is being dispatched
   */
  void BreadthFirst_actionPerformed(ActionEvent e) {
     if(this.maze==null) return;
     maze.stop();
     maze.clear();
     repaint();     maze.strategy = Strategy.BFS;
     maze.start();
  }

  /**
   * What happends when the user does something with the A* button
   * @param e The event (click) that is being dispatched
   */
  void AStar_actionPerformed(ActionEvent e) {
     if(this.maze==null) return;
     maze.stop();
     maze.clear();
     repaint();     maze.strategy = Strategy.AStar;
     maze.start();
  }

  /**
   * What happends when the user chooses the Set Size menu item
   * @param e The event that is being dispatched
   */
  void SetSize_actionPerformed(ActionEvent e){
     SizeDialog d = new SizeDialog(this);
     d.setSize(400,200);
     d.XField.setText(""+COLS);
     d.YField.setText(""+ROWS);

     d.show();
  }

  /**
   * Refresh the cell in the maze. This method should be called whenever the user changes
   * the status of a cell. It will repaint the cell and the wall(s) around it.
   * @param x The X coordinate of the cell
   * @param y The Y coordinate of the cell
   */
  public void refresh(int x, int y){
     mazeGrid.refresh(x, y);
  }

  /**
   * Refresh and repaint the cell in the maze. This method will not only refresh the given cell
   * in the maze, but it will also pause the maze thread so that the user interface can redraw the maze
   * @param x The X coordinate of the cell
   * @param y The Y coordinate of the cell
   */
  public void refreshAndRepaint(int x, int y){
     refresh(x,y);
     maze.pause(PAUSE_MS);
  }

  /**
   *
   * <p>Title: SliderListener</p>
   * <p>Description: An inner class that implements the ChangeListener on the Speed slider.
   *   Its only purpose is to change the PAUSE_MS variable according to the position of the slider</p>
   * <p>Copyright: Copyright (c) 2002</p>
   * <p>Company: </p>
   * @author Zoran Budimlic
   * @version 1.0
   */
  class SliderListener implements ChangeListener {
    public void stateChanged(ChangeEvent e) {
        JSlider source = (JSlider)e.getSource();
        if (!source.getValueIsAdjusting()) {
           int val = (int)source.getValue();
           PAUSE_MS = 2048/(2<<val);

        }
    }
  }

  /**
   * Set the maze dimensions. Recompute the drawing borders and cell dimensions in pixels.
   * @param x The new X dimension
   * @param y The new Y dimension
   */
  public void setMazeSize(int x, int y){
     ROWS = y;
     COLS = x;
     xStart = 100;
     xEnd = 500;
     yStart = 150;
     yEnd = 550;
     dx = (xEnd - xStart)/COLS;
     dy = (yEnd - yStart)/ROWS;

     dx = Math.max(dx, 3);
     dy = Math.max(dy, 3);

     int t=4; // thickness of the walls
     // need to adjust the thickness of the walls if the cells are too small
     if (dx < 20) t = dx/8;
     if (dy < 20 && dy<dx) t = dy/8 ;
     if (t<=0) t = 1;
     wallthickness = t;

     // eliminate the rounding errors for drawing the mazes
     xEnd = xStart + dx*COLS;
     yEnd = yStart + dy*ROWS;
     mazeGrid.revalidate();
     mazeGrid.repaint();
     if (maze != null) maze.stop();
     maze = Maze.generateNewMaze(ROWS,COLS,this);
  }
  }

