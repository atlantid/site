#include <iostream>
#include <typeinfo>
#include <any>

typedef char* CHARS;
typedef CHARS const CPTR;
typedef const CHARS CCPTR;

template<class T, int n = 5> T Sum(T a)
{

    if constexpr(n==0)
    {
        return a;
    }
    return Sum<decltype(a),n-1>(a+n);
}



int main(int argc, char *argv[])
{
    std::cout<<Sum(12)<<std::endl;
    std::any a = 12;
    std::cout<<std::any_cast<int>(a)<<std::endl;

    std::cout<<typeid(CPTR).name()<<std::endl;
    std::cout<<typeid(CCPTR).name()<<std::endl;
    int aa;
    std::cin>>aa;
    return 0;
}

