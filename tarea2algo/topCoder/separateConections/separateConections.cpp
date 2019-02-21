#include <bits/stdc++.h>

/*
Accepted
*/

using namespace std;


int mat[19][19];
int mask[19][1<<19];
int size;

class SeparateConnections {
public:
   int howMany(vector <string>);
};

int search(int node, int nMask) {

    if (node >= size) return 0;
    if (mask[node][nMask] != -1) return mask[node][nMask];
    int res = 0;
    if (!(nMask & (1 << node))) {
        for (int i = node+1; i < size; i++) {
            if (nMask & (1 << i)) continue;
            if (mat[node][i] == 0) continue;
            res = max(res,1 + search( node + 1, nMask | (1 << i)));
        }
    }
    res = max(res,search( node + 1, nMask));
    mask[node][nMask] = res;
    return res;
}

int SeparateConnections::howMany(vector<string> matAdj) {
    memset(mat,0,sizeof(mat));//si me quedó mal el memset :v
    memset(mask,-1,sizeof(mask));
    for (int i = 0; i < matAdj.size(); i++) {
        for (int j = 0; j < matAdj.size(); j++) {
            if (matAdj[i][j] == 'Y'){
                mat[i][j] = 1;
            }
        }
    }
    size = matAdj.size();

    return search(0,0) * 2;
}
/*
int main(){
    int n;

    n = 18;
    string myVec[] = {
    "NNYYYYYYYYYYYYYYYY",
    "NNYYYYYYYYYYYYYYYY",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN",
    "YYNNNNNNNNNNNNNNNN"
    };

    n = 5;
    string myVec[] = {
    "NYYYY",
    "YNNNN",
    "YNNNY",
    "YNNNY",
    "YNYYN"
    };
    vector<string> matAdj;
    for(int i = 0; i < n; i++){
        matAdj.push_back(myVec[i]);
    }
    int res = solve(matAdj);
    printf("%d",res);
    return 0;
}
*/
