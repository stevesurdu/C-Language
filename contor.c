/*
    Author: Igor Voloc
    Grupa:10202
    IDE: Code::Blocks IDE
    Compiler: GNU GCC Compiler
    OS: Ubuntu 14.04 LTS
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int i=0;
char c;

void s_cont(){

    for(i=i;;i++){
        printf("%4d",i);
        Sleep(100);
    }
}
int main(){
    for(;;){
        printf("\nla apasarea tastei S contorul sa inceapa numararea, de la ultima valoare afisata;");
        printf("\nla apasarea tastei O contorul sa se opreasca, raminind afisata valoarea acestuia;");
        printf("\nla apasarea tastei R contorul sa revina la zero si daca anterior functiona, sa se opreasca; ");
        printf("\nla apasarea tastei E sa se iasa din program.");
        printf("\nTastati caracterul:");
        c = getchar();
        switch(c){
            case 'S' : s_cont();
            case 'E' : break;
        }

    }

    return 0;
}
