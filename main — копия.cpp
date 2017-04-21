#include <string>
#include <iostream>

using namespace std;

class Triangle
{
protected:

    int first_side;
    int second_side;
    int third_side;

public:

    Triangle() {
        first_side = 0;
        second_side = 0;
        third_side = 0;

    }

    Triangle(int first_side, int second_side) {
        this->first_side = first_side;
        this->second_side = second_side;
        this->third_side = third_side;
    }

    Triangle(Triangle *rect) {
        first_side = rect->first_side;
        second_side = rect->second_side;
        third_side = rect->third_side;

    }
    ~Triangle() {}

    void setTriangle();
    void getTriangle();
    int  perimetr();
    void equal();


    friend int operator +(Triangle& a1) {

        int p = a1.perimetr();
        return p;

    }

    Triangle operator =(Triangle& a1) {

        first_side = a1.first_side;
        second_side = a1.second_side;
        return this;
    }
};




class ColoredTriangle : protected Triangle {
protected:
    string color;
public:
    ColoredTriangle();
    ColoredTriangle( int first_side, int second_side, int third_side);

    ~ColoredTriangle() {}
    void setColor();
    void getColor();
};

ColoredTriangle::ColoredTriangle() {
    color = "NULL";
}

ColoredTriangle::ColoredTriangle(int first_side, int second_side, int third_side) {

    this->color = color;
}



void Triangle::setTriangle() {
    cout << "Enter fiest side " << endl;
    cin >> first_side;
    cout << "Enter second side " << endl;
    cin >> second_side;
    cout << "Enter third side " << endl;
    cin >> third_side;

}




void ColoredTriangle::setColor() {
    cout << "Enter color" << endl;
    cin >> color;

}



void Triangle::getTriangle() {
    cout << "First side = " << first_side << endl;
    cout << "Second side = " << second_side << endl;
    cout << "Third side = " << third_side << endl;

}



void ColoredTriangle::getColor() {

    cout << "Color is " << color << endl;
}

void Triangle::equal() {

    if (first_side == second_side == third_side)
        cout << "It's a equilateral triangle!" << endl;

    if ( ( first_side == second_side ) || ( first_side == third_side ) || ( second_side == third_side ) )
        cout << "It's a isosceles triangle!" << endl;

}

int Triangle::perimetr() {
    if ((first_side + second_side < third_side) || (first_side + third_side < second_side) ||
        (second_side + third_side < first_side)) {
        cout << "Triangle is not exist!" << endl;
        return -1;
    }
    else
        return (first_side + second_side + third_side);
}








int main(){

    Triangle A;
    Triangle B;
    B = A;
    B.getTriangle();
    Triangle* R;
    R = new Triangle;

    Triangle rect = new Triangle;
    rect.getTriangle();
    R->setTriangle();
    R->getTriangle();
    R->equal();
    int P = R->perimetr();
    if (P !=-1)
        cout << "Perimetr = " << P << endl;

    delete R;

    ColoredTriangle* C;
    C = new ColoredTriangle;
    C->setColor();
    C->getColor();

    return 0;
}




