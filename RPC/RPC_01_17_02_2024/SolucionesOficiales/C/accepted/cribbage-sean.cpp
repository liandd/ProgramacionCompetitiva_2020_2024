#include <iostream>
#include <vector>

using namespace std;


long long Pair_Score(const vector<int>& counts){
  long long score = 0;
  for(int i = 0; i < counts.size(); i++){
    // compute counts[1] choose 2
    int num_pairs = (counts[i] * (counts[i]-1)) / 2;
    score += num_pairs*2;
  }
  return score;
}


// adds the scores of different runs.  Each run can be made in a
// number of ways counted by
// the product of the counts of the ranks inside.
// Each run scores the # of ways it can be done * its length 
long long Run_Score(const vector<int>& counts){
  long long score = 0;
  int run_start = 0;
  while(run_start < 12){ // highest run is J
    while(run_start < counts.size() && counts[run_start] == 0)
      run_start++;
    if(run_start < 12){
      int run_end = run_start+1;
      while(run_end < counts.size() && counts[run_end] != 0)
	run_end++;
    
      if(run_end-run_start >= 3){ // we have a run of at least 3
	run_end--; // go back from the 0 we ended at
	long long num_ways = 1;
	for(int i = run_start; i <= run_end; i++){
	  num_ways = num_ways * counts[i];
	}
	score += num_ways * (run_end-run_start+1);
	
      }
      // set up for the next (disjoint) run
      run_start = run_end+1;
    }
  }
  return score;
}

long long Choose(int n, int r){
  if(r > n)
    return 0;
  long long result = 1;
  int num = n;
  int den = 1;
  while(den <= r){
    result = (result * num)/den;
    num--;
    den++;
  }
  return result;
}

long long Fifteen_Score(const vector<int>& counts, int remaining, int pos){
  long long total = 0;
  if(pos > 10)
    return 0;
  if(counts[pos] == 0)
    return Fifteen_Score(counts, remaining, pos+1);
  
  // how many ways can counts[pos] make 15 by itself?
  if(remaining%pos == 0 && counts[pos] >= (remaining / pos))
    total += Choose(counts[pos], remaining/pos);

  // for each subset of counts[pos], deduct that many from remaining,
  // figure out how many ways we can do it, and recursively try to get the rest
  for(int i = 0; i <= counts[pos]; i++){
    int r = remaining - pos*i;
    if(r > 0){
      long long cur = Choose(counts[pos], i) * Fifteen_Score(counts, r, pos+1);
      total = total + cur;
    }
  }
  return total;
}

int Number_Of(char card){
  if(card == 'A')
    return 1;
  if(card == 'T')
    return 10;
  if(card == 'J')
    return 11;
  if(card == 'Q')
    return 12;
  if(card == 'K')
    return 13;
  // else, it's a number
  return card - '0';
}

int main(){
  int n;
  cin >> n;
  vector<int> counts(14,0); // counts[0] is empty for my sanity,
                            // counts[1] is # of aces
                            // counts[11] is jacks, and so on
  for(int i = 0; i < n; i++){
    char card;
    cin >> card;
    counts[Number_Of(card)]++;
  }

  long long total = 0;
  long long p = Pair_Score(counts);
//  cout << "Pair score: " << p << endl;
  long long r = Run_Score(counts);
//   cout << "Run score: " << r << endl;

  // they all count for 10, this is easier
  counts[10] = counts[10] + counts[11] + counts[12] + counts[13];
  counts[11] = counts[12] = counts[13] = 0;

  long long f = Fifteen_Score(counts, 15, 1)*2;
//   cout << "Fifteen Score: " << f << endl;
  total = p+r+f;
  cout << total << endl;

  return 0;
}
    
