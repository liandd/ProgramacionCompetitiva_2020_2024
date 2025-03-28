#include <bits/stdc++.h>
using namespace std;

int respuesta(int tam, string i)
{
    map <char, int> datos;
    datos['I'] = 1;
    datos['V'] = 5;
    datos['X'] = 10;
    datos['L'] = 50;
    datos['C'] = 100;
    datos['D'] = 500;
    datos['M'] = 1000;

    vector <pair<char,int>> vec2(tam);
    vector <int> nose;

    int sum=0;

    for(int j=1 ; j<=i.size(); j++)
    {

        if(i[j-1] == i[j])
        {
            sum += datos[i[j]];
        }
        else if(sum>0)
        {
            sum += datos[i[j-1]];

            vec2.push_back(make_pair(i[j-1],sum));
            nose.push_back(sum);
            sum=0;
        }
        else
        {
            vec2.push_back(make_pair(i[j-1],datos[i[j-1]]));
            nose.push_back(datos[i[j-1]]);
        }
    }



    int res=0;
    for(int i=1; i<=nose.size() ; i+=2)
    {

            res+=nose[i]-nose[i-1];

    }


    return res;
}


int main()
{

    int TAM;
    string cadena;


    cin >> TAM;

    vector <string> vec(TAM);


    for(int i= 0; i<TAM; i++)
    {
        cin >> cadena;
        cout<<respuesta(TAM,cadena)<<"\n";
        cadena="";
    }




    return 0;
}
