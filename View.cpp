//
//  VIew.cpp
//  pa3
//
//  Created by Joshua Surette on 11/25/16.
//  Copyright © 2016 PA3. All rights reserved.
//

#include "View.h"
#include <iostream>

View::View()
{
    size = 11;
    scale = 2;
    origin = Cart_Point(0,0);
   // cout << "Constructor scale " << scale << ", constructor cp = " << origin << endl;
}

void View::clear()
{
    
    // Set the whole background grid to dots
    for(int row = 0; row < view_maxsize; row++)
    {
        for(int col = 0; col < view_maxsize; col++)
        {
            grid[row][col][0] = '.';
            grid[row][col][1] = ' ';
        }
    }
    
}

void View::plot(Game_Object* ptr)
{
	int ix = 0;	
	int iy = 0;
	//cout << "this is the location: " << ptr->get_location() << endl;
	bool result = get_subscripts(ix,iy,ptr->get_location());
	
	if(result)
	{
		//cout << "ix = " << ix << ", iy = " << iy << endl;
		ptr->drawself(grid[(view_maxsize/2)-iy][ix]);	
	}
}

void View::draw()
{
    
    // Go down row by row, and first start with axis formatting
    for(int row = 0; row < size; row++)
    {
        if(row%2 == 0)
        {
            cout<<(view_maxsize-(2*row));
            if(row > 5)
            {
                cout<<" ";
            }
        }
        else
        {
            cout<<"  ";
        }
        for(int col = 0; col < size;  col++)
        {
            cout<<grid[row][col][0]<<grid[row][col][1];
            if(col == 10)
            {
                cout<<endl;
            }
        }
        
    }
    
    // Subsequently print out the x axis ticks
    cout<<"  0   4   8   12  16  20"<<endl;
    
}

// The following defines the get_subscripts private function
bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
	//cout << "IX = " << location.x << ", IY = " << location.y << endl;
	//cout << "scale = " << this->scale << endl;
	//cout << "origin = " << origin << endl;
    ix = (location.x - origin.x)/scale;
    iy = (location.y - origin.y)/scale;
	//cout << "IX after = " << ix << ", IY after = " << iy << endl;
    if(ix <= view_maxsize && iy <= view_maxsize)
    {
        return true;
    }
    else
    {
        cout<<"An object is outside the display"<<endl;
        return false;
    }
    
}
