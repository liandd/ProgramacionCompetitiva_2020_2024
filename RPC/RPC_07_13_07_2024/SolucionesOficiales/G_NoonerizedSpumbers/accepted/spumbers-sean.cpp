#include <iostream>
#include <string>

using namespace std;

bool Math_Works(string x, string y, string z, char sign){
  //cout << x << sign << y << "=" << z << endl;
  if(sign == '+'){
    if(stoll(x)+stoll(y) == stoll(z))
      return true;
    else
      return false;
  }
  else{
    if(stoll(x)*stoll(y) == stoll(z))
      return true;
    else
      return false;
  }
}

int main(){
  string x;
  char sign;
  string y;
  char equals;
  string z;
  cin >> x >> sign >> y >> equals >> z;

  // swap x and y
  for(int i = 1; i < x.size(); i++){
    string x_prefix = x.substr(0,i);
    string x_suffix = x.substr(i, x.size()-i);
    for(int j = 1; j < y.size(); j++){
      string y_prefix = y.substr(0, j);
      string y_suffix = y.substr(j, y.size() - j);
      string new_x = y_prefix + x_suffix;
      string new_y = x_prefix + y_suffix;
      if(Math_Works(new_x, new_y, z, sign)){
	cout << new_x << " " << sign << " " << new_y << " = " << z << endl;
	return 0;
      }
    }
  }

  // swap x and z
   for(int i = 1; i < x.size(); i++){
    string x_prefix = x.substr(0,i);
    string x_suffix = x.substr(i, x.size()-i);
    for(int j = 1; j < z.size(); j++){
      string z_prefix = z.substr(0, j);
      string z_suffix = z.substr(j, z.size() - j);
      string new_x = z_prefix + x_suffix;
      string new_z = x_prefix + z_suffix;
      if(Math_Works(new_x, y, new_z, sign)){
	cout << new_x << " " << sign << " " << y << " = " << new_z << endl;
	return 0;
      }
    }
  }

   // swap y and z
    for(int i = 1; i < y.size(); i++){
    string y_prefix = y.substr(0,i);
    string y_suffix = y.substr(i, y.size()-i);
    for(int j = 1; j < z.size(); j++){
      string z_prefix = z.substr(0, j);
      string z_suffix = z.substr(j, z.size() - j);
      string new_y = z_prefix + y_suffix;
      string new_z = y_prefix + z_suffix;
      if(Math_Works(x, new_y, new_z, sign)){
	cout << x << " " << sign << " " << new_y << " = " <<new_z << endl;
	return 0;
      }
    }
  }

    cout << "No equations work!" << endl;
    return 0;
}
