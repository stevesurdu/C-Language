/*
    Author: Picaso
    IDE: Code::Blocks IDE
    Compiler: GNU GCC Compiler
    OS: Ubuntu 14.04 LTS
*/

#include <stdio.h>

unsigned int i,n;
int a[10];
void citire(){
    printf("Dati numarul de elemente: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("A[%d]=",i);
        scanf("%d",&a[i]);
    }
}

void afisare(){
    printf("\nAfisare\n");
    for(i=0;i<n;i++)
        printf("%5d",a[i]);
}

// suma componentelor
int sum(){
    int s=0;
    for(i=0;i<n;i++)
        s+=a[i];
    return s;
}
// produsul componentelor
int prod(){
    int p=1;
    for(i=0;i<n;i++)
        p*=a[i];
    return p;
}
// numarul elementelor negative
int nr_neg(){
    int k=0;
    for(i=0;i<n;i++){
        if(a[i] < 0)
            k+=1;
    }
    return k;
}
// numarul elementelor pare
int nr_par(){
    int k=0;
    for(i=0;i<n;i++){
        if((a[i]%2==0)&&(a[i]!=0))
            k+=1;
    }
    return k;
}
// numarul elementelor nenule
int nr_nenul(){
    int k=0;
    for(i=0;i<n;i++){
        if(a[i]!=0)
            k+=1;
    }
    return k;
}
// numarul elementelor pozitive divizibile cu 3 si 5
int nr_poz_div(){
    int k=0;
    for(i=0;i<n;i++){
        if((a[i]>0)&&(a[i]%3==0)&&(a[i]%5==0))
            k+=1;
    }
    return k;
}
// numarul elementelor divizibile cel putin cu 7,9,11
int nr_poz_divor(){
    int k=0;
    for(i=0;i<n;i++){
        if((a[i]!=0)&&((a[i]%7==0)||(a[i]%9==0)||(a[i]%11==0)))
            k+=1;
    }
    return k;
}
//sirul fibonace
void fibonace(){
    a[0]=1;
    a[1]=1;
    for(i=2;i<n;i++)
        a[i]=a[i-2]+a[i-1];
}
int cont_zero(){
    int l=0;
    for(i=0;i<n;i++){
        if(a[i]==0){
            l=i;break;break;
        }
    }
    return l;
}
// aranjarea elementelor in ordine crescatoate
void ord_cresc(){
    int nr_comparari = 0,nr_treceri = 0;
    bool sortat; 
    int i,aux; 
    do{
        nr_treceri++;
        sortat = true;
        for (i=0 ; i<n-1 ; i++){
            nr_comparari++;
            if (a[i]<a[i+1]){
                aux = a[i]; 
                a[i] = a[i+1]; 
                a[i+1] = aux;
                sortat = false ;
             }
        }
    }
    while (!sortat);
}
// aranjarea elementelor in ordine descrescatoate
void ord_desc(){
    int nr_comparari = 0,nr_treceri = 0;
    bool sortat; 
    int i,aux; 
    do{
        nr_treceri++;
        sortat = true;
        for (i=0 ; i<n-1 ; i++){
            nr_comparari++;
            if (a[i]>a[i+1]){
                aux = a[i]; 
                a[i] = a[i+1]; 
                a[i+1] = aux;
                sortat = false ;
             }
        }
    }
    while (!sortat);
}

int main(){

    citire();
    afisare();
    printf("\nSuma:%d",sum());
    printf("\nProdusul:%d",prod());
    printf("\nNumarul elementelor negative :%d",nr_neg());
    printf("\nNumarul elementelor pare :%d",nr_par());
    printf("\nNumarul elementelor nenule :%d",nr_nenul());
    printf("\nNumarul elementelor pozitive divizibile cu 3 si 5 :%d",nr_poz_div());
    printf("\nNumarul elementelor divizibile cel putin cu 7,9,11 :%d",nr_poz_divor());
    printf("\nContine 0 pe pozitia:%d",cont_zero());
    ord_cresc();
    afisare();
    ord_desc();
    afisare();
    fibonace();
    afisare();

    return 0;
}
