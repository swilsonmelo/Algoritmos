
#include <bits/stdc++.h>


using namespace std;

/*
IsomorphicWords  top coder srm 391

*/


int friends( string w1, string w2){

    map<char,char> vis;
    map<char,int> isUsed;
    vis.clear();
    isUsed.clear();
    if( w1.length() != w2.length() ) return 0; //En el parcial puse strlen(w1), que trollllllll jajajajajaja

    for(int i = 0; i < w1.length(); i++){
        if( vis.find(w1[i]) == vis.end() && (isUsed.find(w2[i]) == isUsed.end()) ){
            vis[w1[i]] = w2[i];
            isUsed[w2[i]] = 1;
        }else if(vis[w1[i]] != w2[i] ) {
            return 0;
        }
    }
    return 1;

}


int solve(vector<string> words){
    int res = 0;
    for(int i = 0; i < words.size()-1; i++){
        for( int j = i+1; j < words.size(); j++){
            if(friends(words[i],words[j])){
                res++;
                //printf("%s %s\n",words[i].c_str(),words[j].c_str());
            }
        }
    }
    return res;
}

int main(){
    int n;

    n = 12;
    string myVec[] = {
     "cacccdaabc"
    ,"cdcccaddbc"
    ,"dcdddbccad"
    ,"bdbbbaddcb"
    ,"bdbcadbbdc"
    ,"abaadcbbda"
    ,"babcdabbac"
    ,"cacdbaccad"
    ,"dcddabccad"
    ,"cacccbaadb"
    ,"bbcdcbcbdd"
    ,"bcbadcbbca"

    };

    /*
    n = 5;
    string myVec[] = {
    "aa",
    "ab",
    "bb",
    "cc",
    "cd"
    };
    */


    vector<string> words;
    for(int i = 0; i < n; i++){
        words.push_back(myVec[i]);
    }
    int res = solve(words);
    printf("%d\n",res);

    return 0;
}
