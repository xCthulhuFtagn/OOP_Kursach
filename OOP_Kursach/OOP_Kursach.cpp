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
#include <fstream>

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

void Connect(GearWheel&, GearWheel&);
double InnerConnect(GearWheel&, GearWheel&);
double RatioAngMom(GearWheel& Spinner, GearWheel& Spinned);
double RatioKinEn(GearWheel& Spinner, GearWheel& Spinned);

int main()
{
    const string path = "output.txt";
    ofstream output(path);
    setlocale(LC_ALL, "Russian");
    GearWheel G1(1.6, 0.25, 25.5, 16.7), G2, G3, G4;
    double i;
    G2.PutTeethNum(10); 
    G2.PutToothLength(G1.GetToothLength());
    G3.PutTeethNum(12);
    G3.PutToothLength(G2.GetToothLength()); 
    G4.PutTeethNum(24);
    G4.PutToothLength(G3.GetToothLength());
    cout << "Входные данные" << endl;
    cout << "Параметры первого зубчатого колеса: количество зубьев = " << G1.GetTeethNum() << " шт; длина зуба = " << G1.GetToothLength() << " м; угловая скорость = " << G1.GetAngVel() << " рад/с ; угловой момент = " << G1.GetAngMom() << endl;
    cout << "Параметры второго зубчатого колеса: количество зубьев = " << G2.GetTeethNum() << " шт; длина зуба = " << G2.GetToothLength() << " м" << endl;
    cout << "Параметры второго зубчатого колеса: количество зубьев = " << G3.GetTeethNum() << " шт; длина зуба = " << G3.GetToothLength() << " м" << endl;
    cout << "Параметры второго зубчатого колеса: количество зубьев = " << G4.GetTeethNum() << " шт; длина зуба = " << G4.GetToothLength() << " м" << endl;
    cout << "************************************************************" << endl;
    output << "Входные данные" << endl;
    output << "Параметры первого зубчатого колеса: количество зубьев = " << G1.GetTeethNum() << " шт; длина зуба = " << G1.GetToothLength() << " м; угловая скорость = " << G1.GetAngVel() << " рад/с ; угловой момент = " << G1.GetAngMom() << endl;
    output << "Параметры второго зубчатого колеса: количество зубьев = " << G2.GetTeethNum() << " шт; длина зуба = " << G2.GetToothLength() << " м" << endl;
    output << "Параметры второго зубчатого колеса: количество зубьев = " << G3.GetTeethNum() << " шт; длина зуба = " << G3.GetToothLength() << " м" << endl;
    output << "Параметры второго зубчатого колеса: количество зубьев = " << G4.GetTeethNum() << " шт; длина зуба = " << G4.GetToothLength() << " м" << endl;
    output << "************************************************************" << endl;
    Connect(G1, G2);
    cout << "Отношение момента импульса первого зубчатого колеса к моменту импульса второго: " << RatioAngMom(G1, G2) << endl;
    cout << "Отношение кинетической энергии первого зубчатого колеса к кинетической энергии второго: " << RatioKinEn(G1, G2) << endl;
    output << "Отношение момента импульса первого зубчатого колеса к моменту импульса второго: " << RatioAngMom(G1, G2) << endl;
    output << "Отношение кинетической энергии первого зубчатого колеса к кинетической энергии второго: " << RatioKinEn(G1, G2) << endl;
    Connect(G2, G3);
    cout << "Отношение момента импульса второго зубчатого колеса к моменту импульса третьего: " << RatioAngMom(G2, G3) << endl;
    cout << "Отношение кинетической энергии второго зубчатого колеса к кинетической энергии третьего: " << RatioKinEn(G2, G3) << endl;
    output << "Отношение момента импульса второго зубчатого колеса к моменту импульса третьего: " << RatioAngMom(G2, G3) << endl;
    output << "Отношение кинетической энергии второго зубчатого колеса к кинетической энергии третьего: " << RatioKinEn(G2, G3) << endl;
    Connect(G3, G4);
    cout << "Отношение момента импульса третьего зубчатого колеса к моменту импульса четвертого: " << RatioAngMom(G3, G4) << endl;
    cout << "Отношение кинетической энергии третьего зубчатого колеса к кинетической энергии четвертого: " << RatioKinEn(G3, G4) << endl;
    output << "Отношение момента импульса третьего зубчатого колеса к моменту импульса четвертого: " << RatioAngMom(G3, G4) << endl;
    output << "Отношение кинетической энергии третьего зубчатого колеса к кинетической энергии четвертого: " << RatioKinEn(G3, G4) << endl;
    cout << "Линейные скорости всех зубчатых колес: " << endl;
    cout << "Первое колесо: " << G1.GetRimDotsSpeed() << endl;
    cout << "Второе колесо: " << G2.GetRimDotsSpeed() << endl;
    cout << "Третье колесо: " << G3.GetRimDotsSpeed() << endl;
    cout << "Четвертое колесо: " << G4.GetRimDotsSpeed() << endl;
    output << "Линейные скорости всех зубчатых колес: " << endl;
    output << "Первое колесо: " << G1.GetRimDotsSpeed() << endl;
    output << "Второе колесо: " << G2.GetRimDotsSpeed() << endl;
    output << "Третье колесо: " << G3.GetRimDotsSpeed() << endl;
    output << "Четвертое колесо: " << G4.GetRimDotsSpeed() << endl;
}

