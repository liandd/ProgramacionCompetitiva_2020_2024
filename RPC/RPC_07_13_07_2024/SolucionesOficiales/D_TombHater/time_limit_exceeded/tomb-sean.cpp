// not stepping on a tile more than once between words is a pain
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int MAX_VALUE;

struct Solution{
  int end_r;
  int end_c;
  bool left_open;
  bool right_open;
};


// tries to spell the word using backtracking
void Spell_Word(const vector<vector<char> >& Grid, const string& word, int r, int c, bool left_possible, bool right_possible, vector<Solution>& solution_list, int pos = 0){
  if(pos == word.size()){
    Solution new_solution;
    new_solution.end_r = r;
    new_solution.end_c = c;
    new_solution.left_open = left_possible;
    new_solution.right_open = right_possible;
    solution_list.push_back(new_solution);
    return;
  }
  
  // let's see if I can do this without making a copy of the grid
  // left
  if(left_possible && c > 0 && word[pos] == Grid[r][c-1]){
    Spell_Word(Grid, word, r, c-1, true, false, solution_list, pos+1);
  }
  // right
  if(right_possible && c < Grid[r].size()-1 && word[pos] == Grid[r][c+1]){
    Spell_Word(Grid, word, r, c+1, false, true, solution_list, pos+1);
  }
  // down
  if(r < Grid.size()-1 && word[pos] == Grid[r+1][c])
    Spell_Word(Grid, word, r+1,c, true, true, solution_list, pos+1);
}

  
int Solve(const vector<vector<char> >& Grid, const vector<string>& Dictionary, int r, int c, bool left_possible, bool right_possible){
  if(r == Grid.size()-1)
    return 0;
  int best = MAX_VALUE ;
  for(int i = 0; i < Dictionary.size(); i++){
    vector<Solution> word_choices;
   
    Spell_Word(Grid, Dictionary[i], r, c, left_possible, right_possible, word_choices, 0);

    for(int j = 0; j < word_choices.size(); j++){

      int cur = Dictionary[i].size() + Solve(Grid, Dictionary, word_choices[j].end_r, word_choices[j].end_c, word_choices[j].left_open, word_choices[j].right_open);
      if(cur < best)
	best = cur;
    }
  }
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
  vector<string> Dictionary(k);
  for(int i = 0; i < k; i++){
    cin >> Dictionary[i];
  }

  int best = MAX_VALUE;
  for(int i = 0; i < m; i++){
    int cur = Solve(Grid, Dictionary, 0, i, true, true);
    if(cur < best)
      best = cur;
  }
  if(best == n*m+1)
    cout << "impossible" << endl;
  else
    cout << best << endl;

  return 0;
}
