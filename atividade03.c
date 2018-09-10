#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define RANGE 255
 
float tmp;
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

int maximum(int * array, int size){

  int curr = 0;
  int max = 0;

  for(curr = 0; curr < size; curr++){
    if(array[curr] > max){ max = array[curr]; }
  }

  return max;
}

void countSort2(int *vetor, int n, int exp){

    int output[n]; // output array
    int i, count[10] = {0};
 
    
    for (i = 0; i < n; i++)
        count[ (vetor[i]/exp)%10 ]++;
 
       for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (vetor[i]/exp)%10 ] - 1] = vetor[i];
        count[ (vetor[i]/exp)%10 ]--;
    }
    
    for (i = 0; i < n; i++)
        vetor[i] = output[i];
    
}

void radixSort(int *vetor, int tamanho) {
    
    int exp;
    int m = maximum(vetor, tamanho);
 
    for (exp = 1; m/exp > 0; exp *= 10) {
    	countSort2(vetor, tamanho, exp);
    }
}

void countSort(int *array, int size) { 
  
  	int curr = 0;
  	int max = maximum(array, size);
  	int * counting_array = calloc(max, sizeof(int)); // Zeros out the array

  	for(curr = 0; curr < size; curr ++){
    		counting_array[array[curr]]++;
  	}

  	int num = 0;
  	curr = 0;

  	while(curr <= size){
    		while(counting_array[num] > 0){
      			array[curr] = num;
      			counting_array[num]--;
      			curr++;
      			if(curr > size){ break; }
    		}
    		num++;
	}
    
} 

int imprimeVetor(int *vetor, int tamanho){
	int i;
	for(i = 0;i < tamanho; i++) printf("%d ", vetor[i]);
	return 0;
}

int menu1(){
	
	int op;
	
	printf("\n1. vetor[25] \n2. vetor[10.000] \n3. vetor[100.000]");
	printf("\n");
	scanf("%d", &op);
	
	switch (op){
		case 1:
			url = "vetor.txt";
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

void menu(){
	int var = 1;
	int op;
	float t;
	
	printf("\n1. CoutingSort \n2. RadixSort \n3. Voltar");
	printf("\n");
	scanf("%d", &op);

	switch (op){
		case 1:
			countSort(vetor,tamanho);			
			imprimeVetor(vetor, tamanho);
			//printf("\n\nTempo de execucao: %f", tmp);
		break;
		case 2:
			radixSort(vetor,tamanho);
			imprimeVetor(vetor, tamanho);
			//printf("\n\nTempo de execucao: %f", tmp);
		break;
		case 3:
			menu1();
		break;			
	}	
}

main(){
	menu1();
	vetor = (int*)malloc(sizeof(int)*tamanho);
	lerDados(url);
	menu();		
	printf("\n");
}
