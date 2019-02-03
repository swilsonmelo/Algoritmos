#include<bits/stdc++.h>

using namespace std;



long long iterate(long long a,long long b,long long cur, int canBad) {
        if (cur > b) return 0;
        long res =  0;
        if (cur >= a) ++res;
        res += iterate(a, b, cur * 10 + 4, canBad);
        res += iterate(a, b, cur * 10 + 7, canBad);
        if (canBad) {
            for (int i = 0; i < 10; ++i) {
                if (i == 0 && cur == 0) continue;
                if (i == 4 || i == 7) continue;
                res += iterate(a, b, cur * 10 + i, 0);
            }
        }

        return res;
}


class TheAlmostLuckyNumbersDivOne {
public:
	long long find(long long a, long long b) {
		return iterate(a, b, 0, 1);
	}
};



<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

int main(){
    TheAlmostLuckyNumbersDivOne *taln;
    long long a = 8;
    long long b = 19;
    long res = taln->find(a,b);
    printf("%ld\n",res);
    return 0;
}

