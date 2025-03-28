#include<bits/stdc++.h>
using namespace std;

int main(){

    unsigned long long n=0, m=0, maxx=0, sum=0, maxim=0;
    cin>>n>>m;
    vector<pair<unsigned long long,unsigned long long>> ag(m);
    pair<unsigned long long,unsigned long long> ag2;

    vector<int> sizes(n);
    vector<int> sumas(n);

    for(int i=0; i<n; i++){
    cin>>sizes[i];

    }
    sort(sizes.begin(), sizes.end(), greater<int>());

/*
    for(int i=0; i<n; i++){

    cout<<sizes[i]<<"\n";

    }
*/
    if(n<=m){
        cout<<sizes[0];
    }else{

        for(int i=1; i<=n; i++){

    long long Pind = m-i;
    long long Sind = m-1+i;

    if(Pind >=0 && Pind <n && Sind>= 0 && Sind <n){


            ag2.first = sizes[m-i];
            ag2.second = sizes[m-1+i];
                //cout<<sizes[m-i]<<" "<<sizes[m-1+i]<<"\n";   se guardan biennnnnn :D7
            sum = ag2.first + ag2.second;
            sumas[i-1]=sum;

             ag.push_back(ag2);

        //    cout<<"primer elemento: "<<ag2.first<<" "<<"segundo elemento: "<<ag2.second<<"       sumas:" <<  sumas[i-1]<<"\n";
           // cout<<maxx;
            maxx=max(sumas[i-1], sizes[0]);

            if(maxx>=maxim){
                maxim=maxx;
            }



        }else{
            break;
        }

    }

    cout<<maxim;
    }
    return 0;
}

/*10 5
4 5 6 7 8 9 10 11 12 13

5 4
10 3 9 9 12
*/
