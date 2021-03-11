//1710. Maximum Units on a Truck
//https://leetcode.com/problems/maximum-units-on-a-truck/solution/
class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int truckSize) {
        multimap<int,int> mymap;
        for(auto it: b){
            mymap.insert(make_pair(it[1],it[0]));
        }
        int count=0;
        for(auto ij=mymap.rbegin();ij!=mymap.rend();ij++){
            int deduct=min(ij->second,truckSize);
            count+=ij->first*deduct;
            truckSize-=deduct;
            if(truckSize==0)
                break;
        }
        return count;
    }
};