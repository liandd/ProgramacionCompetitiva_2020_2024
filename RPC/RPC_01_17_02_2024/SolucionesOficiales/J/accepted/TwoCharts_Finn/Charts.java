import java.io.*;
import java.util.*;

public class Charts {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       
        String line1 = br.readLine();
        char[] seq1 = line1.toCharArray();
        boolean isTrivial1 = true;
        for (char c: seq1) {
            if (c=='(') {
                isTrivial1 = false;
            }
        }
        HashMap<Integer, Integer> tree1 = getTree(seq1);
        

        String line2 = br.readLine();
        char[] seq2 = line2.toCharArray();
        boolean isTrivial2 = true;
        for (char c: seq2) {
            if (c=='(') {
                isTrivial2 = false;
            }
        }
        HashMap<Integer, Integer> tree2 = getTree(seq2);
        
        //printTree(tree1);
        //System.out.println();
        //printTree(tree2);
        
        boolean match = true;
        if (isTrivial1 && isTrivial2) {
            if (!line1.trim().equals(line2.trim())) {
                match = false;
            }
        }
        if (tree1.size() != tree2.size()) {
            //System.out.println("Trees have different sizes.");
            match = false;
        }
        for (int value: tree1.keySet()) {
            if (tree2.containsKey(value)) {
                if ((int)tree1.get(value) != (int)tree2.get(value)) {
                    //System.out.printf("%d has parent %d in tree 1 but parent %d in tree 2\n", value, tree1.get(value), tree2.get(value));
                    match = false;
                    break;
                }
            } else {
                match = false;
                //System.out.printf("%d found in tree 1 but not in tree 2\n", value);
                break;
            }
        }
        if (match) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static HashMap<Integer, Integer> getTree(char[] seq) {
        HashMap<Integer, Integer> parent = new HashMap<>();
        Stack<Integer> stk = new Stack<>();
        int value = 0;
        for (char c: seq) {
            if (Character.isDigit(c)) {
               value *= 10;
               value += c - '0';
            }
            if (c==' ') {
                continue;
            }
            if (c=='(') {
                if (value > 0) {
                    if (stk.size() > 0) {
                        parent.put(value, stk.peek());
                    }
                    stk.push(value);
                    value = 0;
                }
            } 
            if (c==')') {
                if (value > 0) {
                    if (stk.size() > 0) {
                        parent.put(value, stk.peek());
                    }
                    stk.push(value);
                    value = 0;
                }
                stk.pop();
            }
        }
        return parent;
    }
    public static void printTree(HashMap<Integer, Integer> tree) {
        ArrayList<Integer> values = new ArrayList<Integer>();
        for (int value: tree.keySet()) {
            values.add(value);
        }
        Collections.sort(values);
        for (int value: values) {
            System.out.printf("%d: %d\n", value, tree.get(value));
        }
    }
}
