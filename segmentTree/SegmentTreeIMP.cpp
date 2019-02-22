#include <bits/stdc++.h>
#define INF 1<<30

using namespace std;

struct SegmentTree {
    int start, end;
    SegmentTree *leftTree, *rightTree;
    int minValue;

    SegmentTree(int start, int end) {
        this->start = start;
        this->end = end;
        this->minValue = INF;
        if(start == end) {  // es una hoja
            leftTree = rightTree = NULL;
            return;
        }
        int mid = (start + end) / 2;
        leftTree = new SegmentTree(start, mid);
        rightTree = new SegmentTree(mid + 1, end);
    }

    void set(int pos, int value) {
        // es una hoja, CASO BASE
        if(start == end) {
            minValue = value;
            return;
        }

        int mid = (start + end) / 2;

        if(pos <= mid)
            leftTree->set(pos, value);
        else
            rightTree->set(pos, value);

        minValue = min(leftTree->minValue, rightTree->minValue);
    }

    int getMin(int low, int high) {
        // [low,high] = [start,end]
        if(start == low && end == high)
            return minValue;

        int mid = (start + end) / 2;

        // [low,high] totalmente incluido en [start,mid]
        if(high <= mid)
            return leftTree->getMin(low, high);

        // [low,high] totalmente incluido en [mid+1,end]
        if(low > mid)
            return rightTree->getMin(low, high);

        // debemos dividir el intervalo en [low,mid] y [mid+1,high]
        int leftMin = leftTree->getMin(low, mid);
        int rightMin = rightTree->getMin(mid+1, high);
        return min(leftMin, rightMin);
    }

};

int main() {
    SegmentTree st(0, 8);  // 9 numeros
    // asigno el arreglo {-20, 19, 7, 4, -10, 5, 100, 1, 3}

    int initialValues[9] = {-20, 19, 7, 4, -10, 5, 100, 1, 3};
    for(int i = 0; i < 9; i++)
        st.set(i, initialValues[i]);

    printf("min in [0,8]: %d\n", st.getMin(0, 8));
    printf("min in [1,7]: %d\n", st.getMin(1, 7));
    printf("min in [5,5]: %d\n", st.getMin(5, 5));
    st.set(0, 8);
    printf("min in [0,8]: %d\n", st.getMin(0, 8));

    return 0;
}

