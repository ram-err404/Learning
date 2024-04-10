/* Q3: N digit number with digits in the increasing order.
	
	T(N) = WorkDone * Number of Nodes
	Number of Nodes = 9^N.
	WorkDone at 1 Node = O(1).
	
	T(N) = O(9^N)
*/

#include <iostream>
#include <vector>

using namespace std;

void solve(int N, vector<int> &v, vector<int> &res) {
    if(N==0) {
        int ans=0;
        for(int i=0; i<v.size(); i++) {
            ans = ans*10 + v[i];
        }
        res.push_back(ans);
        return;
    }
    
    for(int i=1; i<=9; i++) {
        if(v.size()==0 || i > v[v.size()-1]) {
            v.push_back(i);
            
            solve(N-1, v, res);
            v.pop_back();
        }
    }
}
    
vector<int> increasingNumbers(int N)
{
    // Write Your Code here
    vector<int> res;
    vector<int> v;
    
    if(N==1) {
        for(int i=0; i<=9; i++) {
            res.push_back(i);
        }
        return res;
    }
    
    solve(N, v, res);
    return res;
}
    
int main() {
    int N=5;    // res size will increases till 5. (4, 5 will have same size) and then further will start decreasing.
    
    vector<int> res = increasingNumbers(N);
    
    for(int i=0; i<res.size(); i++) {
        cout<< res[i] <<" ";
    }
    cout<<"\nSize of the res array: "<<res.size()<<endl;
    return 0;
}