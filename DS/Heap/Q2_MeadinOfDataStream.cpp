// https://leetcode.com/problems/find-median-from-data-stream/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
    /*  Top of max heap will be the highest among all the numbers.
        Top of min heap will be the lowest among all the numbers.
    */
    priority_queue<int, vector<int>, greater<int>> highNumbers;     // min heap
    priority_queue<int> lowNumbers;     // max heap
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
/*
When adding a new number num into our MedianFinder:
--> Firstly, add num to the maxHeap, now maxHeap may contain the big element (which should belong to minHeap). So we need to balance, by removing the highest element from maxHeap, and offer it to minHeap.
--> Now, the minHeap might hold more elements than maxHeap, in that case, we need to balance the size, by removing the lowest element from minHeap and offer it back to maxHeap.
*/
        lowNumbers.push(num);
        highNumbers.push(lowNumbers.top());
        lowNumbers.pop();

        if(highNumbers.size() > lowNumbers.size()) {
            lowNumbers.push(highNumbers.top());
            highNumbers.pop();
        }
    }
    
    double findMedian() {
        if(lowNumbers.size() == highNumbers.size()) 
            return (lowNumbers.top() + highNumbers.top())/2.0;
        return lowNumbers.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    vector<string> inputTypes {"MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"};
    vector<vector<int>> inputVals {{}, {1}, {2}, {}, {3}, {}};
    MedianFinder ob;

    for(int i=0; i<inputTypes.size(); i++) {
        if(inputTypes[i].compare("addNum") == 0) {
            ob.addNum(inputVals[i][0]);
            cout<<"null, ";
        } else if(inputTypes[i].compare("findMedian") == 0){
            cout<< ob.findMedian() <<", ";
        }
    }
    return 0;
}