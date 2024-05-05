#include<bits/stdc++.h>
using namespace std;

struct Team {
    int pos;
    string name;
    bool visited;
};

struct TeamScore {
    string name;
    float score;
};


bool cmp(TeamScore a, TeamScore b){
    return a.score < b.score;
}

int main(){
    int n;
    cin>>n;
    vector<Team> teams(n);
    
    for(int i = 0; i < n; i++){
        string str;
        cin>>str;
        Team aux;
        aux.name = str;
        aux.pos = i + 1;
        aux.visited = false;
        teams[i] = aux;
    }
    
    vector<TeamScore> myTeams;
    for(int i = 0; i < n; i++){
        if(!teams[i].visited){
            float score_avg = 0;
            int count = 0;
            for(int j = 0; j < n; j++){
                if(!teams[j].visited && teams[j].name == teams[i].name){
                    count++;
                    score_avg += teams[j].pos;
                    teams[j].visited = true;
                }
            }
            TeamScore aux;
            aux.name = teams[i].name;
            aux.score = (score_avg / count);
            myTeams.push_back(aux);
        }
    }
    
    sort(myTeams.begin(), myTeams.end(), cmp);
    for(int i = 0; i < myTeams.size(); i++)
        cout<<myTeams[i].name<<endl;
    
    return 0;
}

