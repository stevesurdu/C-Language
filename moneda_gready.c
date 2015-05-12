#include <stdio.h>


void citire(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }
}
void afisare(int a[],int n){
    int i;
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
void sortare(int a[],int n){
    int i,j,aux;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(a[i]<a[j]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
}
void plata(int a[],int n,int s){
    int i=0,nr,total=0;
    while(s>0 && i<n){
        if(a[i]<=s){
            nr = s/a[i];
            s = s%a[i];
            total +=nr;
            printf("\n %i*%i",nr,a[i]);
        }
        i++;
    }
    printf("\nTotal: %i monede",total);
}
int main(){

    int n,a[10],s;

    printf("Dati n=");scanf("%i",&n);
    printf("Dati s=");scanf("%i",&s);

    citire(a,n);
    afisare(a,n);
    sortare(a,n);
    afisare(a,n);

    plata(a,n,s);

    return 0;
}
