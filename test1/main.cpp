// // #include <iostream>


// // class A {
// // public:

// //     A (int n = 0) : m_n(n) {
// //         std::cout << 'd';
// //     }

// //     A(const A& a) : m_n(a.m_n){
// //         std::cout << 'c';
// //     }

// // private:

// //     int m_n;
// // };


// // void f(const A &a1, const A &a2 = A()) {

// // }



// // int main() {

// //     A a(2), b;

// //     const A c(a), &d = c , e = b;
// //     b = d;

// //     A *p= new A(c), *q = &a;

// //     static_cast<void>(q);

// //     delete p;

// //     f(3);

// //     std::cout << std::endl;

// //     return 0;
// // }


// #include <iostream>

// #include <vector>


// class A {
// public:
//     A(int n = 0) : m_n(n){}

// public:
//     virtual int f() const {return m_n; }
//     virtual ~A() {}

// protected:

//     int m_n;
// };


// class B : public A {

// public:

//     B(int n = 0) : A(n) {}

// public:

//     virtual int f() const { return m_n + 1;}
// };


// int main() {


//     const A a(1);
//     const B b(3);

//     const A *x[2] = {&a , &b};

//     typedef std::vector<A> V;

//     V y({a,b});

//     V::const_iterator i = y.begin();


//     std::cout << x[0]->f() << x[1]->f() << i->f() << (i + 1)->f() << std::endl;
// }





// #include <iostream>

// #include <stdexcept>

// class A {

// public: //

//     A(int n) {
//         if (0 == n) {
//             throw std::logic_error("0");
//         }
//     }
// };


// int main() {


//     A *p0 = nullptr, *p1 = nullptr, *p2 = nullptr;

//     try {
//         p1 = new A(1);
//         p0 = new A(0);
//         p2 = new A(2);
//     } catch (const std::exception &) {

//         std:: cout << 3;
//     }


//     std::cout << ((0 != p1) ? 1 : 0);
//     std::cout << ((0 != p0) ? 1 : 0);
//     std::cout << ((0 != p2) ? 1 : 0) << std::endl;


//     delete p1;
//     delete p0;
//     delete p2;


// }


// #include <iostream>

// class Foo {

// public: 
//     Foo() {}

//     void go() {

//         std::cout << "Foo" << std::endl;
//     }
// };


// class Bar : public Foo {

// public: 

//     Bar() {

//     }

//     void go() {
//         std::cout << "Bar" << std::endl;
//     }
// };


// int main(int argc, char** argv) {

//     Bar b;

//     const Foo f = b;

//     f.go();


// }


// #include <iostream>


// class Shape {


//     public: 

//     void print() {

//         std::cout << "SHAPE" << std::endl;
//     }
// };


// class Box : public Shape {

// public:     

//     void print() {
//         std::cout << "BOX" << std::endl;
//     }
// };


// int main(int argc, char** argv) {

//     Shape* s1 = new Box;

//     s1->print();

//     return 0;

// }

#include <iostream>

class Foo {

    public: 

    int x;
    int y;


};


int main(int argc, char** argv) {

    Foo f;

    if (&f.x < &f.y) {

        std::cout << "Hello world" << std::endl;
    }

    return 0;
}
