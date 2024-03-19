// https://leetcode.com/problems/detonate-the-maximum-bombs/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

#define ll long long int

class Solution {
private:
    ll distance(ll x2, ll x1, ll y2, ll y1) {
        ll dx = abs(x2-x1);
        ll dy = abs(y2-y1);
        return (dx*dx + dy*dy);
    }
    void dfs(int start, vector<vector<int>> &adj, vector<bool> &vis, int &count) {
        vis[start] = true;
        count++;

        for(int v : adj[start]) {
            if(!vis[v]) {
                dfs(v, adj, vis, count);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int V = bombs.size();
        vector<vector<int>> adj(V);

        for(int i=0; i<V; i++) {
            ll r1 = bombs[i][2];
            for(int j=0; j<V; j++) {
                if(i != j) {
                    ll dis = distance(bombs[j][0], bombs[i][0], bombs[j][1], bombs[i][1]);
                    if(dis <= r1*r1) {
                        adj[i].push_back(j);
                    }
                }
            }
        }   // Now our graph is ready.

        // Now we can apply BFS/DFS here.
        int ans=INT_MIN;
        for(int i=0; i<V; i++) {
            int count=0;
            vector<bool> vis(V, false);
            dfs(i, adj, vis, count);
            ans = max(ans, count);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> bombs = {{1,2,3}, {2,3,1}, {3,4,2}, {4,5,3}, {5,6,4}};
    Solution ob;
    
    cout<<"Maximmu number of bombs canbe detanated: "<< ob.maximumDetonation(bombs) <<endl;
    return 0;
}