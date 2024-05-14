#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    int m, n;
    
    bool isValid(int x, int y, vector<vector<int>>& grid) {
        if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1)
            return true;
        return false;
    }
    
    void dfs(int row, int col,
            pair<int, int>& base,
            vector<vector<int>>& grid,
            vector<vector<bool>>& vis,
            vector<pair<int, int>>& shape) {
        
        if(!isValid(row, col, grid) || vis[row][col]) 
            return;
        shape.push_back({row-base.first, col-base.second});
        vis[row][col] = true;
        
        int R[4] = {-1, 0, 1, 0};  // U, R, D, L
        int C[4] = {0, 1, 0, -1};
        for(int i=0; i<4; i++) {
            int new_r = row + R[i];
            int new_c = col + C[i];
            if(!isValid(new_r, new_c, grid) || vis[new_r][new_c])   continue;
            
            dfs(new_r, new_c, base, grid, vis, shape);
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> st; // store all the distinct shapes.
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count=0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1 && !vis[i][j]) {
                    pair<int, int> base = {i, j};
                    vector<pair<int, int>> shape;
                    
                    dfs(i, j, base, grid, vis, shape);
                    
                    if(st.find(shape) == st.end()) {
                        st.insert(shape);
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> grid {{1,1,0,1,1}, {1,0,0,0,0}, {0,0,0,0,1}, {1,1,0,1,1}};
    Solution ob;
    
    cout << ob.countDistinctIslands(grid) <<endl;
    return 0;
}