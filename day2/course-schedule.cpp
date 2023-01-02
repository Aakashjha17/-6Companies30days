class Solution {
private:
    bool dfs(int start,vector<int> path,vector<int>& vis,vector<int> adj[]){
        vis[start]=1;
        path[start]=1;

        for(auto it:adj[start]){
            if(!vis[it]){
                if(dfs(it,path,vis,adj)==true) return true;
            }else if(path[it]) return true;
        }
        path[start]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it: prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
        
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,path,vis,adj)==true) return false;
            }
        }
        return true;
    }
};
