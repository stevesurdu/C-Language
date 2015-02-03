/*
    Author: Picaso
    IDE: Code::Blocks IDE
    Compiler: GNU GCC Compiler
    OS: Ubuntu 14.04 LTS
*/

#include <stdio.h>
#include <limits.h>

#define max(a,b) (a>b)?a:b;
#define min(a,b) (a<b)?a:b;

int i,j,n,m;
int a[10][10];

void citire(){
	printf("Dati n si m: ");
	scanf("%d%d",&n,&m);
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf("A[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}

void afisare(){
	printf("\nAfisare\n");
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}	
}
// Suma elementelor matricii
int suma(){
	int s=0;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			s+=a[i][j];
		}
	}
	return s;
}

// Suma elementelor pozitive
int suma_poz(){
	int s=0;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if (a[i][j]>0)
				s+=a[i][j];
		}
	}
	return s;
}
// Numarul elementelor negative
int nr_neg(){
	int k=0;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if (a[i][j]<0)
				k+=1;
		}
	}
	return k;
}
// afisare elementele liniei t
void afisare_linie(){
	int t;
	printf("\nDati t: ");scanf("%d",&t);
	for (j=0;j<m;j++)
		printf("%5d",a[t][j]);
}
// afisare elementele coloanei t
void afisare_coloana(){
	int t;
	printf("\nDati t: ");scanf("%d",&t);
	for (i=0;i<n;i++)
		printf("%5d\n",a[i][t]);
}
// elementul maxim si pozitiile sale
void max_l(){
	int max = INT_MIN;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if(max<a[i][j])
				max=a[i][j];
		}
	}
	printf("\nElementul maxim:%d",max);
	printf("\nPozitiile elementului maxim\n");
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if(max==a[i][j])
				printf("A[%d][%d]\t",i,j);
		}
	}
}
// elementul minim si pozitiile sale
void min_l(){
	int min = INT_MAX;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if(min>a[i][j])
				min=a[i][j];
		}
	}
	printf("\nElementul minim:%d",min);
	printf("\nPozitiile elementului minim\n");
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if(min==a[i][j])
				printf("A[%d][%d]\t",i,j);
		}
	}
}
// suma pe linii si numarul de elemente pozitive
int suma_linie(){
	int s=0,k=0;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			s+=a[i][j];
			if(a[i][j]>0)
				k+=1;
		}
		printf("\nSuma pe linia %d = %d",i,s);
		printf("\nNumarul de elemente pozitive pe linia %d = %d",i,k);
		s=0;k=0;
	}
}
// suma pe coloane si numarul de elemente negative
int suma_coloana(){
	int s=0,k=0;
	for (j=0;j<m;j++){
		for (i=0;i<n;i++){
			s+=a[i][j];
			if(a[i][j]<0)
				k+=1;
		}
		printf("\nSuma pe coloana %d = %d",j,s);
		printf("\nNumarul de elemente negative pe colona %d = %d",j,k);
		s=0;k=0;
	}
}
// elementul maxim
int maxim(){
    int maxi = INT_MIN;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            maxi=max(maxi,a[i][j]);
    return maxi;
}
// elementul minim
int minim(){
    int mini = INT_MAX;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            mini=min(mini,a[i][j]);
    return mini;
}
// suma de pe diagonala principala
int DP(){
    int s=0;
    for(i=0;i<n;i++)
        s+=a[i][i];
    return s;
}
// suma de pe diagonala secundara
int DS(){
    int s=0;
    for(i=0;i<n;i++)
        s+=a[i][n-i-1];
    return s;
}
// suma de  deasupra  diagonalei principale
int DDP(){
    int s=0;
    for(i=0;i<n;i++){
        for(j=1;j<m;j++){
            if(i<j){s+=a[i][j];}
        }
    }
    return s;
}
// suma de  deasupt  diagonala principala
int SDP(){
    int s=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(i>j){s+=a[i][j];}
        }
    }
    return s;
}
// suma de  deasupra  diagonalei secundare
int DDS(){
    int s=0;
    for(i=0;i<n-1;i++)
        for(j=0; j<n-1-i;j++)
            s+=a[i][j];
    return s;
}
// suma de  deasupt  diagonala secundara
int SDS(){
    int s=0;
    for(i=0;i<n;i++)
        for(j=n-1; j>n-1-i;j--)
            s+=a[i][j];
    return s;
}
int main(){

	citire();
	afisare();
	printf("\nSuma elementelor matricii: %d",suma());
	printf("\nSuma elementelor pozitive: %d",suma_poz());
	printf("\nNumarul elementelor negative: %d",nr_neg());
	afisare_linie();
	afisare_coloana();
	max_l();
	min_l();
	suma_linie();
	suma_coloana();
	printf("Max:%d\n",maxim());
    printf("Min:%d\n",minim());
    printf("Diagonala Principala:%d\n",DP());
    printf("Diagonala Secundara:%d\n",DS());
    printf("Deasupra diag. principale:%d\n",DDP());
    printf("Sub diag. principala:%d\n",SDP());
    printf("Deasupra diag. secundare:%d\n",DDS());
    printf("Sub diag. secundara:%d\n",SDS());

	return 0;
}
