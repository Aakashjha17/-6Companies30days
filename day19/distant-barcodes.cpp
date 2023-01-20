class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size() == 1 || barcodes.size() == 0)
             return barcodes;
        unordered_map<int,int> mp;
        for(int i=0;i<barcodes.size();i++){
            mp[barcodes[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(pq.top().first > 0)
        {
            auto x = pq.top(); 
            pq.pop(); 
            x.first--; 
            ans.push_back(x.second);
            
            auto y = pq.top(); 
            pq.pop(); 
            
            if(y.first > 0)
            {
                ans.push_back(y.second);
                y.first--; 
            }
            pq.push(x); 
            pq.push(y);   
        }
        return ans;
    }
};
