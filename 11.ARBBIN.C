/* PROGRAM DE CONSTRUCTIE RSD A UNUI ARBORE BINAR,
AFISARE A LISTELOR RSD, SRD, SDR A CHEILOR SALE
AFUSARE A NR DE NODURI SI INALTIMII SALE*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <alloc.h>

typedef struct arbore{
	 int inf;
	 struct arbore *ss,*sd;
}ARB;

ARB *init(){
	ARB *aux;
	int x;
	printf(" cheie nod (0 pt NULL): ");scanf("%d",&x);
	if(x!=0){
		  aux=(ARB *) malloc (sizeof (ARB));
		  aux->inf=x;
		  aux->ss=init();
		  aux->sd=init();
		  return(aux);
	}
	else return(NULL);
}

void RSD(ARB *a){
	if(a){
		printf("%d  ",a->inf);
		RSD(a->ss);
		RSD(a->sd);
	}
}

void SDR(ARB *a){
	if(a){
		SDR(a->ss);
		SDR(a->sd);
		printf("%d  ",a->inf);
	}
}

void SRD(ARB *a){
	if(a){
		SRD(a->ss);
		printf("%d  ",a->inf);
		SRD(a->sd);
	}
}
int nrnoduri(ARB *a){
  if(a) return(1+nrnoduri(a->ss)+nrnoduri(a->sd));
  else return(0);
}

int h(ARB *a){
//inaltimea arborelui
  int hs,hd;
  if(a){
    hs=h(a->ss);
    hd=h(a->sd);
    if(hs<hd) return(hd+1);
    else return(hs+1);
  }
  else return(0);
}

void  main(void){
	ARB *a;
	clrscr();
	printf("Arborele se va crea in ordinea RSD\n");
	a=init();
	printf("\nParcurgerea RSD este:\n");
	RSD(a);
	printf("\nParcurgerea SDR este:\n");
	SDR(a);
	printf("\nParcurgerea SRD este:\n");
	SRD(a);
	printf("\nArborele are %d noduri",nrnoduri(a));
	printf("\nArborele are inaltimea %d",h(a));
	getch();
}
