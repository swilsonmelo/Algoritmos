#include<bits/stdc++.h>
#define MAXI 1100
#define MAXIN 1000002
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int isPrime[MAXI];
vll primes;
ll ans[MAXIN];

void seive(){
    for(int i = 0; i < MAXI; i++)isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2; i < MAXI; i++){
        if( isPrime[i] ){
            //printf("%d\n",i);
            primes.push_back(i);
            //printf("%d\n",i);
            for( long long j = i*i; j < MAXI; j+=i){
                isPrime[j] = 0;
            }
        }
    }
    //for(int i = 0; i < 11; i++) printf("%d ",primes[i]);
}

void precalc(){
    ans[1] = 0;
    for(ll i = 2; i < MAXIN; i++){
        ans[i] = ans[i-1];
        ll n = i;
        ll pfIdx = 0, pf = primes[pfIdx];
        while( pf * pf <= n ){
            //printf("%lld %lld\n",n,pf);
            while( n % pf == 0){
                ans[i]++;
                n /= pf;
            }
            pfIdx++;
            pf = primes[pfIdx];
        }
        if(n != 1)ans[i]++;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    seive();
    precalc();
    ll n;
    while( scanf("%lld",&n) == 1 ){
        printf("%lld\n",ans[n]);
    }
    return 0;
}
