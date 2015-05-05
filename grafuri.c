#include <stdio.h>

int a[10][10];
int n;

void citire(int a[10][10],int n){
    FILE *f;
    int i,j;

    f = fopen("in.txt","r");
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            fscanf(f,"%d",&a[i][j]);
            a[j][i] = a[i][j];
        }
    a[i][i] = 0;
    }
    fclose(f);
}
void afisare(int a[10][10],int n){
    FILE *f;
    int i,j;

    f = fopen("out.txt","w");
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            fprintf(f,"%3d",a[i][j]);
            printf("%3d",a[i][j]);
        }
        fprintf(f,"\n");
        printf("\n");
    }
    fclose(f);
}
void warshall(int a[10][10],int n){
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                if(i!=j && a[i][j]==0)
                    a[i][j] = a[i][k] && a[k][j];

}
main(){

    n=4;

    citire(a,n);
    //afisare(a,n);

    //warshall(a,n);


    return 0;
}
