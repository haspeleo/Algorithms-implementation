/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package hashtable;

/**
 *
 * @author doghmen
 */
public interface SymbolTable {
    public void put(int key, Object value) throws HashTableException;
    public Object get(int key) throws HashTableException;
    public void remove(int key) throws HashTableException;
    public boolean contains(int key);
    public int size();

}
