#include <iostream>

using namespace std;

enum PROTECTTYPE
{
    SFJ,
    XSL,
    NAS
};

class soapbase
{
public:
    ~soapbase();
    virtual void show() = 0;
};

class SFJsoap : public soapbase
{
    void show()
    {
        cout << "SFL" << endl;
    }
};
class XSLsoap : public soapbase
{
    void show()
    {
        cout << "XSL" << endl;
    }
};
class NASsoap : public soapbase
{
    void show()
    {
        cout << "NAS" << endl;
    }
};

class FactoryBase
{
    public:
    virtual soapbase* createprotect()=0;
};
class SFJFactory : public FactoryBase
{
    public:
    soapbase* createprotect()
    {
        return new SFJsoap;
    }
};
class XLSFactory : public FactoryBase
{
    public:
    soapbase* createprotect()
    {
        return new XSLsoap;
    }
};
class NASFactory : public FactoryBase
{
    public:
    soapbase* createprotect()
    {
        return new NASsoap;
    }
};



int main()
{
    SFJFactory factory1;
    soapbase* sp1=factory1.createprotect();
    sp1->show();
    XLSFactory factory2;
    soapbase* sp2=factory2.createprotect();
    sp2->show();
    NASFactory factory3;
    soapbase* sp3=factory3.createprotect();
    sp3->show();
    return 0;
}
