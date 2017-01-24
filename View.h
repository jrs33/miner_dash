//
//  View.h
//  pa3
//
//  Created by Joshua Surette on 11/25/16.
//  Copyright © 2016 PA3. All rights reserved.
//

#ifndef VIEW_H
#define VIEW_H

#include "Gold_Mine.h"
#include "Miner.h"
#include "Town_Hall.h"

const int view_maxsize = 20;

// Inherits from Game_Object which gives acces to the drawself() function
class View 
{

    public:
        View();
        void clear();
        void plot(Game_Object*); // Base class pointer allows for upcasting to allow for dynamic plotting on View
        void draw();
    
    private:
        int size;
        double scale;
        Cart_Point origin;
        char grid[view_maxsize][view_maxsize][2];
        bool get_subscripts(int &ix, int &iy, Cart_Point location);
    
};

#endif
