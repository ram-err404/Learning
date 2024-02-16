#include <iostream>
#include <array>
#include <vector>
#include <string>
// using namespace std;

class Person{
  std::string name;
  int age;
  public:
    Person(std::string name="", int age=0): name(name), age(age) {}
    
    friend std::ostream& operator<<(std::ostream& out, const Person &ref);
};

std::ostream& operator<<(std::ostream& out, const Person &ref) {
    out<<"Name:"<<ref.name<<" Age:"<<ref.age<<"\n";
    return out;
}

struct Array{
    std::array<Person, 3> array_elements{};
};




int main() {
  std::array<int, 5> my_array = {1,2,3,4,5};
//  std::array<int, 2> my_array1 = {1,2,3,4,5};       /* error: too many initializers for ‘std::array<int, 2>’ */
  
//  for(int i=0; i<my_array.size(); i)                /* warning: comparison between signed and unsigned integer expressions [-Wsign-compare] */
//  for (std::array<int, 5>::size_type i{ 0 }; i < myArray.size(); ++i)       /* Correct. */
//  for(size_t i=0; i<my_array.size(); i++)           /* Correct, in C++ [] operators in array wants size_t values which is (unsigned int) */
  for(unsigned int i=0; i<my_array.size(); i++)   /* Correct. */
    std::cout<<my_array[i]<<" ";
  std::cout<<"\n";

  for(const auto &item: my_array)
    std::cout<<item<<" ";
  std::cout<<"\n";

  /******************************************************/
  std::array<Person, 3> person_array;
  person_array[0] = Person("Ramji", 23);
  person_array[1] = Person("Shivaji", 20);
  person_array[2] = Person("Shyamji", 23);
  
  for(const auto &item: person_array)
    std::cout<<item;               /* Operator overlodded function will work here and Print both Name and Age. */
  std::cout<<"\n";

  // std::array<Person, 3> person_array1 = { {"Ramji", 23}, {"Shivaji", 20}, {"Shyamji", 23} }; 
  // error: too many initializers for ‘std::array<Person, 3>’
  /* To support this type of initialization, create a structure that has array of Person objects. */

  Array person_array1 = { Person("ABCD", 23), Person("MNO", 20), Person("XYZ", 25) };
//  for(const auto &item: person_array1)  /*error: ‘begin’ was not declared in this scope; and error: ‘end’ was not declared in this scope*/
                                        /*Because person_array1 is my struct variable and not an std::array variable.*/
  std::cout<<sizeof(person_array1)<<"\n";
  for(const auto &item: person_array1.array_elements) {     /*correct*/
    std::cout<<item;
  }
  std::cout<<"\n";
  
  /******************************************************
   * Vectors are also same as array with better memory management, You don't need to specify size 
   * during declaration. Size will automatically assigned and also can be scaled at run-time. */
  
  std::vector<Person> person_vec;
  std::cout<<person_vec.size()<<"\n";

  // person_vec[0] = Person("Mamta", 23);   /*Segmentation fault: beacuse index 0 doesn't exist */
  // person_vec[1] = Person("Mittali", 23);   
  // person_vec[2] = Person("Nelanjli", 23);   
  // person_vec[3] = Person("Ramji", 23);   
  person_vec = { Person("Mamta", 23), Person("Mittali", 23), Person("Nelanjli", 23), Person("Ramji", 23) };
  person_vec[0] = Person("Akshay", 23);     /*This will works as index 1 exist*/
  std::cout<<person_vec.size()<<"\n";
  

  /*We can resize vectors.*/
  person_vec.resize(10);
  std::cout<<person_vec.size()<<"\n";
  for(const auto &item: person_vec)
    std::cout<<item;
  
  person_vec.resize(2);
  std::cout<<person_vec.size()<<"\n";
  for(const auto &item: person_vec)
    std::cout<<item;
  
  return 0;
}
