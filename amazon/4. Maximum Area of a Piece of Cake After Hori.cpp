//1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
//https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
class Solution {
public:
    #define MOD 1000000007
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        priority_queue<int> pqh;
        priority_queue<int> pqw;
        
        int start=0;
        for(int i=0;i<hc.size();i++){
            pqh.push(hc[i]-start);
            start=hc[i];
        }
        pqh.push(h-start);
        start=0;
        for(int i=0;i<vc.size();i++){
            pqw.push(vc[i]-start);
            start=vc[i];
        }
        pqw.push(w-start);
        long long int n=pqh.top()%MOD;
        long long int m=pqw.top()%MOD; 
        return (n*m)%MOD;
        
        
    }
};