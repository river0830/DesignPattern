#include <iostream>
#include "decorator.h"

using namespace std;

class b
{
public:
    b() : i(100) {};
    virtual void f()
    {
        cout << "b:f()!" << endl;
    }
    virtual void ff()
    {
        cout << "b:ff()!" << endl;
    }

private:
    int i;
};

class c : public b
{
public:
    virtual void f()
    {
        cout << "c:f()!" << endl;
    }
    virtual void ff()
    {
        cout << "c:ff()!" << endl;
    }

    void g()
    {
        cout << "c:g()!" << endl;
    }

private:
    b *priv;
};

class d : public c
{
public:
    virtual void f()
    {
        cout << "d:f()!" << endl;
    }
    virtual void ff()
    {
        cout << "d:ff()!" << endl;
    }
};

void mem_test(void)
{
    cout << "sizeof b " << sizeof(b) << endl;
    cout << "sizeof c " << sizeof(c) << endl;
    cout << "sizeof d " << sizeof(d) << endl;

    typedef void (*fun)(void);
    fun pfun = NULL;

    b bb;
    c cc;
    d dd;

    int **vtrb = (int **)&bb;

    pfun = (fun)vtrb[0][0];
    pfun();
    cout << "vtrb[1] " << (int)vtrb[1] << endl;

    vtrb = (int **)&cc;
    pfun = (fun)vtrb[0][0];
    pfun();
    pfun = (fun)vtrb[0][1];
    pfun();

    class vv
    {
    public:
        virtual float fv1() = 0;
        virtual void fv2() = 0;

    private:
        int mm = 10;
    };

    class vvv : public vv
    {
    public:
        virtual float fv1()
        {
            cout << "vvv:fv1()!" << endl;
            return 0.0f;
        }
        virtual void fv2()
        {
            cout << "vvv:fv2()!" << endl;
        }
    };

    vvv v;

    vtrb = (int **)&v;

    typedef float (*pFloat)(void);
    pFloat pffun = NULL;

    pffun = (pFloat)vtrb[0][0];
    pffun();
    pfun = (fun)vtrb[0][1];
    pfun();
    cout << "vv mm " << (int)vtrb[1] << endl;
}

int main()
{
    mem_test();
    decorator_test();
    discount_test();

    return 0;
}

