// https://leetcode.com/problems/word-search/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(int x, int y, vector<vector<char>> &board, int idx, string &word) {
        int m = board.size();
        int n = board[0].size();
        
        if(idx == word.size())   return true;
        if(x<0 || x>=m || y<0 || y>=n || word[idx] != board[x][y])  return false;

        
        char ch = board[x][y];
        board[x][y] = '#';
        
        int R[4] = {1, 0, -1, 0};    // D, R, U, L
        int C[4] = {0, 1, 0, -1};

        bool ans = false;
        for(int i=0; i<4; i++) {
            int newX = x + R[i];
            int newY = y + C[i];
            ans = ans || dfs(newX, newY, board, idx+1, word);
        }
        board[x][y] = ch;   // backtrack.
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, board, 0, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";

    Solution ob;
    
    if(ob.exist(board, word)) {
        cout<<"Word exists in the board"<<endl;
    } else {
        cout<<"Word do not exists in the board"<<endl;
    }
    return 0;
}