/**
 * Tic Tac Toe
 *
 * Class to calculate the computer-turn.
 * @author Markus Lanser
 * Date: 01.12.2003
 */
public class KI {

    /**
     * Method to start the computer-turn.
     * @param gamefield
     * @param ki
     */
    public static void makeTurn(int[][] gamefield, int ki, int gamesize) {
        int freieFelder = 0;

        /** find out, how much fields exist. By now there are this many possibilities */
        for (int i = 0; i < gamesize; i++) {
            for (int j = 0; j < gamesize; j++) {
                if (gamefield[i][j] == 0) {
                    freieFelder++;
                }
            }
        }

        int turn1[] = miniMax(gamefield, ki, TicTacToe.getPlayer(), freieFelder, gamesize);
        TicTacToe.setTurn(turn1[1], turn1[2]);
    }


    public static int[] miniMax(int[][] gamefield, int ki, int player, int freieFelder, int gamesize) {

        int[][] tempWert = new int[freieFelder][3];
        int[] minMaxWert = new int[3];
        int[] tempMinMaxWert = new int[2];

        if (ki-- == 0 || freieFelder == 0) {
            tempMinMaxWert[0] = bewertung(gamefield, gamesize);
            minMaxWert[0] = tempMinMaxWert[0];
            return minMaxWert;
        } else if (2 == Utils.won(gamefield, gamesize) || 1 == Utils.won(gamefield, gamesize) || 3 == Utils.won(gamefield, gamesize)) {
            tempMinMaxWert[0] = bewertung(gamefield, gamesize);
            minMaxWert[0] = tempMinMaxWert[0];
            return minMaxWert;
        } else {
            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }

            int index = 0;
            int[][][] next = new int[freieFelder][gamesize][gamesize];

            for (int i = 0; i < freieFelder; i++) {
                for (int x = 0; x < gamesize; x++) {
                    for (int y = 0; y < gamesize; y++) {
                        next[i][x][y] = gamefield[x][y];
                    }
                }
            }

            while (index < freieFelder) {
                for (int x = 0; x < gamesize; x++) {
                    for (int y = 0; y < gamesize; y++) {
                        if (index < freieFelder && next[index][x][y] == 0) {
                            if (player == 1) {
                                next[index][x][y] = 2;
                            } else {
                                next[index][x][y] = 1;
                            }
                            tempWert[index][2] = x;
                            tempWert[index][1] = y;
                            tempMinMaxWert = miniMax(next[index], ki, player, (freieFelder - 1), gamesize);
                            tempWert[index][0] = tempMinMaxWert[0];
                            index++;
                        }
                    }
                }
            }
            tempMinMaxWert[0] = 0;

            if (player == 1) {
                tempMinMaxWert[1] = tempWert[0][0];
                for (int i = tempMinMaxWert[0]; i < freieFelder; i++) {
                    if (tempMinMaxWert[1] < tempWert[i][0]) {
                        tempMinMaxWert[0] = i;
                        tempMinMaxWert[1] = tempWert[i][0];
                    }
                }
            } else {
                tempMinMaxWert[1] = tempWert[0][0];
                for (int i = tempMinMaxWert[0]; i < freieFelder; i++) {
                    if (tempMinMaxWert[1] > tempWert[i][0]) {
                        tempMinMaxWert[0] = i;
                        tempMinMaxWert[1] = tempWert[i][0];
                    }
                }
            }
            return tempWert[tempMinMaxWert[0]];
        }
    }


    /**
     * Method to show the actual gamefield.
     * @param gamefield
     */
    public static void print(int[][] gamefield, int gamesize) {
        String buffer = "";

        for (int i = 0; i < gamesize; i++) {
            for (int j = 0; j < gamesize; j++) {
                if (gamefield[i][j] == 0) {
                    buffer += "_ ";
                } else if (gamefield[i][j] == 1) {
                    buffer += "X ";
                } else if (gamefield[i][j] == 2) {
                    buffer += "O ";
                }
            }
            System.out.println(buffer);
            buffer = "";
        }
    }

    /**
     * Bewertungsmethode. Gives back, how good a certain turn would be.
     * @param next
     * @param gamesize
     * @return
     */
    public static int bewertung(int[][] next, int gamesize) {
        int min = 0;
        int max = 0;

        int[] check = new int[(2 * gamesize) + 2];

        int horizontal;
        int vertical;
        int diagonal1 = 0;
        int diagonal2 = 0;

        for (int i = 0; i < gamesize; i++) {

            horizontal = 0;
            vertical = 0;

            for (int j = 0; j < gamesize; j++) {
                if (next[i][j] == 1) {
                    horizontal--;
                } else if (next[i][j] == 2) {
                    horizontal++;
                }
                if (next[j][i] == 1) {
                    vertical--;
                } else if (next[j][i] == 2) {
                    vertical++;
                }
            }

            if (next[i][i] == 1) {
                diagonal1--;
            } else if (next[i][i] == 2) {
                diagonal1++;
            }

            if (next[(gamesize - 1) - i][i] == 1) {
                diagonal2--;
            } else if (next[(gamesize - 1) - i][i] == 2) {
                diagonal2++;
            }

            check[i] = horizontal;
            check[gamesize + i] = vertical;
        }

        check[(2 * gamesize)] = diagonal1;
        check[(2 * gamesize) + 1] = diagonal2;

        for (int i = 0; i < check.length; i++) {
            if (max < check[i])
                max = check[i];
            else if (min > check[i])
                min = check[i];
        }
        return min + max;
    }
}
