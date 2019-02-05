#include <bits/stdc++.h>

using namespace std;


int cmp (int a, int b){
    if( a > b) return 1;
    return 0;

}


class Haar1D{
public :
    vector <int> transform(vector <int> data, int l){
        vector<int> seq;
        int limit = data.size();
        for(int i=0;i<l;i++){
            seq.clear();
            for(int j=0;j<limit;j+=2){
              seq.push_back(data[j]+data[j+1]);

            }
            for(int j=0;j<limit;j+=2){
              seq.push_back(data[j]-data[j+1]);

            }
            for(int j=limit;j<data.size();j++){
              seq.push_back(data[j]);

            }

            data=seq;
            limit/=2;
        }
        /*
        for(int i = 0; i < seq.size(); i++) printf("%d ",seq[i]);
        puts("");*/
        return seq;

    }

};
/*
int main(){
    vector<int> res;
    int myVec[] = {1, 2, 3, 5};
    for(int i = 0; i < 4; i++)res.push_back(myVec[i]);
    Haar1D *ha ;
    vector<int> res1 = ha->transform(res,1);
    vector<int> res2 = ha->transform(res,2);
    return 0;
}*/
