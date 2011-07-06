
package hashtable;


public class Bucket {
    private Entry slot;
    private boolean free = true;

    public Bucket(Entry e) {
        this.slot = e;
        this.free = false;
    }
    public void clean() { //mark bucket as free
        slot.setValue(null);
        free = true;
    }
    //getters
    public int getKey() {
        return slot.getKey();
    }
    public Object getValue() {
        return slot.getValue();
    }
    public boolean isFree() {
        return free;
    }
    //setters
    public void setValue(Object value) {
        slot.setValue(value);
        free = false;
    }


}
