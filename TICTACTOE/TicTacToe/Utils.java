
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Tic Tac Toe
 *
 * Klasse fur Methoden, die von mehreren Klassen gebraucht wird.
 * Eigentlich nur wg. "one code one place".
 * @author Markus Lanser
 * Date: 18.11.2003
 */
public class Utils {

    /**
     * Liest eine Int von der Kommandozeile.
     * @return int
     * @throws java.io.IOException
     */
    public static int einlesenInt() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return Integer.parseInt(br.readLine());
    }


    /**
     * Liest eine Int von der Kommandozeile. Zusatzl. Feature: Mit Abfrage! Juhu!
     * @param s Frage
     * @return int
     * @throws java.io.IOException
     */
    public static int einlesenInt(String s) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print(s);
        return Integer.parseInt(br.readLine());
    }


    /**
     * Methode zum Nachprufen, ob es einen Gewinner gibt, bzw. ob das Spiel
     * unentschieden endet.
     * @param gamefield - das Spielfeld
     * @param gamesize - die SpielfeldgroBe
     * @return 1, wenn der Spieler won hat
     *         2, wenn der Computer won hat
     *         3, wenn es keinen Gewinner gibt
     */
    public static int won(int[][] gamefield, int gamesize) {

        int horizontal;
        int vertical;
        int diagonal1 = 0;
        int diagonal2 = 0;
        int empty = gamesize * gamesize;
        int winner = 0;

        for (int i = 0; i < gamesize; i++) {
            horizontal = 0;
            vertical = 0;

            for (int j = 0; j < gamesize; j++) {
                if (gamefield[i][j] == 1)
                    horizontal++;
                else if (gamefield[i][j] == 2)
                    horizontal--;
                if (gamefield[j][i] == 1)
                    vertical++;
                else if (gamefield[j][i] == 2)
                    vertical--;
                if (gamefield[i][j] != 0)
                    empty--;
            }
            if (gamefield[i][i] == 1)
                diagonal1++;
            else if (gamefield[i][i] == 2)
                diagonal1--;
            if (gamefield[(gamesize - 1) - i][i] == 1)
                diagonal2++;
            else if (gamefield[(gamesize - 1) - i][i] == 2)
                diagonal2--;

            if (horizontal == gamesize)
                return 1;
            else if (horizontal == (0 - gamesize))
                return 2;
            if (vertical == gamesize)
                return 1;
            else if (vertical == (0 - gamesize))
                return 2;
        }
        if (diagonal1 == gamesize)
            return 1;
        else if (diagonal1 == (0 - gamesize))
            return 2;
        if (diagonal2 == gamesize)
            return 1;
        else if (diagonal2 == (0 - gamesize))
            return 2;
        if (empty == 0)
            return 3;

        return winner;
    }
}
