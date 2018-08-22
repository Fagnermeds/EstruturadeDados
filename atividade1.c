#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>


int *vetor, tamanho;
char linha[50];
char *url;
clock_t temp;
																				

int tamanhoVetor(char *url){
	
	char ch;
	int vezes=0;
	FILE *arq;
	
	arq = fopen(url, "r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while( (ch=fgetc(arq))!= EOF )
			if(ch == '\n')
			  vezes++;
			  
	fclose(arq);
	return vezes;
}
  	
int aloca(int tamanho, int *vetor){
	
	return 0;
}


void lerDados(char *url){
	
	FILE *arq;
	char Linha[100];
	char *result;
	int i;
	
	
	//clrscr();
	
	
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen(url, "r");

	if (arq == NULL)  // Se houve erro na abertura
  	{
     		printf("Problemas na abertura do arquivo\n");
     		return;
  	}

  	i = 0;
  	
  	//vetor = (int *) malloc(size * sizeof(int)); 
  	
  	while (!feof(arq))
  	{
		// Lê uma linha (inclusive com o '\n')
      		result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      		//printf("linha %d: %s",i,Linha);
      		if (result) vetor[i] = atoi(result); // Se foi possível ler 
      		i++;
      			
  	}
  	fclose(arq);
}

float insertionSort (int *v, int tamanho){
	
   	int i, j, x;
   	temp = clock();   	
   	for (j = 1; j < tamanho; ++j) {
      		x = v[j];
      		for (i = j-1; i >= 0 && v[i] > x; --i) v[i+1] = v[i];
      		v[i+1] = x;
   	}
   	temp = clock() - temp;
   	return ((float)temp)/CLOCKS_PER_SEC;
}

float selectionSort(int *v, int tamanho){

	temp = clock();
	int i,j,min,x;
	 
	for(i = 0; i < tamanho-1; ++i){
		min = i;
		for(j = i+1; j < tamanho; ++j) if(v[j] < v[min]) min = j;
		x = v[i];
		v[i] = v[min];
		v[min] = x;
	}
	temp = clock() - temp;
	
	return ((float)temp)/CLOCKS_PER_SEC;
}

float bubbleSort(int *vetor, int tamanho){
	
	temp = clock();
	int i, j, aux;
	
	for(i = 1; i < tamanho; i++){
		for(j = 0;j < tamanho - i; j++){
			if(vetor[j] > vetor[j+1]){
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux; 
			}
		}
	}
	temp = clock() - temp;
	
	return ((float)temp)/CLOCKS_PER_SEC;
}

float quickSort(int *vetor, int inicio, int fim){	
	
	int i, j, meio, aux;
 	
   	i = inicio;
   	j = fim;
   	meio = vetor[(inicio + fim) / 2];
 	temp = clock();
   	do{
      		while(vetor[i] < meio) i++;
      		while(vetor[j] > meio) j--;
      		if(i <= j){
        		aux = vetor[i];
         		vetor[i] = vetor[j];
         		vetor[j] = aux;
         		i++;
         		j--;
      		}
   	}while(i <= j);
 
   	if(inicio < j) quickSort(vetor, inicio, j);
   	if(i < fim) quickSort(vetor, i, fim);
   	temp = clock() - temp;
   	return ((float)temp)/CLOCKS_PER_SEC;
}

int embaralhar(int *vet, int vetSize){
	int i,r,temp;
	for (i = 0; i < vetSize; i++){
		r = rand() % vetSize;
		temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
	return 0;
}

int imprimeVetor(int *vetor, int tamanho){
	int i;
	for(i = 0;i < tamanho; i++) printf("%d ", vetor[i]);
	return 0;
}

void menu(){
	int var = 1;
	int op;
	float t;
	
	printf("\n1. insertionSort \n2. selectionSort \n3. bubbleSort \n4. quickSort \n5. voltar");
	printf("\n");
	scanf("%d", &op);

	switch (op){
		case 1:
			t = insertionSort(vetor,tamanho);			
			imprimeVetor(vetor, tamanho);
			printf("\n\nTempo de execucao: %f", t);
		break;
		case 2:
			t = selectionSort(vetor,tamanho);
			imprimeVetor(vetor, tamanho);
			printf("\n\nTempo de execucao: %f", t);
		break;
		case 3:
			t = bubbleSort(vetor,tamanho);
			imprimeVetor(vetor, tamanho);
			printf("\n\nTempo de execucao: %f", t);
		break;			
		case 4:
			t = quickSort(vetor,0 , tamanho-1);
			imprimeVetor(vetor, tamanho);
			printf("\n\nTempo de execucao: %f", t);
		break;
		case 5:
			menu1();
		break;
	}	
}

int menu1(){
	
	int op;
	
	printf("\n1. Vetor[1.000] \n2. vetor[10.000] \n3. vetor[100.000]");
	printf("\n");
	scanf("%d", &op);
	
	switch (op){
		case 1:
			url = "num.1000.1.in";
			tamanho = tamanhoVetor(url);
			printf("%d", tamanho);			
		break;
		case 2:
			url = "num.10000.1.in";
			tamanho = tamanhoVetor(url);
			printf("%d", tamanho);			
		break;
		case 3:
			url = "num.100000.4.in";
			tamanho = tamanhoVetor(url);
			printf("%d", tamanho);			
		break;
	}
	
	return 0;
}

int main(int argc, int *argv[]){
	
	menu1();
	vetor = (int*)malloc(sizeof(int)*tamanho);
	lerDados(url);
	menu();		
	printf("\n");		
}

