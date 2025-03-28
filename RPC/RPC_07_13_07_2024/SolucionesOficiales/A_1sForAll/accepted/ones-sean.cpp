#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int num_digits(int n){
  if(n >= 100000)
    return 6;
  if(n >= 10000)
    return 5;
  if(n >= 1000)
    return 4;
  if(n >= 100)
    return 3;
  if(n >= 10)
    return 2;
  return 1;
}

      
int Solve(int n, vector<int>& Memo){
  Memo[0] = 0;
  Memo[1] = 1;
  for(int pos = 2; pos <= n; pos++){
    //  if(pos == n)
    //  cout << "Hi" << endl;
   
    int best = n; // you can always add ones
    
    for(int i = 1; i < pos; i++){
      int cur = Memo[i] + Memo[pos-i];
      if(cur < best)
	best = cur;
    }
    
    
    // multiply
    for(int i = 2; i <= sqrt(pos); i++){
      int cur = Memo[pos/i] + Memo[i] +  Memo[pos-(i*(pos/i))];
	
      if(cur < best)
	best = cur;
      
    }
    
    // concatenate
    
    for(int i = 1; i <= num_digits(pos); i++){
     	int first = pos/pow(10,i);
	int rest = pos%(int)pow(10,i);
	if(rest != 0 && (num_digits(first) + num_digits(rest) == num_digits(pos))){
	  int cur = Memo[first] + Memo[rest];
	  if(cur < best)
	    best = cur;
	}
    }
    
    
    Memo[pos] = best;
  }
  return Memo[n];
}

  
int main(){
  int n;
  cin >> n;

  vector<int> Memo(n+1, -1);
  int result = Solve(n, Memo);

  cout << result << endl;
  return 0;
}
