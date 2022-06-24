#include <iostream>
using namespace std;

class Base {
public:
    virtual void funcA() {cout << "Base A\n";}
    void funcB() {cout << "Base B\n";}
};

class Derived : public Base {
public:
    void funcA() final {cout << "Derived A\n";}
    void funcB() {cout << "Derived B\n";}
};

int main() {
    Base* p = new Derived();
    p->funcA();
    p->funcB();
    //输出结果
}
