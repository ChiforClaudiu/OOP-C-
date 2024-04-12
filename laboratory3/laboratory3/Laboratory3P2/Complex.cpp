#include "Complex.h"
#include<iostream>
using namespace std;
Complex::Complex()
{
	this->real = 0;
	this->imaginary = 0;
}

Complex::Complex(float real, float imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

void Complex::setReal(float real)
{
	this->real = real;
}

float Complex::getReal() const
{
	return this->real;
}

void Complex::setImaginary(float imaginary)
{
	this->imaginary = imaginary;
}

float Complex::getImaginary() const
{
	return this->imaginary;
}

bool Complex::operator==(const Complex& other) const
{
	if (this->real == other.real && this->imaginary == other.imaginary) {
		return true;
	}
	else 
		return false;
	
}

bool Complex::operator!=(const Complex& other) const
{
	if (this->real != other.real || this->imaginary != other.imaginary) {
		return true;
	}
	else
		return false;
}

float Complex::magnitude() const
{
	return sqrt(this->real*this->real+this->imaginary*this->imaginary);
}

float Complex::phase() const
{
	return atan(this->imaginary/this->real);
}

Complex::DISPLAY_TYPE Complex::displayType = Complex::DISPLAY_TYPE::RECTANGULAR_FORM;

Complex::DISPLAY_TYPE Complex::getDisplayType() {
	return displayType;
}

void Complex::setDisplayType(DISPLAY_TYPE type) {
	displayType = type;
}

Complex Complex::operator+(const Complex& other) const
{
	return Complex(real+other.real,imaginary+other.imaginary);
}

Complex Complex::operator-(const Complex& other) const
{
	return Complex(real-other.real,imaginary-other.imaginary);
}

Complex Complex::operator*(const Complex& other) const
{
	return Complex(real*other.real-imaginary*other.imaginary, real*other.imaginary+imaginary*other.real);
}

Complex Complex::operator*(float scalar) const
{
	return Complex(real*scalar,imaginary*scalar);
}

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
	if (Complex::displayType == Complex::DISPLAY_TYPE::RECTANGULAR_FORM) {
		os <<  "(" << complex.getReal() << "+" << complex.getImaginary() << "i)";
	}
	else if (Complex::displayType == Complex::DISPLAY_TYPE::POLAR_FORM) {
		float magnitude = complex.magnitude();
		float phase = complex.phase();
		os << magnitude << "*(cos(" << phase << ") + i sin(" << phase << "))";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Complex& complex) {
	is >> complex.real >> complex.imaginary;
	return is;
}
