#include <iostream>

using namespace std;

// Base class for a cylinder
// Базовый класс для цилиндра
class Cylinder
{
    private:

        double h;

     protected:

        Figure* f; // указатель на фигурный объект // pointer to a Figure object

    public:

        Cylinder(double);
        virtual ~Cylinder();

        double CalcVolume();

};

// Derived class for a cylinder with a circular base
// Производный класс для цилиндра с круглым основанием
class  CircleCylinder: public Cylinder
{
    private:

        CircleCylinder(Circle<double>*, double);

    public:

        virtual ~CircleCylinder();

        static CircleCylinder* CreateInstance(Circle<double>*, double);

};

// Derived class for a cylinder with a triangular base
// Производный класс для цилиндра с треугольным основанием
class  TringleCylinder: public Cylinder
{
    private:

        TringleCylinder(Triangle<double>*, double);

    public:

        virtual ~TringleCylinder();

        static TringleCylinder* CreateInstance(Triangle<double>*, double);

};

// Derived class for a cylinder with a star-shaped base
// Производный класс для цилиндра со звездообразным основанием
class  StarCylinder: public Cylinder
{
    private:

        StarCylinder(Star<double>*, double); // constructor (конструктор)

    public:

        virtual ~StarCylinder(); // virtual destructor (виртуальный деструктор)

        static StarCylinder* CreateInstance(Star<double>*, double); // static method to create an instance of StarCylinder
                                                                    // статический метод для создания экземпляра Start cylinder      
};
