#include <bits/stdc++.h>
#define Maxi 1000002

using namespace std;

typedef long long ll;
typedef vector<int> vi;


int isPrime[Maxi];
vi primes;

/**
* 2*primes[0]*primes[1]*7*11*.....*primes[k] = k^2
*/


void seive(){
    for(int i = 0; i < Maxi; i++ )isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2; i < Maxi; i++){
        if(isPrime[i]){
            for(ll j = i*i; j < Maxi; j += i)isPrime[j] = 0;
            primes.push_back(i);
        }
    }
}

/**
*Count the number of prime factors of N
*/
ll numPF(ll N){
    ll pfIdx = 0, pf = primes[pfIdx], ans = 0;
    while( pf * pf <= N ){
        while( N % pf == 0 ){
            //printf("%lld ",pf);
            N /= pf;
            ans ++;
        }
        pfIdx++;
        pf = primes[pfIdx];
    }
    //printf("%lld ",N);
    if( N != 1 ) ans++;
    return ans;
}

/**
*Count the number of different prime factors of N
*/
ll numDifPF(ll N){
    ll pfIdx = 0, pf = primes[pfIdx], ans = 0;
    while( pf * pf <= N ){
        if( N % pf == 0)ans ++;
        while( N % pf == 0 ){
            N /= pf;
        }
        pfIdx++;
        pf = primes[pfIdx];
    }
    if( N != 1 ) ans++;
    return ans;
}

/**
*Sum the prime factors of N
*/
ll sumPF(ll N){
    ll pfIdx = 0, pf = primes[pfIdx], ans = 0;
    while( pf * pf <= N ){
        while( N % pf == 0 ){
            N /= pf;
            ans += pf;
        }
        pfIdx++;
        pf = primes[pfIdx];
    }
    if( N != 1 ) ans += N;
    return ans;

}

/**
*count de number of divisors of N
* N = (a^i)*(b^j)*...*(c^k) then
* N has (i+1)*(j+1)*...*(k+1) divisors
*/
ll numDiv(ll N){
    ll pfIdx = 0, pf = primes[pfIdx], ans = 1;
    while( pf * pf <= N ){
        ll power = 0;
        while( N % pf == 0 ){
            N /= pf;
            power++;
        }
        ans *= (power + 1);
        pfIdx++;
        pf = primes[pfIdx];
    }
    if( N != 1 ) ans*=2;
    return ans;
}

/**
*sum the divisors of N
*/
ll sumDiv(ll N){
    ll pfIdx = 0, pf = primes[pfIdx], ans = 1;
    while( pf * pf <= N){
        ll power = 0;
        while( N % pf == 0 ){
            N /= pf;
            power++;
        }
        //printf("%lld %lld\n",pf,power);
        ans *= ((ll)pow((double)pf, power + 1.0) - 1) / (pf - 1);
        pfIdx++;
        pf = primes[pfIdx];
    }
    if( N != 1 ) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);
    return ans;
}

/**
*Count the first x coprimes of N where x < N
*/
ll EulerPhi(ll N){
    ll pfIdx = 0, pf = primes[pfIdx], ans = N;
    while( pf * pf <= N ){
        if( N % pf == 0 ){
            ans -= ans/pf;
        }
        while( N % pf == 0 ){
            N /= pf;
        }
        pfIdx++;
        pf = primes[pfIdx];
    }
    if( N != 1 ) ans -= ans/pf;
    return ans;
}


int main(){
    seive();
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll N;
    scanf("%lld",&N);
    ll res;
    res = numPF(N);
    printf("%lld tiene %lld factores primos\n",N,res);
    res = numDifPF(N);
    printf("%lld tiene %lld factores primos diferentes\n",N,res);
    res = sumPF(N);
    printf("La suma de los factores primos de %lld es %lld\n",N,res);
    res = numDiv(N);
    printf("%lld tiene %lld divisores\n",N,res);
    res = sumDiv(N);
    printf("La suma de los divisores de %lld es %lld\n",N,res);
    res = EulerPhi(N);
    printf("%lld tiene %lld coprimos menores que el\n",N,res);
    return 0;
}
