/*
    Author: Picaso
    IDE: Code::Blocks IDE
    Compiler: GNU GCC Compiler
    OS: Ubuntu 14.04 LTS
*/

#include <iostream>

using namespace std;

float f;
int a,b;


int main()

{
    cout << "Fractia va fi sub forma a/b= \n";
    cout << "Dati valoare lui a="; cin>>a;
    cout << "Dati valoare lui b="; cin>>b;

    if ((a<b)&&(b>0)){
        f=a*1.0/b;
        cout << "Fractia subunitara este f="<<f<<endl;
    }else if((a>b)&&(b>0)){
        f=a*1.0/b;
        cout << "Fractia supraunitara este f="<<f<<endl;
    }else if((a==b)&&(b>0)){
        f=a*1.0/b;
        cout << "Fractia echivalenta este f="<<f<<endl;
    }else{
        cout << "Fractia nu are sens"<<endl;
    }

    return 0;
}
