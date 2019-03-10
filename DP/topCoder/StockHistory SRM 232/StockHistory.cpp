#include <bits/stdc++.h>

using namespace std;


class StockHistory{
public:



    int maximumEarnings(int initialInvestment, int monthlyContribution, vector <string> stockPrices){

        int n;
        int nstock;
        n = stockPrices.size();
        vector<vector<int> > price;

        price = vector<vector<int> >(n, vector<int>(0));
        for(int i = 0; i < n; i++){

            int buf;
            stringstream sst(stockPrices[i]);
            while(!sst.eof()){
                sst >> buf;
                price[i].push_back(buf);
            }

        }
        nstock = price[0].size();

        double ret = 0;
        double maxGain = 1;
        for(int i = n - 2; i >= 0; i--){
            ret += (maxGain - 1) * monthlyContribution;
            for(int j = 0; j < nstock; j++){
                double tempGain = (double)price[n - 1][j] / price[i][j];
                maxGain = max(maxGain,tempGain);
            }
        }
        ret += (maxGain - 1) * initialInvestment;

        return ret;

    }

};
