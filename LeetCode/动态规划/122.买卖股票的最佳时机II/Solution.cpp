/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/



#include<vector>
using namespace std;

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxProfit = 0;
        while(i < prices.size() - 1) {
            //找到波谷
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            //找到波峰
            while(i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxProfit += peak - valley;
        }
        return maxProfit;
    }
};


class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i - 1])
            maxProfit += prices[i] - prices[i - 1]; 
        }
        return maxProfit;
    }
};