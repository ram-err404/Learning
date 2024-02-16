
--> Python is a Dynamic Typed Programming language.

--> Functional programming Feature 	(from C)
--> OOPs programming 				(from C++)
--> Scripting programming 			(from Perl and shell scripting)
--> Modular programming 			(from Modula-3)
--> Most Syntax 					(from C and ABC language)
------------------------------------------------------------------------

Where we can use python:
------------------------
-> Desktop/Standalone App
-> Web App 						(Django... etc)
-> Database App
-> For Networking App
-> Games
-> Data Analysis App
-> Machine Learning App
-> AI App
-> IOT App
----------------------------------------------------

#########################################################################
Identifiers: name to identify vars/funct/class etc.
Rules to define Identifiers in Python:
--------------------------------------
1. Alphabet symbols(both upper and lower case)
 	Digits (0-9)
	Underscore (_)
2. Identifier should not start with digit.
	total123 =10	valid
	123total =10	invalid
3. Python identifiers are case sensitive.
	total =10	valid
	TOTAL =20	valid
4. Keywords are not allowed to use as identifiers.
	x =10 		valid
	if =20		invalid
	def =30		invalid
5. There is no limit for length of an identifers in python.
6. if identifiers starts with underscore symbol. It will be private.
7. if Identifiers starts with 2 underscore symbol. It is strongly private.
8. if Identifiers starts and ends with 2 underscore symbol. It is language specific identifiers.
	Ex: __main__
##########################################################################
-----------------------------------------------------------------

#########################################################################
Reserved words : (33 reserved words)
---------------
****************************************************************
>>> import keyword
>>> keyword.kwlist
['and', 'as', 'assert', 'break', 'class', 'continue', 'def', 'del', 'elif', 'else', 'except', 'exec', 'finally', 'for', 'from', 'global', 'if', 'import', 'in', 'is', 'lambda', 'not', 'or', 'pass', 'print', 'raise', 'return', 'try', 'while', 'with', 'yield']
****************************************************************

True, False, None 	-->(Boolean)
and, or, not, is 	-->	(operator)
if, else, elif		-->	(conditions/ switch is not available in python)
for, while, break, continue, return, in, yeild	--> (iteration/ no do-while loop in python)
try, except, finally, raise, assert		--> (exception)
import, from, as, class, def, pass, global, nonlocal,lambda, del, with

Note:
--> No modifier in python, but global and local variables can be made.
--> except==> catch
--> raise==> throw
--> lambda==> annonymous functions
--> as==>to create alias

--> All reserved words contains only alphabet symbols.
--> only lower case alphabet except True, False and None
--------------------------------------------------------------------
##########################################################################

##########################################################################
Data Types: (Python is Dynamically typed Programming languaage)
-----------
(No size limit in python for datatype (like int is 4bytes in java))

int		
float
complex ==> 10+2j 	(for syntific apps)
bool
str
bytes
bytearray
range
list
tupple
set
frozenset
dict
None

--> Python provides some inbuild functions like:
	print(), 
	type(), 
	id(), 	==> to find the address of something. 
		Ex: a=10 
			id(a)

--> In Python everything is an object. (wheather datatype or even function-names are also)
--> long ==> In python3 long is not available as it was availble in python2 but int is capable to handle long types here.

-----------------------------------------------------
--> Integeral values can be represented in following forms
	1. Decimal Form 		(default)
		a = 9876
	2. Binary Form 			(starts with 0b or 0B)
		a = (+-)0b1011 / 0B1011
	3. Octal Form			(0o or 0O)
		a = 0o7654 / 0O7654
	4. Hexadecimal Form 	(0x or 0X)
		a = 0xabcd / 0XABCD / 0xABCD / 0XaBcdE 	(valid)
		b = 0xFace		(valid)
	print(a) ==> prints 'a' only in decimal form.
	
	Base Conversion:
	-----------------
	bin(), oct(), hex()
	Ex: a=1234
		print(bin(a)) / print(hex(a)) / print(oct(a))

 Type conversion is very easy in python.
		Ex: a=10	(int)
			a=True
-------------------------------------------------------
--> float data type:
	salary = 1234567.89
	x = 123.5e12

-------------------------------------------------------
--> complex:
		val = a+bj	(a=Real part, b=Imaginary Part)
Note: Real part can be binary, octal, decimal or hexadecimal value but imaginary part must be decimal only.
		val = 10+30j
		val.real		==> 10.0
		val.imag		==> 30.0
---------------------------------------------------------
--> bool:
True or False 					|	(True as 1 and False as 0)
	a =True						|	True + True 	==>2
	b,c =10, 20					|	False + True	==>1
	d = b < c					|	False * True 	==>1
	print(d)		==> True	|	False / True	==>0
