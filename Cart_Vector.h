#ifndef CART_VECTOR_H
#define CART_VECTOR_H
#include <iostream>
#include <cmath>

using namespace std;

// Creation of Cart_Vector class, which will be to do linear operations to figure out where an object is on the real plane
class Cart_Vector
{

	public: 

	// Defining public member variables and member methods prototypes
	double x;
	double y;

	// Constructors
	Cart_Vector(); // Default constructor
	Cart_Vector(double, double); // Other constructor with user input

};

// Non-member overloaded operator prototypes
Cart_Vector operator*(const Cart_Vector&, double);
Cart_Vector operator/(const Cart_Vector&, double);
ostream& operator<<(ostream&, const Cart_Vector&);

#endif
