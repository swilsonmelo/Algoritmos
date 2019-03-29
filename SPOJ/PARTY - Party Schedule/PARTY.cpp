#include <bits/stdc++.h>
#define MAXP 505
#define MAXM 105

using namespace std;

int pri[MAXP];
int fun[MAXP];
int dp[MAXM][MAXP];


int solve(int pos, int m){
    int res = dp[pos][m];
    if(res != -1) return res;
    if( m <= 0 ) return 0;
    if( pos < 0 ) return 0;

    int res1 = solve(pos-1,m);
    int res2 = 0;
    if(pri[pos] <= m){
        res2 = fun[pos] +  solve(pos-1,m-pri[pos]);
    }
    res = max(res1,res2);
    dp[pos][m] = res;
    return res;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    scanf("%d %d",&m,&n);
    while( n != 0 && m != 0){

        for(int i = 0; i < n; i++){
            scanf("%d %d",&pri[i],&fun[i]);
        }

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                dp[i][j] = 0;
            }
        }
        for(int i = 1;i <= n; i++){
            for(int j = 1;j <= m; j++){
                if(pri[i-1] <= j){
                    dp[i][j] = max(fun[i-1]+dp[i-1][j-pri[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int maxfun = dp[n][m];
        int minmoney = 0;
        for(int i = 0;i <= m;i ++){
            if(dp[n][i] == maxfun){
                minmoney = i;
                break;
            }
        }
        printf("%d %d\n",minmoney,maxfun);
        scanf("%d %d",&m,&n);
    }

    return 0;
}



