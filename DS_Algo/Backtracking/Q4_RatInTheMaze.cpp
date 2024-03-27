/* Q4: Rat int the maze:
	
	T(n) = WorkDone at 1 Node * Number of Nodes.
	Number of Nodes:	4^N.
	WorkDone at 1 node:	O(1).
	
	T(N)	= O(4^N).
*/

#include <iostream>
#include <vector> 

using namespace std;

bool isValid(int x, int y, vector<vector<int>> &maze) {
    int M=maze.size();
    int N=maze[0].size();

    if(x>=0 && x<M && y>=0 && y<N && maze[x][y]==1) {
        return true;
    }
    return false;
}
    
void solve(int x, int y, string &s, vector<vector<int>> &maze, vector<string> &res) {
    int M=maze.size();
    int N=maze[0].size();

    if(isValid(x, y, maze)==false)  return;

    if(isValid(x, y, maze) && x==M-1 && y==N-1) {
        res.push_back(s);
        return;
    }

    char D[4] = {'U', 'R', 'D', 'L'};
    int R[4] = {-1, 0, 1, 0};
    int C[4] = {0, 1, 0, -1};

    for(int i=0; i<4; i++) {
        int newX = x + R[i];
        int newY = y + C[i];

        if(isValid(newX, newY, maze)) {
            maze[x][y] = 0;     // marked cell as visited.
            s.push_back(D[i]);
            solve(newX, newY, s, maze, res);

            // Backtrack.
            maze[x][y] = 1;     // restore the original maze.
            s.pop_back();
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

    cout<<"All possible paths: [ ";
    for(string s:res) {
        cout<<s<<" ";
    }
    cout<<"]\nsize of res: "<<res.size()<<endl;
    return 0;
}