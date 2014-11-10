#include <iostream>
#include <string>
#include <utility>

#include "decorator.h"

using namespace std;

//decorator
cCondimentDecorator :: cCondimentDecorator(cBeverage *rhs)
{
     priv = rhs;
}

float cCondimentDecorator::cost(void)
{
    if(priv)
    {
        return priv->cost();
    }

    return 1.0f;
}

void cCondimentDecorator::show(void)
{
    if(priv)
    {
        priv->show();
    }
}

//tea
float cTea::cost()
{
    cout << "tea price " << mPrice << endl;
    return mPrice;
}
void cTea::show()
{
    cout << "A cup tea!" << endl;
}
//coffee
float cCoffee::cost()
{
    cout << "coffee price " << mPrice << endl;
    return mPrice;
}
void cCoffee::show()
{
    cout << "A cup coffee!" << endl;
}
//mick
float cMilk::cost()
{
    float p = cCondimentDecorator::cost();

    p += 5.0f;
    cout << "add milk price:  " <<  p << endl;
    return p;
}
void cMilk::show()
{
    cCondimentDecorator::show();
    cout << "add milk" << endl;
}
//sugar
float cSugar::cost()
{
    float p = cCondimentDecorator::cost();

    p += 6.0f;
    cout << "add sugar price: " << p << endl;
    return p;
}
void cSugar::show()
{
    cCondimentDecorator::show();
    cout << "add sugar" << endl;
}
//flower
float cFlower::cost()
{
    float p = cCondimentDecorator::cost();

    p += 7.0f;
    cout << "add flower price: " << p << endl;
    return p;
}
void cFlower::show()
{
    cCondimentDecorator::show();
    cout << "add flower" << endl;
}

//=======================================
void decorator_test(void)
{
    cBeverage *pT = new cTea();
    cBeverage *pD = new cMilk(pT);

    pD->show();
    pD->cost();

    delete pT;
    delete pD;
}

