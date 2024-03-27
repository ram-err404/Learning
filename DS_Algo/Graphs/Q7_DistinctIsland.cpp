// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

// Number of Distinct Islands:

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
private:
    set<vector<pair<int, int>>> st;
    
    bool isValid(int x, int y, vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(x>=0 && x<m && y>=0 && y<n)  return true;
        return false;
    }

    void dfs(int x, int y, int baseX, int baseY, vector<vector<int>> &grid, vector<pair<int, int>> &temp) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(!isValid(x, y, grid))    return;
        
        grid[x][y] = 0;
        temp.push_back({x-baseX, y-baseY});
        
        int R[4] = {1, 0, -1, 0};   // D, R, U, L
        int C[4] = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++) {
            int newX = x + R[i];
            int newY = y + C[i];
            
            if(isValid(newX, newY, grid) && grid[newX][newY]==1) {
                dfs(newX, newY, baseX, baseY, grid, temp);
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> notVis = grid;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(notVis[i][j] == 1) {
                    vector<pair<int, int>> temp;
                    
                    dfs(i, j, i, j, notVis, temp);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};

int main() {

  vector<vector<int>> grid{
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}};
            
  Solution obj;
  cout << obj.countDistinctIslands(grid) << endl;

}