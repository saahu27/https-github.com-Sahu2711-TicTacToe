//
//  ClassPointerArrays.cpp
//  MIT
//
//  Created by sahruday  reddy patti on 27/04/21.
//

#include <iostream>

using namespace std;

class PointArray
{
    int size;
    Point *points;
    void resize(int size);
    
public:
    PointArray();
    PointArray(const Point pts[], const int size);
    PointArray(const PointArray &pv);
    ~PointArray();
    
    
    void clear();
    int getSize() const { return size;}
    void push_back(const Point &p);
    void insert(const int pos, const Point &p);
    void remove(const int pos);
    Point *get(const int pos);
    const Point *get(const int pos) const;

};

PointArray :: PointArray() {
    size = 0;
    points = new Point[0]; // Allows deleting later

}


PointArray :: PointArray( const Point ptstocopy[], const int copysize)
{
    
    points = new Point[copysize] ;
    size = copysize ;
    for (int i = 0 ; i < copysize ; ++i)
    {
        points[i] = ptstocopy[i] ;
    }
}
    
PointArray :: PointArray( const PointArray &other)
    {
        size = other.size;
        points = new Point[size] ;
        for (int i=0 ; i<size; ++i)
        {
            points[i] = other.points[i] ;
        }
    }


PointArray :: ~PointArray()
{
    delete[] points;
}


void PointArray::resize(int newSize) {

    Point *pts = new Point[newSize] ;
    int minSize = (newSize > size ? size : newSize);
    for (int i = 0; i < minSize; i++)
    {
    pts[i] = points[i];
    }
    delete[] points;
    size = newSize;
    points = pts;
}

void PointArray :: clear()
{
    resize(0);
}

void PointArray::push_back(const Point &p) {
    resize(size + 1) ;
    points[size - 1] = p ;
    //could also use insert(size , p)
    }

void PointArray::insert(const int pos, const Point &p) {
    resize(size + 1);
    for ( int i = size - 1 ; i >  pos ; i--)
    {
        points[i] = points[i-1];
    }
    points[pos] = p;
}

void PointArray::remove(const int pos)
{
    if(pos>=0 && pos < size) {
        for(int i = pos ; i < size - 2 ; i++)
        {
            points[i] = points [i + 1] ;
        }
        resize(size - 1) ;
    }
}

Point *PointArray::get(const int pos) {
    return pos>=0 && pos <size ? points + pos : NULL ;
}

const Point *PointArray::get(const int pos) const {
    return pos>=0 && pos <size ? points + pos : NULL ;
}
