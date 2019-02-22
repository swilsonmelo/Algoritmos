#include <bits/stdc++.h>
#define INF 1<<30

using namespace std;

struct SegmentTree {
    int start, end;
    SegmentTree *leftTree, *rightTree;
    long long sumValue;

    SegmentTree(int start, int end) {
        this->start = start;
        this->end = end;
        this->sumValue = 0LL;
        if(start == end) {  // es una hoja
            leftTree = rightTree = NULL;
            return;
        }
        int mid = (start + end) / 2;
        leftTree = new SegmentTree(start, mid);
        rightTree = new SegmentTree(mid + 1, end);
    }

    void set(int pos, long long value) {
        // es una hoja, CASO BASE
        if(start == end) {
            sumValue = value;
            return;
        }

        int mid = (start + end) / 2;

        if(pos <= mid)
            leftTree->set(pos, value);
        else
            rightTree->set(pos, value);

        sumValue = leftTree->sumValue + rightTree->sumValue;
    }

    void xxor(int pos, long long x){
        if(start == end) {
            sumValue ^= x;
            return;
        }
        int mid = (start + end) / 2;

        if(pos <= mid)
            leftTree->xxor(pos, x);
        else
            rightTree->xxor(pos, x);

        sumValue = leftTree->sumValue + rightTree->sumValue;
    }

    long long getSum(int low, int high) {
        // [low,high] = [start,end]
        if(start == low && end == high)
            return sumValue;

        int mid = (start + end) / 2;

        // [low,high] totalmente incluido en [start,mid]
        if(high <= mid)
            return leftTree->getSum(low, high);

        // [low,high] totalmente incluido en [mid+1,end]
        if(low > mid)
            return rightTree->getSum(low, high);

        // debemos dividir el intervalo en [low,mid] y [mid+1,high]
        long long leftMin = leftTree->getSum(low, mid);
        long long rightMin = rightTree->getSum(mid+1, high);
        return (leftMin + rightMin);
    }

};


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("in.txt","r",stdin);

    int n;
    long long x;
    //scanf("%d",&n);
    cin >> n;
    SegmentTree st(0,n);
    for(int i = 0; i < n; i++){
        //scanf("%lld",&x);
        cin >> x;
        st.set(i,x);
    }
    int m,R,L,H;
    //scanf("%d",&m);
    cin >> m;
    for(int i = 0; i < m; i++){
        //scanf("%d",&R);
        cin >> R;
        if(R == 1){
            //scanf("%d %d",&L,&H);
            cin >> L>> H;
            //printf("[%d, %d] %d\n",L-1,H-1,st.getSum(L-1,H-1));
            //printf("%lld\n",st.getSum(L-1,H-1));
            cout << st.getSum(L-1,H-1)<< endl;
        }
        else if(R == 2){
            //scanf("%d %d %lld",&L,&H,&x);
            cin >>L >> H >> x;
            for(int j = L-1; j <= H-1; j++){
                st.xxor(j,x);
            }
        }
    }
    return 0;
}

