#include <bits/stdc++.h>


using namespace std;

/*

T(n)=5T(n-1)-6T(n-2)
(x^2) - 5x + 6
(x-3)(x-2)
f(n) = A(3^n)+B(2^n)
f(0) = A+B
f(1) = 3A+2b
f(0) = 2
f(1) = 5
2 = A+B
5 = 3A+2B
A = 1
B = 1

*/

int recu(n){
    if( n == 0 )return 2;
    if( n == 1 ) return 5;
    else{
        return 5*reu(n-1) + 6*recu(n-2)
    }

}

int recuWithsqrt(n){
    int p1 = 1;
    for(int i = 0; i < n; i++) p1 *= 3;
    int p2 = 1;
    for(int i = 0; i < n; i++) p1 *= 2;
    return (p1+p2)

}

int main(){
    for(int i = 0; i < 10; i++){
        printf("recurrente %d ----- recurrencia con la raiz %d\n",recu(i), recuWithsqrt(i));
    }
    return 0;
}
