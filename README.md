# Activity 02 - APA - UFPB

## Description

This project intends to implement the ordering algorithm Merge and Quick Sort in C ++.

## Compilation/Linker

To compile/linker execute `make` in the clone directory.

Example:

```bash
user@host:~/activity02_apa$ make
Compilando arquivo objeto: ordenacao2
user@host:~/activity02_apa$
```

## Execution

Then, execute the generated binary:

```bash
user@host:~/activity02_apa$ ./ordenacao2 -h

Uso: ./ordenacao2 [OPÇÕES]

OPÇÕES:

 -t [ms|qs]     Tipo da Ordenação. P/ MergeSort -> MS , QuickSort -> QS.

                        Ex.: -t ms | -t qs

 -i [Arquivo]   Define o arquivo de entrada, com os valores a serem ordenados.

                        Ex.: -i ./couting.txt | -i ~/ordenar.txt
                        

 -h      Mostra esta tela de ajuda e sai
 -v      Mostra a versão do programa e sai
 
   
Exemplo completo de uso:

./ordenacao2 -t ms -i entrada.txt 
```

