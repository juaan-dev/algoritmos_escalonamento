//ALGORITMO FCFS (First-Come, First Served)

#include<iostream>
#include <locale.h>
using namespace std;
 
void tempoEspera(int processos[], int n, int exec[], int espera[], int chegada[]){
    int soma_tempo[n];
    soma_tempo[0] = chegada[0];
    espera[0] = 0;
 
    for (int i = 1; i < n ; i++){ 					//calcula o tempo de espera
        soma_tempo[i] = soma_tempo[i-1] + exec[i-1];
        espera[i] = soma_tempo[i] - chegada[i];
        if (espera[i] < 0)
            espera[i] = 0;
    }
}
 

void tempoTurnAround(int processos[], int n, int exec[],int espera[], int turnaroundtime[]){
    for (int i = 0; i < n ; i++)
        turnaroundtime[i] = exec[i] + espera[i];
}
 
void tempo_Medio(int processos[], int n, int exec[], int chegada[])
{
    int espera[n], turnaroundtime[n];
 
    tempoEspera(processos, n, exec, espera, chegada);
 
    tempoTurnAround(processos, n, exec, espera, turnaroundtime);
 
    cout << "Processos " <<  "	Execução " << " 	Chegada "
         << " 	Espera " << " Turn-Around Time "
         << " Tempo de Finalização \n";
    int total_espera = 0, total_turnaroundtime = 0;
    for (int i = 0 ; i < n ; i++)
    {
        total_espera = total_espera + espera[i];
        total_turnaroundtime = total_turnaroundtime + turnaroundtime[i];
        int final_tempo = turnaroundtime[i] + chegada[i];
        cout << " " << i+1 << "\t\t" << exec[i] << "\t\t"
             << chegada[i] << "\t\t" << espera[i] << "\t\t "
             << turnaroundtime[i]  <<  "\t\t " << final_tempo << endl;
    }
 	cout << "\nTempo médio de execução = "
         << (float)total_turnaroundtime / (float)n
    	 <<"s"
		 << "\n";
    cout << "Tempo médio de espera = "
         << (float)total_espera / (float)n
 		<<"s";
}
 
int main()
{
	
    setlocale(LC_ALL, "Portuguese");
	int processos[] = {1, 2, 3, 4};
    int n = sizeof processos / sizeof processos[0];
 
	int X[] = {0, 0, 1, 3}; 
    int Y[] = {5, 2, 4, 3};

 	cout<< ("\nTeste 1\n");
    tempo_Medio(processos, n, Y, X);
    
    return 0;
}
