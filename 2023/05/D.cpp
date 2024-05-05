#include <iostream>
#include <string>

using namespace std;

bool isDickensian(const string& word) {
    bool leftHand = false, rightHand = false;
    
    for (char c : word) {
        bool inLeftHand = string("qwertasdfgzxcvb").find(c) != string::npos;
        bool inRightHand = string("yuiophjklnm").find(c) != string::npos;
        
        if (!inLeftHand && !inRightHand) {
            return false;
        }
        
        if (inLeftHand && leftHand || inRightHand && rightHand) {
            return false;
        }
        
        leftHand = inLeftHand;
        rightHand = inRightHand;
    }
    
    return true;
}

int main() {
    string word;
    cin >> word;
    if (isDickensian(word)) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
    return 0;
}

