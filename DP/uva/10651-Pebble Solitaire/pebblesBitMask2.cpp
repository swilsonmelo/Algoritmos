/*
    Ejercicio de KATTIS 23 posiciones posibles
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1<<24;
int dp[MAX];

int isOn(int b, int mask){
    if( ((1<<b)&mask) != 0 ) return 1;
    return 0;
}

void turnOn(int b, int& mask){
    mask |= 1<<(b);
}

void turnOff(int b, int& mask){
    mask &= ~(1<<(b));
}

int recursive (int mask){
	//printf("%d\n",mask);
	if( dp[mask] != -1 )return dp[mask];
	int temp = mask;
	int ans = 1<<5;
    for ( int i = 0; i < 22; i++ ) {
        if ( isOn(i,mask) && isOn(i+1,mask) ) {
            if ( i + 2 < 23 &&  !isOn(i+2,mask) ) {
                //a [i + 2] = 'o';
                //prender el bit i+2
                //mask |= 1<<(i+2);
                turnOn(i+2,mask);
                //a [i] = a [i + 1] = '-';
                //apagar el i+1
                //mask &= ~(1<<(i+1));
                turnOff(i+1,mask);
                //mask &= ~(1<<(i));
                turnOff(i,mask);
                ans = min(ans,recursive(mask));
                mask = temp;
            }
            if ( i - 1 >= 0 && !isOn(i-1,mask)  ) {
                //a [i - 1] = 'o';
                //mask |= 1<<(i-1);
                turnOn(i-1,mask);
                //a [i] = a [i + 1] = '-';
                //mask &= ~(1<<(i));
                turnOff(i,mask);
                //mask &= ~(1<<(i+1));
                turnOff(i+1,mask);
                ans = min(ans,recursive(mask));
                mask = temp;
            }
        }
    }

    // contar los bits encendidos
    return dp[mask] = min(ans,__builtin_popcount(mask));
}

int main (){
    freopen("in2.txt","r",stdin);
	freopen("out2.txt","w",stdout);
    int testCase;
    scanf ("%d", &testCase);
    memset(dp,-1,sizeof(dp));

    while ( testCase-- ) {

        int mask = 0;
        char input [25];
        scanf ("%s", input);

        for(int i = 22; i >= 0; i--){
            mask |= input[i] == 'o'? 1<<i :0 ;
        }
        //out << input << endl;
        int cnt = 100;
        //printf("%d\n",mask);
        cnt = recursive (mask);
        printf ("%d\n", cnt);
    }

    return 0;
}
