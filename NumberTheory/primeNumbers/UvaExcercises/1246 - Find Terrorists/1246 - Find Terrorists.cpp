#include<bits/stdc++.h>
#define MAXI 11002

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int isPrime[MAXI];
vi primes;

void seive(){
    for(int i = 0; i < MAXI; i++) isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2; i < MAXI; i++){
        if( isPrime[i] ){
            primes.push_back(i);
            for(ll j = i*i; j < MAXI; j+= i)isPrime[j] = 0;
        }
    }
    //for(int i = 0; i < 11; i++) printf("%d ",primes[i]);

}


ll numDiv(ll N){
    ll pfIdx = 0, pf = primes[pfIdx], ans = 1;
    while( pf * pf <= N && !isPrime[N]){
        ll power = 0;
        while( N % pf == 0){
            power++;
            N /= pf;
        }
        ans *= (power+1);
        pfIdx++;
        pf = primes[pfIdx];

    }
    if( N != 1 )ans *= 2;
    return ans;

}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    seive();
    //ll res = numDiv(10000);
    //printf("%d\n",res);
    int cases;
    scanf("%d",&cases);
    for(int c = 0; c < cases; c++){
        vi res;
        ll L,H;
        scanf("%lld %lld",&L,&H);
        for(int i = L; i <= H; i++){
            ll nDiv = numDiv(i);
            if( isPrime[nDiv] ) res.push_back(i);
        }
        if( res.size() ){
            for(int i = 0; i < res.size()-1; i++)printf("%d ",res[i]);
            printf("%d\n",res[res.size()-1]);
        }else puts("-1");
    }
    return 0;
}
