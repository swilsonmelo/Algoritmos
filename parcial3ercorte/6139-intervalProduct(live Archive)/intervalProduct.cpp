#include<bits/stdc++.h>
#define MAXI 100000

using namespace std;

int data[MAXI];

struct SegmentTree {
    int start, end;
    SegmentTree *leftTree, *rightTree;
    int paridad;

    SegmentTree(int start, int end) {
        this->start = start;
        this->end = end;

        if(start == end) {  // es una hoja
            leftTree = rightTree = NULL;
            //printf(" st %d num %d \n",start,data[start]);
            if(data[start] == 0) this->paridad = 0;
            else if(data[start] < 0)this->paridad = -1;
            else this->paridad = 1;
            return;
        }
        int mid = (start + end) / 2;
        leftTree = new SegmentTree(start, mid);
        rightTree = new SegmentTree(mid + 1, end);
        if( leftTree->paridad == 0 || rightTree->paridad == 0){
            this->paridad = 0;
        }else if( (leftTree->paridad == 1 && rightTree->paridad == -1) || (leftTree->paridad == -1 && rightTree->paridad == 1) ){
            this->paridad = -1;
        }else{
            this->paridad = 1;
        }
    }

    void set(int pos, int value) {
        // es una hoja, CASO BASE
        if(start == end) {
            data[start] = value;
            if(value == 0)paridad = 0;
            else if(value < 0) paridad = -1;
            else paridad = 1;
            return;
        }

        int mid = (start + end) / 2;

        if(pos <= mid)
            leftTree->set(pos, value);
        else
            rightTree->set(pos, value);

        if( leftTree->paridad == 0 || rightTree->paridad == 0){
            paridad = 0;
        }else if( (leftTree->paridad == 1 && rightTree->paridad == -1) || (leftTree->paridad == -1 && rightTree->paridad == 1) ){
            paridad = -1;
        }else{
            paridad = 1;
        }
    }

    int getParity(int low, int high) {
        // [low,high] = [start,end]
        if(start == low && end == high)
            return paridad;

        int mid = (start + end) / 2;

        // [low,high] totalmente incluido en [start,mid]
        if(high <= mid)
            return leftTree->getParity(low, high);

        // [low,high] totalmente incluido en [mid+1,end]
        if(low > mid)
            return rightTree->getParity(low, high);

        // debemos dividir el intervalo en [low,mid] y [mid+1,high]
        int leftParity = leftTree->getParity(low, mid);
        int rightParity = rightTree->getParity(mid+1, high);

        if( leftParity == 0 || rightParity == 0){
            return 0;
        }else if( (leftParity == 1 && rightParity == -1) || (leftParity == -1 && rightParity == 1) ){
            return -1;
        }else{
            return 1;
        }
    }

};


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k;
    while(cin >> n >> k){

        for(int i = 0; i < n; i++){
            scanf("%d",&data[i]);
        }
        SegmentTree st(0, n-1);
        /*
        for(int i = 0; i < n; i++){
            int res = st.getParity(i,i);
            printf("num %d pari %d\n",data[i],res);
        }
        //puts("");

        int res = st.getParity(0,n-1);
        printf("TOTAL pari %d\n",res);
        */
        char C;
        int x,y;
        for(int i = 1; i <= k; i++){
            cin >> C >> x >> y;
            if( C == 'C'){
                st.set(x-1,y);
                /*
                res = st.getParity(x-1,x-1);
                printf("num %d pari %d\n",data[x-1],res);
                int res = st.getParity(0,n-1);
                printf("TOTAL pari %d\n",res);
                */
            }else{
                int res = st.getParity(x-1,y-1);
                if(res == -1)printf("-");
                else if(res == 1)printf("+");
                else printf("0");
            }
            //printf("%c %d %d\n",C,x,y);
        }
        puts("");

    }
    return 0;
}