// topologicalSort:
void topologicalSort(Graph &G, int &v, vector<bool> &visited) {
    visited[v]=true;
    cout<<v<<" ";
    
    for(auto edge:ajc[v]) {
        if(!visited[edge.endVertex])
            topologicalSort(G, edge.endVertex, visited)
    }
}

//-----------------------------------------------------------
// KMP:

void calcLPS(string &needle, vector<int> lps) {
    int len=0, i=1, n=needle.size();
    
    while(i<n) {
        if(needle[len] == needle[i]) {
            lps[i++] = ++len;
        } else if(len==0) {
            i++;
        } else {
            len = lps[len-1];
        }
    }
}

bool kmp(string &haystack, string &needle) {
    int n=needle.size();
    int m=haystack.size();
    bool found=false;
    
    vector<int> lps(n);
    lps[0]=0;
    
    calcLPS(needle, lps);
    
    int i=0, j=0;
    while(i<m) {
        if(haystack[i] == needle[j]) {
            i++; j++;
        } else {
            if(j==0)
                i++;
            else {
                j = lps[j-1];
            }
        }
        
        if(j==n) {
            cout<<"String fround from index: "<<(i-j) <<endl;
            found=true;
        }
    }
    return found;
}

// ------------------------------------------------------------------------
// Minimum subset problem:



