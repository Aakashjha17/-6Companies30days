vector<int> ans;
        for(auto it: queries){
            priority_queue<pair<string,int>> pq;
            for(int i=0;i<nums.size();i++){
                int t=nums[i].length()-it[1];
                string p=nums[i].substr(t,it[1]);
                if(pq.size()<it[0]){
                    pq.push({p,i});
                }else{
                    if(pq.top().first>p){
                        pq.pop();
                        pq.push({p,i});
                    }
                }
            }
            int val=pq.top().second;
            ans.push_back(val);
        }
        return ans;
