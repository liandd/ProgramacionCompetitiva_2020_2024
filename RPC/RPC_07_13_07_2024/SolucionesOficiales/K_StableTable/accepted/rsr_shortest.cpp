// Note to anyone foolish enough to read this: I am not a C++ programmer!
// This is a translation from a java program, made with the assistance of
// lots of Google searches about how to do things that are not the same
// in C++. Do not expect good style or efficiency or maybe even correctness.

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Edge {
  public:
     int from,to,cost;

     Edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

class Node {
  public:
     int id;
     vector<int> dist;
     vector<int> parent; //results of 3 searches
     vector<int> nbr;
     vector<int> rnbr; // reversed edges

     Node(int i = 0) : id(i), dist(3,INT_MAX/3), parent(3,-1) {}
};

class Comp0 {
public:
    bool operator() (Node n1, Node n2) {
      return n1.dist[0] > n2.dist[0];
    }
};

class Comp1 {
public:
    bool operator() (Node n1, Node n2) {
      return n1.dist[1] > n2.dist[1];
    }
};

class Comp2 {
public:
    bool operator() (Node n1, Node n2) {
      return n1.dist[2] > n2.dist[2];
    }
};

int w,h;
int maxV;
vector<Node> graph;
vector<int> top;
vector<bool> visited;
vector<int> numv;
int src, sink;
priority_queue<Node, vector<Node>,Comp0> pq0;
priority_queue<Node, vector<Node>,Comp1> pq1;
priority_queue<Node, vector<Node>,Comp2> pq2;

bool contains(vector<int> a, int x) {
  for (int i:a) {
    if (i==x) return true;
  }
  return false;
}

void dijk(int src, int start, int sink, int m) {
  visited[start] = true;
  Node s = graph[start];
  vector<int>nbr = s.nbr;
  if (m == 2) nbr = s.rnbr;
  for (int e: nbr) {
    if (visited[e]) continue; // already done
    Node *t = &(graph[e]);
    if (s.dist[m] + 1 < (*t).dist[m]) {
      (*t).dist[m] = s.dist[m] + 1;
      (*t).parent[m] = start;
      switch(m) {
        case 0: pq0.push(*t); break;
        case 1: pq1.push((*t)); break;
        case 2: pq2.push((*t)); break;
      }
    }
  }

  switch (m) {
    case 0: if (!pq0.empty()) {
                Node t = pq0.top(); pq0.pop();
                dijk(src,t.id,sink,m);
            } break;
    case 1: if (!pq1.empty()) {
                Node t = pq1.top(); pq1.pop();
                dijk(src,t.id,sink,m);
            } break;
    case 2: if (!pq2.empty()) {
                Node t = pq2.top(); pq2.pop();
                dijk(src,t.id,sink,m);
            } break;
    }
}

void reset() {
  for (int i = 0; i < maxV; i++) {
    visited[i] = false;
  }
}



int main() {
  cin >> h >> w;
  int table[h][w];
  maxV = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      // subtract 1 from all inputs to get zero-based:
      cin  >> table[i][j]; 
      table[i][j]--;
      maxV = max(maxV,table[i][j]+1);
     }
  }

  maxV += 2; // "+2" for source (graph[maxV-2]) and sink (graph[maxV-1])
  bool used[maxV]; // so we don't duplicate nodes
  fill_n(used,maxV,false);

  graph.resize(maxV);
  src = maxV-2;
  sink = maxV-1;
  graph[src] = Node(src);
  graph[sink] = Node(sink);

  // create the graph:
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int t = table[i][j];
      int below;
      if (i < h-1) {
        below = table[i+1][j];
      }
      else {
        below = sink; // goes to "sink" node
      }
      if (!used[t]) {
        graph[t] = Node(t);
        used[t] = true;
      }
      if (t != below && !contains(graph[t].nbr,below)) {
        graph[t].nbr.push_back(below);
        if (i < h-1 && !used[below]) {
          graph[below] = Node(below);
          used[below] = true;
        } 
        graph[below].rnbr.push_back(t);
      }
    }
  }

  // Point the source to the top table element(s):
  graph[src].nbr.push_back(table[0][0]);
  if (table[0][w-1] != table[0][0]) {
    graph[src].nbr.push_back(table[0][w-1]);
  }

  int numtop = graph[src].nbr.size();

  // Easy case: only one top piece
  if (numtop == 1) {
    // only one top piece, so find shortest path to sink:
    visited.resize(maxV);
    reset();
    graph[src].dist[0] = 0;
    dijk(src,src,sink,0);
    cout << graph[sink].dist[0]-1 << endl;
  } else {

  // Hard(er) case: two top pieces

    int t1 = graph[src].nbr[0];
    int t2 = graph[src].nbr[1];

    int best = INT_MAX/3;
    // Find shortest paths from t1 to all vertices:
    visited.resize(maxV);
    graph[t1].dist[0] = 0;
    dijk(t1,t1,sink,0);
    reset();
    graph[t2].dist[1] = 0;
    dijk(t2,t2,sink,1);
    reset();
    graph[sink].dist[2] = 0;
    dijk(sink,sink,src,2);
    
    best = graph[sink].dist[0]+graph[sink].dist[1];
    for (int i = 0; i < maxV; i++) {
       best = min(best, graph[i].dist[0]+graph[i].dist[1]+graph[i].dist[2]); 
    }
    cout << best << endl;
  }
}
