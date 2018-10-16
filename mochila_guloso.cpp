#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

//Usa o conceito de algoritmos gulosos para resolver o problema da mochila
using namespace std;
using std::vector;

typedef struct{
	double valor_utilidade;
	int peso;
	int valor;
}Item;

typedef struct{
	int capacidade;
	vector<Item> itens;
	int maior_custo;
	vector<int> produtos_escolhidos;
}Mochila;

typedef struct{
	int qnt_produtos;
	vector<Item> t_itens;
}Caixa;

bool larger(const Item& item1, const Item& item2){
	 return item1.valor_utilidade > item2.valor_utilidade;
}

void add_item_caixa(Caixa *C,float v_utilidade, int peso, int valor){
	Item item;
	item.valor_utilidade = v_utilidade;
	item.peso = peso;
	item.valor = valor;
	C->t_itens.push_back(item);
}

void ler_entrada(Caixa *C, Mochila *M, Item *I, char *nome){
	int i,peso,valor; 
	double v_utilidade;
	FILE *f;
	f = fopen(nome,"r");
	fscanf(f,"%d%d", &C->qnt_produtos,&M->capacidade);
	
	for(i = 0; i < C->qnt_produtos; i++){
		fscanf(f,"%d%d",&peso,&valor);
		v_utilidade = (double) valor/peso;
		add_item_caixa(C,v_utilidade,peso,valor);
	}	
}

void alg_mochila(Caixa *C, Mochila *M, Item *I){
	int i,j,k;
	M->maior_custo = 0;
	sort(C->t_itens.begin(), C->t_itens.end(),larger);

	for(i = 0; i < C->qnt_produtos; i++){
		if(C->t_itens[i].peso <= M->capacidade){
			M->itens.push_back(C->t_itens[i]);
			M->capacidade = M->capacidade - C->t_itens[i].peso;
		}
	}
	for(j = 0; j < M->itens.size(); j++){  
		M->maior_custo += M->itens[j].valor;
	}
	
	cout << "Maior custo: " << M->maior_custo << endl;
}

int main(int argc, char *argv[]){
	Caixa caixa;
	Item item;
	Mochila mochila;
	ler_entrada(&caixa,&mochila,&item,argv[1]);
	alg_mochila(&caixa,&mochila,&item);
	return 0;
}
