#include <bits/stdc++.h>
#define MAXI 34000

using namespace std;
typedef long long ll;
typedef vector<int> vi;

vi primes;
int isPrime[MAXI];

void seive(){
    for(int i = 0; i < MAXI; i++)isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i < MAXI; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(ll j = i*i; j < MAXI; j+= i)isPrime[j] = 0;
        }
    }
    //for(int i = 0; i < 11; i++)printf("%d ",primes[i]);
    //puts("KHA");
}

ll eulerPhi(ll N){
    ll pfIdx = 0, pf = primes[pfIdx], ans = N;
    while( pf * pf <= N){

        if( N % pf == 0 ) ans -= ans/pf;
        while( N % pf == 0 ) N /= pf;


        pfIdx++;
        pf = primes[pfIdx];
        //printf("%lld %lld\n",N,pf);
    }
    if( N != 1 ) ans -= ans/N;
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    seive();
    ll N;
    scanf("%lld",&N);
    while( N ){
        ll res = eulerPhi(N);
        printf("%lld\n",res);
        scanf("%lld",&N);
    }
    return 0;
}
