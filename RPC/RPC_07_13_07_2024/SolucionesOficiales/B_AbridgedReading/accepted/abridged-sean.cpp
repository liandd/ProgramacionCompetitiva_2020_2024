#include <iostream>
#include <vector>

using namespace std;
int Get_Parent(const vector<vector<bool> >& Adj, int v){
	for(int i = 0; i < Adj.size(); i++)
	  if(Adj[v][i])
	    return i;
	return -1;
}

bool Find(const vector<int>& v, int key){
	for(int i = 0; i < v.size(); i++)
	  if(v[i] == key)
	    return true;
	return false;
}

int Find_Common_Ancestor(const vector<vector<bool> >& Adj, int v1, int v2){
	vector<int> Ancestor_List1;
	int p = v1;
	while(p != -1){
	  p = Get_Parent(Adj, p);
	  Ancestor_List1.push_back(p);
	}
	p = v2;
	while(p !=-1){
	  p = Get_Parent(Adj, p);
	  if(Find(Ancestor_List1, p))
	    return p;
	}
	return -1;
}

int Path_To_Start(const vector<vector<bool> >& Adj, const vector<int>& lengths,  int v){
	int total = 0;
	int p = v;
	while(p !=-1){

	  
	total = total + lengths[p];
	  p = Get_Parent(Adj, p);

	}
	return total;
}

int Path_To(const vector<vector<bool> >& Adj, const vector<int>& lengths, int source, int dest){
  int cur = source;
  int total = lengths[source];
  while(cur != dest){
    cur = Get_Parent(Adj, cur);
    if(cur != dest)
      total = total + lengths[cur];
  }
  return total;
}

		
		
int main(){
  int n,m;
  cin >> n >>m;
  vector<int> lengths(n+1);
  for(int i = 0; i < n; i++){
    cin >> lengths[i+1];
  }
  vector<vector<bool> > Adj(n+1);
  for(int i = 0; i < n+1; i++){
    Adj[i].resize(n+1, false);
  }
  vector<bool> CC(n+1, true);
  CC[0] = false;
  for(int i = 0; i< m; i++){
    int p, q;
    cin >> p >> q;
    Adj[q][p] = true;
    // do the other way?
    CC[p] = false;
  }
  int best = 100000000;
  for(int i = 0; i <=n; i++)
    for(int j = i+1; j <=n; j++)
      if(CC[i] && CC[j]){
	int ancestor = Find_Common_Ancestor(Adj, i, j);
	int total;
	if(ancestor == -1){ // no common ancestor
	  total = Path_To_Start(Adj, lengths, i) + Path_To_Start(Adj, lengths, j);
	}
	else{
	  total = Path_To_Start(Adj, lengths, ancestor) + Path_To(Adj, lengths, i, ancestor) + Path_To(Adj, lengths, j, ancestor);
	}
	if(total < best)
	  best = total;
      }
  
  cout << best << endl;
  return 0;
}

	
	
		
	
