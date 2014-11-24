/*
    Author: Picaso
    IDE: Code::Blocks IDE
    Compiler: GNU GCC Compiler
    OS: Ubuntu 14.04 LTS
*/
//Verificarea unui numar daca este palindrom

#include <stdio.h>

int n,i,t,inv=0,c;
int main()
{
    //Citim numarul
    printf("Dati numarul:");
    scanf("%i",&n);
    
    //Copiem numarul intr-o variabila
    c = n;

    while(n!=0)
    {
        t=n%10; // preluam in variabila t ultima cifra a numarului
        inv=inv*10+t; // copiem cifra in alta variabila inv
        n=n/10; // stergem ultima cifra din numarul introdus n
    }

    //Verificam daca numarul introdus este egal cu inversul
    c==inv?printf("Numarul este polindrom"):printf("Numarul nu este polindrom");

    return 0;
}