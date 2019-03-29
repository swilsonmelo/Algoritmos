#include <bits/stdc++.h>
#define MAXI 10000000



using namespace std;

int mat[25][25];
int dp[25][25];
int n,m,x,y;

int solve(int i,int j){
    if( i == n && j == m) return mat[i][j];
    if( i > n || j > m) return MAXI;
    int res = dp[i][j];
    if( res != -1 ) return res;

    res = mat[i][j] + min(solve(i+1,j),solve(i,j+1));
    dp[i][j] = res;
    return res;

}


int main(){

    scanf("%d %d %d %d",&n,&m,&x,&y);
    memset(dp,-1,sizeof dp);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    n--;
    m--;
    int power = mat[x-1][y-1];
    int res = power + power - solve(x-1,y-1);
    if( res >= 0 )printf("Y %d\n",res);
    else printf("N\n");
    return 0;
}
