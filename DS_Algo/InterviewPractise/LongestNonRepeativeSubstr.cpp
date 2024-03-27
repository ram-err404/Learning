#include<iostream>
#include<string>
#include<set>
using namespace std;

int longestSubstringLen(string &str) {
    set<char>   s;
    int count=0;
    int mx=0;
    
    for(int i=0; i<str.size(); i++) {
        if(s.find(str[i]) == s.end()) {
            s.insert(str[i]);
            count++;
            
            if(count>mx)    mx=count;
        } else {
            count=0;
            s.clear();
        }
    }
    return count;
}

int main() {
    string str="pwwkew";
    
    cout<<"Length of Longest Substring without repeating chars: "<< longestSubstringLen(str) <<endl;
    return 0;
}