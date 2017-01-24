#include "Cart_Point.h"

using namespace std;

// Defining constructors
Cart_Point::Cart_Point() // Default constructor
	{ 
		// Default set the coordinates to the origin
		x = 0.0;
		y = 0.0;						

	}

Cart_Point::Cart_Point(double inputx, double inputy) // Sets input to each cartesian point
	{
		// Set the coordinates to their respective input values
		x = inputx;
		y = inputy;
	}

// Defining non-member functions
double cart_distance(const Cart_Point& p1, const Cart_Point& p2) 
{

	return sqrt(pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2));

}

// Overloading operators

ostream& operator<<(ostream& os, const Cart_Point& p1)
{

	os << "(" << p1.x << "," << p1.y << ")";
	return os;

}

Cart_Point operator+(const Cart_Point& p1, const Cart_Vector& v1)
{

	Cart_Point p(p1.x + v1.x,p1.y + v1.y); // Creating a new Cart_Point object with proper x and y vals
	return p; // Returning new object with added x and y values from the vector

}

Cart_Vector operator-(const Cart_Point& p1, const Cart_Point& p2)
{

	Cart_Vector v(p1.x-p2.x, p1.y-p2.y); // Creating a new Cart_Vector with proper values	
	return v;

}

