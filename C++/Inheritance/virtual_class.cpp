#include <iostream> 
using namespace std; 

class A { 
public: 
	void show() 
	{ 
		cout << "Hello form A \n"; 
	} 
}; 

class B :virtual public A { 
}; 

class C : public A { 
}; 

class D : public B, public C { 
}; 

int main() 
{ 
	D object;
  cout<<"sizeof(A)" <<sizeof(A) <<" sizeof(B) "<<sizeof(B) <<" sizeof(C) "<<sizeof(A) <<endl;   /*Output: sizeof(A)1 sizeof(B) 8 sizeof(C) 1 */
  cout<<"sizeof(object): "<<sizeof(object)<<endl; 
	object.B::show(); 
} 

