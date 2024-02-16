#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// Max Heap.
class Heap{
private:
  vector<int> data;
  void max_heapify();
  bool hasParent(int index);
  int getParentIndex(int index);
public:
  void insert(int val);
  void printHeap();
  int peek();
};

bool Heap::hasParent(int index) {
  if(index==0)  return false;
  return true;
}
void Heap::max_heapify() {
  int i=data.size()-1;
  while(hasParent(i) && data[i]>data[getParentIndex(i)]) {
    swap(data[i], data[getParentIndex(i)]);
    i=getParentIndex(i);
  }
}
int Heap::getParentIndex(int index) {
  if(hasParent(index))
    return floor((index-1)/2);
  else 
    return 0;
}

void Heap::insert(int val) {
  data.push_back(val);
  max_heapify();  // re-heapify to make it max-heap again.
}
void Heap::printHeap() {
  for(auto val:data)
    cout<<val<<" ";
  cout<<"\n";
}
int Heap::peek() {
  // return the element at index 0 and move to last element to zeroth index and re-heapify.
  int temp=data[0];
  int n=data.size();
  data[0]=data[n-1];

  

}

int main() {
  Heap h;
  h.insert(40);
  h.insert(20);
  h.insert(30);
  h.insert(10);
  h.insert(8);
  h.insert(35);
  h.insert(33);
  h.printHeap();
  
  h.insert(45);
  h.insert(30);
  h.insert(80);
  h.insert(67);
  h.printHeap();

  h.insert(44);
}