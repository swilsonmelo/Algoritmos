#include <bits/stdc++.h>

using namespace std;


class Haar1D{
public :
    vector <int> transform(vector <int> data, int l){
        vector<int> res;
        for(int i = 0; i < data.size(); i += 2){
            res.push_back(dat[i]+dat[i+1]);
            res.push_back(dat[i]-dat[i+1]);
        }
        l--;
        if(l == 0){
            for(int i = 0; i < res.size(); i++) printf("%d ",res[i]);
            puts();
            return res;
        }else{
            return transform(res,l);
        }
    }

};

int main(){
    vector<int> res;
    int myVec[] = {1, 2, 3, 5};
    for(int i = 0; i < 4; i++)res.push_back(myVec[i]);
    Haar1D *ha ;
    vector<int> res1 = ha->transform(res,1);

    return 0;

}
