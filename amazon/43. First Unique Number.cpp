//1429. First Unique Number
//https://leetcode.com/problems/first-unique-number/
class FirstUnique {
public:
    queue<int> q;
    unordered_map<int,int> hash;
    FirstUnique(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        if(q.empty())
            return -1;
        return q.front();
    }
    
    void add(int value) {
        q.push(value);
        hash[value]++;
        while(!q.empty()){
            if(hash[q.front()]>1)
                q.pop();
            else
                break;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */