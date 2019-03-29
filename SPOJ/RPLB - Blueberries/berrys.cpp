#include <bits/stdc++.h>
#define MAXI 1005

using namespace std;

int dp[MAXI][MAXI];
int berr[MAXI];

int solve(int pos, int m){
    if( pos < 0 ) return 0;
    if( m <= 0 ) return 0;
    int res = dp[pos][m];
    if( res != -1) return res;
    int r1 = solve(pos-1,m);
    int r2 = 0;
    if(berr[pos] <= m){
        r2 = berr[pos] + solve(pos-2, m-berr[pos]);
    }

    dp[pos][m] = max(r1,r2);
    return dp[pos][m];
}


int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    scanf("%d",&cases);

    for(int c = 1; c <= cases; c++){
        memset(dp,-1,sizeof dp);
        int n,m;

        scanf("%d %d",&n,&m);
        for(int i = 0; i < n; i++){
            scanf("%d",&berr[i]);
        }
        int res = solve(n-1,m);
        printf("Scenario #%d: %d\n",c,res);


    }

    return 0;
}
