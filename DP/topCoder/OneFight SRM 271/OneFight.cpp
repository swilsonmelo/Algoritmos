#include <bits/stdc++.h>
#define INF 1<<30

using namespace std;

class OneFight{
public:
    int res;

    int isOn(int b, int mask){
        if( ((1<<b)&mask) != 0 ) return 1;
        return 0;
    }

    void turnOn(int b, int& mask){
        mask |= 1<<(b);
    }

    void turnOff(int b, int& mask){
        mask &= ~(1<<(b));
    }

    void solve(vector<int> life, vector<int> damage, int yourDamage, int mask, int sofar){
        int done = 1;
        int totalDamage = 0;
        for(int i = 0; i < life.size(); i++){
            if( !isOn(i,mask)){
                done = 0;
                totalDamage += damage[i];
            }
        }

        if(done){
            res = min(res,sofar);
        }else{
            for(int i = 0; i < life.size(); i++){
                if( !isOn(i,mask) ){
                    turnOn(i,mask);
                    solve(life, damage, yourDamage, mask, sofar + totalDamage*((life[i]+yourDamage-1)/yourDamage));
                    turnOff(i,mask);
                }
            }
        }

    }

    int monsterKilling(vector<int> life, vector <int> damage, int yourDamage){
        res = INF;
        int useMask = 0;
        solve(life, damage, yourDamage, useMask, 0);
        return res+1;
    }
};


