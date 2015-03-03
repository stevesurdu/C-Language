#include<stdio.h>


int f[10],n,i;

typedef struct fete
{
  char nume[15];
  int ani;
  float inaltime,kg;
} fete;
 void citire(fete f[], int n)
 {

for(i=0;i<n;i++)
{

    printf("nume:");
    scanf("%s", &f[i].nume);

     printf("ani:");
    scanf("%i", &f[i].ani);

     printf("inaltime:");
    scanf("%f", &f[i].inaltime);

     printf("kg:");
    scanf("%f", &f[i].kg);
}
}
void afisare(fete f[],int n)
{

    printf("\n Nume   Varsta   Inaltime   Kg \n");
    printf("\n_______________________________\n");
    for(i=0;i<n;i++)
        printf("%5s  %4i   %5.2f   %5.2f \n", f[i].nume, f[i].ani,f[i].inaltime,f[i].kg );

}

void kg2(fete f[],int n)
{ int max=f[1].kg;
for(i=0;i<n;i++){
    if(max<f[i].kg)
    max=f[i].kg;

}
printf("\n Nume     Inaltime \n");
printf("\n_______________________________\n");
for(i=0;i<n;i++){
        if (max==f[i].kg)
        printf("%5s   %5.2f\n", f[i].nume,f[i].inaltime);
}

}
 int main()
 {
     printf( "dati n =");
     scanf("%i",&n);

     citire(f,n);
     afisare(f,n);
     kg2(f,n);
     return 0;
 }
