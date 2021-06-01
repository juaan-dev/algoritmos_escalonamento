// 2 QUESTÃO DE THREADS
// Implemente um programa que inverta os valores das linhas de uma matriz 3x3 de 
// números inteiros e imprima a matriz resultante na tela. 
// A inversão de cada linha da matriz deve ser realizada em paralelo por threads.


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int m[3][3];

void * function (void *arg) {
	int *valor = (int *)(arg);
	int i,j,temp;
	if (*valor == 1) {
		printf ("Thread 1 executando...\n");
		for(i=0;i<3;i++) {    //PREENCHER A MATRIZ DE FORMA ALEATORIA
    		for(j=0;j<3;j++){
      			m[i][j] = 1 + rand() % 100;
    		}
  		}
	printf("\n\n---------------------------------------------\n\n"); 
   for(i=0;i<3;i++){   //imprime a matriz 
    for(j=0;j<3;j++) {
      printf("%d\t", m[i][j]);
    }
	printf("\n");
	}
printf("\n\n---------------------------------------------\n\n"); 
}
	else {
		printf ("Thread 2 executando...\n");
		for(i=0;i<3;i++){                          //TROCA AS LINHAS
    		for(j=0;j<3;j++){
    	 		temp = m[0][0]; 
      	 		m[0][0] = m[0][2];
		 		m[0][2] = temp; 
		 		temp = m[1][0];  
      	 		m[1][0] = m[1][2]; 
      	 		m[1][2] = temp;
      	 		temp = m[2][0];
      	 		m[2][0] = m[2][2]; 
      	 		m[2][2] = temp;
    }
  } 
	}	
}

int main () {
	pthread_t t1, t2;
	int a1 = 1;
	int a2 = 2;
	int i,j;
	
	pthread_create(&t1, NULL, function, (void *)(&a1));
	pthread_create(&t2, NULL, function, (void *)(&a2));
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	for(i=0;i<3;i++) {  
    	for(j=0;j<3;j++){
      		printf(" %d ",m[i][j]);
    	}
    	printf("\n");
  	} 
	printf ("\n");
	
	exit(0);	
}
