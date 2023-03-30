

#include <conio.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class Circle {
public:
    int midX;
    int midY;
    int R;
public:
    Circle() { // конструктор без параметра 
        midX = 0;
        midY = 0;
        R = 1;
        cout << "Circle = (" << midX << " " << midY << " " << R << ") " << endl;

    }
    Circle(int midX, int midY, int R) { //конструктро с параметром
        this->midX = midX;
        this->midY = midY;
        this->R = R;
        cout << "Circle(int midX, int midY, int R) = (" << midX << " " << midY << " " << R << ") " << endl;
    }
    Circle(const Circle &m) { //конструктор копирования
        midX = m.midX;
        midY = m.midY;
        R = m.R;
        cout << "Circle(const Circle &m) = (" << midX << " " << midY << " " << R << ") " << endl;

    }
    ~Circle() { //деструктор
        cout << "Circle (" << midX << " " << midY << " " << R << ") " << "delete" << endl;
    }
    void changeR(int dm) { //реализация метода в определении
        R = R + dm;
        cout << "changedR Circle = (" << midX << " " << midY << " " << R << ") " << endl;
    }
    void changeMid(int dx, int dy);
};

void Circle::changeMid(int dx, int dy){ //реализация метода после определения
     midX = midX + dx;
     midY = midY + dy;
     cout << "changeMid Circle = (" << midX << " " << midY << " " << R << ") " << endl;

}



class ColorCircle : public Circle { //композиция
public:
    int color;
public:
    ColorCircle() : Circle() { // конструктор без параметра
        color = 1;
        cout << "ColorCircle(" << midX << " " << midY << " " << R << " " << color << ") " << endl;
    }
    ColorCircle(int midX, int midY, int R, int color): Circle(midX,midY,R) { //конструктро с параметром
        this->color = color;
        cout << "ColorCircle(" << midX << " " << midY << " " << R << " " << color << ") " << endl;
    }
    ColorCircle(const ColorCircle &m) { //конструктор копирования
        color = m.color;
        midX = m.midX;
        midY = m.midY;
        R = m.R;
        cout << "ColorCircle(" << midX << " " << midY << " " << R << " " << color << ") " << endl;
    }
    ~ColorCircle() { //деструктор
        cout << "ColorCircle(" << midX << " " << midY << " " << R << " " << color << ") " << "delete" << endl;
    }
    void changecolor(int dm) { //реализация метода в определении
        color = color + dm;
        cout << "change ColorCircle(" << midX << " " << midY << " " << R << " " << color << ") " << endl;
    }
};

class Cylinder {
public:
    Circle* m1;
    Circle* m2;
public:
    Cylinder() { // конструктор без параметра 
        cout << "Cylinder " << endl;
        m1 = new Circle;
        m2 = new Circle;
    }
    Cylinder(int x1, int y1, int R1, int x2, int y2, int R2) { //конструктро с параметром
        cout << "Cylinder(int x1, int y1, int R1, int x2, int y2, int R2) " << endl;
        m1 = new Circle(x1,y1,R1);
        m2 = new Circle(x2,y2,R2);
    }
    Cylinder(const Cylinder &s) { //конструктор копирования
        cout << "Cylinder(const Circle &m)" << endl;
        m1 = new Circle(*s.m1);
        m2 = new Circle(*s.m2);
    }
    ~Cylinder() { //деструктор
        delete m1;
        delete m2;
        cout << "Cylinder() delete" << endl;
    }
};




int main()
{
    //композиция классов
    
    Cylinder* n1 = new Cylinder; //создание класса Cylinder из объектов класса Circle
    Cylinder* n2 = new Cylinder(10,10,2, 10, 20, 2); 
    Cylinder* n3 = new Cylinder(*n2);
    delete n1;
    delete n2;
    delete n3;
    

    /*
    Circle *m1 = new ColorCircle(10, 10, 7, 2); //помещение объекта потомка в указатель на базовый класс
    ColorCircle *m2 = new ColorCircle(10, 12, 3, 3); //помещение объекта ColorCircle в переменную своего класса 
    delete m1;
    delete m2;
    */


    /*
    ColorCircle *m = new ColorCircle(10, 10, 2, 20); // динамическое создание класса наследника
    m->changecolor(2);
    delete m;
    */


    /*
    Circle *m = new Circle; //динамическое создание
    m->changeMid(2, 2);
    Circle *m2 = new Circle(10,10,2);
    m->changeR(3);
    Circle *m3 = new Circle(*m2);
    m->changeMid(3, 3);
    delete m;
    delete m2;  
    delete m3;
    */


    /*
    {
        Circle m; //статическое создание
        m.changeMid(2, 2);
        Circle m2(10, 10, 2);
        m2.changeR(1);
        Circle m3(m2);
        m3.changeR(-1);
    }
    */

    _getch();
    return 0;
}

