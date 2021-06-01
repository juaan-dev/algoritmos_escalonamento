#include <stdio.h>
int main() 
{
      int X[10], Y[10], temp[10],teste=1,limpa=0;   // X = tempo de chegada ; e Y = Tempo de execucao;
      int i, j, menor, cont = 0, tempo, N;
      double t_espera = 0, t_turnaround = 0, fim;
      float media_espera=0, media_turnaround=0;
      printf("\nTotal de processos:\t");
	  scanf("%d", &N);
	  
      while(N>0){
      printf("\nDetalhes dos %d Processos\n", N);
      for(i = 0; i < N; i++)
      {
            printf("\nTempo de chegada:\t");
            scanf("%d", &X[i]);
            printf("Tempo de execucao:\t");
            scanf("%d", &Y[i]); 
            temp[i] = Y[i];
      }
      Y[9] = 9999;  
      for(tempo = 0; cont != N; tempo++)
      {
            menor = 9;
            for(i = 0; i < N; i++)
            {
                  if(X[i] <= tempo && Y[i] < Y[menor] && Y[i] > 0)
                  {
                        menor = i;
                  }
            }
            Y[menor]--;
            if(Y[menor] == 0)
            {
                  cont++;
                  fim = tempo + 1;
                  t_espera = t_espera + fim - X[menor] - temp[menor];
                  t_turnaround = t_turnaround + fim - X[menor];
            }
      }
      printf("---------------------------------");
      printf("\nTeste %d",teste);
      media_espera = t_espera / N; 
      media_turnaround = t_turnaround / N;
      printf("\nTempo medio de execucao: %.2lfs\n", media_turnaround);
      printf("\nTempo medio de espera: %.2lfs\n", media_espera);
      
      teste++;
      printf("\n\n");
      scanf("%d", &N);
	}
}
