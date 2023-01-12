// Constraints are really small and brute force works, yet, its the implementation that really hard to understand.
// So what I did was first creating a priority queue (max-heap) and inserting all the single grid values into it (in case rhombus of size 1 is biggest). Now take 3 counters->
// k = height of the rhombus (which shall be limited to either of the dimensions)
// i = row counter
// j = col counter
// Now, x helps us in traversing the rhombus, Given that the current point is our
// This is the starting state of the rhombus:
// Upper vertex at (i,j+k)
// Left vertex at (i+k, j)
// Right vertex at (i+k, j+2 * k)
// Lower vertex at (i+2 * k, j+k)
// Traversing in 4 direction and increment the sum.
// Push sum values in pq and atlast insert those values into a vector, while checking for duplicates and return vector

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int> pq;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                pq.push(grid[i][j]);
        }
        for(int k=1; k<min(m, n); k++) //the height of the rhombus
        {
            for(int i=0; i+2*k<m; i++)
            {
                for(int j=0; j+2*k<n;j++)
                {
                    int sum=0;
                    for(int x=0; x<k; x++)
                    {
                        sum+=grid[i+k-x][j+x]; //left to up
                        sum+=grid[i+x][j+k+x]; //top to right
                        sum+=grid[i+k+x][j+2*k-x]; //right to down
                        sum+=grid[i+2*k-x][j+k-x]; //bottom to left
                    }
                    pq.push(sum);
                }
            }
        }
        vector<int> ret;
        while(!pq.empty())
        {
            if(ret.empty()||ret.back()!=pq.top()) //for distinct values
                ret.push_back(pq.top());
            if(ret.size()==3)
                return ret;
            pq.pop();
        }
        return ret;
    }
};
