#include<bits/stdc++.h>
using namespace std;

int oneDigit(unsigned long long num){
	return (num >= 0 && num < 10);
}

bool isPalUtil(unsigned long long num, unsigned long long* dupNum){
	if (oneDigit(num))
		return (num == (*dupNum) % 10);

	if (!isPalUtil(num/10, dupNum))
		return false;

	*dupNum /= 10;

	return (num % 10 == (*dupNum) % 10);
}

int isPal(unsigned long long num)
{
	if (num < 0)
	num = -num;

	unsigned long long *dupNum = new unsigned long long(num); 

	return isPalUtil(num, dupNum);
}

int solve(unsigned long long L, unsigned long long H){
    vector<unsigned long long> posible;
    for(unsigned long long i = L; i <= H; i++)
        if(isPal(i)) posible.push_back(i);
    
    vector<bool> prime(H + 1, true);
    
    for (unsigned long long p=2; p*p<=H; p++){
        if (prime[p] == true){
            for (unsigned long long i=p*2; i<=H; i += p)
                prime[i] = false;
        }
    }
    int salida = 0;  
    for(int i = 0; i < posible.size(); i++)
        if(prime[posible[i]])
            salida++;
    return salida;
}

int main(){
    unsigned long long L, H;
    cin>>L>>H;
	cout<<solve(L, H)<<'\n';
}

