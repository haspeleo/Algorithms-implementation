/*
 *http://www.markuslanser.com/coding.html
 * */


import java.io.IOException;

/**
 * Tic Tac Toe
 *
 * Start-class.
 * @author Markus Lanser
 * Date: 18.11.2003
 */
public class Start {
    /**
     * to start the game
     *
     * @param args
     */
    public static void main(String[] args) throws IOException {
        int ki = 0;
        int size = 0;
        int anfaenger;
        System.out.println("Tic Tac Toe   v1.01");
        size = Utils.einlesenInt("Enter size of gamefield: ");

        /* Eingeben der Suchtiefe */
        ki = Utils.einlesenInt("KI difficulty level (1 to " + size * size + "): ");
        while (ki > size * size || ki < 1) {
            System.out.println("Wrong Input!");
            ki = Utils.einlesenInt("KI (1 to " + size * size + "): ");
        }

        /* Eingeben, wer anfangen soll */
        anfaenger = Utils.einlesenInt("Who starts (Press 1 for Player, 2 for Computer)? ");
        while (anfaenger > 2 || anfaenger < 1) {
            System.out.println("Wrong Input!");
            anfaenger = Utils.einlesenInt("Who starts (Press 1 for Player, 2 for Computer? ");
        }

        TicTacToe Spiel = new TicTacToe(size, anfaenger, ki);
        Spiel.run();

    }

}
