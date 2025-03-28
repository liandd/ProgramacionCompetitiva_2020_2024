// Arup Guha
// 8/19/2024
// Alternate Solution for 2024 UCF Locals Problem: Christmas Tree Adapter

using namespace std;
#include <iostream>

int main() {

    // Read in info.
    int amp, watt, volt;
    cin >> amp >> watt >> volt;

    // This is what we have to check.
    if (amp*volt <= watt)
        cout << "1" << endl;
    else
        cout << "0" << endl;

    return 0;
}
