#include<bits/stdc++.h>
using namespace std;

class TwoDimensionShape {
    public:
        virtual double area() = 0;
    };
    
class ThreedimensionShape {
    public:
        virtual double area() = 0;
        virtual double volume() = 0;
};

class Square: public TwoDimensionShape {
    private:
        double side;
    
    public:
        Square(double s): side(s){}

        double area() override{
            return side*side;
        }
};
class Rectangle: public TwoDimensionShape {
    private:
        double length, width;
    
    public:
        Rectangle(double l, double w): length(l), width(w){}

        double area() override{
            return length*width;
        }
};

class Cube: public ThreedimensionShape {
    private:
        double side;
    
    public:
        Cube(double s): side(s){}

        double area() override{
            return side*side;
        }

        double volume() override{
            return side*side*side;
        }
};

int main(){
    TwoDimensionShape *s = new Square(4);
    TwoDimensionShape *r = new Rectangle(4, 3);
    cout << "Square area 4: " << s->area() << endl;
    cout << "Rectangle area 4: " << r->area() << endl;

    ThreedimensionShape *c = new Cube(3);
    cout << "Cube area 3: " << c->area() << endl;
    cout << "Cube volume 3: " << c->volume() << endl;
    return 0;
}