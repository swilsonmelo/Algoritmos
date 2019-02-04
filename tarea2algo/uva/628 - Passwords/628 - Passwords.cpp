#include <bits/stdc++.h>

using namespace std;


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,k,t;
    char cad[100];

    while(scanf("%d",&n) == 1){
        t = 0;
        vector<string> cads;
        printf("--\n");
        for(int i = 0; i < n; i++){
            scanf("%s",&cad);
            cads.push_back(cad);
            //printf("%s\n",cad);
        }

        scanf("%d",&m);
        for(int i = 0; i < m; i++){
            scanf("%s",&cad);
            for(int i = 0; i < cads.size(); i++){
                k = 10;
                t = 0;
                for(int j = 0; j < strlen(cad); j++){
                    if(cad[j] == '#'){
                        printf("%s",cads[i].c_str());
                    }
                    if(cad[j] == '0'){
                        printf("%d",0);
                        t = 1;
                    }

                }
                puts("");
                if(t) k = 1;
                for(int L = k; L < 10; L++){
                    for(int j = 0; j < strlen(cad); j++){
                        if(cad[j] == '#'){
                            printf("%s",cads[i].c_str());
                        }
                        if(cad[j] == '0'){
                            printf("%d",L);
                        }

                    }
                    puts("");

                }

            }


        }

    }

    return 0;
}
