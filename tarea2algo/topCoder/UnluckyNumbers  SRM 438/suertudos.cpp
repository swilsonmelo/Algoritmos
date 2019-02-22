#include<bits/stdc++.h>

using namespace std;


class UnluckyNumbers{
public:
    int range(int A,int B,int n){
        int res = (n-A)*(B-(n-1));
        //printf("res1 %d %d %d %d\n",res,A,B,n);
        res += (B-n);
        //printf("res2 %d\n",res);
        return res;
    }

    int getCount(vector<int> suertudos, int n){
        sort(suertudos.begin(),suertudos.end());
        int minBefore = 1;
        int maxAfter = 1;
        for(int i = 0; i < suertudos.size()-1; i++){
            if(suertudos[i] == n) return 0;
            if( i == 0 && suertudos[i] > n){
                maxAfter = suertudos[i]-1;
                break;
            }
            if( suertudos[i] < n && suertudos[i+1] > n ){
                minBefore = suertudos[i]+1;
                maxAfter = suertudos[i+1]-1;
                break;
            }
        }
        //printf("min %d, max %d\n",minBefore,maxAfter);
        if(maxAfter-minBefore == 0) return 0;
        return range(minBefore,maxAfter,n);

    }

};

int main(){

    /*
    cases:
    4 2 1 7 14 10
    5 10 4 8 13 24 30
    5 30 10 20 30 40 50
    */
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    int num;
    int k;
    vector<int> suertudos;
    scanf("%d",&n);
    scanf("%d",&num);
    for(int i = 0; i < n; i++){
        scanf("%d",&k);
        suertudos.push_back(k);
    }
    UnluckyNumbers *ul;

    int res = ul ->getCount(suertudos,num);
    printf("%d\n",res);
    return 0;
}
