class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            //mapping all the distance for evey ith element
            map<int,int> mp;
            for(int j=0;j<n;j++){
                int dist=((points[i][0]-points[j][0])*(points[i][0]-points[j][0]))+ ((points[i][1]-points[j][1]))*(points[i][1]-points[j][1]);
                mp[dist]++;
            }
            // creating map for every ith element
            for(auto it:mp){
                /*
                 * for all the groups of points, 
                 * number of ways to select 2 from n = 
                 * nP2 = n!/(n - 2)! = n * (n - 1)
                 */
                if(it.second) ans+=it.second*(it.second-1);
            }
        }
        return ans;
    }
};
