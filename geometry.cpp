//
//  geometry.cpp
//  MIT
//
//  Created by sahruday  reddy patti on 26/04/21.
//

#include <iostream>

class Point
{
private:
    
    int x,y;

public:
    

    

Point(int xx=0, int yy=0)
    {
        x = xx;
        y = yy;
    }
        int getX() const
            {
                return x;
                
            }
        int getY() const
            {
                return y;
                
            }
        void setX(const int xx)
            {
                x = xx;
            }
        void setY(const int yy)
            {
                y =yy;
            }
};
