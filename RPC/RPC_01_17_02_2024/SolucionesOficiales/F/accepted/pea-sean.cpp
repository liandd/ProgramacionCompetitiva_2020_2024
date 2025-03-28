#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string Next_Pea(const string& cur){
  stringstream result;
  for(char i = '0'; i <= '9'; i++){
    int count = 0;
    for(int j = 0; j < cur.size(); j++){
      if(cur[j] == i)
	count++;
    }
    if(count > 0)
      result << count << i;
  }
  return result.str();
}

bool Find(const vector<string>& v, const string& key){
  for(int i = 0; i < v.size(); i++){
    if(v[i] == key)
      return true;
  }
  return false;
}


int main(){
  string n;
  string m;
  cin >> n >> m;
  vector<string> history;
  history.push_back(n);
  
  bool done = false;
  if(n == m){
    cout << 1 << endl;
    done = true;

  }
  while(!done){
    string next = Next_Pea(n);
    //cout << next << endl;
    if(next == m){
      cout << history.size()+1 << endl;
      done = true;
    }
    else if(Find(history, next)){
      cout << "Does not appear" << endl;
      done = true;
    }
    else{
      history.push_back(next);
      n = next;
      if(history.size() > 100){
	cout << "Does not appear" << endl;
	done = true;
      }
    }
  }
  return 0;
}

      
  
