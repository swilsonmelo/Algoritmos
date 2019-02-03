#include <bits/stdc++.h>

using namespace std;


class Truckloads{
public:
    int numTrucks(int numCrates, int loadSize);
};


int Truckloads::numTrucks(int numCrates, int loadSize){
    if(numCrates <= loadSize) return 1;
    else{
        if(numCrates % 2 == 0){
            return Truckloads::numTrucks(numCrates/2,loadSize) + Truckloads::numTrucks(numCrates/2,loadSize);
        }else{
            return Truckloads::numTrucks(numCrates/2,loadSize) + Truckloads::numTrucks(numCrates/2 + 1,loadSize);
        }
    }

}

/*
int main(){
    Truckloads *tl;
    int res = tl->numTrucks(1024, 5);
    printf("%d",res);

    return 0;
}*/
