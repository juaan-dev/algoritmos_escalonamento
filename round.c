#include<stdio.h>

int main()
{
      int i, N, total = 0, x, cont = 0, M,teste=1;
      int tempo_espera = 0, turnaround_time = 0, X[10], Y[10], temp[10];
      float media_espera, total_turnaround;
      printf("\nTempo de Quantum:\t");
      scanf("%d", &M);
      printf("\nNumero total de processos:\t");
      scanf("%d", &N);
      while(N>0){
      x = N;
      for(i = 0; i < N; i++)
      {
            printf("\nDetalhes do Processo [%d]\n", i + 1);
 
            printf("Chegada:\t");
 
            scanf("%d", &X[i]);
 
            printf("Duracao:\t");
 
            scanf("%d", &Y[i]);
 
            temp[i] = Y[i];
      }
 
      printf("\nProcesso\t\tExecucao\t Turnaround \t Tempo espera\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= M && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  cont = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - M;
                  total = total + M;
            }
            if(temp[i] == 0 && cont == 1)
            {
                  x--;
                  printf("\nProcesso[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, Y[i], total - X[i], total - X[i] - Y[i]);
                  tempo_espera = tempo_espera + total - X[i] - Y[i];
                  turnaround_time = turnaround_time + total - X[i];
                  cont = 0;
            }
            if(i == N - 1)
            {
                  i = 0;
            }
            else if(X[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 	  
 	  printf("\n----------------------------------------------------------");
 	  printf("\nTeste %d",teste);
      media_espera = tempo_espera * 1.0 / N;
      total_turnaround = turnaround_time * 1.0 / N;
      printf("\nTempo medio execucao:\t%.2fs\n",  total_turnaround);
      printf("\n\nTempo medio de espera:\t%.2fs", media_espera);
      printf("\n\n");
      
      teste++;
      scanf("%d", &N);
	}
}
