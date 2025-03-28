#include<iostream>
#include<sstream>
using namespace std;

const bool CHECKALL = true;

bool ok(string, string, string, string);

int main()
{
    string val1, op, val2, val3, equals;

    cin >> val1 >> op >> val2 >> equals >> val3;

    for(int i1=1; i1<val1.length(); i1++) {
        string val1a = val1.substr(0,i1);
        string val1b = val1.substr(i1);
        for(int i2=1; i2<val2.length(); i2++) {
            string val2a = val2.substr(0,i2);
            string val2b = val2.substr(i2);
            if (ok(val2a+val1b, val1a+val2b, val3, op)) {
                cout << val2a+val1b+" "+op+" "+val1a+val2b+" = " + val3 << endl;
                if (!CHECKALL) exit(0);
            }
        }
        for(int i3=1; i3<val3.length(); i3++) {
            string val3a = val3.substr(0,i3);
            string val3b = val3.substr(i3);
            if (ok(val3a+val1b, val2, val1a+val3b, op)) {
                cout << val3a+val1b+" "+op+" "+val2+" = " + val1a+val3b << endl;
                if (!CHECKALL) exit(0);
            }
        }
    }
    for(int i2=1; i2<val2.length(); i2++) {
        string val2a = val2.substr(0,i2);
        string val2b = val2.substr(i2);
        for(int i3=1; i3<val3.length(); i3++) {
            string val3a = val3.substr(0,i3);
            string val3b = val3.substr(i3);
            if (ok(val1, val3a+val2b, val2a+val3b, op)) {
                cout << val1+" "+op+" "+val3a+val2b+" = " + val2a+val3b << endl;
                if (!CHECKALL) exit(0);
            }
        }
    }
}

bool ok(string val1, string val2, string val3, string op)
{
    long v1, v2, v3;
    stringstream ss;
    ss << val1 << " " << val2 << " " << val3;
    ss >> v1 >> v2 >> v3;
    if (op == "+")
        return (v1+v2 == v3);
    else
        return (v1*v2 == v3);
}

