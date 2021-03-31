#include<iostream>

using namespace std;


class Target
{
    public:
    Target(){}
    virtual ~Target(){}
    virtual void Request()
    {
        cout<<"Target  Request"<<endl;
    }
};

class Adaptee
{
    public:
    Adaptee(){}
    ~Adaptee(){}
    void SpeRequst()
    {
        cout<<"'Adaptee SpeRequest"<<endl;
    }
};

class Adapter:public Target,private Adaptee
{
    public:
    Adapter(){}
    ~Adapter(){}
    void Request()
    {
        this->SpeRequst();
    }
};


int main()
{
    Target* T=new Adapter();
    T->Request();
    delete T;
    return 0;
}