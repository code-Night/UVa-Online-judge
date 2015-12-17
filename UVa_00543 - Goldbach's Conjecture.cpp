#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector <bool> isPrime ;
vector <long int> primes ;
void sieve (long long limit){
    isPrime.resize(limit);
    fill(isPrime.begin(),isPrime.end(),true);
    isPrime[0]=false ;
    isPrime[1]=false ;
    for(int i=0 ; i*i<limit ; i++){
        if(isPrime[i]){
            long long j = i*i ;
            while(j < limit){
                isPrime[j] = false ;
                j += i ;
            }
        }
    }
    for(int i=0 ; i<limit ; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }

}

int main()
{
    //freopen("input.txt","r",stdin) ;
    sieve(1000000);
    int x = -1;
    cin >> x ;
    while(x != 0){
        int i=0;
        int curr = primes[i];
        int a,b ;
        while(curr <= x){
            if(isPrime[x-curr]){
                a = curr ;
                b = x-curr ;
                break ;
            }else{
                curr = primes[++i] ;
            }
        }
        cout << x <<" = "<< a << " + " << b << endl;
        cin >> x ;
    }
    return 0;
}
