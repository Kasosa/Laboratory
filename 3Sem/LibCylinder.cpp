#include "LibShapes.h"
#include "LibCylinder.h"

// Конструктор для класса Cylinder
// Constructor for the Cylinder class

Cylinder::Cylinder(double new_h)
{
    cout << "\n- Конструктор Cylinder() -";

    if(new_h > 0)
    {
        h = new_h;
    }

    else
    {
        MyEx e(new_h, " * Неверное значение высоты!");
        throw e;
    }
}
// Деструктор для класса Cylinder
// Destructor for the Cylinder class
Cylinder::~Cylinder()
{
    cout << "\n- Деструктор Cylinder() -";
    delete f;
}
// Рассчитайте объем цилиндра
// Calculate the volume of the cylinder
double Cylinder::CalcVolume()
{
    return h *(f->Calc_Square());
}

// Конструктор для класса Circle Cylinder
// Constructor for the CircleCylinder class
CircleCylinder::CircleCylinder(Circle<double>* figure, double new_h):Cylinder(new_h)
{
    cout << "\n- Конструктор CircleCylinder() -";
    f = new Circle<double>(figure->GetRadius());
}

// Создайте новый экземпляр класса Circle Cylinder
// Create a new instance of the CircleCylinder class
CircleCylinder* CircleCylinder::CreateInstance(Circle<double>* figure, double new_h)
{
    CircleCylinder* CirCyl = new CircleCylinder(figure, new_h);
    return CirCyl;
}

CircleCylinder::~CircleCylinder()
{
    cout << "\n- Деструктор CircleCylinder() -";
}

TringleCylinder::TringleCylinder(Triangle<double>* figure, double new_h):Cylinder(new_h)
{
    cout << "\n- Конструктор TringleCylinder() -";
    f = new Triangle<double>(figure->GetSideA(), figure->GetSideB(), figure->GetSideC() );
}

TringleCylinder* TringleCylinder::CreateInstance(Triangle<double>* figure, double new_h)
{
    TringleCylinder* TriCyl = new TringleCylinder(figure, new_h);
    return TriCyl;
}

TringleCylinder::~TringleCylinder()
{
    cout << "\n- Деструктор TringleCylinder() -";
}

StarCylinder::StarCylinder(Star<double>* figure, double new_h):Cylinder(new_h)
{
    cout << "\n- Конструктор StarCylinder() -";
    f = new Star<double>(figure->GetBaseRay());
}

StarCylinder* StarCylinder::CreateInstance(Star<double>* figure, double new_h)
{
    StarCylinder* StaCyl = new StarCylinder(figure, new_h);
    return StaCyl;
}

StarCylinder::~StarCylinder()
{
    cout << "\n- Деструктор StarCylinder() -";
}
