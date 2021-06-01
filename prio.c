//ALGORITMO DE ESCALONAMENTO POR PRIORIDADE

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <locale.h>
void main()
{
    setlocale(LC_ALL, "Portuguese");
	int Y[20],X[10],N,i,j,k,temp,prioridade[10],st[10],final_tempo[10],espera[10],turnaround[10];
    int total_espera=0,total_turnaround=0,teste=1;
    float med_espera,med_turn;
    char id_processo[10][10],t[10];
    printf("Número de Processos:");
    scanf("%d",&N);
    //while(N>0){
    for(i=0; i<N; i++)
    {
        printf("Número do Processo ,Chegada, Execução e Prioridade:");
        scanf("%s%d%d%d",id_processo[i],&X[i],&Y[i],&prioridade[i]);
    }
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            if(prioridade[i]<prioridade[j])
            {
                temp=prioridade[i];
                prioridade[i]=prioridade[j];
                prioridade[j]=temp;
                temp=X[i];
                X[i]=X[j];
                X[j]=temp;
                temp=Y[i];
                Y[i]=Y[j];
                Y[j]=temp;
                strcpy(t,id_processo[i]);
                strcpy(id_processo[i],id_processo[j]);
                strcpy(id_processo[j],t);
            }
        }
    for(i=0; i<N; i++)
 
    {
 
        if(i==0)
        {
            st[i]=X[i];
            espera[i]=st[i]-X[i];
            final_tempo[i]=st[i]+Y[i];
            turnaround[i]=final_tempo[i]-X[i];
        }
        else
        {
            st[i]=final_tempo[i-1];
            espera[i]=st[i]-X[i];
            final_tempo[i]=st[i]+Y[i];
            turnaround[i]=final_tempo[i]-X[i];
        }
        total_espera+= espera[i];
        total_turnaround+=turnaround[i];
    }
    med_espera=(float)total_espera/N;
    med_turn=(float)total_turnaround/N;
    printf("Teste %d",teste);
	printf("\nProcesso Chegada\tExecução\tPrioridade\tTempo de Espera\tTurnaround");
    for(i=0; i<N; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",id_processo[i],X[i],Y[i],prioridade[i],espera[i],turnaround[i]);
    printf("\nTempo médio de execução:%.2fs",med_turn);
    printf("\nTempo médio de espera:%.2fs", med_espera);
    getch();
	
	for(i=0;i<38;i++)
		printf("-");
		printf("\n\nGANTT\n");
		printf("-");
		for(i=0; i<(turnaround[N-1] + 2*N);i++)
			printf("-");
			printf("\n");
			printf("|");
			for(i=0;i<N;i++){
				k = Y[i]/2;
				for(j=0; j<k;j++)
					printf(" ");
					printf("P%s",id_processo[i]);
					for(j=k+1;j<Y[i];j++)
						printf(" ");
						printf("|");
			}
			printf("\n");
			printf("-");
		for(i=0;i<(turnaround[N-1] + 2*N);i++)
			printf("-");
			printf("\n");
	
	  //teste++;
     // printf("\n\n");
     // scanf("%d", &N);
	//}
}
