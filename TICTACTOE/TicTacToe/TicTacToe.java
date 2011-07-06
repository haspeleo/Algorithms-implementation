/**
 * Tic Tac Toe
 *
 * The most important class. the most important calculations are done here or.
 * delegated to other classes!
 * @author Markus Lanser
 * Date: 18.11.2003
 */

import java.io.*;

public class TicTacToe {

    public int gamesize = 0;            // size of gamefield
    public static int player = 0;       // who's turn is it?
    public int ki = 0;                  // depth of search
    public static int[][] gamefield;    // gamefield

    /**
     * Werte wurden von Start ubergeben.
     * @param gamesize - size of gamefield, which has
     *                   gamesize*gamesize fields.
     * @param anfaenger - 1 (Player) or 2 (Computer), who has the first turn.
     * @param ki - search depth for Computer.
     */
    public TicTacToe(int gamesize, int anfaenger, int ki) {
        this.gamesize = gamesize;
        this.player = anfaenger;
        this.ki = ki;
        this.gamefield = new int[this.gamesize][this.gamesize];

        /** gamefield is initialised with 0's */
        // TODO: automatically initialised with o's?
        for (int i = 0; i < gamesize; i++) {
            for (int j = 0; j < gamesize; j++) {
                gamefield[i][j] = 0;
            }
        }

    }


    /**
     * this should be clear
     * @return who's turn it is
     */
    public static int getPlayer() {
        return player;
    }


    /**
     * Start of the game. runs as long as somebody has won the game,
     * or no more turns are possible.
     * @throws IOException
     */
    public void run() throws IOException {
        while (0 == Utils.won(gamefield, gamesize)) {
            turn(player);
            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        }

        /** When we've been gone so far, the game must be over
	  * now comes the result. */
        if (Utils.won(gamefield, gamesize) == 1) {
            print(gamefield);
            System.out.println("You won!");
        } else if (Utils.won(gamefield, gamesize) == 2) {
            print(gamefield);
            System.out.println("You lost!");
        } else {
            print(gamefield);
            System.out.println("It's a Draw!");
        }
    }


    /**
     * Turn should be done. If player == 1 then Player 2 is the Computer.
     * @param player
     * @throws IOException
     */
    private void turn(int player) throws IOException {
        if (player == 1) {      /** if it is the player's turn... */
            print(gamefield);
            int eingabe;
            eingabe = Utils.einlesenInt("Make your turn (" + 1 + " to " + (gamesize * gamesize) + "): ");

            /** Checken, if Input has been done within the possible fields. */
            while (eingabe > gamesize * gamesize || eingabe < 1) {
                System.out.println("Wrong Input!");
                eingabe = Utils.einlesenInt("Make your turn (" + 1 + " to " + (gamesize * gamesize) + "): ");
            }

            boolean check2 = true;
            /** is the field empty? */
            for (int i = 0; i < gamesize; i++) {
                if (check2)
                    for (int j = 0; j < gamesize; j++) {
                        if (eingabe == 1) {
                            gamefield[i][j] = 1;
                            check2 = false;
                            break;
                        } else
                            eingabe--;
                    }
            }
        } else {                /** if it is the computer's turn... */
            KI.makeTurn(gamefield, ki, gamesize);
        }
    }


    /**
     * Method to do the turn. Vorher wird aber gepruft,
     * ob das Feld uberhaupt frei ist.
     * @param x - X-Koordinate
     * @param y - Y-Koordinate
     * @return true - wenn jemand gewonnen hat
     */
    public static boolean setTurn(int x, int y) {
        if (gamefield[y][x] == 0) {
            gamefield[y][x] = player;
            return true;
        }
        return false;
    }


    /**
     * Checkt, was fur eine Eingabe in dem ubergebenen Feld gemacht wurde
     * und liefert entweder X, O oder _ (leer) zuruck.
     * @param x
     * @return String
     */
    public String printFigure(int x) {
        if (x == 1)
            return "X";
        else if (x == 2)
            return "O";
        else
            return "_";
    }


    /**
     * Print-Methode zur Ausgabe des Feldes auf die Konsole.
     * -> greift auf printFigure zu
     */
    public void print(int gamefield[][]) {
        for (int i = 0; i < gamesize; i++) {
            for (int j = 0; j < gamesize; j++) {
                System.out.print(printFigure(gamefield[i][j]));
                System.out.print(" ");
            }
            System.out.println();
        }
    }

}