void Connect(GearWheel& Spinner, GearWheel& Spinned) {
    // i - передаточное число
    double i = -(double)Spinned.GetRadius()/Spinner.GetRadius(); //при внешнем зацеплении направление вращения изменяется
    Spinned.PutAngMom(Spinner.GetAngMom() * pow(i, 6));
    Spinned.PutAngVel(Spinner.GetAngVel() * i);
}

double InnerConnect(GearWheel& Spinner, GearWheel& Spinned) {
    double i = (double)Spinned.GetRadius() / Spinner.GetRadius();//при внутреннем зацеплении направление вращения не изменяется
    Spinned.PutAngMom(Spinner.GetAngMom() * pow(i, 6));
    Spinned.PutAngVel(Spinner.GetAngVel() * i);
}

double RatioAngMom(GearWheel& Spinner, GearWheel& Spinned) {
   return pow(Spinner.GetRadius() / Spinned.GetRadius(), 4);
}

double RatioKinEn(GearWheel& Spinner, GearWheel& Spinned) {
    return pow(Spinner.GetRadius() / Spinned.GetRadius(), 6);
}

//m = ToothLength / TeethNum
GearWheel::GearWheel(unsigned TeethNumInp, double ToothLengthInp, double AngVelInp, double AngMomInp) 
{
    TeethNum = TeethNumInp;
    ToothLength = ToothLengthInp;
    AngVel = AngVelInp;
    AngMom = AngMomInp;
}
unsigned GearWheel::GetTeethNum() { return TeethNum; }
double GearWheel::GetRadius() { return (TeethNum+2)*ToothLength/4.5; /* R = D_e/2 = (z+2)*m/2 = (z+2)*h/4.5 */ }
double GearWheel::GetWheelRimLength() { return (GetRadius() - GetToothLength()) * 2 * M_PI; }
double GearWheel::GetRimDotsSpeed() { return AngVel * GetRadius(); }
double GearWheel::GetKineticEnergy() { return AngMom * pow(AngVel, 2) / 2; }
double GearWheel::GetToothLength() { return ToothLength; }
double GearWheel::GetAngVel() { return AngVel; }
double GearWheel::GetAngMom() { return AngMom; }
void GearWheel::PutTeethNum(unsigned input) { TeethNum = input; }
void GearWheel::PutToothLength(double input) { ToothLength = input; }
void GearWheel::PutAngVel(double input) { AngVel = input; }
void GearWheel::PutAngMom(double input) { AngMom = input; }

