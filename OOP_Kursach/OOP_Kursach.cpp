/*
Класс «Зубчатое колесо». Колодяжный Максим Алексеевич
Поля данных – количество зубьев у зубчатого колеса,
длина зуба вдоль обода зубчатого колеса, угловая скорость вращения зубчатого колеса,
момент инерции колеса. Методы класса возвращают радиус колеса, длину обода колеса,
линейную скорость точек на ободе колеса, момент импульса колеса и кинетическую энергию вращательного
движения зубчатого колеса. Создав объекты – зубчатые колёса с одинаковыми размерами зубьев, но с
разным количеством зубьев, соединить их в зубчатую передачу. Задав угловую скорость вращения одного
объекта-колеса, вычислить скорости вращения других колёс. Рассчитать отношения моментов импульсов и
кинетических энергий вращения пары любых объектов - колёс. Для этих расчётов создать функции, аргументы
которых – объекты.
*/

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

class GearWheel {
public:
    GearWheel(){}
    GearWheel(unsigned, double, double, double);
    unsigned GetTeethNum();
    double GetRadius();
    double GetWheelRimLength();
    double GetRimDotsSpeed();
    double GetKineticEnergy();
    double GetToothLength();
    double GetAngVel();
    double GetAngMom();
    void PutTeethNum(unsigned);
    void PutToothLength(double);
    void PutAngVel(double);
    void PutAngMom(double);
private:
    unsigned TeethNum;//z
    double ToothLength; //D_d
    double AngVel, AngMom;
};

double Connect(GearWheel, GearWheel&);

int main()
{
    GearWheel G1(16, 0.25, 25.5, 16.7), G2, G3, G4;
    double i;
    G2.PutTeethNum(10); 
    G2.PutToothLength(G1.GetToothLength());
    G3.PutTeethNum(12);
    G3.PutToothLength(G2.GetToothLength()); 
    G4.PutTeethNum(24);
    G4.PutToothLength(G3.GetToothLength());
    i = Connect(G1, G2);
    cout << "Ratio of Angular Momentum of second gearwheel to the Angular Moment of first one: " << i << endl;
    cout << "Ratio of Kinetic Energy of second gearwheel to the Kinetic Energy of first one: " << pow(i, 2) / 2 << endl;
    i = Connect(G2, G3);
    cout << "Ratio of Angular Momentum of third gearwheel to the Angular Moment of second one: " << i << endl;
    cout << "Ratio of Kinetic Energy of second gearwheel to the Kinetic Energy of first one: " << pow(i, 2) / 2 << endl;
    i = Connect(G3, G4);
    cout << "Ratio of Angular Momentum of fourth gearwheel to the Angular Moment of third one: " << i << endl;
    cout << "Ratio of Kinetic Energy of second gearwheel to the Kinetic Energy of first one: " << pow(i, 2) / 2 << endl;
}

double Connect(GearWheel Spinner, GearWheel& Spinned) {
    // i - передаточное число
    double i = (double)Spinned.GetTeethNum()/Spinner.GetTeethNum();
    Spinned.PutAngMom(Spinner.GetAngMom()*i);
    Spinned.PutAngVel(Spinner.GetAngVel()*i);
    return i;
}

//m = ToothLength / TeethNum
GearWheel::GearWheel(unsigned TeethNumInp, double ToothLengthInp, double AngVelInp, double AngMomInp) {
    TeethNum = TeethNumInp;
    ToothLength = ToothLengthInp;
    AngVel = AngVelInp;
    AngMom = AngMomInp;
}

unsigned GearWheel::GetTeethNum() {
    return TeethNum;
}

double GearWheel::GetRadius() { // D_e / 2
    return ToothLength * (0.5 + 1/TeethNum); // R = D_e/2 = (D_d + 2m)/2
}
double GearWheel::GetWheelRimLength() {
    return (GetRadius() - GetToothLength()) * 2 * M_PI;
}
double GearWheel::GetRimDotsSpeed() {
    return AngVel * GetRadius();
}
double GearWheel::GetKineticEnergy() {
    return AngMom * pow(AngVel, 2) / 2;
}
double GearWheel::GetToothLength() {
    return ToothLength;
}
double GearWheel::GetAngVel() {
    return AngVel;
}
double GearWheel::GetAngMom() {
    return AngMom;
}

void GearWheel::PutTeethNum(unsigned input) {
    TeethNum = input;
}
void GearWheel::PutToothLength(double input) {
    ToothLength = input;
}
void GearWheel::PutAngVel(double input) {
    AngVel = input;
}
void GearWheel::PutAngMom(double input) {
    AngMom = input;
}

