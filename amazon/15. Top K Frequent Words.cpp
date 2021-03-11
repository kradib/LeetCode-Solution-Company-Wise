//692. Top K Frequent Words
//https://leetcode.com/problems/top-k-frequent-words/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mymap;
        for(auto it: words){
            mymap[it]++;
        }
        
        auto func=[](pair<string, int> &a, pair<string,int> &b){
            if(a.second<b.second)
                return false;
            else if(a.second>b.second)
                return true;
            else{
                return a.first<b.first;
            }
        };
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(func)> pq(func);
        
        for(auto &[key,val]:mymap){
            //cout<<key<<" "<<val<<endl;
            if(pq.size()<k){
                pq.push(make_pair(key,val));
            }
            else{
                //cout<<"pq top is "<<pq.top().second<<" "<<pq.top().first<<endl;;  
                if(val>pq.top().second){
                    pq.pop();
                    pq.push(make_pair(key,val));
                }
                else if(val==pq.top().second && key<pq.top().first){
                    pq.pop();
                    pq.push(make_pair(key,val));
                }
            }
        }
        
        vector<string> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};