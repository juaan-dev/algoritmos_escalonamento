// 1 questão de THREADS
//Escreva um programa em C (ou Java) composto por duas threads: 
//   a primeira deve contar e exibir na tela todos os números entre 1 a 500 
//   (de forma crescente); a segunda deve contar e 
//   exibir na tela todos os números entre 500 a 1 (de forma decrescente). 
//   As duas threads devem ser executadas em paralelo.



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 501

int v[SIZE];

void * function (void *arg) {
	int *valor = (int *)(arg);
	int i;
	if (*valor == 1) {
		printf ("Thread 1 executando...\n");
		for (i = 2; i < (SIZE-1) ; i++) {
			v[i] = i;
            printf(" %d ",v[i]);
		}
	}
	else {
		printf ("Thread 2 executando...\n");
		for (i = (SIZE-1) ; i > 1; i--) {
			v[i] = i;
           printf(" %d ",v[i]);
		}
	}	

}

int main () {
	pthread_t t1, t2;
	int a1 = 1;
	int a2 = 2;
	int i;
	
	pthread_create(&t1, NULL, function, (void *)(&a1));
	pthread_create(&t2, NULL, function, (void *)(&a2));
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
  
	printf ("\n");
	
	exit(0);	
}
