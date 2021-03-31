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

class Adapter:public Target
{
    public:
    Adapter(Adaptee* ada){
        adaptee=ada;
    }
    Adapter(){}
    ~Adapter(){}
    void Request()
    {
        this->adaptee->SpeRequst();
    }
    private:
    Adaptee* adaptee;
};


int main()
{
    Target* T=new Adapter();
    T->Request();
    delete T;
    return 0;
}

int main(int arc, char **argv)
{
    /* 构造函数1创建对象 */
    Adaptee* adaptee = new Adaptee();
    Target* target0= new Adapter(adaptee);
    target0->Request();
	delete adaptee;
	delete target0;
	
    /* 构造函数2创建对象 */
    Target* target1 = new Adapter();
    target1->Request();
	delete target1;
	
    return 0;
}