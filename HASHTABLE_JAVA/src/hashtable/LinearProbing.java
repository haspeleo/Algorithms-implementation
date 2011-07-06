/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package hashtable;

/**
 *
 * @author doghmen
 */
public class LinearProbing implements CollisionManagement {

    public int nextIndex(int h, int i) {
        return h + i;
    }
   
}
