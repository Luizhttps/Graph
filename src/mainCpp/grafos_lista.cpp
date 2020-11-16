#include <iostream>
#include <list>
#include <algorithm> // função find
#include <string.h>
#include <fstream>
using namespace std;

class Grafo{
	int V; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências

	public:
		int tamanhoG;
		int tamanhoGrafo(string);
		void leArquivo(string);
		Grafo();
		Grafo (int V); // construtor
		void adicionarAresta (int v1, int v2); // adiciona uma aresta no grafo
		// obtém o grau de saída de um dado vértice
		// grau de saída é o número de arcos que saem de "v"
		int obterGrauDeSaida (int v);
		bool existeVizinho (int v1, int v2); // verifica se v2 é vizinho de v1
};

Grafo::Grafo(){};

int Grafo::tamanhoGrafo(string nameArq){
	int tamanho;
	ifstream arquivo;
	arquivo.open(nameArq);
	if (!arquivo.is_open()) 
        cout<<"File is not found!"<<endl;
    else
		arquivo>>tamanho;

	return tamanho;
}

void Grafo::leArquivo(string nameArq){
	tamanhoG;
	tamanhoG = tamanhoGrafo("Arquivo01.txt");
	cout<<tamanhoG<<endl;

	ifstream arquivo;
    arquivo.open(nameArq);

    if (!arquivo.is_open()) {
        cout<<"File is not found!"<<endl;
    }else{

    	int myArray[tamanhoG][tamanhoG];
		char auxArray[tamanhoG*tamanhoG];
		int x=0;

		char aux;
		while (arquivo.get(aux)){
			if(aux!=',' and aux!=' ' and aux!= '\n')
				auxArray[x++]=aux;
		}
		for(int i=0; i<sizeof(auxArray); i++)
			cout<<auxArray[i]<<" ";

		cout<<endl;
		x=0;
    	for (int i=0; i<tamanhoG; i++) {
			for (int j=0; j<tamanhoG; j++) {
    	    	myArray[i][j] = (auxArray[x++]-'0');
			}
		}

		for (int i=0; i<tamanhoG; i++) {
			for (int j=0; j<tamanhoG; j++) {
    	    	cout << myArray[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}

int main(){

	Grafo grafo;

	grafo.leArquivo ("Arquivo01.txt");
	//cout<<G<<endl;
	// criando um grafo
	/*
	Grafo grafo(G);

	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 3);
	grafo.adicionarAresta(1, 2);
	grafo.adicionarAresta(3, 1);
	grafo.adicionarAresta(3, 2);

	// mostrando os graus de saída
	cout << "Grau de saida do vertice 1: " << grafo.obterGrauDeSaida(1);
	cout << "\nGrau de saida do vertice 3: " << grafo.obterGrauDeSaida(3);

	// verifica se existe vizinhos
	if(grafo.existeVizinho(0, 1))
		cout << "\n\n1 eh vizinho de 0\n";
	else
		cout << "\n\n1 NAO eh vizinho de 0\n";

	if(grafo.existeVizinho(0, 2))
		cout << "2 eh vizinho de 0\n";
	else
		cout << "2 NAO eh vizinho de 0\n";
		*/

	return 0;
}

Grafo::Grafo(int V){
	this->V = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2){
	adj[v1].push_back(v2);// adiciona vértice v2 à lista de vértices adjacentes de v1
}

int Grafo::obterGrauDeSaida(int v){
	return adj[v].size();// basta retornar o tamanho da lista que é a quantidade de vizinhos
}

bool Grafo::existeVizinho(int v1, int v2){
	return (find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end()) ? true : false;
}