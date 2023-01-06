// Use Dijkstra to find the shortest amount of time.
// Use DP to keep states of shortest time fo a node.
// while finding shortest time
// when we find a shorter time we change dp by new value.
// when we find equal time we add value to current node's dp.

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> adj(n+1);
        //creating adjencency list
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        long long inf=1e15;
        long long mod=1e9+7;
        //min heap :-priority_queue <Type, vector<Type>, ComparisonType > min_heap;
        priority_queue<pair<long long ,long long>,vector<pair<long long ,long long>>,greater<pair<long long ,long long >>> pq;

        vector<long long> dist(n+1,inf);
        // keep states of shortest time fo a node
        vector<long long> dp(n+1,0);
        pq.push({0,0});
        dp[0]=1;
        dist[0]=0;
        
        while(!pq.empty()){
            long long node=pq.top().second;
            long long weight=pq.top().first;
            pq.pop();

            if(dist[node]<weight) continue;
            for(auto it:adj[node]){
                long long adjNode=it.first;
                long long edgeWeight=it.second;

                if(weight+edgeWeight==dist[adjNode]){
                    dp[adjNode]=(dp[adjNode]+dp[node])%mod;
                }
                if(weight+edgeWeight<dist[adjNode]){
                    dist[adjNode]=weight+edgeWeight;
                    dp[adjNode]=dp[node]%mod;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dp[n-1];
    }
};
