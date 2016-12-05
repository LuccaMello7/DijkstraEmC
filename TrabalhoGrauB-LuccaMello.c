#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000
#define MAXN 20

int numeroDeVertices; 
int limite[MAXN][MAXN];
int armazenarValor[MAXN]; 
int distancia[MAXN]; 
int caminho[MAXN]; 

void Dijkstra(int v0) {
	int i, j; 
	int k; //outra variavel pro 'for'
	 
	for (i = 0; i < numeroDeVertices; i++) {
		distancia[i] = limite[v0][i];
		armazenarValor[i] = 0;
		if (i != v0 && distancia[i] < INF)
			caminho[i] = v0;
		else
			caminho[i] = -1;
	}
	
	armazenarValor[v0] = 1;
	distancia[v0] = 0;
	
	for (i = 0; i < numeroDeVertices - 1; i++) {
		int min = INF;
		int u = v0;
		for (j = 0; j < numeroDeVertices; j++) {
			if (!armazenarValor[j] && distancia[j] < min) {
				u = j;
				min = distancia[j];
			}
		}
		armazenarValor[u] = 1; //significa que o menos caminho foi encontrado.
		
		for (k = 0; k < numeroDeVertices; k++) {
			
			if (!armazenarValor[k] && limite[u][k] < INF && distancia[u] + limite[u][k] < distancia[k]) {
				distancia[k] = distancia[u] + limite[u][k];
				caminho[k] = u;
			}
		}
	}
}

int main() {
	
	int i, j;
	int verticeInicio, verticeFim, peso; //Inicio, fim and peso.
	
	printf("Inserir numero total de vertices:\n");
	scanf("%d", &numeroDeVertices);
	
	printf("\n Valores para os vertices \n\n A = 0\n B = 1\n C = 2\n D = 3\n E = 4\n\n");
	
	while (1) {
		
		printf("Inserir o vertice de inicio, fim e o seu peso:\n");
		scanf("%d%d%d", &verticeInicio, &verticeFim, &peso);
		
		if (verticeInicio == -1 && verticeFim == -1 && peso == -1)
		
		break;
		
		limite[verticeInicio][verticeFim] = peso;
	}
	
	
	for (i = 0; i < numeroDeVertices; i++) {
		for (j = 1; j <= numeroDeVertices; j++) {
			if (i == j)
				limite[i][j] = 0;
			else if (limite[i][j] == 0)
				limite[i][j] = INF;
		}
	}

	Dijkstra(0);

	int caminhoMaisCurto[MAXN];
	
	for (i = 0; i < numeroDeVertices; i++) {
		
		printf("%d\t", distancia[i]);
		memset(caminhoMaisCurto, 0, sizeof(caminhoMaisCurto));
		//primeiro byte da posicao / valor que cada elemento irá receber / numero de bytes que cada elemento possui
		int k = 0;
		caminhoMaisCurto[k] = i;
		
		while (caminho[caminhoMaisCurto[k]] != 0) {
			k++;
			caminhoMaisCurto[k] = caminho[caminhoMaisCurto[k - 1]];
		}
		
		k++;
		
		caminhoMaisCurto[k] = 0;
		for(j = k; j>0; j--)
		
		printf("%d->",caminhoMaisCurto[j]);
		printf("%d\n",caminhoMaisCurto[0]);
	}
	
	return 0;
}
