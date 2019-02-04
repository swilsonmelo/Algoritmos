#include<bits/stdc++.h>
#define N 1000
using namespace std;

bool used[N];
int len;
char now[N], str[N];

bool comparator(char a, char b){
	if(tolower(a) == tolower(b)){
		return a<b;
	}
	return tolower(a) < tolower(b);
}


void recu(int pos){

    if (pos == len){
        //printf("tamaño %d\n",len);
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
    while (Case--){
        scanf("%s ",&str);
        len = strlen(str);
        //printf("%s %d\n",str,len);
        for(int i = 0; i < len; i++){
            used[i] = false;
        }
        sort(str, str + len,comparator);

        recu(0);

    }

    return 0;
}
