package Advanced.Collections;

import java.util.Comparator;

public class emailComparator implements Comparator<customer> {
    @Override
    public int compare(customer one,customer other){
        return (one.getEmail()).compareTo(other.getEmail());
    }
}
