package maze;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

/**
 * <p>Title: SizeDialog</p>
 * <p>Description: A dialog to enter the new maze dimensions</p>
 * <p>Copyright: Copyright (c) 2002</p>
 * <p>Company: </p>
 * @author Zoran Budimlic
 * @version 1.0
 */
public class SizeDialog extends JDialog {
  JTextField XField = new JTextField();
  JLabel XSize = new JLabel();
  JLabel YSize = new JLabel();
  JTextField YField = new JTextField();
  JButton OKButton = new JButton();
  JButton CancelButton = new JButton();
  JLabel jLabel1 = new JLabel();
  MazeWindow window;
  Panel panel1 = new Panel();


  public SizeDialog(Frame frame, String title, boolean modal, MazeWindow window) {
    super(frame, title, modal);
    this.window = window;
    try {
      jbInit();
      pack();
    }
    catch(Exception ex) {
      ex.printStackTrace();
    }
  }

  public SizeDialog(MazeWindow window) {
      this(null, "", false, window);
  }
  void jbInit() throws Exception {
    XSize.setHorizontalAlignment(SwingConstants.RIGHT);
    XSize.setText("X Size:");
    XSize.setVerticalAlignment(SwingConstants.BOTTOM);
    XSize.setBounds(new Rectangle(70, 58, 99, 17));
    YSize.setToolTipText("");
    YSize.setHorizontalAlignment(SwingConstants.RIGHT);
    YSize.setHorizontalTextPosition(SwingConstants.RIGHT);
    YSize.setText("Y Size:");
    YSize.setBounds(new Rectangle(83, 97, 84, 17));
    OKButton.setBounds(new Rectangle(168, 140, 51, 27));
    OKButton.setText("OK");
    OKButton.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        OKButton_actionPerformed(e);
      }
    });
    CancelButton.setBounds(new Rectangle(247, 140, 73, 27));
    CancelButton.setText("Cancel");
    CancelButton.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        CancelButton_actionPerformed(e);
      }
    });
    YField.setPreferredSize(new Dimension(10, 21));
    YField.setBounds(new Rectangle(173, 96, 154, 21));
    jLabel1.setText("Enter the maze dimensions:");
    jLabel1.setBounds(new Rectangle(78, 25, 154, 17));
    this.getContentPane().setLayout(null);
    this.setResizable(false);
    this.setTitle("Enter the maze dimensions");
    panel1.setLayout(null);
    XField.setBounds(new Rectangle(173, 57, 154, 21));
    panel1.setBounds(new Rectangle(0, 0, 407, 180));
    panel1.add(CancelButton, null);
    panel1.add(OKButton, null);
    panel1.add(YField, null);
    panel1.add(jLabel1, null);
    panel1.add(XField, null);
    panel1.add(XSize, null);
    panel1.add(YSize, null);
    this.getContentPane().add(panel1, null);
  }

  /**
   * What to do when the user clicks the "Cancel" button
   * @param e The event dispatched
   */
  void CancelButton_actionPerformed(ActionEvent e) {
     this.hide();
  }

  /**
   * What to do when the user clicks the "OK" button
   * @param e The event dispathed
   */
  void OKButton_actionPerformed(ActionEvent e) {
     int x,y;
     try{
       x = Integer.decode(XField.getText()).intValue();
       y = Integer.decode(YField.getText()).intValue();
     }catch(Exception ex){
        return;
     }
     if (x > 0 && y > 0)
       window.setMazeSize(x,y);
     this.hide();
  }
}
