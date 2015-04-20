//Arbore oarecare reprezentat prin legatura la descendent-stanga, frate-dreapta
//se preteaza parcurgerii in adancime

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

typedef struct arbore{
	 int inf;
	 struct arbore *ds,*fd;
}ARB;

ARB *creare(){
        ARB *aux;
	int x;
	printf(" cheie nod (0 pt NULL): ");scanf("%d",&x);
	if(x!=0){
		  aux=(ARB *) malloc (sizeof (ARB));
		  aux->inf=x;
		  printf("\nDescendent stanga pt %d \n",x);
		  aux->ds=creare();
		  printf("\nFrate dreapta pt %d \n",x);
		  aux->fd=creare();		  
		  return(aux);
	}
	else return(NULL);	
}

void DF(ARB *a){
//depth-first(in adancime)
	if(a){
	   printf("%d ",a->inf);
	   DF(a->ds);
	   DF(a->fd);
	}
}
void  main(void){
	ARB *a;
	clrscr();
	printf("Crearea DSFD - se incepe de la radacina\n");
	a=creare();
	printf("\nParcurgerea in adancime :\n");
	DF(a);
	getch();
}
