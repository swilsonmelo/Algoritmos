#include <bits/stdc++.h>

using namespace std;


vector< vector<int> > graph;
int vis[105];

void dfs(int source, int n){
    memset(vis, 0, sizeof(vis));
    stack<int> s;
    s.push(source);
    while( !s.empty() ) {
        int v,u;
        v = s.top();
        s.pop();

        for(int i = 0; i < graph[v].size(); i++){
            u = graph[v][i];
            if( vis[u] == 0 ){
                vis[u] = 1;
                s.push(u);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        if( !vis[i]  ) res++;
    }
    printf("%d",res);

    for(int i = 0; i < n; i++){
        if( !vis[i] ) printf(" %d",i+1);
    }
    puts("");

}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    while( n ){
        //printf("n: %d\n",n);
        graph.clear();
        graph.resize(n);
        int u,v;
        scanf("%d",&u);
        while(u){
            //printf("u: %d\n",u);
            scanf("%d",&v);
            while(v){
                //printf("v: %d\n",v);
                graph[u-1].push_back(v-1);
                scanf("%d",&v);
            }
            //puts("");
            scanf("%d",&u);
        }
        //puts("");

        int m,a;
        scanf("%d",&m);
        //printf("m: %d\n",m);
        for(int i = 0; i < m; i++){
            scanf("%d",&a);
            //printf("a: %d\n",a);
            dfs(a-1,n);
        }

        //puts("");
        scanf("%d",&n);
    }

    return 0;
}
