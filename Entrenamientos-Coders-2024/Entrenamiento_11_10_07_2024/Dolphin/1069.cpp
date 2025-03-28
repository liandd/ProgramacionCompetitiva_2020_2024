#include <bits/stdc++.h>
using namespace std;
//1069
int main ()
{

  int n, con=0;
  string cad;

  cin >> n;
    cin.ignore();
  while (n--){
	  if(getline(cin,cad)){
      stack<char>op;
	  for (int i = 0; i < cad.size (); i++)
		{
		  if (cad[i] == '<')
			{
			  op.push (cad[i]);
			}
		  else if (cad[i] == '>')
			{
			  if (!op.empty())
				{
				  op.pop ();
				  con++;
				}

			}
		}
	  }
	  cout <<con << "\n";
	  con = 0;

	}

  return 0;
}
