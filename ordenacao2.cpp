/*
UFPB - CENTRO DE INFORMATICA
DISCIPLINA: ANÁLISE E PROJETO DE ALGORITMOS
AUTOR: BRUNO CORREIA
DATA: 14/03/2018
VERSÃO: 0.001
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// CLASSE MENSAGEM
class mensagem{
public:

	void versao(){
		cout<<"Versão 0.001"<<endl<<endl;
	}

	void ajuda(){
		cout<<"\nUso: ./ordenacao2 [OPÇÕES]\n\nOPÇÕES:\n\n -t [ms|qs]     Tipo da Ordenação. P/ MergeSort -> MS , QuickSort -> QS.\n\n                        Ex.: -t ms | -t qs\n\n -i [Arquivo]   Define o arquivo de entrada, com os valores a serem ordenados.\n\n                        Ex.: -i ./couting.txt | -i ~/ordenar.txt\n\n\n -h      Mostra esta tela de ajuda e sai\n -v      Mostra a versão do programa e sai\n\n\nExemplo completo de uso:\n\n./ordenacao2 -t ms -i entrada.txt\n\n";
	}

	void erro(){
		cout<<"Opção inválida, tente novamente. Use -h para ajuda."<<endl<<endl;
    }
    
};

/* MERGESORT - INICIO */

void juntar(int* A, int p, int q, int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1];
    int R[n2+1];

    for(int i=0; i<n1; i++) 
    	L[i]=A[p+i];
    
    for(int j=0; j<n2; j++) 
    	R[j]=A[q+1+j];

    int i=0, j=0, n=0;
    
    while(i!=n1 && j!=n2){
        
        if(L[i]>R[j]){
            A[p+n]=R[j];
            j++;
        } else {
            A[p+n]=L[i];
            i++;
        }
        n++;
    }

    while(j!=n2){
        A[p+n]=R[j];
        j++;
        n++;
    }

    while(i!=n1){
        A[p+n]=L[i];
        i++;
        n++;
    }
}

void MergeSort(int* A, int p, int r){
    if(r>p){
        int q;
        q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        juntar(A,p,q,r);
    }
}

/* MERGESORT - FIM */

/* QUICKSORT - INICIO */

void QuickSort(int* A, int p, int r){
    int i, j, x, y;

    i = p;
    j = r;
    x = A[(p + r) / 2];
     
    while(i <= j){

        while(A[i] < x && i < r){
            i++;
        }

        while(A[j] > x && j > p){
            j--;
        }

        if(i <= j){
            y = A[i];
            A[i] = A[j];
            A[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > p){
        QuickSort(A, p, j);
    }

    if(i < r){
        QuickSort(A, i, r);
    }
}

/* QUICKSORT - FIM */

int main(int argc, char *argv[]){

	mensagem exibir;

	int i, numParametros = argc;

	string	nomePrograma=argv[0], tipo, arquivoEntrada, arquivoSaida;


	if ( numParametros == 2 ){

		if (argv[1][0] == '-' ){

			switch(argv[1][1]){

				case 'v':
				case 'V':
					exibir.versao();
					return 0;
					break;

				case 'h':
				case 'H':
					exibir.ajuda();
					return 0;
					break;

				default:
					exibir.erro();
					return 1;
			}

		}

	} else if ( numParametros == 5 ){

			while ((++argv)[0]){

				if (argv[0][0] == '-' ){

					switch(argv[0][1]){

						case 't':
							tipo = argv[1];
							break;

						case 'i':
							arquivoEntrada = argv[1];
							break;

						default:
							exibir.erro();
							return 1;
					}

				}

			}

		// EXECUTION PROGRAM
		ifstream contar(arquivoEntrada.c_str());

		int N_LINHAS = 0;

		if(!contar.is_open()){
			cout << "Arquivo não pode ser aberto, verifique se o mesmo existe." << "\n\n";
			return 1;
		} else {
			string linha;

			while(getline(contar,linha)){
				++N_LINHAS;
			}

			contar.close();
		}

		int array[N_LINHAS];

		ifstream arquivo(arquivoEntrada.c_str());

		if(!arquivo.is_open()){
			cout << "Arquivo não pode ser aberto, verifique se o mesmo existe." << "\n\n";
			return 1;
		}

		for( i=0 ; i < N_LINHAS ; i++ ){
			arquivo >> array[i];
		}

		arquivo.close();

		if ( tipo == "MS" || tipo == "ms" ) {
			
		    cout << endl << "Merge Sort" << endl << endl;
		    cout << "Antes de ordenar:" << endl;

		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";

		    cout << endl;

		    MergeSort(array,0,(N_LINHAS-1));

		    
		    cout << endl << "Depois de ordenar:" << endl;
		    for (int i = 0; i < N_LINHAS; i++)
		        cout << array[i] << " ";
		    
		    cout << endl << endl;
		    

		} else if ( tipo == "QS" || tipo == "qs" ){
			
		    cout << endl << "Quick Sort" << endl << endl;
		    cout << "Antes de ordenar:" << endl;

		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";

		    QuickSort(array,0,(N_LINHAS-1));

		    cout << endl << endl << "Depois de ordenar:" << endl;
		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";
		    cout << endl << endl;

		} else {

			cout << "Tipo inválido, use" << nomePrograma << " -h para ajuda." << "\n\n";
			return 1;

		}

	} else {

		exibir.erro();
		return 1;
	
	}

	return 0;

}