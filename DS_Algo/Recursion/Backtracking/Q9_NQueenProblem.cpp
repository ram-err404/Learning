#include <iostream>
#include <vector>

using namespace std;

vector<int> leftCol(30, 0);
vector<int> lUpperDaigonal(30, 0);
vector<int> lLowerDaigonal(30, 0);

class Solution{
private:
#if 0
    bool isSafe(int row, int col, vector<vector<char>>& board) {
        // we know if I'm at a column (say 3), Then I don't need to any column after three as 
        // I haven't placed any Queen there. So I only need to check on the left side if queen
        // is present there or not. (i.e. leftRow, leftUpperDaigonal, leftLowerDaigonal)
        int dupRow=row, dupCol=col;

        // left row
        while(col>=0) {
            if(board[row][col--]=='Q')
                return false;
        }
        // left Upper Daigonal.
        row=dupRow; col=dupCol;
        while(row>=0 && col>=0) {
            if(board[row--][col--]=='Q')
                return false;
        }
        // left lower Daigonal
        row=dupRow; col=dupCol;
        while(col>=0 && row<board.size()) {
            if(board[row++][col--]=='Q')
                return false;
        }
        return true;
    }
#endif
    int solve(int col, vector<vector<char>>& board) {
        int N=board.size();
        if(col>=N)   return true;
        for(int row=0; row<N; row++) {
            // if(isSafe(row, col, board)) {
                // A better approach is to store the leftColumn, leftUpperDaigonal and leftLowerDaigonal.
            if(leftCol[row]!=1 && lUpperDaigonal[row-col+N-1]!=1 && lLowerDaigonal[row+col]!=1) {
                // With this if check we can actually save 3 (N-size) iterations.
                // we can place our Queen here.
                leftCol[row] = lUpperDaigonal[row-col+N-1] = lLowerDaigonal[row+col] = 1;
                board[row][col] = 'Q';
                if(solve(col+1, board)) {
                    return true;
                }
                board[row][col] = '.';
                leftCol[row] = lUpperDaigonal[row-col+N-1] = lLowerDaigonal[row+col] = 0;
            }
        }
        return false;
    }
public:
    bool placeNQueen(vector<vector<char>>& board) {
        int n = board.size();

        return solve(0, board);
    }
};

void print_board(vector<vector<char>>& board) {
    for(int row=0; row<board.size(); row++) {
        for(int col=0; col<board[0].size(); col++) {
            cout<< board[row][col] <<" ";
        }
        cout<<"\n";
    }
    cout<< endl;
}

int main() {
    int n=4;    // Solution is not possible for n=3
    vector<vector<char>> board(n, vector<char>(n, '.'));

    Solution ob;
    
    if(ob.placeNQueen(board)) {
        // print board now.
        print_board(board);
    } else {
        cout<< "Solution Not Possible" <<endl;
    }

    return 0;
}