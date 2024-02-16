/* Virtual destructors: 
 * Although C++ provides a default destructor for your classes if you do not provide one yourself, it is sometimes 
 * the case that you will want to provide your own destructor (particularly if the class needs to deallocate memory). 
 * You should always make your destructors virtual if you’re dealing with inheritance.*/

#include <iostream>

using namespace std;

class Base{
  char *str_base;
  public:
    Base(size_t n) { 
      str_base = (char*) malloc(sizeof(char) * n);
      cout<<"Base Constructor"<<endl; 
    }
    virtual ~Base() { 
      free(str_base);
      cout<<"Base Destructor"<<endl; 
    }  /* If we do not make this destructor as virtual, so if we try to create a ptr of Base
        * which points to Derived obj and try to delete Base ptr, it will only call Base Destructor
        * and Derived object will still not be deleted. So it is adviced to create destructors as virtual. */
};

class Derived: public Base {
  char *str_derived;
  public:
    Derived(size_t n): Base(n) { 
      str_derived = (char*) malloc(sizeof(char) * n);
      cout<<"Derived Constructor"<<endl; 
    }
    ~Derived() { 
      free(str_derived);
      cout<<"Derived Destructor"<<endl; 
    }
};

int main()
{
  Derived *dptr = new Derived(10);
  Base *bptr = dptr;

  delete bptr;  /* If Base destructor is not virtual then derived destructor will not be called and memory allocated 
                 * for str_derived will remain unfreed and leads to memleak. */
  return 0;
}
