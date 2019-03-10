#include <bits/stdc++.h>

using namespace std;

class FibonacciSequence{
public:
    int numFibs(int a, int b){
        int fibb[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597};
        int res = 0;
        for(int i = 0; i < 17; i++){
                //printf("%d\n",fibb[i]);
            if( fibb[i] >= a && fibb[i] <= b ){
                    res += 1;
            }
        }
        return res;

    }

};


int main(){
    FibonacciSequence *fs;
    int res = fs->numFibs(2,5);
    printf("%d\n",res);
    return 0;
}
