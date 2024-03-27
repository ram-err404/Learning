// https://leetcode.com/problems/spiral-matrix/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int top=0, left=0, right=n-1, bottom=m-1;

        while(top<=bottom && left<=right) {
            // move from left tp right. (from top)
            for(int i=left; i<=right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            // move from top to bottom. (from right)
            for(int i=top; i<=bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            // move from right to left. (from bottom)
            if(top<=bottom) {
                for(int i=right; i>=left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // move from bottom to top. (from left)
            if(left<=right) {    
                for(int i=bottom; i>=top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution ob;
    vector<int> res = ob.spiralOrder(matrix);

    cout<<"Matrix in spiral order: [ ";
    for(int x:res) {
        cout<< x <<" ";
    }
    cout<<" ]"<<endl;
    return 0;
}