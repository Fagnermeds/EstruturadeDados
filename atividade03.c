#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define RANGE 255
 

int vetor[] = {23,4,6,1,65,32,13,54,78,100,434,9,15,19,145,348,43,89,60,180,567,2,5,77,700};
int tamanho = 0;

int maximum(int array[], int size){

  int curr = 0;
  int max = 0;

  for(curr = 0; curr < size; curr++){
    if(array[curr] > max){ max = array[curr]; }
  }

  return max;
}

void countSort2(int vetor[], int n, int exp){

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

void radixSort(int vetor[], int tamanho) {
    
    int exp;
    int m = maximum(vetor, tamanho);
 
    for (exp = 1; m/exp > 0; exp *= 10) {
    	countSort2(vetor, tamanho, exp);
    }
}

void countSort(int array[], int size) { 
  
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

int imprimeVetor(int vetor[], int tamanho){
	int i;
	for(i = 0;i < tamanho; i++) printf("%d ", vetor[i]);
	return 0;
}



void menu(){
		
	int op;
		
	printf("\n1. CoutingSort \n2. RadixSort");
	printf("\n");
	scanf("%d", &op);

	switch (op){
		case 1:
			countSort(vetor,tamanho);			
			imprimeVetor(vetor, tamanho);
		break;
		case 2:
			radixSort(vetor,tamanho);
			imprimeVetor(vetor, tamanho);			
		break;			
	}	
}

main(){
	 
	tamanho = sizeof(vetor)/sizeof(vetor[0]);
	menu();		
	printf("\n");
}
