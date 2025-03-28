
// Problem: Easy Problem
// Author:  Coach Travis

// Include the all goodies that c++ has to offer
#include <bits/stdc++.h>

// Use the standard namespace to prevent using std:: everywhere
using namespace std;

// The main function
int main() 
{
    // Create the variables for reading in the solves for the halfway and the
    // last hour
    int h2, h4;

    // Read the number of solves by each hour from standard input
    cin >> h2 >> h4;

    // Check if the problem was solved by at least half the contestents by the 
    // halfway point of the contest
    if (h2 * 2 >= h4) 
    {
        // Print that the problem was easy
        cout << "E" << endl;
    }
    else
    {
        // Print that the problem was hard
        cout << "H" << endl;
    }

    // Exit the program
    return 0;
}
