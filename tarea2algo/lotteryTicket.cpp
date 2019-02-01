#include <bits/stdc++.h>

using namespace std;

class LotteryTicket {
public:
  string buy(int, int, int, int, int);
};


int bills[5];


bool solve(int pos,int sum,int price){
	if( sum == price ){
		return true;
	}else if( pos == -1 ){
		return false;
	}else{
		bool res1 = solve(pos-1,sum,price );
		bool res2 = solve(pos-1,sum+bills[pos],price);
		return res1 || res2;
	}
}



string LotteryTicket::buy(int price , int b1, int b2, int b3, int b4){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	bills[0] = b1;
	bills[1] = b2;
	bills[2] = b3;
	bills[3] = b4;

	bool res = solve(4,0,price);
	if(res){
		return "POSSIBLE";
	}else{
		return "IMPOSSIBLE";
	}


}


int main(){
	LotteryTicket *lt;
	string res = lt->buy(1000, 999, 998, 997, 996);
	cout << res;
}



