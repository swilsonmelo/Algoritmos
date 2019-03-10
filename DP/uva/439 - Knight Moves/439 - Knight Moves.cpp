#include <bits/stdc++.h>

using namespace std;

int dx[]={ 1, 1,-1,-1, 2, 2,-2,-2};
int dy[]={ 2,-2, 2,-2, 1,-1, 1,-1};

struct node{
    int x;
    int y;
    node(int a, int b){
        x = a;
        y = b;
    }

};

int bfs(node source, node target){
    int step[9][9] = {0};
    queue<node> q;
    q.push(source);
    while(!q.empty()){
        node u = q.front();
        q.pop();
        //printf("%d %d %d\n",u.x, u.y, u.cost);
        if( u.x == target.x && u.y == target.y ) return step[u.x][u.y];

        for(int i = 0 ;i < 8; i++){
            int a = u.x + dx[i];
            int b = u.y + dy[i];
            if( a >= 1 && b >= 1 && a <= 8 && b <= 8){
                q.push(node(a, b));
                step[a][b] = step[u.x][u.y] + 1;
            }

        }

    }

}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string s1,s2;
    int x1,y1,x2,y2;
    while(cin>>s1>>s2){
        x1=s1[0]-'a'+1;
        y1=s1[1]-'0';
        x2=s2[0]-'a'+1;
        y2=s2[1]-'0';
        node n1 = node(x1, y1);
        node n2 = node(x2, y2);
        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<bfs(n1, n2)<<" knight moves."<<endl;
    }//To get from e2 to e4 takes 2 knight moves.

    return 0;
}
