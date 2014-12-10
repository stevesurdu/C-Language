/*
    Author: Picaso
    IDE: Code::Blocks IDE
    Compiler: GNU GCC Compiler
    OS: Ubuntu 14.04 LTS
*/
#include <stdio.h>
#include <conio.h>
#define LIM  10 // valoarea maxima a  lui n care poate fi modificata

float  a[LIM][LIM], ratio, det=1;
unsigned int i, j, k, n;

//Functia care introduce valorile citite de la tastatura intr-o matrice bidimensionala
void insert(){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("A[%i][%i]=",i,j);
            scanf("%f", &a[i][j]);
        }
    }
}

//Functia care afiseaza matricea
void view(){
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.5f \t",a[i][j]);
          }
        printf("\n");
    }
    printf("\n");
}

//verifica daca exista elemente diferite de 0 in prima coloana si schimba liniile in caz afirmativ
void ver_zero(){
    int l,aux;
    for(i=0;i<n;i++)
        if(a[i][0]!=0){l=i;break;}else{det=-1;}
    for(i=0; i<n;i++){
        aux = a[0][i];
        a[0][i] = a[l][i];
        a[l][i] = aux;
    }
}

//Functia care converteste matricea initiala in una cu elemente nule coltul sting jos
void conversion(){
    for(i=0; i<n;i++){
        for(j=0;j<n;j++){
            if(j>i){
                ratio = a[j][i]/a[i][i]; // se determina ratia
                for(k = 0; k < n; k++){
                    a[j][k] -= ratio * a[i][k]; // se scade elementul din linia precedenta cu cel din linia curent inmultit cu ratia
                }
            }
        }
    }
}

//Functia care calculeaza determinantul
float determinant(){
    for(i = 0; i < n; i++)
        det *= a[i][i]; //face produsul elementelor pe diagonala principala
     return det;
}

int main(){

    printf("Dati n: ");
    scanf("%d", &n);

    insert();
    view();
    ver_zero();
    view();
    conversion();
    view();

    printf("\nDeterminantul matricei: %.2f", determinant());
    getch();
    return 0;
}
