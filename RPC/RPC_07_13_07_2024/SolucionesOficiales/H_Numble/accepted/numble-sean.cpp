// cases for testing:
// 1) a word that (say, horizontally) intersects two different
// vertical words
// 2) a word that (say, horizontally) passes between two different numbers
//   above and below
// 3) A word that becomes legal or illegal because of a doubler or tripler space
// 4) A word that hits a triple word score horinzontally and vertically
// 5) the best score (illegally) doesn't intersect with any letters
// 6) A word that (say, horizontally) ends in 2 consecutive board letters
//    going in thew wrong direction
//Rule question: Do we triple the word score before seeing if it's divisible
// by 3?  (If so, all words that hit one are legal)
// Rule question: Do we want to allow turning 1234 into 12345?
// Clarification: We need to promise final score fits into an int


// for each square on the board
// for each of the 2^t possible (horizntal, increasing) tile placements
// try to place that set of numbers in that square (you need to scan left
// first through potential existing numbers to get the start of the sequence)
// If the sequence you are building is not increasing all the way across,
// return -1.  If the sequence you are building runs out of room,
// return -1.  If you get to the end and don't have a total %3 = 0, return -1
// Otherwise, build the score of the number across along with the vertical
//things you touch along the way, and return that total.

#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

int ctoi(char c){
  return c-'0';
}


vector<char> Get_Subset_Number(vector<char> v, int k){
  vector<char> result;
  int pos = 0;
  while(k > 0){
    if(k % 2 == 1)
      result.push_back(v[pos]);
    pos++;
    k = k/2;
  }
  /*  
  for(int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
  cout << endl;
  */
  return result;
}

// returns true if v is in order up or down, false otherwise
bool Sequential(const vector<char>& v){
  if(v.size() <= 1)
    return true;
  bool increasing = true;
  bool decreasing = true;
  for(int i = 1; i < v.size(); i++){
    if(v[i] > v[i-1]){
      if(!increasing)
	return false;
      decreasing = false;
    }
    if(v[i] < v[i-1]){
      if(!decreasing)
	return false;
      increasing = false;
    }
  }
  return (increasing || decreasing);
}

// returns the score of the vertical line through Board[r][c], -1 if it's
// illegal
int Check_Horizontal(const vector<vector<char> >& Board, char digit, int r, int c){
  vector<char> sequence;
  int cur_c = c-1;

  while(cur_c >= 0 && isdigit(Board[r][cur_c]))
    cur_c--;
  cur_c++;
  while(cur_c < c){
    if(isdigit(Board[r][cur_c])){
      sequence.push_back(Board[r][cur_c]);
      cur_c++;
    }
  }
  sequence.push_back(digit);
  cur_c++;
  while(cur_c < Board[r].size() && isdigit(Board[r][cur_c])){
    sequence.push_back(Board[r][cur_c]);
    cur_c++;
  }
  if(!Sequential(sequence))
    return -1;
  if(sequence.size() == 1)
    return 0;
  int total = 0;
  for(int i = 0; i < sequence.size(); i++){
    total = total + ctoi(sequence[i]);
    
  }
  if(Board[r][c] == 'd')
    total = total + ctoi(digit);
  if(Board[r][c] == 't')
      total = total + 2*ctoi(digit);
 
 
  if(Board[r][c] == 'D')
    total = total * 2;
  if(Board[r][c] == 'T')
    total = total * 3;
  if(total % 3 != 0) 
   return -1;
  else
    return total;
}


