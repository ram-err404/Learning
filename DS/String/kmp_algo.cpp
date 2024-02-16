#include <iostream>
using namespace std;

void calLPS(string &needle, int *lps, int n) {
    int len=0, i=1;

    while(i<n) {
        if(needle[len]==needle[i])
            lps[i++] = ++len;
        else if(len == 0)
            lps[i++] = 0;
        else
            len = lps[len-1];
    }
}

void kmp_search(string &haystack, string &needle) {
    int m=haystack.size();
    int n=needle.size();

    int lps[n]={0};
    calLPS(needle, lps, n);

    int i=0, j=0;   // i for haystack and j for needle.
    while(i<m) {
        if(haystack[i] == needle[j]) {
            i++; j++;
        } else {
            if(j==0)
                i++;
            else
                j=lps[j-1];
        }
        if(j==n)
            cout<<"Found at index: "<<(i-n)<<endl;
    }
}

int main() {
    string haystack="AAAXAAAAA";
    string needle="AAAA";

    kmp_search(haystack, needle);

    return 0;
}