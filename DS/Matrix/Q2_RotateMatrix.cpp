// https://leetcode.com/problems/rotate-image/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /* Idea here is to transpose the matrix and then reverse each row.*/
        int m=matrix.size();
        
        // Transpose of the matrix.
        for(int i=0; i<m; i++) {
            for(int j=0; j<=i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Now reverse each row.
        for(int i=0; i<m; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    vector<vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution ob;
    ob.rotate(matrix);

    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            cout<< matrix[i][j] <<" ";
        }
        cout<<"\n";
    }
    return 0;
}