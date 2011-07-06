// Exercise 2.15: VendingMachine.java
// Creates vending machine GUI.

//http://www.hackchina.com/en/r/199221/VendingMachine.java__html

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;

public class VendingMachine extends JFrame
{
   private JButton oneJButton, twoJButton, threeJButton, fourJButton,
      aJButton, bJButton, pushJButton;
   private JLabel a1JLabel, a2JLabel, a3JLabel, b1JLabel, b2JLabel, 
      b3JLabel, a1IconJLabel, a2IconJLabel, a3IconJLabel, 
      b1IconJLabel, b2IconJLabel, b3IconJLabel;
   private JPanel windowJPanel, selectionJPanel;
   private JTextField displayJTextField;
   
   // no-argument constructor
   public VendingMachine()
   {
      createUserInterface();
   }
   
   // create and position GUI components
   private void createUserInterface()
   {
      // get content pane and set layout to null
      Container contentPane = getContentPane();
      contentPane.setLayout( null );
      
      // set up windowJPanel
      windowJPanel = new JPanel();
      windowJPanel.setBounds( 10, 10, 190, 170 );
      windowJPanel.setBorder( new LineBorder( Color.BLACK ) );
      windowJPanel.setLayout( null );
      contentPane.add( windowJPanel );
      
      // set up a1IconJLabel
      a1IconJLabel = new JLabel();
      a1IconJLabel.setIcon(new ImageIcon("images/cookie.png"));
      a1IconJLabel.setBounds( 10, 10, 50, 50 );
      windowJPanel.add( a1IconJLabel );
      
      // set up a1JLabel
      a1JLabel = new JLabel();
      a1JLabel.setText( "A1" );
      a1JLabel.setBounds( 10, 60, 50, 20 );
      a1JLabel.setHorizontalAlignment( JLabel.CENTER );
      windowJPanel.add( a1JLabel );
      
      // set up a2IconJLabel
      a2IconJLabel = new JLabel();
      a2IconJLabel.setIcon(new ImageIcon("images/gum.png"));
      a2IconJLabel.setBounds( 70, 10, 50, 50 );
      windowJPanel.add( a2IconJLabel );
      
      // set up a2JLabel
      a2JLabel = new JLabel();
      a2JLabel.setText( "A2" );
      a2JLabel.setBounds( 70, 60, 50, 20 );
      a2JLabel.setHorizontalAlignment( JLabel.CENTER );
      windowJPanel.add( a2JLabel );
      
      // set up a3IconJLabel
      a3IconJLabel = new JLabel();
      a3IconJLabel.setIcon(new ImageIcon("images/pretzel.png"));
      a3IconJLabel.setBounds( 130, 10, 50, 50 );
      windowJPanel.add( a3IconJLabel );
            
      // set up a3JLabel
      a3JLabel = new JLabel();
      a3JLabel.setText( "A3" );
      a3JLabel.setBounds( 130, 60, 50, 20 );
      a3JLabel.setHorizontalAlignment( JLabel.CENTER );
      windowJPanel.add( a3JLabel );
      
      // set up b1IconJLabel
      b1IconJLabel = new JLabel();
      b1IconJLabel.setIcon( new ImageIcon( "images/pretzel.png" ) );
      b1IconJLabel.setBounds( 10, 90, 50, 50 );
      windowJPanel.add( b1IconJLabel );
      
      // set up b1JLabel
      b1JLabel = new JLabel();
      b1JLabel.setText( "B1" );
      b1JLabel.setBounds( 10, 140, 50, 20 );
      b1JLabel.setHorizontalAlignment( JLabel.CENTER );
      windowJPanel.add( b1JLabel );
      
      // set up b2IconJLabel
      b2IconJLabel = new JLabel();
      b2IconJLabel.setIcon( new ImageIcon( "images/cookie.png" ) );
      b2IconJLabel.setBounds( 70, 90, 50, 50 );
      windowJPanel.add( b2IconJLabel );
      
      // set up b2JLabel
      b2JLabel = new JLabel();
      b2JLabel.setText( "B2" );
      b2JLabel.setBounds( 70, 140, 50, 20 );
      b2JLabel.setHorizontalAlignment( JLabel.CENTER );
      windowJPanel.add( b2JLabel );
      
      // set up b3IconJLabel
      b3IconJLabel = new JLabel();
      b3IconJLabel.setIcon( new ImageIcon( "images/soda.png" ) );
      b3IconJLabel.setBounds( 130, 90, 50, 50 );
      windowJPanel.add( b3IconJLabel );
      
      // set up b3JLabel
      b3JLabel = new JLabel();
      b3JLabel.setText( "B3" );
      b3JLabel.setBounds( 130, 140, 50, 20 );
      b3JLabel.setHorizontalAlignment( JLabel.CENTER );
      windowJPanel.add( b3JLabel );
            
      // set up pushJButton
      pushJButton = new JButton();
      pushJButton.setText( "PUSH" );
      pushJButton.setBounds( 10, 190, 190, 30 );
      contentPane.add( pushJButton );
      
      // set up displayJTextField
      displayJTextField = new JTextField();
      displayJTextField.setText( "B2" );
      displayJTextField.setBounds( 210, 10, 170, 30 );
      displayJTextField.setEditable( false );
      displayJTextField.setHorizontalAlignment( JLabel.CENTER );
      contentPane.add( displayJTextField );
      
      // set up selectionJPanel
      selectionJPanel = new JPanel();
      selectionJPanel.setBounds( 210, 50, 170, 130 );
      selectionJPanel.setBorder( new TitledBorder( new EtchedBorder( 
         EtchedBorder.LOWERED ), "Please make selection" ) );
      selectionJPanel.setLayout( null );
      contentPane.add( selectionJPanel );
      
      // set up aJButton
      aJButton = new JButton();
      aJButton.setText( "A" );
      aJButton.setBounds( 40, 20, 42, 42 );
      selectionJPanel.add( aJButton );
      
      // set up bJButton
      bJButton = new JButton();
      bJButton.setText( "B" );
      bJButton.setBounds( 90, 20, 42, 42 );
      selectionJPanel.add( bJButton );
            
      // set up oneJButton
      oneJButton = new JButton();
      oneJButton.setText( "1" );
      oneJButton.setBounds( 12, 72, 42, 42 );
      selectionJPanel.add( oneJButton );
      
      // set up twoJButton
      twoJButton = new JButton();
      twoJButton.setText( "2" );
      twoJButton.setBounds( 64, 72, 42, 42 );
      selectionJPanel.add( twoJButton );
      
      // set up threeJButton
      threeJButton = new JButton();
      threeJButton.setText( "3" );
      threeJButton.setBounds( 116, 72, 42, 42 );
      selectionJPanel.add( threeJButton );
            
      // set properties of application's window
      setTitle( "VendingMachine" ); // set title bar text
      setSize( 395, 255 );          // set window size
      setVisible( true );           // display window

   } // end method createUserInterface
   
   // main method
   public static void main( String[] args ) 
   {
      VendingMachine application = new VendingMachine();
      application.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );

   } // end method main
   
} // end class VendingMachine


 /**************************************************************************
  * (C) Copyright 1992-2004 by Deitel & Associates, Inc. and               *
  * Pearson Education, Inc. All Rights Reserved.                           *
  *                                                                        *
  * DISCLAIMER: The authors and publisher of this book have used their     *
  * best efforts in preparing the book. These efforts include the          *
  * development, research, and testing of the theories and programs        *
  * to determine their effectiveness. The authors and publisher make       *
  * no warranty of any kind, expressed or implied, with regard to these    *
  * programs or to the documentation contained in these books. The authors *
  * and publisher shall not be liable in any event for incidental or       *
  * consequential damages in connection with, or arising out of, the       *
  * furnishing, performance, or use of these programs.                     *
  **************************************************************************/
