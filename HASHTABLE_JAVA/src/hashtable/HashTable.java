/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package hashtable;

import java.util.Random;

public class HashTable implements SymbolTable {

    // for hashing
        private int a, b;
	private int p;

    private Bucket [] bucketArray; //Array for key-value pairs
    private int nbrObject = 0;     //number of elements inserted
    private CollisionManagement manager; //collision manager

    public HashTable(int size) {
       // this(size, new LinearProbing()); //use linear probing by default
    }

    public HashTable(int size, CollisionManagement manager) {
        this.manager = manager;
        bucketArray = new Bucket[size];

        Random generator = new Random(); // Générateur de nombres aléatoires

        p = 1073676287; // Grand nombre premier

        a = (Math.abs(generator.nextInt()) % p) + 1;
        b = Math.abs(generator.nextInt()) % p;
    }


    public void put(int key, Object value) throws HashTableException {
        if(bucketArray.length == nbrObject)
        throw new HashTableException("Table is Full !.");
        int index = getBucketIndex(key);
        boolean inc = true;
        if(bucketArray[index] == null)
            bucketArray[index] = new Bucket(new Entry(key, value));
        else {
            inc = bucketArray[index].isFree();
            bucketArray[index].setValue(value);
        }
        if(inc)
            nbrObject ++;

    }

    public Object get(int key) throws HashTableException {
        if(nbrObject == 0)
        throw new HashTableException("Empty table ! ");

        Bucket bucket = bucketArray[getBucketIndex(key)];
        if(bucket != null && !bucket.isFree())
            return bucket.getValue();
        else
            throw new HashTableException("Key not found !");
    }

    
    public void remove(int key) throws HashTableException {
        if(nbrObject == 0)
        throw new HashTableException("Empty table nothing to remove !");

        Bucket delete = bucketArray[getBucketIndex(key)]; //slot to free

        if(delete == null || delete.isFree())
            throw new HashTableException("key to remove not found");
        delete.clean();
        nbrObject --;
    }

    public boolean contains(int key) {
        Bucket bucket = bucketArray[getBucketIndex(key)];
	return (bucket != null && !bucket.isFree());
    }

    public int size() {    
        return nbrObject;
    }

    /* add a hashing function */
    /**renvoie un entier qui peut servir d'indice pour le bucket array*/
    private int hash(String s) {
        int h = 0;
        return (Math.abs(h) % p) % bucketArray.length;
    }

    private int getBucketIndex(int key) {

        int h = hash(new Integer(key).toString());
        int index = h; //index for the key
     // for(int i = 0;  bucketArray[index] != null && bucketArray[index].getKey() ! = key; i++)
        for(int i = 0 ; bucketArray[index] != null && bucketArray[index].getKey() != key ; i++)
            index = manager.nextIndex(h, i) % bucketArray.length; //next slot
            return index;
       }    

}// HashTable
