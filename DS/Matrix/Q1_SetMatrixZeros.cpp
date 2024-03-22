// https://leetcode.com/problems/set-matrix-zeroes/

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            // set all the row's with same col to 0.
            for(int i=0; i<m; i++) {
                matrix[i][c] = 0;
            }
            // set all the col's with same row to 0.
            for(int j=0; j<n; j++) {
                matrix[r][j] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int m = matrix.size();
    int n = matrix[0].size();
    Solution ob;
    ob.setZeroes(matrix);

    cout<<"Matrix After setting all the corresponding row and col of 0 to 0:"<<endl;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<< matrix[i][j] <<" ";
        }
        cout<<"\n";
    }
    return 0;
}