// Arup Guha
// 8/10/2023
// Solution to 2023 UCF Local Qualifying Round Problem: Rightsizing

import java.util.*;

public class Rightsizing {

	public static void main(String[] args) {
		
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		int numE = stdin.nextInt();
		
		// Map will link name to accurate salary.
		HashMap<String,Long> map = new HashMap<String,Long>();
		
		// Fired will link name to if someone is fired or not.
		HashMap<String,Boolean> fired = new HashMap<String,Boolean>();
		
		// Priority Queue might have multiple copies of the same person, linked to
		// the different salaries they've had over the time of the simulation.
		PriorityQueue<person> pq = new PriorityQueue<person>();
		
		// Read the data, updating all three data structures.
		for (int i=0; i<n; i++) {
			String name = stdin.next();
			long sal = stdin.nextLong();
			map.put(name, sal);
			fired.put(name, false);
			pq.offer(new person(name, sal));
		}
		
		// Process actions.
		for (int i=0; i<numE; i++) {
			
			int id = stdin.nextInt();
			
			// Raise.
			if (id == 1) {
				String name = stdin.next();
				long newval = stdin.nextLong() + map.get(name);
				map.put(name, newval);
				pq.offer(new person(name, newval));
			}
			
			// Fire.
			else {
				
				// Here we keep going until we find someone in the priority queue that hasn't
				// been fired yet. Once we do, fire them!
				while (true) {
					person p = pq.poll();
					if (!fired.get(p.name)) {
						fired.put(p.name, true);
						System.out.println(p);
						break;
					}
				}
			}
		}
	}

}

// For sorting purposes.
class person implements Comparable<person> {

	public String name;
	public long salary;
	
	public person(String n, long s) {
		salary = s;
		name = n;
	}
	
	// Here is where the key logic is, go big to small on salary but alpha by name.
	public int compareTo(person other) {
		if (salary != other.salary)
			return Long.compare(other.salary, salary);
		return name.compareTo(other.name);
	}
	
	public String toString() {
		return name+" "+salary;
	}
}