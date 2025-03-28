#include <bits/stdc++.h>

using namespace std;

int main()
{
    long double n;
    int c=0;

    cin>>n;

    //Resultado con logaritmo
    //Si es potencia exacta de 2 no se redondea con ceil
    /*if(pow(2,floor(log2(n))) == n)
        cout<<log2(n)+1<<endl;
    else cout<<ceil(log2(n))+1<<endl;*/
    while(n>1){
        //cout<<"n: "<<n<<endl;
        n=n/2;
        c++;
    }
    //cout<<"n: "<<n<<endl;
    cout<<c+1<<"\n";

    return 0;
}
