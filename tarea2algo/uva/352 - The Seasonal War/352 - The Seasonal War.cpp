#include <bits/stdc++.h>


using namespace std;
char mat[30][30];
int  used[30][30];
int xi[] = {-1,-1,-1, 0, 0, 0, 1, 1, 1};
int yi[] = {-1, 0, 1,-1, 0, 1,-1, 0, 1};



void dfs(int x,int y,int n){
    int a;
    int b;
    for(int i = 0; i < 9; i++){
        a = x + xi[i];
        b = y + yi[i];
        if( a >= 0 && a < n && b >= 0 && b < n){
            if( mat[a][b] == '1' && used[a][b] == 0 ){
                used[a][b] = 1;
                dfs(a,b,n);
            }
        }
    }
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d",used[i][j]);
        }
        puts("");
    }
    puts("");
    */
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,cases = 1;
    while( scanf("%d",&n) == 1 ){

        for(int i = 0; i < n; i++) {
            scanf("%s",&mat[i]);
        }
        memset(used,0, sizeof(used) );
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if( mat[i][j] == '1' && used[i][j] == 0 ){
                    used[i][j] = 1;
                    res += 1;
                    dfs(i,j,n);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",cases,res);
        cases++;
    }

    return 0;
}
