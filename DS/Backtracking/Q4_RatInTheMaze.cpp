/* Q4: Rat int the maze:
	
	T(n) = WorkDone at 1 Node * Number of Nodes.
	Number of Nodes:	4^N.
	WorkDone at 1 node:	O(1).
	
	T(N)	= O(4^N).
*/
#include <iostream>
#include <vector> 

using namespace std;

void solve(int x, int y, string &s, vector<vector<int>> &maze, vector<string> &res) {
    int M=maze.size();
    int N=maze[0].size();
    // Base case:
    if(x<0 || y<0 || maze[x][y]==0) return;
    
    if(x==M-1 && y==N-1 && maze[x][y]==1) {
        res.push_back(s);
        return;
    }
    
    // Now here we can move to 4 direction [Up, Right, Down, Left].
    char D[4] = {'U', 'R', 'D', 'L'};
    int R[4] = {-1, 0, 1, 0};   // Row's movement.
    int C[4] = {0, 1, 0, -1};   // Col's movement.
    
    for(int i=0; i<4; i++) {
        int newx = x + R[i];
        int newy = y + C[i];
        if(newx>=x && newy>=y && newx<M && newy<N && maze[newx][newy]==1) {
            s.push_back(D[i]);     // Add the moved direction to the string.
            
            solve(newx, newy, s, maze, res);
            
            s.pop_back();   // Backtracking.
        }
    }
}

vector<string> ratInMaze(vector<vector<int>> &maze) {
    vector<string> res;
    
    string s="";   // Here I will apply my backtracking.
    
    solve(0, 0, s, maze, res);
    
    return res;
}

int main() {
    vector<vector<int>> maze{{1,0,0,1,0}, {1,1,0,1,1}, {1,1,1,0,0}, {0,1,1,1,1}};

    vector<string> res = ratInMaze(maze);

    cout<<"All possible paths: [";
    for(string s:res) {
        cout<<s<<", ";
    }
    cout<<"]\nsize of res: "<<res.size()<<endl;
    return 0;
}