package Advanced.Generics;

public class UserComparable implements Comparable<UserComparable>{
    private int points;

    public UserComparable(int points){
        this.points = points;
    }

    //necessary implementation of methods in Comparable
    @Override
    public int compareTo(UserComparable o) {          //compares one user to another
        //this < o.points -> -1
        //this == o,.points -> 0
        //this > o.points -> 1
        System.out.println(this.points - o.points);
        return this.points - o.points;
    }
}
