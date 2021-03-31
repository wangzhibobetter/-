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

class Factory
{
public:
    soapbase *createsoap(PROTECTTYPE type)
    {
        switch (type)
        {
            case SFJ:
                return new SFJsoap();
                break;
            case XSL:
                return new XSLsoap();
                break;
            case NAS:
                return new NASsoap();
                break;
            default:break;
        }
    }
};


int main()
{
    Factory factory;
    soapbase* sp1=factory.createsoap(SFJ);
    sp1->show();
    soapbase* sp2=factory.createsoap(XSL);
    sp2->show();
    soapbase* sp3=factory.createsoap(NAS);
    sp3->show();
    return 0;
}
