
// Problem: Rightsizing
// Solution Author: Coach Travis

// Include all the useful things
#include <bits/stdc++.h>

// Avoid using std in a lot of places
using namespace std;

// 64 bit ints
typedef long long int lli;

// The class of employee that will be sorted
class Employee 
{
    public:
        string name; // Name of employee
        lli salary;  // Salary of employee
                     
        // Constructor
        Employee(string name, lli salary) : name(name), salary(salary) {}
};

// Function to compare 2 employees for the priority queue
bool operator < (const Employee & a, const Employee & b) 
{
    // Check if there is a difference in salary
    if (a.salary != b.salary) 
    {
        // Sorty by the salary
        return a.salary < b.salary;
    }

    // Sort by the name as a tie break
    return a.name > b.name;
}

// The main function
int main()
{
    // Read in the employees and queries
    int n, m;
    cin >> n >> m;

    // Store employees by firability
    priority_queue<Employee> pq;
    
    // Store fired employees here
    set<string> fired;

    // Store a lookup table for name to salary
    map<string, lli> sal_map;

    // Read in the initial employees
    for (int i = 0; i < n; i++) 
    {
        string name;
        lli salary;
        cin >> name >> salary;
        sal_map[name] = salary;
        pq.push(Employee(name, salary));
    }

    // Handle all the queries
    for (int j = 0; j < m; j++) 
    {
        // Read the type of query
        int type;
        cin >> type;

        // Check the query type
        if (type == 2) 
        {
            // Fire query

            // Find the most firable (unfired) employee
            Employee e = pq.top();
            pq.pop();
            while (fired.count(e.name) || sal_map[e.name] != e.salary) 
            {
                assert(pq.size());
                e = pq.top();
                pq.pop();
            }

            // Fire the employee
            fired.insert(e.name);

            // Print the employee that was fired
            cout << e.name << " " << e.salary << endl;
        } 
        else 
        {
            // Raise query
            string name;
            lli amt;

            // Read in the query information
            cin >> name >> amt;

            // Adjust the salary
            sal_map[name] += amt;

            // Put the employee into the priority queue
            pq.push(Employee(name, sal_map[name]));
        }
    }

    // Exit the program
    return 0;
}
