#include <stdio.h>

double a,b;

double pow(double a,double b){

    if(b>0)
        return a * pow(a,b-1);
    else
        return 1;
}

int main(){
    printf("Dati a:");
    scanf("%lf",&a);

    printf("Dati b:");
    scanf("%lf",&b);

    printf("Raspuns: %lf",pow(a,b));

    return 0;
}
