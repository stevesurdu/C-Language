#include <stdio.h>

int n;

double fact(int n){

    if(n>0)
        return n*fact(n-1);
    else
        return 1;
}

int main(){
    printf("Dati n");
    scanf("%d",&n);

    printf("Raspuns: %lf",fact(n));

    return 0;
}
