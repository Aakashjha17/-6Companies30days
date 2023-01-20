struct Compare {
    bool operator() (pair<string, int> a, pair<string, int> b) {

        // frequencies equal so sort reverse alphabetically
        if(a.second == b.second)
            return a.first > b.first;

        // sort by frequency
        else
            return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // build frequency map of words
        unordered_map<string, int> mp;
        for(auto& word : words) mp[word]++;

        // make priority queue of word and frequency
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        for(auto& p : mp) pq.push({p.first, p.second});

        // find k most frequent words
        vector<string> ret;
        while(k--){
            ret.push_back(pq.top().first);
            pq.pop();
        }

        return ret;
    }
};
