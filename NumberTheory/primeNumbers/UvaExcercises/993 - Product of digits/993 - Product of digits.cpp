#include <bits/stdc++.h>

using namespace std;

int dig[10];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cases,n;
    scanf("%d",&cases);
    for(int c = 0; c < cases; c++){
        scanf("%d",&n);
        if( n == 0 ) puts("0");
        else if(n == 1)printf("1\n");
        else{
            for(int i = 0; i < 10; i++) dig[i] = 0;
            for(int j = 9; j >= 2; j--){
                while( n % j  == 0){
                    dig[j]++;
                    n /= j;
                }
            }
            if(n == 1){
                for(int i = 2; i < 10; i++){
                    for(int j = 0; j < dig[i]; j++) printf("%d",i);
                }
                puts("");
            }else printf("-1\n");

        }
    }
    return 0;
}
