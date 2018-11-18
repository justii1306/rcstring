#include "rcstring.h"

int main()
{
rcstring a,b,c;
a="10";
b="ala ma kota";
cout << a << " " << b << endl; // 10 ala ma ma kota
c=a+b;
cout << c<<endl; // 10ala ma kota
c=a+rcstring(" ")+b;
cout << c << endl; //10 ala ma kota
rcstring d("a");
cout << d <<endl; //a
d+="ula";
cout << d << endl; //aula
d+="15";
cout << d << endl; //aula15
cout << d[3]<<endl; //a
d[3]='b';
cout << d << endl; //aulb15
d[2]=d[1]=d[0];
cout << d << endl; //aaab15

rcstring test;
test = "Ola Ma Psa";
cout<<"Normal: "<<test<<endl;
rcstring testlow = test.toLower();
cout<<"toLower: "<<testlow<<endl;
cout<<"Normal: "<<test<<endl;
rcstring test2;
test2 = "1234";
cout<<"Normal: "<<test2<<endl;
cout<<"atoi + 1: "<<test2.atoi()+1<<endl;
rcstring test3 = test2.Left(2);
cout<<"Left: "<<test3<<endl;
cout<<"Left2: "<<test2.Left(2)<<endl;
return 0;
}

