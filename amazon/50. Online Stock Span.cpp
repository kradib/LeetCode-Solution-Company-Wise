//901. Online Stock Span
//https://leetcode.com/problems/online-stock-span/
class StockSpanner {
public:
    
    stack<int> weight;
    stack<int> prices;
    StockSpanner() {
        
    }
    
    
    
    int next(int price) {
        int ans=1;
        while(!prices.empty() && prices.top()<=price){
            prices.pop();
            ans+=weight.top();
            weight.pop();
        }
            
        prices.push(price);
        weight.push(ans);
        
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */