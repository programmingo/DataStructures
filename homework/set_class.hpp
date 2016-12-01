/*
 * Data Structures
 * HW 2
 * practice c++ class with set theory
 * module of set theory computation 
 * *.hpp file
 */


#include<iostream>
#include<string>

using namespace std;

class Set
{
 private:
   string id;
   string element;
 public:
   Set(string i, string el);
   ~Set();
   string conclusion(bool *ascii);
   Set operator+(const Set &B);
   Set operator*(const Set &B);
   Set operator-(const Set &B);
   Set operator>=(const Set &B);
   friend istream &operator>>(istream &is, Set &A);
   friend ostream &operator<<(ostream &os, const Set &A);
};

// constructor
Set:: Set(string i="empty", string el=" "): id(i), element(el) {}

// destructor
Set:: ~Set() {}

// conclusion
string Set::
conclusion(bool *ascii)
{
 string str;
 for (int i=0; i<256; i++){
   if (ascii[i]){
     string ch; ch=(char) i;
     str+=ch;
   }
 }
 
 return str;
}

// union: + overload
Set Set::
operator+(const Set &B)
{
 bool ascii[256]={false};
 char ch;
 string id_A, id_B, c, str;

 id_A=(*this).id;
 id_B=B.id;
 c=this->element+B.element;

 for (auto &ch_c: c){
   ch=ch_c;
   ascii[ch]=true;
 }

 str=conclusion(ascii);

 return Set(id_A+"+"+id_B,str);
}

// intersection: * overload
Set Set::
operator*(const Set &B)
{
 bool ascii[256]={false};
 char ch;
 string id_A, id_B, a, b, str;

 id_A=(*this).id;
 id_B=B.id;
 a=this->element;
 b=B.element;

 for (auto &ch_a: a){
   for (auto &ch_b: b)
     if (ch_a == ch_b){
       ch=ch_a;
       ascii[ch]=true;
     }
 }

 str=conclusion(ascii);

 return Set(id_A+"*"+id_B,str);
}

// difference: - overload
Set Set::
operator-(const Set &B)
{
 bool ascii[256]={false};
 char ch;
 string id_A, id_B, a, b, str;

 id_A=(*this).id;
 id_B=B.id;
 a=this->element;
 b=B.element;
 
 for (auto &ch_a: a){
   int j=0;
   for (auto &ch_b: b){
     if (ch_a != ch_b)
       j++;
   }
   if ( j == b.size()){
     ch=ch_a;
     ascii[ch]=true;
   }
 }

 str=conclusion(ascii);

 return Set(id_A+"-"+id_B, str);
}

// contain: >= overload
Set Set::
operator>=(const Set &B)
{
 Set C;
 string b, id_A, id_B;
 bool ascii[256]={false};
 char ch; 
 
 id_A=(*this).id;
 id_B=B.id;
 C=(*this)*B;
 b=B.element;

 for (auto &ch_b : b){
   ch=ch_b;
   ascii[ch]=true;
 }

 b=conclusion(ascii);
 
 if (C.element == b)
   return Set(id_A+" contains "+id_B+" with ", C.element);
 else
   return Set(id_A+" does not contain "+id_B+" with ");
}

// read in: >> overload
istream &operator>>(istream &is, Set &A)
{
 is >> A.element;

 return is;
}

// output: << overload
ostream &operator<<(ostream &os, const Set &A)
{
 os << A.id << " {" << A.element << "}";

 return os;
}
