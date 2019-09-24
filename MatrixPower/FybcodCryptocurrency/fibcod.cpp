
#include <bits/stdc++.h>
#define MAX_N 2
#define MOD 524288

using namespace std;

struct Matrix{

    long long mat[MAX_N][MAX_N];

};


Matrix matMult(Matrix a, Matrix b){
    Matrix ans;
    int k;
    for(int i = 0; i < MAX_N; i++){
        for(int j = 0; j < MAX_N; j++){
            for(ans.mat[i][j] = k = 0; k < MAX_N; k++){
                ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % MOD;
            }
        }
    }
    return ans;
}


Matrix matPow(Matrix base, long long p){
    Matrix ans;
    for(int i = 0; i < MAX_N; i++){
        for(int j = 0; j < MAX_N; j++){
            ans.mat[i][j] = (i==j);
        }
    }
    while(p){
        if(p & 1) ans = matMult(ans,base);
        base = matMult(base,base);
        p >>= 1;
    }
    return ans;
}

int main(){

    int n;
    scanf("%d",&n);
    while(n){
        vector<int> m(n);
        for(int i = 0; i < n; i++) scanf("%d",&m[i]);
        Matrix base;
        base.mat[0][0] = 1;
        base.mat[0][1] = base.mat[1][0] = 1;
        base.mat[1][1] = 0;
        int ini;
        if( n % 2 == 0){
            ini = -1;
        }else{
            ini = 1;
        }
        long long suma = 0;
        long long potencia = 1;
        for(int i = n-1; i >= 0; i--){            
            if(ini == 1){
                Matrix ans = matPow(base,potencia);
                for(int j = 0; j < m[i]; j++){
                    long long res = ans.mat[0][0];
                    suma += res;        
                    suma %= MOD;
                    potencia += 1;
                    ans = matMult(ans,base);
                }
            }else{              
                potencia += m[i];                                        
            }
            
            ini *= -1;

            
        }
        printf("%lld\n",suma);

        scanf("%d",&n);


    }

    return 0;
}

