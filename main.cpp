#include <iostream>
#include <string>
#include <math.h>
# define PI           3.14159265358979323846
using namespace std;


struct BoundingBoxDimensions{
    double width;
    double height;
public:

    BoundingBoxDimensions(double width, double height) : width(width), height(height){};

};

std::istream& operator>> (std::istream &in, BoundingBoxDimensions& p){
    in >> p.width >> p.height;
    return in;
}

std::ostream& operator<< (std::ostream &out, const BoundingBoxDimensions &p){
    out << "Describing Rectangle: " << p.width << " " << p.height << endl;
    return out;
}

class Shape{
public:
    Shape(){};
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual string type() = 0;

    virtual void printParam() { }
};

class Circle : virtual public Shape {
    double radius;
public:

    Circle(double radius) : radius(radius){};

    virtual double square() {
        return PI*radius*radius;
    };

    virtual BoundingBoxDimensions dimensions(){
        BoundingBoxDimensions m(radius * 2, radius * 2);
        return m;
    };

    virtual string type(){
        return "Circle";
    }

    virtual void printParam() {
        cout << "Radius: " << radius << endl;
    }

};

class Rectangle : virtual public Shape {
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height){};

    virtual double square() {
        return width * height;
    };

    virtual BoundingBoxDimensions dimensions(){
        BoundingBoxDimensions m(width, height);
        return m;
    };

    virtual string type(){
        return "Rectangle";
    }

    virtual void printParam() {
        cout << "Sides: " << width << " " << height << endl;
    }

};

class Triangle : virtual public Shape{
    double a;
    double b;
    double c;

public:

    Triangle(double a, double b, double c){
        this->a = a;
        this->b = b;
        this->c = c;
    }

    virtual double square() {
        double p = (a + b + c) / 3;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    };

    virtual BoundingBoxDimensions dimensions(){
        double p = (a + b + c) / 3;
        double k = (a * b * c / (4 * sqrt(p*(p - a)*(p - b)*(p - c))));
        BoundingBoxDimensions m(k*2, k*2);
        return m;
    };

    virtual string type(){
        return "Triangle";
    }

    virtual void printParam() {
        cout << "Sides: " << a << " " << b << " " << c << endl;
    }

};

 void printParams(Shape *shape) {
    std::cout << "Type: " << shape->type() << std::endl;
    cout << "Square: " << shape->square() << endl;
    cout << shape->dimensions();
    shape->printParam();
}

int main() {

    Shape* tri = new Triangle(2, 4, 5);
    printParams(tri);

    cout << endl;

    Shape* rec = new Rectangle(2, 3);
    printParams(rec);

    cout << endl;

    Shape* sq = new Circle(3);
    printParams(sq);

}