----------------------------------------------------------

--> str: 		('Ramji' or "Ramji")
------------------------------------
Note: Triple single qoute (''') will be used for multi line string.

	Ex: myStr = '''Ramji
					Misra'''
		print('''Ramji Misra is "Extra Ordinary" Performer''')
			==> Ramji Misra is "Extra Ordinary" Performer
	---------------
	slice operator: 	str[begin:end]	/ 	str[begin:end:step]
	If you want some piece of a string
	---------------
		Ex: s="Ramji Misra"		|	+ve and -ve index are possible.
			s[2:8]	==>'mji Mi'	|	+ve index means from left to right.
			s[6]	==>'M'		|	-ve index means from right to left.
			s[-2]	==>'r'
			s[20]	==> IndexError: string index out of range
			s[-1:-4]	==> '' {slice operator dont give error}
			
			s[1:8:2]	==>'aj i'
			s[2:8:2]	==>'miM'
			r='Ramji'
			r*10		==> print Ramji 10 times
	--> len(): gives length
			len(s)	==>11

	**********************************************************
	-------------------------------
	Type Casting or Type coersion:
	-------------------------------
		int(), float(), complex(), bool(), str()

	-->	int():
		------
		int(12.456) 	==> 123
		int(10+20j)		==>TypeError: can't convert complex to int
		int('Ramji')	==>ValueError: invalid literal for int() with base 10: 'Ramji'
		int(True)		==> 1
		int("10")		==> 10
		int("10.5")		==>ValueError: invalid literal for int() with base 10: '10.5'
		int(0b11101) 	==> 29
		int("0b11101")	==>ValueError: invalid literal for int() with base 10: '0b11101'

	-->	float():
		--------
		float(10)	==>10.0
		float(10+20j)	==>TypeError: can't convert complex to float
		float(True)		==> 1.0
		float("10")		==> 10.0
		float("10.5")	==>	10.5
		float("ten")	==>ValueError: could not convert string to float: ten
		float("0b1111") ==>ValueError: invalid literal for float(): 0b1111
		float(0b1111)	==> 15.0

	-->	complex():
		----------
		Form 1: complex(x) ==> x+0j
		Form 2: complex(x,y) ==> x=yj

		complex(10) 	==> 10+0j
		complex(True) 	==> 1+0j
		complex('10.5') ==> 10.5+0j
		complex(10,20)	==> 10+20j
		complex(10,20.5)==> 10+20.5j
		complex('10.5', '3.6')==>TypeError: complex() can't take second arg if first is a string

	--> bool():
		-------
		(For int argument):
		bool(0) ==>False	False if 0, otherwise True.
		bool(10)==>True
		bool(-10)==>True
		(For float argument): 	If total value is zero False, otherwise True.
		bool(0.000000) 	==> False
		bool(0.001)		==> True
		(For Complex argument): If both real and imaginary part are zero then False, otherwise True.
		bool(0+0j) ==> False
		bool(0+3.5j) ==> True
		(For str argument): If empty string then False, otherwise True.
		bool('') ==>False
		bool(' ')==>True
		bool('Ramji')==>True
		
	--> str():	No restriction, you can convert any type to str.
		------
		str(10) ==>'10'
		str(10-3.5j) ==>'10-3.5j'
		str(True) ==> 'True'

---------------------------------------------------------------------
	Immutable Vs Fundamental Data Types:
---------------------------------------------------------------------
	mutable ==> changable
	immutable ==> non-changable		
	(Every Fundamental objects(int,float,bool,complex,str) are immutable in python and unused objects will be destroyed by garbage collector) To get memory utilisation and improved performance.
										------				--------
			x=10				x --/->	| 10 |	<---z		|  11  |	<---- x
			y=10				y----->	------				--------
			z=10
			x=11																
			id(x) / id(y) / id(z) ==> All will same. As id returns address.
		-->	y is z ==> True	 (just as java == in python we have is)
			z is y ==> True	 (Since both points to same object it is True.)
			x is y ==> False	
			Note: Reusable concept is only valid from (0 to 256)
					x =257
					y =257
					x is y ==> False
				For Floating type re-useablity is not available.
					x=10.5	\n y=10.5
					x is y ==> False
				For Complex type re-useablity is not available.
					x=10+3j	\n 	y=20+4j
					x is y	==>False

				Re-usability only in th following range:
					int ==> 0 to 256
					bool==> alwayse
					str ==> alwayse (But python don't create any object at start)
					float ==> not available	(A new object will be created everytime)
					complex ==> not available
				--> At the time python interpreter starts
						from 0 to 256 integer objects will be created at the begening.
				--> Since in float and complex we can have infinite values b/w 0 to 1.
					we dont have reusability concept here.
	***********************************************************
-----------------------------------------------------------------------
--> bytes: (Mostly used to handle binary data)
	It represents a group of byte number (just like an array). Bytes are immutable.
	How to create byte
	Ex: x = [10,20,30,40]
		b = bytes(x) 	/*b is of bytes type*/
		type(b)	==> class 'str'	(from 3.72 version)
		x=[10,20,256,258]
		b=bytes(x) 	==> valid in 3.72 version. before bytes only accepts values 0-256.
		b[1] = 20  ==>TypeError: 'str' object does not support item assignment.
------------------------------------------------------------------------------------
--> bytearray: (Only difference they are mutable).
	Ex: x=[10,20,30,40] 	(Only allowed values are 0-256)
		b=bytearray(x)
		b[0] ==>10
		for i in b: print(i)
		...
		10
		20
		30
		40

		b[0]=120
		for i in b: print(i)
		...
		120
		20
		30
		40

		x=[10,20,256,258]
		b=bytearray(x) ==> ValueError: byte must be in range(0, 256)
-------------------------------------------------------------------------------------
--> list: 	(insertion order is preserved and duplicates are allowed and are mutable)
	Ex: l=[10]			//List 
		type(l) ==> <type 'list'>
		l.append(10)		(growable)
		l.append(20)
		l.append(10)
		l.append("Ramji")	(Accepts hetrogeneous objects)
		l.append(None)		(Accepts None)
		print(l)	==>[10, 20, 10, 'Ramji', None] 
		l[1:5]		==>[20, 10, 'Ramji', None]		(slice operator available)
		l.remove(10) ==> [20, 10, 'Ramji', None] 	(1st occured 10 will be removed)
		l[-2]		==> 'Ramji'
	Ex: s=l*2	==>[20, 10, 'Ramji', None, 20, 10, 'Ramji', None]
		print(l*l) 	==>TypeError: can't multiply sequence by non-int of type 'list'
		l[2]='shiva'	==>[20, 10, 'shiva', None]	(Mutable, so value can be changed)
        l[100]      ==>IndexError: list index out of range
-----------------------------------------------------------------------------------
--> Tuple: (same as list but Tuples are immutable)  (maybe not growable)
		Ex: m=(10)							//int in 3.72
		Ex: m=('Ramji')						//str in 3.72
		Ex: m=(10,20)						//Tuple

			t=(10,20,10,'Ramji', None)		//Tuple
			t 			 ==>(10,20,10,'Ramji', None)
			t[3] ='shiva' ==>TypeError: 'tuple' object does not support item assignment
			t1=t*2 ==>(10, 20, 10, 'Ramji', None, 10, 20, 10, 'Ramji', None)
--------------------------------------------------------------------------------------
--> range(): range data type represent a sequence of values, immutable.
	------
	(range data type is valid for integer datas only)
	Form-1: range(end) 	//it represent values from 0 to end-1.
		Ex: r=range(10) 
			type(r)  ==><type 'list'>  //earlier it was range,but in 3.72 it is list. So it mutable also.
			r[1] = 6 ==>[0, 6, 2, 3, 4, 5, 6, 7, 8, 9]  //valid, since it is list now.

	Form-2: range(star, end)
	Form-3: range(start, end, step)
		Ex: for i in range(10,50,5)
		... 
		10
		15
		20
		25
		30
		35
		40
		45
		  i=range(10.5) ==>TypeError: range() integer end argument expected, got float	

--------------------------------------------------------------------------------------
--> set: (Duplicates are not allowed, order is not important, but they are mutable and growable)
	----
	Set do not support indexing, slicing

	Ex: s={10,20,30,10,20,30}
		s 	==>set([10, 20, 30]) 	//Internally only one objects.No duplicate
		s[0] ==>TypeError: 'set' object does not support indexing
		s[1:] ==>TypeError: 'set' object has no attribute '__getitem__'
		s.add('Ramji') ==>set([10, 20, 'Ramji', 30])	(growable and mutable)
		s.remove(20) ==>set([10, 'Ramji', 30])
	Ex: s=set() 		// empty set
		for i in range(10): s.add(i) ==> 	(Order is not preserved)
		set([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 'Ramji', 30])
-------------------------------------------------------------------------------------
--> frozenset: (Exactly same as set but are immutable)
	Ex: fs = frozenset(s) ==>frozenset([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 'Ramji', 30])
		type(fs) 	==><type 'frozenset'>
		fs.add('shiva') ==>AttributeError: 'frozenset' object has no attribute 'add'
	   fs.remove('Ramji')==>AttributeError: 'frozenset' object has no attribute 'remove'
-------------------------------------------------------------------------------------
--> dict: (key will not be duplicate, but values may duplicated)
	dict is mutable
		words==>meaning		(any type of object)
		key--->value		(any type of object)
	Ex: d={100:'Ramji', 200:'shiva', 300:'Misra'}
		d1={}	==>	//empty dict by default, not set.
		d1[10] = 'sunny'
		d1[20] = 200
		d1[300] = 'bunny'
		d1[10]= 'chinny' 	(sunny will be changed with chinny)
		{10:chinny, 20:200, 300:'bunny'}
-------------------------------------------------------------------------------------
--> None:

----------------------------------------
Summary
----------------------------------------
str==>'' , "", ''''''
list==>[]
tuple==>()
set==>{}
dict==>{}

1. int,float,complex.bool,str 	(Fundamental Datatypes)
2. bytes and bytearray==>to represent binary data, like images, videos and audio files.
3. long data type
	python 2==> available
	python 3==> not available
4. ch='a'===>str;	(char datatype is not available)
5.	
##########################################################################


#####################################################################################
-->def:		(Function)

	def f1():
		a=10

	def f2():
		amount = 100
		if amount > 100:
			print("Do something")
		else :
			pass
	
	def f3():
		/*Your code here*/

	====>Escape characters: (available in python)
	\n, \t, \r (carriage return: go to the 1st position),
	\b (backspace), \f (form feed: "page down" or go to the next page),
	\', \", \\, \v (vertical tab)
#########################################################################

Constant: 	
----------
(There is no such concept of constant in python, but to create contant values we can declare UPPER_CASE variable. Its all developers responsibiity to take care of such variable, that they should not be changed in program. Python don't applies anything like constant. )
	Ex: MAX_VAL = 10 	(Its developers duty to take care that its value should not be changed in the program.)
		MIN_VAL = 1
		MIN_VAL = 5	(valid. Developers need to take care of it)

##########################################################################

*************************************************************************
Operator:
----------
1. Arithmatic operators
2. Relational Operators or Comparison Operator.
3. Logical Operators
4. Bitwise Operators
5. Assignment Operators
6. Special Operators
----------------------------------------------------
Arithmatic Operators:
---------------------
+	===>Addition 	(applicable for str concat also, if both are str)
-	===>Substraction
*	===>Multiplication (repeatation for str, if any of 1 arg is int)
/	===>Division	(returns float)
%	===>Modulo

//	===>Floor Division Operator 	(returns int or float)
		(If both arguments are int ==>int)
		(If arguments are float ==>float)
**	===>Exponent Operator or Power Operator
	Ex: 
	a = 10
    b = 2
    print("a+b = ", a+b)	#12
    print("a-b = ", a-b)	#8
    print("a*b = ", a*b)	#20
    print("a/b = ", a/b)	#5
    print("a%b = ", a % b)	#0
    print("a//b = ", a // b)  #5
    print("a**b = ", a ** b)  #100
	a, b =10.5, 2
	a/b		#5.25
	a//b	#5.0
	a**b	#110.25
	'ramji' + 'misra' ==>ramjimisra
	'ramji' +3 ==>TypeError: cannot concatenate 'str' and 'int' objects
	'ramji' + '3' ==>ramji3
	'ramji' + str(3) ==>ramji3
	'ramji'*3	==>ramjiramjiramji
	'ramji'*'3' ==>TypeError: can't multiply sequence by non-int of type 'str'
	3*'ramji'	==>ramjiramjiramji   (order is not important).
	'ramji' * -3 ==>''	(empty str)
	(10.2j)**(10+2j) ==>(-5955821969.656015+3132803455.4997764j)
------------------------------------------------------------------
2. Relational Operators or Comparison Operator.
-----------------------------------------------
<
<=
>
>=
==

	Ex:
	a='ramji'
	b='shiv'
	print("a>b : ", a>b)	# F	(not on basis of length, but on basis of alphabetical order)
	print("a>=b : ", a>=b)	# F
	print("a<b : ", a<b)	# T
	print("a<=b : ", a<=b)	# T
	10<20	==>True
	10<20<30 ==>True	(chaining of relational operator is possible)
	10<20>30==>False 	(If any comparision is false result is False)

---------------------------------------------------------------------
3. Logical Operator:
--------------------
and ==>if both are true, True
or  ==>if any one is true, True
not ==>opposite action

  For non-boolean types:
  ---------------------
  0 means False
  non-zero means True
  empty string ==> False

  x and y:
  --------
  if x evaluates to false the result is x, otherwise returns y
  Ex: 10 and 20   ==> 20 
      0 and 20    ==> 0 
      1 and 'Ram' ==> 'Ram'

  x or y:
  -------
  if x evaluates to True then return x, otherwise return y.
  Ex: 10 or 20  ==>10 (if 1st is true, 2nd value will not be evaluated)
      0 or 20   ==>20
      10 or 'Ram' ==>10
      'Ram' or 10 ==>'Ram'
      0 or True ==>True

  not x:
  ------
  Ex: not 10  ==>False
      not ''  ==>True
      not 0   ==>True
      not 'Ram' ==>False

  Ex: 10 or 10/0  ==>10 (1st one is True, so 2nd value will not be evaluated)
      10 and 10/0 ==>ZeroDivisionError: integer division or modulo by zero.
            (Since 1st is True, so 2nd value is evaluated)
-----------------------------------------------------------------

4. Bitwise Operator: (can be applied only for int and boolean types)
--------------------
&   ==>And  (If both bits are 1 then 1, otherwise 0)
|   ==>Or   (If atleast one bits is 1, otherwise 0)
^   ==>Xor (Either 1st one, or 2nd one but not both/ If both bits are
            different then 1 otherwise 0)
~   ==>Not  (bitwise complement operator) 1 ==>0    0==>1
<<  ==>Left Shift
>>  ==>Right Shift

  Ex: ~4  ==> -5  (Negative numbers are represented in 2's complement form)
      ~True ==> -2


(Tutorial 13 is missing)




*************************************************************************
##########################################################################

--> Input and Output statement:
--------------------------------

Python-2:
---------
x = raw_input("Enter some number") ==> always str
  we require to use typecasting functions

y = input("Enter some number")
  not considered as str type, treated as Whatever type provided
  we are not required typecasting

Python-3:   (Only input func is available, but it is acted same as raw_input func)
---------
x = input("Enter some number")    //Type casting is required.
  (But in python 3.72, it is again same as that of python-2. Typecasting not required now)
  
  type(input("Enter some number"))
  Enter some number'ramji'
  <type 'str'>

x, y, z = [int(x) for x in input("Enter 2 number").split()]
            ==> (not working in 3.72)

x, y, z = [int(x) for x in raw_input("Enter 2 number").split()]

--> eval(): (Not require to make any kind of type conversion)
-----------
  eval() fn will automatically converts to the required types

  Ex: eval("10+20*4")   ==>90 (takes input as str and evaluates)
      list = eval(raw_input("Enter list of values"))
      Enter list of values[10,20,30,40]
      type(list)        ==><type 'list'>
*************************************************************************      
--> Command Line argument: (import sys module) ==>argv list type variable
--------------------------
  from sys import argv
  print(argv)
  ./test.py 10 20 30 40 50  ==> refer prog4
  
  ==> len(): to check number arguments in array or list.
      ------
      print("The number of command line args : ", len(argv))
      ==>('The number of command line args :', 6)
  print(argv[100])  ==>IndexError: List index out of range
  print(argv[2:100])  ==>[20, 30, 40, 50]  #slice operator will not give error
**************************************************************************
Output Statements:
------------------
  print():
  Form 1: without any argument
    print()   ==> prints a new line

  Form 2: with str argumnts
    print("Ramji")  ==>Ramji
  -->concatation of strings (Both args should be str)
    print("Ramji" + "Misra") ==>RamjiMisra
  -->Repeatation operator (2nd args should be int)
    print("Ramji"*3)  ==>RamjiRamjiRamji

  Form 3: with variable number of arguments
    print("Ramji","Misra")  ==>Ramji Misra    (space is added in b/w)
    print("The values are",10,20,30) ==>The values are 10 20 30  # default seperator is space
    print(10,20,30,sep=',')   ==> 10,20,30  #seperator is ','
    print(10,20,30,sep=':')   ==> 10:20:30  #seperator is ':'
    
    end='' attribute: next data will be printed in the same line with space
    print("Hello", end='')
    print("Ramji", end='-')
    print("Misra")
      ==>Hello Ramji-Misra

  Form 4: with formatted string
    %i  ==> int type
    %d  ==> int type
    %f  ==> float type
    %s  ==> str type
  Syntax: print("Formatted String ", %(variable_list))
  Ex:   a,b,c=10,20.5,'Ramji'
        print("a = %i", %a)
        print("a=%i, b=%f, c=%s", %(a,b,c))


NOTE:
a==b  ==> content comparision
a is b ==> reference comparision
##########################################################################

