#include "Complex.h"
using namespace std;

//Write a class to represent a complex number. This is similar to the std::complex from C++
//(https://en.cppreference.com/w/cpp/numeric/complex). Use a modular programming approach!
//Your class should have two members, one for the realand one for the imaginary part of the number.
//In addition, your class should contain at least :
//	a.Default constructorand a constructor that initializes a complex number with the realand imaginary parts.
//	b.Overloads for the equal to and not equal to operators.
//	c.Computing the magnitudeand the phase of a complex number.
//	d.A private static member of an enum type DISPLAY_TYPE.It can have two values :
//	  RECTANGULAR_FORM and POLAR_FORM.Generate gettersand setters for this member.
//	e.Overload for the stream insertion operator ( << ) and stream extraction(>> ) operators.In
//	  the stream insertion operator check the value of DISPLAY_TYPE.If DISPLAY_TYPE is
//	  RECTANGULAR_FORM then the complex number will be displayed in rectangular form
//	  (re + img * i), otherwise, it will be displayed in polar form z = mag * (cosθ + i sinθ).The same
//	  applies for the toString method.
//	f.Overloads for the arithmetic operators : addition(+), subtraction(-) and multiplication(*).
//	g.Overload for multiplying the complex number with a scalar value.

//Now, in another file(main.cpp), test the module that you wrote :
//-Define a variable of Complex type such that it is stored on the stack.Call the functions that
//compute the magnitude, the phaseand the polar form of this complex number.
//- Define a variable of Complex type such that is stored on the head and allocate memory for it.
//Call the functions that compute the magnitude, the phaseand the polar form of this
//complex number.
//- Now compute the multiplication, addition, subtractionand division between these two variables.

int main() {
	/*
	* //Testing phase below
	Complex c1(3, 4);
	Complex c2(4,4);
	cout << c1.magnitude()<<endl;
	cout << c2.phase()<<endl;
	if (c1 == c2) {
		cout << "The number are equal."<<endl;
	}
	else {
		cout << "The numbers are not equal"<<endl;
	}
	Complex c;
	std::cin >> c;
	cout << c;
	*/

	Complex cStack(3, 4); 
	float magnitude = cStack.magnitude();
	float phase = cStack.phase();

	cout << cStack<<endl;
	cout << "Magnitude for the first number is: " << magnitude << endl;
	cout << "Phase for the first number is: " << phase << endl;

	Complex* cHeap = new Complex(4, 6);
	float mag = cHeap->magnitude();
	float phs = cHeap->phase();

	cout << *cHeap << endl;
	cout << "Magnitude for the second number is: " << mag << endl;
	cout << "Phase for the second number is: " << phs << endl;

	Complex sum = cStack + (*cHeap);
	Complex difference = cStack - (*cHeap);
	Complex product = cStack * (*cHeap);

	cout << "The sum of the numbers is:" << sum << endl;
	cout << "The difference of the numbers is:" << difference << endl;
	cout << "The product of the numbers is:" << product << endl;

	delete cHeap;
}