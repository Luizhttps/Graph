#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Grafo{
	public:
		int tamanhoG;
		int *adj;
		int **matriz;
		int **matrizT;
		Grafo ();
        void leArquivo(char[]);
		void criaGrafo();				  //1
		void insereAresta(int, int, int); //2
		bool verificaAresta(int, int);	  //3
		void verticesAdjacente(int**,int);//4
		void retiraAresta(int, int);	  //5
		void mostraGrafo(int**);		  //6
		int  numeroVertices();		 	  //7
		void grafoTransposto(int**);	  //8
		void arestaMenorPeso(int**);	  //9
		void limpaMatriz(int**);
};

void Grafo::leArquivo(char fileName[]){
    FILE *fp;
    fp= fopen(fileName,"r");

		fscanf(fp,"%i",&tamanhoG);
		//
		criaGrafo();
		//
        while(!feof(fp)){
            for(int i=0;i<tamanhoG;i++){
                for(int j=0;j<tamanhoG;j++){
                    fscanf(fp,"%i",&matriz[i][j]);
                }
            }
        }
}

int main(){

	Grafo G;

    char nomeArquivo[] = {"arq01.txt"};

	G.leArquivo(nomeArquivo);
	//
	cout<<"Numero de vertices: "<<G.numeroVertices()<<endl;
	//
	int x=0, y=2;
	if(G.verificaAresta(x, y))
		cout<<"Aresta {"<<x<<","<<y<<"} existe no Grafo."<<endl;
	else
		cout<<"Aresta {"<<x<<","<<y<<"} nao existe no Grafo."<<endl;
	//
	cout<<endl<<"Grafo Principal: "<<endl;
	G.mostraGrafo(G.matriz);
	//
	G.verticesAdjacente(G.matriz, 3);
	//
	x=0; y=1;
	cout<<"Retirando Aresta: {"<<x<<","<<y<<"}"<<endl;
	G.retiraAresta(x,y);
	x=1; y=0;
	cout<<"Retirando Aresta: {"<<x<<","<<y<<"}"<<endl;
	G.retiraAresta(x,y);
	//
	cout<<endl<<"Grafo Principal: "<<endl;
	G.mostraGrafo(G.matriz);
	//
	G.grafoTransposto(G.matriz);
	cout<<endl<<"Grafo Transposto: "<<endl;
	G.mostraGrafo(G.matrizT);
	//
	cout<<endl;
	G.arestaMenorPeso(G.matriz);
	//
	G.limpaMatriz(G.matriz);
	G.limpaMatriz(G.matrizT);

	return 0;
}


Grafo::Grafo(){};
//1
void Grafo::criaGrafo(){
	matriz = new int* [tamanhoG];
    	for(int i=0; i<tamanhoG; i++)
        	matriz[i] = new int [tamanhoG];
}

//2
void Grafo::insereAresta(int valor, int linha, int coluna){
    matriz[linha][coluna] = valor;
}

//3
bool Grafo::verificaAresta(int linha, int coluna){
	return (matriz[linha][coluna] == 1) ? true : false;
}

//4
void Grafo::verticesAdjacente(int **mat, int v){
	int cont=0, x=0;
	for (int i=0; i<tamanhoG; i++){
		if(matriz[i][v]==1)
			cont++;
	}
	adj = new int [cont];
	for (int i=0; i<tamanhoG; i++){
		if(matriz[i][v]==1)
			adj[x++]=i;
	}
	cout<<endl<<"Vertices adjacentes a "<<v<<": ";
	for (int i=0; i<cont; i++){
		cout<<adj[i]<<" ";
	}cout<<endl;
}

//5
void Grafo::retiraAresta(int linha, int coluna){
	if (matriz[linha][coluna]==1)
		matriz[linha][coluna] =0; 
}

//6
void Grafo::mostraGrafo(int **mat){
	for (int i=0; i<tamanhoG; i++) {
		for (int j=0; j<tamanhoG; j++) {
    	    cout << mat[i][j]<<" ";
	    }
	    cout<<endl;
    }
}

//7
int Grafo::numeroVertices(){
	return tamanhoG;
}

//8
void Grafo::grafoTransposto(int **mat){
	matrizT = new int* [tamanhoG];
    	for(int i=0; i<tamanhoG; i++)
        	matrizT[i] = new int [tamanhoG];
	
	for (int i=0; i<tamanhoG; i++){
		for (int j=0; j<tamanhoG; j++){
			matrizT[j][i]=mat[i][j];
		}
	}
}

//9
void Grafo::arestaMenorPeso(int **mat){
	int peso, linha=0, coluna=0;
	peso=mat[0][0];
	for (int i=0; i<tamanhoG; i++){
		for (int j=0; j<tamanhoG; j++){
			if (mat[i][j] < peso){
				peso = mat[i][j];
				linha = i;
				coluna= j;
			}
		}
	}
	cout<<"Aresta de menor peso : {"<<linha<<","<<coluna<<"}"<<endl;
	cout<<"Peso da Aresta :"<<peso<<endl;
}

void Grafo::limpaMatriz(int **mat){
	for (int i =0; i<tamanhoG; i++) {
    	free(mat[i]);
    	mat[i] = NULL;
  	}
  	free(mat);
  	mat = NULL;
}