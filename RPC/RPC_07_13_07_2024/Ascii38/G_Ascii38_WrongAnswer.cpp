#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string operacion;
  getline(cin, operacion);
  string x, y, z, op, eq;
  stringstream ss(operacion);
  ss >> x >> op >> y >> eq >> z;
  string conector = "", aux = "";

  if (op == "+") {
    // Cuando x + y es mayor que z intercambiando 2
    if (stoi(x) + stoi(y) > stoi(z)) {
      conector = x.substr(0, 2);
      conector += z;
      aux = x.substr(2, x.size() - 2);
      if (stoi(aux) + stoi(y) == stoi(conector))
        cout << conector << " + " << y << " = " << aux << "\n";
      // Cuando x + y es mayor que z intercambiando 3
      else {
        conector = "";
        conector = x.substr(0, 3);
        conector += z;
        aux = x.substr(3, x.size() - 3);
        if (stoi(conector) + stoi(y) == stoi(z))
          cout << conector << " + " << y << " = " << aux << "\n";
      }
    } else {
      conector = z.substr(0, 2);
      conector += x;
      aux = z.substr(2, z.size() - 2);
      if (stoi(conector) + stoi(y) == stoi(aux))
        cout << conector << " + " << y << " = " << aux << "\n";
      else {
        conector = "";
        conector = z.substr(0, 3);
        conector += x;
        aux = z.substr(3, z.size() - 3);
        if (stoi(conector) + stoi(y) == stoi(z))
          cout << conector << " + " << y << " = " << aux << "\n";
      }
    }
    // multiplicacion
  } else {
    // Cuando x * y es mayor que z intercambiando 2
    if (stoi(x) * stoi(y) > stoi(z)) {
      conector = x.substr(0, 2);
      conector += y;
      aux = x.substr(2, x.size() - 2);
      if (stoi(aux) + stoi(conector) == stoi(z))
        cout << aux << " * " << conector << " = " << z << "\n";
      // Cuando x + y es mayor que z intercambiando 3
      else {
        conector = "";
        conector = x.substr(0, 3);
        conector += y;
        aux = x.substr(3, x.size() - 3);
        if (stoi(aux) + stoi(conector) == stoi(z))
          cout << aux << " * " << conector << " = " << z << "\n";
      }
    } else {
      conector = y.substr(0, 2);
      conector += x;
      aux = y.substr(2, y.size() - 2);
      if (stoi(conector) + stoi(aux) == stoi(z))
        cout << conector << " * " << aux << " = " << z << "\n";
      else {
        conector = "";
        conector = y.substr(0, 3);
        conector += x;
        aux = y.substr(3, y.size() - 3);
        if (stoi(conector) + stoi(aux) == stoi(y))
          cout << conector << " * " << aux << " = " << y << "\n";
      }
    }
  }
  return 0;
}
