

#include <iostream>

/********************************************************************************/
class A
{
public:
	virtual const char* getName1(int x) { return "A"; }
	virtual const char* getName2(int x) { return "A"; }
	virtual const char* getName3(int x) { return "A"; }
  virtual const char* getName4() { return "A"; }
};
 
class B : public A
{
public:

  /* override is mainly used to point-out a compile error if tries to override any virtual function with different signature.
   * If we do not use override specifier and gives different signature for any virtual function, then it will not override
   * that function, infact it will create a new function of that name with given signature. */
//  virtual const char* getName1(short int x) override { return "B"; } // compile error, function is not an override as signature is different.
//	virtual const char* getName2(int x) const override { return "B"; } // compile error, function is not an override as signature is different.
	virtual const char* getName3(int x) override { return "B"; } // okay, function is an override of A::getName3(int)
  
  // note use of final specifier on following line -- that makes this function no longer overridable
  virtual const char* getName4() override final { return "B"; }    // okay, overrides A::getName()
  // final function, so cannot be overridden it further.
 
};

/* The final specifier:
 * There may be cases where you don’t want someone to be able to override a virtual function, or inherit from a class. 
 * The final specifier can be used to tell the compiler to enforce this. If the user tries to override a function or class that
 * has been specified as final, the compiler will give a compile error.
 * */
class C: public B {
  public:
//    const char* getName4() override { return "C"; }   // compile error: overrides B::getName(), which is final
};

/********************************************************************************/

/* Covariant return types: 
 * There is one special case in which a derived class virtual function override can have a different return type than the base 
 * class and still be considered a matching override. If the return type of a virtual function is a pointer or a reference to a class, 
 * override functions can return a pointer or a reference to a derived class. These are called covariant return types. */

class Base
{
public:
	// This version of getThis() returns a pointer to a Base class
	virtual Base* getThis() { std::cout << "called Base::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Base\n"; }
};
 
class Derived : public Base
{
public:
	// Normally override functions have to return objects of the same type as the base function
	// However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
	virtual Derived* getThis() { std::cout << "called Derived::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Derived\n"; }
};

/********************************************************************************/

int main()
{
  B b;
	A &rBase = b;
	std::cout << rBase.getName1(1) << '\n';
	std::cout << rBase.getName2(2) << '\n';
	std::cout << rBase.getName3(3) << '\n';
  
  C c;
  rBase = c;
	std::cout << rBase.getName4() << '\n';
/********************************************************************************/
  
  Derived d;
	Base *bptr = &d;
	d.getThis()->printType(); // calls Derived::getThis(), returns a Derived*, calls Derived::printType
	bptr->getThis()->printType(); // calls Derived::getThis(), returns a Base*, calls Base::printType

	return 0;
}
