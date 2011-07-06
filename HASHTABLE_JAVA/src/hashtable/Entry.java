
package hashtable;

public class Entry {

    private int key;
    private Object value;

    public Entry(int key, Object value) {
        this.key = key;
        this.value = value;
    }
    //getters
    public int getKey() {
        return key;
    }
    public Object getValue() {
        return value;
    }
    //setters
    public void setValue(Object value) {
        this.value = value;
    }
}
