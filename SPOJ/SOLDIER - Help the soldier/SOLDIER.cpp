#include <bits/stdc++.h>
#define MAXI 105
#define INF 1005

using namespace std;
typedef vector<int> vii;

vector<int> types[8];
int quality[MAXI];
int price[MAXI];

int solve(int n, int m){
    if(m < 0) return 0;
    if( n <= 0) return INF;
    int res = 0;
    for( int i = 0; i < types[n].size(); i++){
        int pos = types[n][i];
        //printf("type %d pos %d\n",n,pos);
        if( m >= price[pos]){
            res = max( res, min( quality[pos], solve(n-1, m - price[pos] ) ) );
        }
    }
    return res;

}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    while(scanf("%d %d",&n,&m) == 2){
        int type,p,q;
        for(int i = 0; i < n; i++)   {
            scanf("%d %d %d",&type,&price[i],&quality[i]);
            //printf("type  %d\n",type);
            types[type].push_back(i);
        }
        /*
        for( int i = 1; i <= 6; i++){
            printf("type %d\n",i);
            for(int j = 0; j < types[i].size(); j++){
                printf("%d ",types[i][j]);
            }
            puts("");
        }*/
        int res = solve(6,m);
        printf("%d\n",res);
    }

    return 0;
}