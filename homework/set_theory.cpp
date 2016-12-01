#include<iostream>
#include"set_class.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
 Set A("A"), B("B"), C, D;
 
 cout << "Please input elements of two sets:" << endl;
 cin >> A >> B;

 C=A+B;
 D=A*B;

 cout << "The sets" << endl;
 
 cout << A << endl;
 cout << B << endl;
 cout << C << endl;
 cout << D << endl;
 cout << (A-B) << endl;
 cout << (B-A) << endl;
 cout << (A>=B) << endl;
 cout << (B>=A) << endl;

 return 0;
}
