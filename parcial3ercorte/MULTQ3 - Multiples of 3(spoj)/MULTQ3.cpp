#include <bits/stdc++.h>
#define INF 1<<30
#define MAXI 100002

using namespace std;

int data[MAXI];

struct SegmentTree {
    int start, end;
    SegmentTree *leftTree, *rightTree;
    int multsOf3;

    SegmentTree(int start, int end) {
        this->start = start;
        this->end = end;
        this->multsOf3 = 0;
        if(start == end) {  // es una hoja
            leftTree = rightTree = NULL;

            if(data[start] % 3 == 0){
                this->multsOf3 = 1;
            }
            //printf("start %d end %d data %d mults %d\n",start,end,data[start]%3,multsOf3);
            return;
        }
        int mid = (start + end) / 2;
        leftTree = new SegmentTree(start, mid);
        int lefT3 = leftTree->multsOf3;
        rightTree = new SegmentTree(mid + 1, end);
        int rightT3 = rightTree->multsOf3;
        this->multsOf3 = lefT3+rightT3;
    }

    void set(int pos, int value) {
        // es una hoja, CASO BASE
        if(start == end) {
            data[start] += value;
            if(data[start] % 3 == 0) multsOf3 = 1;
            else multsOf3 = 0;
            return;
        }

        int mid = (start + end) / 2;

        if(pos <= mid)
            leftTree->set(pos, value);
        else
            rightTree->set(pos, value);

        multsOf3 = leftTree->multsOf3 + rightTree->multsOf3;
    }

    int getMultsOf3(int low, int high) {
        // [low,high] = [start,end]
        if(start == low && end == high)
            return multsOf3;

        int mid = (start + end) / 2;

        // [low,high] totalmente incluido en [start,mid]
        if(high <= mid)
            return leftTree->getMultsOf3(low, high);

        // [low,high] totalmente incluido en [mid+1,end]
        if(low > mid)
            return rightTree->getMultsOf3(low, high);

        // debemos dividir el intervalo en [low,mid] y [mid+1,high]
        int leftMults = leftTree->getMultsOf3(low, mid);
        int rightMults = rightTree->getMultsOf3(mid+1, high);

        return leftMults+rightMults;
    }

};

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,Q;
    int op,src,tgt;

    scanf("%d %d",&n,&Q);

    for(int i = 0; i < n; i++){
        data[i] = 0;
    }
    SegmentTree st(0,n-1);
    /*
    for(int i = 0; i < n; i++){
        data[i] = 0;
        int res = st.getMultsOf3(i,i);
        printf("pos %d res %d\n",i,res);
    }*/

    for(int q = 0; q < Q; q++){
        scanf("%d %d %d",&op,&src,&tgt);
        if(op == 1){
            int res = st.getMultsOf3(src,tgt);
            printf("%d\n",res);
        }else{
            for(int i = src; i <= tgt; i++ ){
                st.set(i,1);
            }

        }
    }

}










