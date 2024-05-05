#include<bits/stdc++.h>
using namespace std;
string dexor(const string& num1, const string& num2) {
    int digitos = max(num1.length(), num2.length());
    string paddedNum1 = string(digitos - num1.length(), '0') + num1;
    string paddedNum2 = string(digitos - num2.length(), '0') + num2;
    string result;
    for (int i = digitos - 1; i >= 0; i--) {
        int digit1 = paddedNum1[i] - '0';
        int digit2 = paddedNum2[i] - '0';
        if ((digit1 <= 2 && digit2 <= 2) || (digit1 >= 7 && digit2 >= 7)) {
            result = '0' + result;
        } else {
            result = '9' + result;
        }
    }
    return result;
}
int main() {
    string num1, num2;
    cin >> num1 >> num2;
    string ans = dexor(num1, num2);
    cout << ans << endl;
    return 0;
}
