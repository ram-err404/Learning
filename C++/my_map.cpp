/* Maps are the key value pairs: 
 *
 * map<class T1, class T2> 
 *
 * Some basic functions associated with Map:
 * begin() – Returns an iterator to the first element in the map
 * end() – Returns an iterator to the theoretical element that follows last element in the map
 * size() – Returns the number of elements in the map
 * max_size() – Returns the maximum number of elements that the map can hold
 * empty() – Returns whether the map is empty
 * pair insert(keyvalue, mapvalue) – Adds a new element to the map
 * erase(iterator position) – Removes the element at the position pointed by the iterator
 * erase(const g)– Removes the key value ‘g’ from the map
 * clear() – Removes all the elements from the map. 
 *
 * */

#include <iostream> 
#include <string>
#include <iterator> 
#include <map> 

using namespace std; 

int main() 
{ 

  // empty map container 
  map<int, int> gquiz1;
  map<int, char> m{ {1,'a'}, {2,'b'}, {3,'c'} };  //Declaration and initialization.

  map<string, int> map1;
  map1["abc"]=100;    // inserts key = "abc" with value = 100
  map1["b"]=200;      // inserts key = "b" with value = 200
  map1["c"]=300;      // inserts key = "c" with value = 300
  map1["def"]=400;    // inserts key = "def" with value = 400

  map<char,int> map2 (map1.begin(), map1.end());
    /* creates a map map2 which have entries copied 
        from map1.begin() to map1.end() */ 
    
    map<char,int> map3 (m);
    /* creates map map3 which is a copy of map m */

  // insert elements in random order
  gquiz1.insert(pair<int, int>(1, 40));
  gquiz1.insert(pair<int, int>(2, 30)); 
  gquiz1.insert(pair<int, int>(3, 60)); 
  gquiz1.insert(pair<int, int>(4, 20)); 
  gquiz1.insert(pair<int, int>(5, 50)); 
  gquiz1.insert(pair<int, int>(6, 50)); 
  gquiz1.insert(pair<int, int>(7, 10)); 

  // printing map gquiz1 
  map<int, int>::iterator itr; 
  cout << "\nThe map gquiz1 is : \n"; 
  cout << "\tKEY\tELEMENT\n"; 
  for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) { 
    cout << '\t' << itr->first 
      << '\t' << itr->second << '\n'; 
  } 
  cout << endl; 

  // assigning the elements from gquiz1 to gquiz2 
  map<int, int> gquiz2(gquiz1.begin(), gquiz1.end()); 

  // print all elements of the map gquiz2 
  cout << "\nThe map gquiz2 after"
    << " assign from gquiz1 is : \n"; 
  cout << "\tKEY\tELEMENT\n"; 
  for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
    cout << '\t' << itr->first 
      << '\t' << itr->second << '\n'; 
  } 
  cout << endl; 

  // remove all elements up to 
  // element with key=3 in gquiz2 
  cout << "\ngquiz2 after removal of"
    " elements less than key=3 : \n"; 
  cout << "\tKEY\tELEMENT\n"; 
  gquiz2.erase(gquiz2.begin(), gquiz2.find(3)); 
  for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
    cout << '\t' << itr->first 
      << '\t' << itr->second << '\n'; 
  } 

  // remove all elements with key = 4 
  int num; 
  num = gquiz2.erase(4); 
  cout << "\ngquiz2.erase(4) : "; 
  cout << num << " removed \n"; 
  cout << "\tKEY\tELEMENT\n"; 
  for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
    cout << '\t' << itr->first 
      << '\t' << itr->second << '\n'; 
  } 

  cout << endl; 

  // lower bound and upper bound for map gquiz1 key = 5 
  cout << "gquiz1.lower_bound(5) : "
    << "\tKEY = "; 
  cout << gquiz1.lower_bound(5)->first << '\t'; 
  cout << "\tELEMENT = "
    << gquiz1.lower_bound(5)->second << endl; 
  cout << "gquiz1.upper_bound(5) : "
    << "\tKEY = "; 
  cout << gquiz1.upper_bound(5)->first << '\t'; 
  cout << "\tELEMENT = "
    << gquiz1.upper_bound(5)->second << endl; 

  return 0; 
} 
