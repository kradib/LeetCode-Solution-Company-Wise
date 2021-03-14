//121. Best Time to Buy and Sell Stock
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2)
            return 0;
            
        
        int max=prices[1]-prices[0];
        int min=prices[0];
        
        for(int i=1;i<n;i++){
            if(prices[i]-min>max)
                max=prices[i]-min;
            if(prices[i]<min)
                min=prices[i];
        }
        if(max<0)
            return 0;
        return max;
    }
};