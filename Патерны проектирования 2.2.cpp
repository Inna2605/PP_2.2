// Добавить к коду на слайде 22 презентации по Паттернам проектирования (выслана в Тимс) возможность создавать кирпичные дома.

#include <iostream>
using namespace std;

//продукт () определяет интерфейс объектов, создаваемых фабричным методом
class House abstract
{};

//Конкретный продукт реализует интерфейс Product (в нашем случае, House) 
class PanelHouse :public House
{
public:
    PanelHouse()
    {
        cout << "Panel house built\n";
    }
};

//Конкретный продукт реализует интерфейс Product (в нашем случае, House)
class WoodHouse :public House
{
public:
    WoodHouse()
    {
        cout << "Wooden house built\n";
    }
};

class BrickHouse :public House
{
public:
    BrickHouse()
    {
        cout << "Brick house built\n";
    }
};

//Creator объявляет фабричный метод, возвращающий объект типа Product.
//абстрактный класс строительной компании
class Developer abstract
{
    //фабричный метод
public:
    virtual House* Create() = 0;
};

//конкретный создатель замещает фабричный метод, возвращающий объект ConcreteProduct.
//строит панельные дома
class PanelDeveloper :public Developer
{
public:
    House* Create()override
    {
        return new PanelHouse;
    }
};

//конкретный создатель замещает фабричный метод, возвращающий объект ConcreteProduct.
//строит деревянные дома
class WoodDeveloper :public Developer
{
public:
    House* Create()override
    {
        return new WoodHouse;
    }
};

//строит кирпичные дома
class BrickDeveloper :public Developer
{
public:
    House* Create()override
    {
        return new BrickHouse;
    }
};

//Патерн позволяет использовать в клиентском коде программы не специфические
//классы, а манипулировать абстрактными объектами на более высоком уровне.
House* Client(Developer* pDev)
{
    return pDev->Create();
}

int main()
{
    Developer* pDev = new PanelDeveloper();//создали объект создателя панельных домов
    House* pHouse = Client(pDev);//передали создателя в функцию Client и записали созданый дом в pHouse
    delete pHouse;
    delete pDev;
    cout << endl;

    pDev = new WoodDeveloper();//теперь pDev уже "смотрит" на создателя деревянных домов
    pHouse = Client(pDev);//передали создателя в функцию Client и записали созданный дом в pHouse
    delete pHouse;
    delete pDev;
    cout << endl;

    pDev = new BrickDeveloper();//pDev "смотрит" на создателя кирпичных домов
    pHouse = Client(pDev);
    delete pHouse;
    delete pDev;
    cout << endl;
}
