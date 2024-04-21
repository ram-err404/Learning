// https://leetcode.com/problems/find-edges-in-shortest-paths/description/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    vector<long long> disjaktra(int start, int n, vector<vector<pair<long long, long long>>>& graph) {
        set<pair<long long, long long>> st;
        vector<long long> distance(n, 4e18);
        st.insert({0, start});
        distance[start] = 0;
        
        while(!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            // if(distance[node] != dis) {continue;}
            
            for(auto neighbore : graph[node]) {
                if(dis + neighbore.second < distance[neighbore.first]) {
                    if(distance[neighbore.first] != INT_MAX) {
                        st.erase({distance[neighbore.first], neighbore.first});
                    }
                    distance[neighbore.first] = dis+neighbore.second;
                    st.insert({dis + neighbore.second, neighbore.first});
                }
            }
        }
        return distance;
    }
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<long long, long long>>> graph(n);

        for(auto e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> d0 = disjaktra(0, n, graph);
        vector<long long> dn = disjaktra(n-1, n, graph);

        vector<bool> res;

        for(auto e : edges) {
            long long d0UV = d0[e[0]] + dn[e[1]] + e[2];
            long long d0VU = d0[e[1]] + dn[e[0]] + e[2];

            if(d0UV == d0[n-1] || d0VU == d0[n-1]) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};

int main() {
    // TC 1:  n = 6, edges = [[0,1,4],[0,2,1],[1,3,2],[1,4,3],[1,5,1],[2,3,1],[3,5,3],[4,5,2]]
    int n=6;
    vector<vector<int>> edges {{0,1,4},{0,2,1},{1,3,2},{1,4,3},{1,5,1},{2,3,1},{3,5,3},{4,5,2}};
    Solution ob;
    vector<bool> res = ob.findAnswer(n, edges);

    cout<<"[ ";
    for(bool x:res)
        cout<< boolalpha << x <<" ";
    cout<<"]";
    return 0;
}