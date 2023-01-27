class Solution {
    vector<int> v;
public:
    Solution(vector<int>& w) {
        v.push_back(w[0]);
        for(int i=1;i<w.size();i++)v.push_back(v.back()+w[i]);
    }
    
    int pickIndex() {
        int rand_weight = rand()%(v.back());
        return upper_bound(v.begin(),v.end(),rand_weight)-v.begin();
    }
};
