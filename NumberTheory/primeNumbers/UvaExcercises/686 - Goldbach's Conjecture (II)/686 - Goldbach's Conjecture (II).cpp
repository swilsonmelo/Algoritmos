#include <bits/stdc++.h>
#define Maxi (1<<15)+10

using namespace std;
typedef vector<int> vi;

int isPrime[Maxi];
vi primes;

void seive(){
    for(int i = 0; i < Maxi; i++)isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i < Maxi; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j = i*i; j < Maxi; j += i)isPrime[j] = 0;
        }
    }
    /*
    for(int i = 0; i < 11; i++)printf("%d ",primes[i]);
    puts(" ");
    */
}

int main(){
    seive();
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    while( n ){
        int numPair = 0;
        for(int i = 0; i < primes.size(); i++){
            int p = primes[i];
            if(p > n/2) break;
            if(isPrime[n-p]) numPair++;
        }
        printf("%d\n",numPair);
        scanf("%d",&n);
    }
    return 0;
}
