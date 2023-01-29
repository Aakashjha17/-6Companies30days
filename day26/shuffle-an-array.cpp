class Solution {
public:
    vector<int> org,shuf;
    Solution(vector<int>& nums) {
        org=shuf=nums;
    }
    
    vector<int> reset() {
        return org;
    }
    
    vector<int> shuffle() {
        int i=rand()%shuf.size();
        int j=rand()%shuf.size();
        swap(shuf[i],shuf[j]);
        return shuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
