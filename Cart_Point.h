#ifndef CART_POINT_H
#define CART_POINT_H
#include <iostream>
#include <cmath>
#include "Cart_Vector.h"

using namespace std;


// Creation of Cart_Point class, which will be used to simplify tracking coordinates
class Cart_Point
{
	public:
	
	// Defining public member variables and public method prototypes
	double x;
	double y;
	
	// Constructors
	Cart_Point(); // Default constructor
	Cart_Point(double, double); // Sets input to each cartesian point

};

// Non-Member function prototypes
double cart_distance(const Cart_Point&, const Cart_Point&);

// Operator overload prototypes
ostream& operator<<(ostream&, const Cart_Point&);
Cart_Point operator+(const Cart_Point&, const Cart_Vector&);
Cart_Vector operator-(const Cart_Point&, const Cart_Point&);

#endif
