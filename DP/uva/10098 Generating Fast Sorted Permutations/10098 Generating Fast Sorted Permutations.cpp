#include<bits/stdc++.h>
#define N 12
using namespace std;

bool used[N];
int len;
char now[N], str[N];

void recu(int pos){

    if (pos == len){
        printf("%c",now[0]);
        for(int i = 1; i < len; i++) printf("%c",now[i]);
        puts("");
        now[pos] = '\0';
        //puts(now);*/
    }
    else
    {
        char last = '\0';
        for (int i = 0; i < len; i++){
            if (!used[i] && str[i] != last){
                used[i] = true;
                now[pos] = str[i];
                last = str[i];

                recu(pos + 1);
                used[i] = false;
            }

        }
    }

}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int Case;
    scanf("%d", &Case);
    getchar();
    while (Case--){
        gets(str);
        len = strlen(str);
        for(int i = 0; i < len; i++){
            used[i] = false;
        }

        sort(str, str + len);

        recu(0);
        puts("");
    }

    return 0;
}
