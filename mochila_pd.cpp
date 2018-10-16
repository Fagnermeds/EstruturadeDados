#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

//Programacao dinamica para resolver o problema da mochila

using namespace std;
using std::vector;


typedef struct{
	int qnt_itens;
	int valor;
	int peso;
}Item;

typedef struct{
	int capacidade_mochila;
	vector<Item> itens;
}Mochila;

vector<Item> v;

//ler o txt com as instancias do problema
void ler_entrada(Item *I,Mochila *M, char *nome){
	
		int i,j,k;
		FILE *f;
		f = fopen(nome, "r");
		fscanf(f,"%d%d",&I->qnt_itens,&M->capacidade_mochila);
		for(i = 0; i < I->qnt_itens; i++){
			fscanf(f,"%d%d",&I->peso,&I->valor);
			v.push_back(*I);
		}
		fclose(f);
				
}

void alg_mochila(Item *I, Mochila *M){
	//valora com o valor 0 cada posicao da matriz
	int m[I->qnt_itens+1][M->capacidade_mochila+1],k,j,s,w;
	for(j = 0; j <= I->qnt_itens; j++){
		for(k = 0; k <= M->capacidade_mochila; k++){
			m[j][k] = 0;
				
		}
	}
	//metodo principal que usa programacao dinamica							
	for(s = 1; s <= I->qnt_itens; s++){
		for(w = 1; w <= M->capacidade_mochila; w++){
			if(v[s-1].peso <= w){
				int indice = w - v[s-1].peso;
				m[s][w] = v[s-1].valor + m[s-1][indice];
				if(m[s][w] < m[s-1][w]) m[s][w] = m[s-1][w];
			} else{
				m[s][w] = m[s-1][w];
			}
			
		}
	}
	int z = I->qnt_itens;
	int n = M->capacidade_mochila;
	
	//mostra quais itens foram escolhidos para entrar na mochila
	while(I->qnt_itens > 0){
		if (m[I->qnt_itens][M->capacidade_mochila] != m[I->qnt_itens-1][M->capacidade_mochila]){
			M->itens.push_back(v[I->qnt_itens-1]);
			M->capacidade_mochila -= v[I->qnt_itens-1].peso;
			I->qnt_itens--; 
		} else I->qnt_itens--;
	}
	
	int l;
	
	cout << "Pesos dos itens colocados na mochila: ";
	for(l = 0; l < M->itens.size(); l++) cout << M->itens[l].peso << " ";
	cout << endl;
	cout << "Maior custo: " << m[z][n] << endl;	
}



int main(int argc, char *argv[]){
	Item I; 
	Mochila M;
	ler_entrada(&I, &M, argv[1]);
	alg_mochila(&I,&M);
	return 0;	
}
