

// Hash Map unordered_map map HashMap
import java.io.*;
import java.util.*;
public class MyClass {
    public static void main(String args[]) {
        HashMap<Integer, Integer> hmap = new HashMap<>();
        for(int i = 0; i < 10; ++ i) {
            hmap.put(i, i + 100);
        }
        //way to get a value if corresponding key is present or return default value if not present
        // (key, default value)
        //hmap.getOrDefault("b", 500);
        if(hmap.containsKey(1)) {
            int ans = hmap.get(1);
            System.out.println("It is here = " + ans);
        }
        hmap.remove(1);
        for(Map.Entry<Integer, Integer> e : hmap.entrySet()) {
            System.out.println(e.getKey() + "   " + e.getValue());
        }
        System.out.println(hmap.size());
    }
}

// Map TreeMap
import java.io.*;
import java.util.*;
public class MyClass {
    public static void main(String args[]) {
        TreeMap<Integer, Integer> tmap = new TreeMap<>();
        for(int i = 0; i < 10; ++ i) {
            tmap.put(i, i + 1); // inser key, value
        }
        if(tmap.containsKey(2)) { // check if key exists
            System.out.println(tmap.get(2)); // get value corrseponding to the key
        }
        if(tmap.containsValue(3)) { // check if value exists
            System.out.println("It contains 2");
        }
        tmap.remove(0); // remove key, value pair
        for(Map.Entry<Integer, Integer> e : tmap.entrySet()) { // iterate through the map
            System.out.println(e.getKey() + "   " + e.getValue());
        }
        try {
            int a = tmap.lowerKey(2); // returns the greatest key strictly less than to given key, passed as the parameter. 
            int b = tmap.ceilingKey(2); // returns the least key greater than or equal to the given key or null if the such a key is absent.
            int c = tmap.higherKey(2);  // returns the least key strictly greater than the given key, or null if there is no such key.
            // in all you must catch the exception and deal with it appropriately 
            System.out.println("Found : " + a);
        } catch (Exception e) {
            System.out.println("Not present");
        }
        System.out.println(tmap.size());
        /*
        add firstKey() and lastKey()
        */
    }
}

// Pair, random arraylist sort
import java.io.*;
import java.util.*;
/*
https://www.infoworld.com/article/3323403/java-challengers-5-sorting-with-comparable-and-comparator-in-java.html
https://www.baeldung.com/java-generating-random-numbers-in-range
https://www.geeksforgeeks.org/comparable-vs-comparator-in-java/
*/
class Pair implements Comparable<Pair> {
    int a, b;
    Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
    public int compareTo(Pair other) {
        if(this.a == other.a) {
            return this.b - other.b;
        }
        return this.a - other.a;
    }
}
public class MyClass {
    static int randRange(int min, int max) {
        Random rand = new Random();
        return rand.nextInt(max - min) + min;
    }
    public static void main(String args[]) {
        List<Pair> lst = new ArrayList<>();
        for(int i = 0; i < 10; ++ i) {
            lst.add(new Pair(randRange(1, 5), randRange(101, 105)));
        }
        for(Pair p : lst) {
            System.out.println(p.a + "   " + p.b);
        }
        System.out.println("---Sorted----");
        Collections.sort(lst);
        for(Pair p : lst) {
            System.out.println(p.a + "   " + p.b);
        }
    }
}

// Queue 
import java.util.*;
import java.io.*;
public class MyClass {
    public static void main(String args[]) {
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < 10; ++ i) {
            q.offer(i);
        }
        System.out.println(q.peek());
        while(q.size() > 0) {
            System.out.println(q.poll());
        }
    }
}

// Stack
import java.util.*;
import java.io.*;
public class MyClass {
    public static void main(String args[]) {
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < 10; ++ i) {
            st.push(i);
        }
        System.out.println(st.peek());
        while(st.size() > 0) {
            System.out.println(st.pop());
        }
    }
}

// Priority Queue
import java.io.*;
import java.util.*;
/*
https://www.infoworld.com/article/3323403/java-challengers-5-sorting-with-comparable-and-comparator-in-java.html
https://www.baeldung.com/java-generating-random-numbers-in-range
https://www.geeksforgeeks.org/comparable-vs-comparator-in-java/
*/
class Pair implements Comparable<Pair> {
    int a, b;
    Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
    public int compareTo(Pair other) {
        if(this.a == other.a) {
            return this.b - other.b;
        }
        return other.a - this.a;
    }
}
public class MyClass {
    static int randRange(int min, int max) {
        Random rand = new Random();
        return rand.nextInt(max - min) + min;
    }
    public static void main(String args[]) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        for(int i = 0; i < 10; ++ i) {
            pq.offer(new Pair(randRange(1, 100), randRange(1, 100)));
        }
        System.out.println(pq.peek().a + "   " + pq.peek().b);
        while(pq.size() > 0) {
            Pair cur = pq.poll();
            System.out.println(cur.a + "   " + cur.b);
        }
    }
}


























































































































































