#include <bits/stdc++.h>
#define Maxi 47000
using namespace std;


typedef long long ll;
typedef vector<ll> vll;

vll primes;
int isPrime[Maxi];


void seive(){
    for( int i = 0; i < Maxi; i++) isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for(long long i = 0; i < Maxi; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j = i*i; j < Maxi; j+= i) isPrime[j] = 0;
        }
    }
    /*
    for(int i = 0; i < 11; i++) printf("%d ",primes[i]);
    puts("");
    */
}

int solve(ll n, ll m){
    //vll pFm;
    //map<ll,ll> pfMPower;
    ll pfIdx = 0, pf = primes[pfIdx];
    while( pf * pf <= m){
        ll power = 0;
        /*
        if( m % pf == 0 ){
            pFm.push_back(pf);
        }*/
        while( m % pf == 0){
            power++;
            m /= pf;
        }
        if( power ){
            //pfMPower[pf] = power;
            ll power2 = 0;
            for(ll j = pf; j <= n; j *= pf){
            //if( n % j == 0)power += n/j;
                power2 += n/j;

            }
            if( power > power2){
                return 0;
            }

        }
        pfIdx++;
        pf = primes[pfIdx];
    }
    if( m != 1 ) {
        //pFm.push_back(m);
        //pfMPower[m] = 1;
        ll power2 = 0;
        /*
        for(ll j = m; j <= n; j *= m){
            power2 += n/j;
        }*/
        if( 1 > n/m){
            return 0;
        }
    }
    return 1;
    /*
    for(int i = 0; i < pFm.size(); i++) printf("%d : %d  ",pFm[i],pfMPower[pFm[i]]);
    puts("");
    */
    /*
    int res = 1;
    for(int i = 0; i < pFm.size(); i++){
        ll pf = pFm[i];
        //printf("%d\n",pf);
        ll power = 0;
        for(ll j = pf; j <= n; j *= pf){
            //if( n % j == 0)power += n/j;
            power += n/j;
        }
        //printf("%d %d %d\n",pf,pfMPower[pf],power);
        if (pfMPower[pf] > power){
            //printf("nel %d %d %d\n",pf,pfMPower[pf],power);
            res = 0;
            break;
        }
    }
    return res;*/


}

int main(){
    seive();
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll x,y;
    while( scanf("%lld %lld",&x,&y) == 2 ){
        if( y == 0 )printf("%lld does not divide %lld!\n",y,x);
        else if( y <= x)printf("%lld divides %lld!\n",y,x);
        else{
            int res = solve(x,y);
            if(!res)printf("%lld does not divide %lld!\n",y,x);
            else printf("%lld divides %lld!\n",y,x);
        }

    }
    return 0;
}