// Builds a horizontal number begining at Board[r][c], going left to right
// Board[r][c] is not a number, but we need to check to the left anyway
int Build_Number_Vertical(const vector<vector<char> >& Board,
				       vector<char>& Hand, int r, int c, bool increasing){
  int x = 1;
  // set r to the leftmost digit before the start if there are digits
  // before the start
  while(r > 0 && isdigit(Board[r-1][c])){
      r--;
    }
  bool used_board = false;
  int word_total = 0;
  int pos = 0;
  char last_number = '0';
  if(!increasing)
    last_number = ':';
  int factor = 1;
  int additional_score = 0;
  while(r < Board.size() && pos < Hand.size()){
      if(isdigit(Board[r][c])){
	used_board = true;
	if((increasing && Board[r][c] < last_number) || (!increasing && Board[r][c] > last_number))
	  return -1;
	else{
	  
	  last_number = Board[r][c];
	  word_total = word_total + ctoi(Board[r][c]);
	}
      }
      else{ // we'll be placing the next hand number
	if((increasing && Hand[pos] < last_number) || (!increasing && Hand[pos] > last_number))
	  return -1;
	else{
	  last_number = Hand[pos];
	  int vertical_score = Check_Horizontal(Board, Hand[pos], r, c);
	  if(vertical_score == -1)
	    return -1;
	  else{
	    if(vertical_score > 0)
	      used_board = true;
	    additional_score = additional_score + vertical_score;
	    if(Board[r][c] == 'd')
	      word_total = word_total + 2*ctoi(Hand[pos]);
	    else if(Board[r][c] == 't')
	      word_total = word_total + 3*ctoi(Hand[pos]);
	    else{
	      word_total = word_total + ctoi(Hand[pos]);
	      if(Board[r][c] == 'D')
		factor = factor * 2;
	      if(Board[r][c] == 'T')
		factor = factor * 3;
	    }
	  }
	  pos++;
	}
      }
      r++;
    }
    if(pos < Hand.size()) // couldn't fit the word
       return -1;
    // add in any extra numbers to the right of our finished word
    while(r < Board.size() && isdigit(Board[r][c])){
      used_board = true;
      if((increasing && Board[r][c] < last_number) || (!increasing && Board[r][c] > last_number))
	return -1;
      else{
	last_number = Board[r][c];
	word_total = word_total + ctoi(Board[r][c]);
      }
      r++;
    }
    if(word_total == ctoi(Hand[0])) // we made a word of just 1 letter
       return -1;
    word_total = word_total * factor;
    if(word_total % 3 != 0)
      return -1;
    if(!used_board)
      return -1;
    int total_score = word_total+ additional_score;
    return total_score;
  
}

void Sort(vector<char>& v){
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v.size()-1; j++){
      if(v[j] > v[j+1]){
	char temp = v[j];
	v[j] = v[j+1];
	v[j+1] = temp;
      }
    }
  }
}

void Print_Rack(const vector<char>& v){
  for(int i = 0; i < v.size(); i++)
    cout << v[i];
  cout << endl;
}

int main(){
  int r, c;
  cin >> r >> c;
  vector<vector<char> > Board(r);
  vector<vector<char> > Transpose(c);
  for(int i = 0; i < r; i++)
    Board[i].resize(c);
  for(int i  = 0; i < c; i++)
    Transpose[i].resize(r);
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++){
      cin >> Board[i][j];
      Transpose[j][i] = Board[i][j];
    }
  int t;
  cin >> t;
  vector<char> Hand(t);
 
  for(int i = 0; i < t; i++){
    cin >> Hand[i];
   
  }
  
   vector<char> Reverse_Hand(t);
   Sort(Hand);
   for(int i = 0; i < Hand.size(); i++){
     Reverse_Hand[t-i-1] = Hand[i];
   }

  int best_score = 0;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(!isdigit(Board[i][j])){
	  for(int k = 1; k < pow(2, t); k++){
	    vector<char> My_Numbers = Get_Subset_Number(Hand, k);
	    
	    int score = Build_Number_Vertical(Board, My_Numbers, i, j, true);
	    if(score > best_score){
	      // cout << "Vertical increasing at " << i << " " << j << ": " << score  << endl;
	      //	Print_Rack(My_Numbers);
	      best_score = score;
	    }
	    // horizontal is vertical on the transpose
	    score = Build_Number_Vertical(Transpose, My_Numbers, j, i, true);
	    if(score > best_score){
	      //  cout << "Horizontal Increasing at " << i << " " << j << ": " <<  score << endl;
	      // 	Print_Rack(My_Numbers);
	      best_score = score;
	    }
	    
	    My_Numbers = Get_Subset_Number(Reverse_Hand, k);
	    score = Build_Number_Vertical(Board, My_Numbers, i, j, false);
	    if(score > best_score){
	      //  cout << "Vertical decreasing at " << i << " " << j << ": " << score << endl;
	      //  Print_Rack(My_Numbers);
		
	      best_score = score;
	    }
	    
	    score = Build_Number_Vertical(Transpose, My_Numbers, j, i, false);
	    if(score > best_score){
	      best_score = score;
	      //   cout << "Horizontal decreasing at " << i << " " << j << ": " << score << endl;
	      //   Print_Rack(My_Numbers);
	    }
	  }
      }
      
    }
  }
  
    
  cout << best_score << endl;
}
