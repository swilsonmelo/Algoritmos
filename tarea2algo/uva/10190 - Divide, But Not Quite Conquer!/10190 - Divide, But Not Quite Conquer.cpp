#include <bits/stdc++.h>

using namespace std;


vector<int> res;

int recu(int cant,int m){
    if(cant == 1){
        res.push_back(cant);
        return 1;
    }
    if(cant % m != 0) return 0;
    else{
        int num = cant/m;
        res.push_back(cant);
        return recu(num,m);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while( scanf("%d %d", &n, &m) == 2){
        res.clear();
        //printf("%d %d\n",n,m);
        if( m < 2 || n == 0 || n < m){
            printf("Boring!\n");
            continue;
        }
        if(recu(n,m)){
            printf("%d",res[0]);
            for(int i = 1; i < res.size(); i++){
                printf(" %d",res[i]);
            }
            puts("");
        }else{
            printf("Boring!\n");
        }
    }

    return 0;
}
