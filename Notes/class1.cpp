#include <iostream>

using namespace std;
//default behavior of a class is private
//default behavior of a struct is public

class Point {
    private:
        double xCoord = 0.0; 
        double yCoord = 0.0;
    public: //member functions
        Point(); //default construct;
        void setX(double);
        void setY(double);
        void display() const;
};

int main() {

    Point p1; //calls the default constructor
    p1.setX(1.5);
    p1.setY(2.1);

    Point p2;
    p2.setX(-4.1);

    cout << "p1: ";
    p1.display();
    cout << endl;
    
    cout << "p2: ";
    p2.display();
    cout << endl;

    return 0;
}

//allocates the memory of xCoord & yCoord 
Point::Point() {
    xCoord = 0.0;
    yCoord = 0.0;
}

void Point::setX(double x) {
    xCoord = x;
}

void Point::setY(double y) {
    yCoord = y;
}

void Point::display() const { //actually passed by reference 
    cout << '(' << xCoord << ',' << yCoord << ')'; 
}