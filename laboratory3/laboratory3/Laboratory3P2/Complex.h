#pragma once
#include <iostream>
#include <string>
#include<cmath>

class Complex {
public:
	enum class DISPLAY_TYPE {
		RECTANGULAR_FORM,
		POLAR_FORM
	};

private:
	float real;
	float imaginary;
	static DISPLAY_TYPE displayType;
public:
	Complex();
	Complex(float real, float imaginary);
	void setReal(float real);
	float getReal() const;
	void setImaginary(float imaginary);
	float getImaginary() const;
	bool operator==(const Complex& other) const;
	bool operator!=(const Complex& other) const;
	float magnitude() const;
	float phase() const ;
	static DISPLAY_TYPE getDisplayType();
	static void setDisplayType(DISPLAY_TYPE type);
	friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
	friend std::istream& operator>>(std::istream& is, Complex& complex);
	Complex operator+(const Complex& other) const;
	Complex operator-(const Complex& other) const;
	Complex operator*(const Complex& other) const;
	Complex operator*(float scalar) const;
};
