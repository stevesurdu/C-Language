#include <stdio.h>

int a[10][10];
int n,det,l,i,j,d;
int sum11=1,sum12=0, sum21=1, sum22=0;

int opr(int a[10][10], int size){
    for(i=0;i<size;i++){
        sum11=1;
        l=2*size-1-i;
        sum21=1;
        for(j=0;j<size;j++){
            sum21*=a[j][l%size];
            l--;
            sum11*=a[j][(j+i)%(size)];}
            sum22+=sum21;
            sum12+=sum11;
    }
    d=sum12-sum22;
    return d;
}
int citire(int a[10][10]){
    printf("Dati n : ");
    scanf("%i",&n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("A[%i][%i]=",i,j);
            scanf("%i",&a[i][j]);
        }
    }

    return 0;
}
int view(int a[10][10]){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%i \t",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int main(){

    citire(a);
    view(a);
    printf("Determinantul: %i",opr(a,n));

    return 0;
}
