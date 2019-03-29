#include <bits/stdc++.h>
#define MAXI 6105
using namespace std;

int dp[MAXI][MAXI];
char s[MAXI];

int solve( int i , int j){
    if(i == j)return 0;
    if(i + 1 == j  ){
        if(s[i] == s[j]){
            return 0;
        }
        return 1;
    }
    if(dp[i][j] != -1)return dp[i][j];
    if(s[i] == s[j]){
        return dp[i][j] = solve(i+1 , j-1);
    }
    else {
        return dp[i][j] = 1 + min(solve(i+1 , j) , solve(i , j-1)) ;
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++ ){
        memset(dp , -1 , sizeof dp);
        scanf("%s",s);
        int len = strlen(s);
        printf("%d\n",solve(0 , len-1));
    }
    return 0;
}
