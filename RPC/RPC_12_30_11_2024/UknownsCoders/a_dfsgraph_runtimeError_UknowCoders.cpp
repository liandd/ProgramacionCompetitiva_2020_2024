#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int v2;
    
    vector<list<int>> adj;

    void DFSutil(int v,vector<bool> &visited){
       
       visited[v]=true;
       cout<<v<<"\n";

       for(int i:adj[v]){
         if(!visited[i]){
            DFSutil(i,visited);
         }
       }
    }

    public:
    Graph(int v2){
        this->v2=v2;
        adj.resize(v2);
    }

    void addEdge(int v,int w){
        adj[v].push_back(w);
    }

    void DFS(int v){
        vector<bool> visited(v2,false);
        DFSutil(v,visited);
    }
};

int main(){


    int num=0,num2=0,num3=0,num4=0;
    cin>>num>>num2;

    Graph g(num);

    if(num2==0){
        cout<<1<<"\n";
    }else{
    for(int i=0;i<num2;i=i+1){
        cin>>num3>>num4;
         g.addEdge(num3,num4);
    }

    /*g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(2,6);
    g.addEdge(3,7);
    g.addEdge(4,8);
    */
    
    g.DFS(num2);
    }
    /*
    8 8
    1 2
    2 3
    3 4
    1 4
    1 5
    2 6
    3 7
    4 8
    */
    return 0;
}

