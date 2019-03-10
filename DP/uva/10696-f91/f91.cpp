#include <bits/stdc++.h>

using namespace std;

map<int,int> myMap;


int f91(int n){
    if( n >= 101 ){
        return n-10;
    }else if( myMap.find(n) != myMap.end() ){
        return myMap[n];
    }else{
        myMap[n] = f91(f91(n+11));
        return myMap[n];
    }

}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,res;
    scanf("%d",&n);
    while( n != 0 ){
        res = f91(n);
        printf("f91(%d) = %d\n",n,res);
        scanf("%d",&n);
    }

    return 0;
}
