/*
    Author: Picaso
    IDE: Code::Blocks IDE
    Compiler: GNU GCC Compiler
    OS: Ubuntu 14.04 LTS
*/
// Programul dat calculeaza determinantul dupa metoda din urmatoarea sursa http://www.e-formule.ro/wp-content/uploads/determinantul-matricei.htm
#include<conio.h>
#include<stdio.h>
#define LIM  10 // valoarea maxima a  lui n care poate fi modificata

int a[LIM][LIM],n;
int i,j;

//Functia care introduce valorile citite de la tastatura intr-o matrice bidimensionala
void insert(){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("A[%i][%i]=",i,j);
            scanf("%i", &a[i][j]);
        }
    }
}

//Functia care afiseaza matricea
void view(){
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%5i",a[i][j]);
          }
        printf("\n");
    }
    printf("\n");
}

//Functia care calculeza determinantul
int determinant(int f[LIM][LIM],int x)
{
  int pr,c[LIM],d=0,b[LIM][LIM],j,p,q,t;
  if(x==2) //daca rangul matricei este egal cu 2 se calculeaza dupa metoda standorta produsul elementelor de pe diagonala principala minus produsul elementelor de pe diagonala secundara
  {
    d=0;
    d=(f[1][1]*f[2][2])-(f[1][2]*f[2][1]);
    return(d);
   }
  else //daca rangul matricei este diferit de 2 determinantul se calculeaza dupa metoda din sursa din antetul programului
  {
    for(j=1;j<=x;j++)
    {
      int r=1,s=1;
      for(p=1;p<=x;p++)
        {
          for(q=1;q<=x;q++)
            {
              if(p!=1&&q!=j)
              {
                b[r][s]=f[p][q];
                s++;
                if(s>x-1)
                 {
                   r++;
                   s=1;
                  }
               }
             }
         }
     for(t=1,pr=1;t<=(1+j);t++)
     pr=(-1)*pr;
     c[j]=pr*determinant(b,x-1);
     }
     for(j=1,d=0;j<=x;j++)
     {
       d=d+(f[1][j]*c[j]);
      }
     return(d);
   }
}

int main()
{
  printf("\n\nDati ordinul matricii : ");
  scanf("%i",&n);
  printf("\nDati elementele matricii\n");
  insert();
  view();
  printf("\n Determinantul=%i .",determinant(a,n));
  getch();
}
