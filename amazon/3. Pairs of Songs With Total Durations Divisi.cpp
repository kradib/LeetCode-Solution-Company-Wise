//1010. Pairs of Songs With Total Durations Divisible by 60
//https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int freqs[60] = {0}, res = 0;
        
        for (auto t: time) 
            freqs[t % 60]++;
        
        for (int i = 1; i < 30; i++) 
            res += freqs[i] * freqs[60 - i];
        
        res += freqs[0] * (freqs[0] - 1) / 2 + freqs[30] * (freqs[30] - 1) / 2;
        return res;
    }
};