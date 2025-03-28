// not stepping on a tile more than once between words is a pain
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int MAX_VALUE;
const int MAX_SIZE = 101;

 short int Memo[MAX_SIZE][MAX_SIZE][2][2][MAX_SIZE][MAX_SIZE];



  
int Solve(const vector<vector<char> >& Grid, const vector<string>& Dictionary,
	  short int Memo[MAX_SIZE][MAX_SIZE][2][2][MAX_SIZE][MAX_SIZE], int r, int c, bool left_possible, bool right_possible, int word, int pos){

  if(pos == Dictionary[word].size() && r == Grid.size() -1)
    return 0;
  if(Memo[r][c][left_possible][right_possible][word][pos] != -1){
    return Memo[r][c][left_possible][right_possible][word][pos];
  }
  
  int best = MAX_VALUE ;

  if(pos == Dictionary[word].size()){ // start a new word
    for(int i = 0; i < Dictionary.size(); i++){
      // left
      int cur = MAX_VALUE;
      if(r >= 0 && left_possible && c > 0 && Dictionary[i][0] == Grid[r][c-1]){
        cur = 1+Solve(Grid, Dictionary, Memo, r, c-1, true, false, i, 1);
      }
      // right
      if(r >= 0 && right_possible && c < Grid[r].size()-1 && Dictionary[i][0] == Grid[r][c+1]){
	cur =  min(cur, 1+Solve(Grid, Dictionary, Memo, r, c+1, false, true, i, 1));
      }
      // down
      if(r < Grid.size()-1 && Dictionary[i][0] == Grid[r+1][c])
	cur = min(cur,1+ Solve(Grid, Dictionary, Memo, r+1, c, true, true, i, 1));
      best = min(best, cur);
    }
  }
  else{ // see if we can continue the current word
    int cur = MAX_VALUE;
    if(r >= 0 && left_possible && c > 0 && Dictionary[word][pos] == Grid[r][c-1])
      cur = 1+Solve(Grid, Dictionary, Memo, r, c-1, true, false, word, pos+1);
    if(r >= 0 && right_possible && c < Grid[r].size() && Dictionary[word][pos] == Grid[r][c+1])
      cur = min(cur, 1+Solve(Grid, Dictionary, Memo, r, c+1, false, true, word, pos+1));
    if(r < Grid.size()-1 && Dictionary[word][pos] == Grid[r+1][c])
      cur = min(cur, 1+Solve(Grid, Dictionary, Memo, r+1, c, true, true, word, pos+1));
    best = min(cur, best);
  }	       


  
  Memo[r][c][left_possible][right_possible][word][pos] = best;
  return best;
}

int main(){
  int n;
  int m;
  int k;
  cin >> n >> m >> k;
  MAX_VALUE = n*m+1;
 vector<vector<char> > Grid(n);
  for(int i = 0; i < n; i++){
    Grid[i].resize(m);
    for(int j = 0; j < m; j++){
      cin >> Grid[i][j];
    }
  }
  // r x c x left_possible x right_possible x word we're working on x pos in word
  // Yeah, I know, it's nuts.
  memset(Memo, -1, sizeof(Memo));
  vector<string> Dictionary(k);
  for(int i = 0; i < k; i++){
    cin >> Dictionary[i];
  }


 
  
  int best = MAX_VALUE;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < Dictionary.size(); j++){
      if(Dictionary[j][0] == Grid[0][i]){
	int cur = 1+Solve(Grid, Dictionary, Memo, 0, i, true, true, j, 1);
	if(cur < best)
	  best = cur;
      }
    }
  }
  if(best == n*m+1)
    cout << "impossible" << endl;
  else
    cout << best << endl;

  return 0;
}
