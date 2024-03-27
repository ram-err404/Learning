#include <iostream>
#include <climits>
using namespace std;

int main() {
  int N;
  int min = INT_MAX;
  int max = INT_MIN;

  cout<<"Enter size of the array: "<< endl;     
  cin >> N;
  int *array = new int[N];
  cout<<"Enter arrays elements: "<< endl;

  for(int i=0; i<N; i++) {
    cin >> array[i];
    if(array[i] < min)  min = array[i];
    if(array[i] > max)  max = array[i];
  }
  cout<<"min: "<< min <<"\t max: "<< max << endl;
  delete[] array;

  return 0;
}
