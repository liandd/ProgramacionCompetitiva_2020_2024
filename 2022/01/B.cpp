#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    cin>>s;
    int q, k, salida;
    cin>>q;
    while(q--)
    {
        int cont=0;
        cin>>t;
        cin>>k;
        if (s.find(t)!= std::string::npos)
        {
            for (int i=0; i<s.size() && cont<=k; i++)
            {
                string aux="";
                if(s[i]==t[0])
                {
                    if(t.size()==1)
                    {
                        aux=t[0];
                    }
                    else
                    {
                        aux = s.substr(i,t.size());

                    }
                    if(aux==t)
                    {
                        cont++;
                    }
                    if (cont==k)
                    {
                        salida=i+1;
                        break;
                    }
                }

            }
            if(salida<k)
                cout<<"-1\n";
            else
                cout<<salida<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
    }


    return 0;
}
