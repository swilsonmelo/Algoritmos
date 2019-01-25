#include <bits/stdc++.h>

using namespace std;

class DerivativeSequence{
public:
    vector<int> derSeq(vector<int> a, int n);
};

vector<int> DerivativeSequence::derSeq(vector<int> a, int n){
    for(int ord = 0; ord < n; ord++){
            vector<int> vRes;
            for(int i = 0; i < a.size()-1; i++){
                vRes.push_back(a[i+1]-a[i]);
            }
            a = vRes;

    }
    return a;


}
/*
int main(){
    DerivativeSequence *dt;
    vector<int> vec;
    int myVec[] = 	{5, 6, 3, 9, -1};
    for(int i = 0; i < 5; i++){
        vec.push_back(myVec[i]);
    }
    vector<int> res = dt->derSeq(vec,1);
    printf("%d\n",res.size());
    for(int i = 0; i < res.size(); i++){
        printf("%d ",res[i]);
    }
    return 0;
}*/


