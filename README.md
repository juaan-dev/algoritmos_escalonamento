
<h4>Algoritmos de escalonamento desenvolvidos para a disciplina de Sistemas Operacionais do curso Sistemas de Informação na Universidade Federal do Amazonas (UFAM)</h4>

# FIFO (First In, First Out)

<p align="justify" > É um algoritmo de escalonamento não preemptivo, no qual os
processos recebem tempo de CPU na mesma ordem em que solicitam. Como
vantagens deste algoritmo, pode-se citar a facilidade de entendimento e
implementação, além de sua imparcialidade. Como desvantagens pode-se
mencionar a sensibilidade à ordem de chegada das tarefas e o aumento do tempo
médio de espera no caso de processos grandes chegarem primeiro na fila.</p>

# LIFO (Last In, First Out)

<p align="justify" >É um método para lidar com estruturas de dados em que o último 
elemento é processado primeiro e o primeiro elemento é processado por último. </p>


# SJF (Shortest Job First)

<p align="justify" >Também é um algoritmo não preemptivo, que
assume que os tempos de execução dos jobs são conhecidos antecipadamente.
Caso haja várias tarefas em uma fila de entrada, de igual importância para serem
executadas, o escalonador irá selecionar a tarefa mais curta primeiro. </p>


# RR (Round-Robin)

<p align="justify" > O algoritmo RR opera em sistemas iterativos, realizando um
rodízio entre os processos da seguinte maneira: cada job possui um intervalo de
tempo (quantum) durante o qual ele pode ser executado. Caso ele esteja em
execução e seu quantum terminar (esse job será colocado no final da fila), será
feita a preempção da CPU e esta será alocada para outro job. </p>
