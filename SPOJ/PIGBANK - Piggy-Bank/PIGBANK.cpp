#include<bits/stdc++.h>
#define Maxi 502
#define MaxiW 10000
using namespace std;


int p[Maxi],w[Maxi];
long long dp[MaxiW];



int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cases;
    scanf("%d",&cases);

    for(int c = 0; c < cases; c++){
        int iniW ,totW,n,minW;
        scanf("%d %d %d",&iniW,&totW,&n);
        //minW = INT_MAX;
        for(int i = 0; i < n; i++){
            scanf("%d %d",&p[i],&w[i]);
            //minW = min(minW,w[i]);
        }
        totW -= iniW;
        for(int i = 0; i <= totW; i++)dp[i] = INT_MAX;

        dp[0] = 0;

        for(int i = 1; i <= totW; i++ ){
            
            for(int j = 0; j < n; j++){

                if( i >= w[j] ){
                    //printf("%d %d %d %d\n",i,w[j],dp[i],dp[i-w[j]]);
                    dp[i] = min(dp[i],p[j]+dp[i-w[j]]);
                }
            }
        }
        //for(int i = 0; i <= totW; i++)printf("%d ",dp[i]);
        //puts("");
        if( dp[totW] >= INT_MAX ) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[totW]);

    }


    return 0;
}