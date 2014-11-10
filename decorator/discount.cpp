#include <iostream>

#include "decorator.h"

using namespace std;


/*
 * 某饭店打折,分金卡,银卡,普通顾客;每种卡打折不一样
 *
 */

class cCustomerImpl
{
public:
    cCustomerImpl(float m = 10.0f) : m_Price(m) {};
    virtual ~cCustomerImpl() {};

    virtual float cost() = 0;
    virtual void SetDiscount(float m) = 0;

    float GetPrice()
    {
        return m_Price;
    }
    void SetPrice(float m)
    {
        if(m > 0)
        {
            m_Price = m;
        }
    }

private:
    float m_Price;
};

class cCustomer : public cCustomerImpl
{
public:
    virtual float cost()
    {
        cout << "cCustomer cost!" << endl;
        return GetPrice();
    }
    virtual void SetDiscount(float m)
    {
        cout << "cCustomer SetDiscount!" << endl;
    }
};

class cCustomerDecorator : public cCustomerImpl
{
public:
    explicit cCustomerDecorator(cCustomerImpl *c) : mp_Customer(c) {};

    virtual float cost()
    {
        cout << "Decorator cost!" << endl;
        if(mp_Customer)
        {
            return mp_Customer->cost();
        }

        return 1.0f;
    }
    virtual void SetDiscount(float m)
    {
        if(mp_Customer)
        {
            mp_Customer->SetDiscount(m);
        }
        cout << "Decorator SetDiscount!" << endl;
    }

protected:
    cCustomerImpl *mp_Customer;
};

class cCommCustomer : public cCustomerDecorator
{
public:
    explicit cCommCustomer(cCustomerImpl *c) : cCustomerDecorator(c)
    {
        m_Discount = 0.9f;
    };

    virtual float cost()
    {
        cout << "Comm cost!" << endl;
        if(mp_Customer)
        {
            return mp_Customer->cost() * m_Discount;
        }

        return m_Discount;
    }
    virtual void SetDiscount(float m)
    {
        m_Discount = m;
        cout << "Comm SetDiscount!" << endl;
    }

private:
    float m_Discount;
};

class cSiliverCustomer : public cCustomerDecorator
{
public:
    explicit cSiliverCustomer(cCustomerImpl *c) : cCustomerDecorator(c)
    {
        m_Discount = 0.8f;
    };

    virtual float cost()
    {
        cout << "Siliver cost!" << endl;
        if(mp_Customer)
        {
            return mp_Customer->cost() * m_Discount;
        }

        return m_Discount;
    }
    virtual void SetDiscount(float m)
    {
        m_Discount = m;
        cout << "Siliver SetDiscount!" << endl;
    }

private:
    float m_Discount;
};

class cGoldCustomer : public cCustomerDecorator
{
public:
    explicit cGoldCustomer(cCustomerImpl *c) : cCustomerDecorator(c)
    {
        m_Discount = 0.7f;
    }

    virtual float cost()
    {
        cout << "Gold cost!" << endl;
        if(mp_Customer)
        {
            return mp_Customer->cost() * m_Discount;
        }

        return m_Discount;
    }
    virtual void SetDiscount(float m)
    {
        m_Discount = m;
        cout << "Gold SetDiscount!" << endl;
    }

private:
    float m_Discount;
};

void discount_test(void)
{
    cCustomer b;
    cCustomerImpl *pCustomer = &b;
    cCustomerImpl *pCommCustomer = new cCommCustomer(pCustomer);
    cCustomerImpl *pSiliverCustomer = new cSiliverCustomer(pCustomer);
    cCustomerImpl *pGoldCustomer = new cGoldCustomer(pCustomer);

    cout << "sizeof cCustomerImpl " << sizeof(cCustomerImpl) << endl;
    cout << "sizeof cCustomer " << sizeof(cCustomer) << endl;
    cout << "sizeof cCustomerDecorator " << sizeof(cCustomerDecorator) << endl;
    cout << "sizeof cCommCustomer " << sizeof(cCommCustomer) << endl;
    cout << "sizeof cSiliverCustomer " << sizeof(cSiliverCustomer) << endl;
    cout << "sizeof cGoldCustomer " << sizeof(cGoldCustomer) << endl;

    cout << "GeneralCustomer cost " << pCustomer->cost() << endl;
    cout << "CommCustomer cost " << pCommCustomer->cost() << endl;
    cout << "SiliverCustomer cost " << pSiliverCustomer->cost() << endl;
    cout << "GoldCustomer cost " << pGoldCustomer->cost() << endl;

    delete pSiliverCustomer;
    delete pGoldCustomer;

    //pCustomer->SetPrice(100.0f);
    pSiliverCustomer = new cSiliverCustomer(pCommCustomer);
    pGoldCustomer    = new cGoldCustomer(pSiliverCustomer);

    cout << "GeneralCustomer cost " << pCustomer->cost() << endl;
    cout << "CommCustomer cost " << pCommCustomer->cost() << endl;
    cout << "SiliverCustomer cost " << pSiliverCustomer->cost() << endl;
    cout << "GoldCustomer cost " << pGoldCustomer->cost() << endl;

    delete pCustomer;
    delete pCommCustomer;
    delete pSiliverCustomer;
    delete pGoldCustomer;
}
