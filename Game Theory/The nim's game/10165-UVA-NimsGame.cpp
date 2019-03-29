#include<bits/stdc++.h>


using namespace std;


int main(){
    int n,nim,val;
    scanf("%d",&n);
    while(n){
        nim = 0;
        for(int i = 0; i < n; i++){
            scanf("%d",&val);
            nim ^= val;
        }
        //printf("%d\n",nim);
        if( nim ) puts("Yes");
        else puts("No");

        scanf("%d",&n);
    }

    return 0;
}
