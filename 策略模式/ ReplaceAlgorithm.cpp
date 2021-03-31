#include<iostream>

using namespace std;


class ReplaceAlgorithm
{
    public:
        virtual void Replace()=0;
};


//三种具体的替换算法
class LRU_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
	void Replace() { cout<<"Least Recently Used replace algorithm"<<endl; }
};
 
class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
	void Replace() { cout<<"First in First out replace algorithm"<<endl; }
};
class Random_ReplaceAlgorithm: public ReplaceAlgorithm
{
public:
	void Replace() { cout<<"Random replace algorithm"<<endl; }
};



//Cache需要用到替换算法
// //方法一
// class Cache
// {
//     private:
//         ReplaceAlgorithm *m_ptr;
//     public:
//         Cache(ReplaceAlgorithm *p)
//         {
//             m_ptr=p;
//         }
//         ~Cache()
//         {
//             delete m_ptr;
//         }
//         void  Replace()
//         {
//             m_ptr->Replace();
//         }
// };
// int main()
// {
//     Cache c=Cache(new LRU_ReplaceAlgorithm);
//     c.Replace();
//     return 0;
// }

// //方法二

// enum Ra {LRU,FIFO,Random};//标签
// class Cache
// {
//     public:
//     Cache(enum Ra ra )
//     {
//         if(ra==LRU)
//         {
//             m_ptr=new LRU_ReplaceAlgorithm();
//         }
//         if(ra==FIFO)
//         {
//             m_ptr=new FIFO_ReplaceAlgorithm();
//         }
//         if(ra==Random)
//         {
//             m_ptr=new Random_ReplaceAlgorithm();
//         }
//     }
//     void Replace()
//     {
//         m_ptr->Replace();
//     }

//     private:
//         ReplaceAlgorithm* m_ptr;
    
// };


// int main()
// {
//     Cache c=Cache(LRU);
//     c.Replace();
//     return 0;
//}

//方法三 模版

template<typename ra>
class Cache
{
    private:
    ra m_ptr;
    public:
    Cache(){}
    ~Cache(){}
    void Repalce()
    {
        m_ptr.Replace();
    }
};

int main()
{
    Cache<FIFO_ReplaceAlgorithm> c;
    c.Repalce();
    return  0;
}





















