class Solution {
public:
    int n;

    int score(vector<int>&a,vector<int>&b){
        int cnt = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] == b[i]) cnt++;
        }
        return cnt;
    }

    int solve(vector<vector<int>>&students,vector<vector<int>>& mentors,int ind,vector<int>&vis){
        if(ind == n) return 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            vis[i] = 1;
            ans = max(ans,score(students[ind],mentors[i]) + solve(students,mentors,ind+1,vis));
            vis[i] = 0;
        }
        return ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n = students.size();
        vector<int>vis(n,0);
        return solve(students,mentors,0,vis);
    }
};
