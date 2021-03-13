//239. Sliding Window Maximum
//https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multimap<int,int> mymap;
        int n=nums.size();
        for(int i=0;i<k;i++){
            mymap.insert(make_pair(nums[i],i));
        }
        vector<int> myvec;
        myvec.push_back(mymap.rbegin()->first);
        for(int i=k;i<n;i++){
            mymap.erase(mymap.find(nums[i-k]));
            mymap.insert(make_pair(nums[i],i));
            myvec.push_back(mymap.rbegin()->first);
        }
        
        return myvec;
    }
};
///////////////////////////////////////////////////////

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<pair<int,int>> dq;
        
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && dq.front().second<i-k+1)
                dq.pop_front();
            while(!dq.empty() && dq.back().first<nums[i])
                dq.pop_back();
            dq.push_back(make_pair(nums[i],i));
            
            if(i>=k-1)
                ans.push_back(dq.front().first);
        }
        return ans;
    }
};