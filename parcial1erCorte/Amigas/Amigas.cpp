
#include <bits/stdc++.h>


using namespace std;



int friends( string w1, string w2){

    map<char,char> vis;
    map<char,int> isUsed;
    if( w1.length() != w2.length() ) return 0; //En el parcial puse strlen(w1), que trollllllll jajajajajaja

    //printf("%c %c\n",w1[0].w2[0]);
    /*
    AGGGHHHHH no compila por lo del w1[1], no sabia que no podía acceder de esa manera a las cadenas
    Este seria el código.......
    for(int i = 0; i < w1.length(); i++){
        if(w1[i] != w2[i]){
            if(vis.find(w1[i]) == vis.end()){
                vis[w1[i]] = w1[i];
            }
            if(vis[w1[i]] != w2[i] && (isUsed[w1[i]] != isUsed.end()) ) {
                return 0;
            }else{
                vis[w1[i]] = w2[i];
                isUsed[w1[i]] = 1;
            }
        }else{
             if(vis.find(w1[i]) == vis.end()){
                vis[w1[i]] = w1[i];
                isUsed[w1[i]] = 1;
             }else{
                if(vis[w1[i]] != w2[i]){
                    return 0;
                }else{
                    isUsed[w1[i]] = 1;
                }
             }

        }

    }*/
    return 1;

}


int solve(vector<string> words){
    int res = 0;
    for(int i = 0; i < words.size()-1; i++){
        for( int j = i+1; j < words.size(); j++){
            if(friends(words[i],words[j])) res++;
        }
    }
    return res;
}

int main(){
    int n;
    n = 3;
    string myVec[] = {
    "abca",
    "zbxz",
    "opqr"
    };


    vector<string> words;
    for(int i = 0; i < n; i++){
        words.push_back(myVec[i]);
    }
    int res = solve(words);
    printf("%d\n",res);

    return 0;
}
