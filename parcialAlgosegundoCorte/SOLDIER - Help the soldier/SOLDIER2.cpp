#include <bits/stdc++.h>
#define MAXIN  1000
#define MAXIT  1005

using namespace std;
// WA
int n,t;
int type[7];
int dp[MAXIN][MAXIT];
int types[MAXIN];
int p[MAXIN];
int q[MAXIN];

int solve(int i, int m){
    //printf("%d %d\n",i,m);
    if(m == 0 || i >= n){
        /*
        for(int j = 0; j <= 6; j++ ) printf("%d ",type[j]);
        puts("");
        */
        int r = MAXIT;
        for(int j = 1; j <= 6; j++){
            if( type[j] == -1 ) return MAXIT;
            r = min(r,type[j]);
        }
        return r;
    }
    if( m < 0) return MAXIT;
    //int res = dp[i][m] ;
    //printf(" res %d\n",res);
    //if(res != MAXIT) return res;
    //printf("kha2\n");
    int res1 = solve(i+1,m);
    //printf("res1 %d\n",res1);
    int res2 = MAXIT;
    //printf("p %d m %d\n",p[i],m);
    if(p[i] <= m){
        //printf("okk\n");
        if(type[i] != -1){
            if(type[types[i]] < q[i]){
                type[types[i]] = q[i];
                res2 = solve(i+1,m-p[i]);
                //printf("res2 %d\n",res2);
            }
        }else{
            type[types[i]] = q[i];
            res2 = solve(i+1,m-p[i]);
            //printf("res2 %d\n",res2);
        }
    }
    dp[i][m] = min(res1,res2);
    return dp[i][m];

}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d %d",&n,&t);

    for(int i = 0; i <= 7; i++) type[i] = -1;

    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= t; j++ ){
            dp[i][j] = MAXIT;
        }
    }


    for(int i = 0; i < n; i++){
        scanf("%d %d %d",&types[i],&p[i],&q[i]);
    }

    int res = solve(0,t);
    if (res == MAXIT) printf("0\n");
    else printf("%d\n",res);

    return 0;
}
