#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Max(const vector<int>& v){
  int max_pos = 0;
  int max_val = v[0];
  for(int i = 1; i < v.size(); i++)
    if(v[i] > max_val){
      max_pos = i;
      max_val = v[i];
    }
  return max_pos;
}

char Letter_Of(int n){
  if(n == 0)
    return 'A';
  if(n == 1)
    return 'T';
  if(n == 2)
    return 'G';
  if(n == 3)
    return 'C';
  return '!'; // uh-oh
}

void Print_Counts(const vector<vector<int> >& v){
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[i].size(); j++)
      cout << v[i][j] << " ";
    cout << endl;
  }
}

int main(){

  string s;
  cin >> s;
  vector<vector<int> > counts(4); // ATGC
  for(int i = 0; i < 4; i++){
    counts[i].resize(s.size()+1, 0);
  }

 
  
  for(int i = 0; i < s.size(); i++){
    for(int j = 0; j < 4; j++){
      counts[j][i+1] = counts[j][i];
    }
    if(s[i] == 'A')
      counts[0][i+1]++;
    if(s[i] == 'T')
      counts[1][i+1]++;
    if(s[i] == 'G')
      counts[2][i+1]++;
    if(s[i] == 'C')
      counts[3][i+1]++;
    
  }
  //Print_Counts(counts);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int s, e;
    cin >> s >> e;
  
    vector<int> substring_counts(4);
    for(int j = 0; j < 4; j++)
      substring_counts[j] = counts[j][e] - counts[j][s-1];

    for(int j = 0; j < 4; j++){
      int pos = Max(substring_counts);
      cout << Letter_Of(pos);
      substring_counts[pos] = -1;
    }
    cout << endl;
  }
}
 
    
