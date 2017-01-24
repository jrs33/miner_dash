#include "Cart_Vector.h"

using namespace std;

// Defining constructors
Cart_Vector::Cart_Vector() // Default constructor
{ 
	// Default set the coordinates to the origin
	x = 0.0;
	y = 0.0;						

}

Cart_Vector::Cart_Vector(double inputx, double inputy)
{
	// Set the coordinates to their respective input values
	x = inputx;
	y = inputy;		

}

// Defining non-member overloaded operators
Cart_Vector operator*(const Cart_Vector& v1, double d)
{

	Cart_Vector vnew(v1.x * d, v1.y * d);
	return vnew;

}

Cart_Vector operator/(const Cart_Vector& v1, double d)
{
	if(d == 0) { // Trying to divide by zero

		return v1;

	}
	else {

		Cart_Vector vnew(v1.x / d, v1.y / d);
		return vnew;	

	}

}

ostream& operator<<(ostream& os, const Cart_Vector& p1)
{

	os << "<" << p1.x << "," << p1.y << ">";
	return os;

}
