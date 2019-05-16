#include <bits/stdc++.h>
#define MAXI 1000005
#define MAXTAM 10005
using namespace std;

int arr[MAXTAM];
int isPrime[MAXI];

void seive(){
    for(int i = 0; i < MAXI; i++) isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for(long long i = 2; i < MAXI; i++){
        if( isPrime[i] ){
            for(long long j = i*i; j < MAXI; j+=i){
                isPrime[j] = 0;
            }
        }
    }
}


struct SegmentTree {
    int start, end;
    SegmentTree *leftTree, *rightTree;
    int primes;

    SegmentTree(int start, int end) {
        this->start = start;
        this->end = end;
        this->primes = 0;
        if(start == end) {  // es una hoja
            int num;
            num = arr[start];
            if(isPrime[num]) primes = 1 ;
            leftTree = rightTree = NULL;
            return;
        }
        int mid = (start + end) / 2;
        leftTree = new SegmentTree(start, mid);
        rightTree = new SegmentTree(mid + 1, end);
        primes = leftTree->primes + rightTree->primes;
    }

    void set(int pos, int value) {
        // es una hoja, CASO BASE
        if(start == end) {
            arr[start] = value;
            if(isPrime[value]) primes = 1;
            else primes = 0;
            return;
        }

        int mid = (start + end) / 2;

        if(pos <= mid)
            leftTree->set(pos, value);
        else
            rightTree->set(pos, value);

        primes = leftTree->primes + rightTree->primes;
    }

    int getPrimes(int low, int high) {
        // [low,high] = [start,end]
        if(start == low && end == high)
            return primes;

        int mid = (start + end) / 2;

        // [low,high] totalmente incluido en [start,mid]
        if(high <= mid)
            return leftTree->getPrimes(low, high);

        // [low,high] totalmente incluido en [mid+1,end]
        if(low > mid)
            return rightTree->getPrimes(low, high);

        // debemos dividir el intervalo en [low,mid] y [mid+1,high]
        int leftPrimes = leftTree->getPrimes(low, mid);
        int righPrimes = rightTree->getPrimes(mid+1, high);
        return leftPrimes + righPrimes;
    }

};

int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    seive();
    int cases;
    scanf("%d",&cases);
    for(int c = 0; c < cases; c++){
        
        int n,q;
        scanf("%d %d", &n, &q);
        
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        SegmentTree st(0, n-1);  // 9 numeros
        /*
        for(int i = 0; i < n; i++){
            int res = st.getPrimes(i,i);
            printf("%d %d\n",arr[i],res);
        }
        */
        int op,x,y,v;
        printf("Case %d:\n",c+1);
        for(int i = 0; i < q; i++){
            scanf("%d",&op);
            if(op == 0){
                scanf(" %d %d %d", &x, &y, &v);
                for(int j = x; j <= y; j++){
                    st.set(j-1, v);
                }
                
            }else{
                scanf(" %d %d", &x, &y);
                int res = st.getPrimes(x-1,y-1);
                printf("%d\n",res);
            }
        }
    }

    return 0;
}

