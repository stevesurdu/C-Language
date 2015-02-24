#include <stdio.h>

int n;

double suma(int n){

    if(n>0)
        return n + suma(n-1);
    else
        return 0;
}

int main(){
    printf("Dati n:");
    scanf("%d",&n);

    printf("Raspuns: %lf",suma(n));

    return 0;
}
