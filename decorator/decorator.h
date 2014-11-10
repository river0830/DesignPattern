#pragma once

#include <string>

class cBeverage
{
public:
    virtual ~cBeverage(){ };

    virtual float cost(void) = 0;
    virtual void show(void) = 0;

protected:
    cBeverage(){};
};

class cCondimentDecorator : public cBeverage
{
public:
    virtual float cost(void);
    virtual void show(void);

protected:
    cCondimentDecorator(cBeverage *);

private:
    cBeverage *priv;
};

//subclass
class cTea : public cBeverage
{
public:
    cTea():mPrice(10.0f){};

    virtual float cost(void);
    virtual void show(void);

private:
    float mPrice;
};

class cCoffee : public cBeverage
{
public:
    cCoffee():mPrice(20.0f){};

    virtual float cost(void);
    virtual void show(void);

private:
    float mPrice;
};

//sub decorator class
class cMilk : public cCondimentDecorator
{
public:
    virtual float cost(void);
    virtual void show(void);

    cMilk(cBeverage *c) : cCondimentDecorator(c) {};
};
class cSugar : public cCondimentDecorator
{
public:
    virtual float cost(void);
    virtual void show(void);

    cSugar(cBeverage *c) : cCondimentDecorator(c) {};
};
class cFlower : public cCondimentDecorator
{
public:
    virtual float cost(void);
    virtual void show(void);

    cFlower(cBeverage *c) : cCondimentDecorator(c) {};
};

//================================
//test demo
void decorator_test(void);
void discount_test(void);
