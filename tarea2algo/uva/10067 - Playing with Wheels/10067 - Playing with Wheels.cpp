#include <bits/stdc++.h>

#define maxN 10000
using namespace std;
int change[8][4] = {{1,0,0,0},{-1,0,0,0},{0,1,0,0},{0,-1,0,0},{0,0,1,0},{0,0,-1,0},{0,0,0,1},{0,0,0,-1}};

string Start, End;
map<string, int> Index;

int BFS() {
   if (Start==End) return 0;

   if (Index[End]==-1) return -1;

   queue<string> Q;

   queue<int> Qidx;
   Q.push(Start); Qidx.push(1);

   while (!Q.empty()) {
      string u = Q.front(); Q.pop();
      int idxu = Qidx.front(); Qidx.pop();

      for (int k = 0; k < 8; k++) {
         string v = u;
         for (int i=0; i<4; i++) {
            v[i] += change[k][i];
            if (v[i]<'0') v[i] = '9';
            else if (v[i]>'9') v[i] = '0';
         }
         int idx = Index[v];
         if (idx!=0) continue;
         if (v==End) return idxu;
         idx = Index[v] = idxu + 1;
         Q.push(v); Qidx.push(idx);
      }
   }
   return -1;
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int Case, val, m;
   scanf("%d", &Case);
   while (Case--) {
      Start = End = ""; Index.clear();
      for (int i=0; i<4; i++) {
         scanf("%d", &val); Start += val+48;
      }
      for (int i=0; i<4; i++) {
         scanf("%d", &val); End += val+48;
      }
      scanf("%d", &m);
      while (m--) {
         string tmp = "";
         for (int i=0; i<4; i++) {
            scanf("%d", &val); tmp += val+48;
         }
         Index[tmp] = -1;
      }
      Index[Start]=1;
      printf("%d\n", BFS());
   }
}
