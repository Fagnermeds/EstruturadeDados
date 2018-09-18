#include <stdio.h>

int A [] = {12,11,13,5,6,7,54,45,34,56,34,67,89,75,15,65,20,100,200,140,156,354,280}; 


int left(i){
	return 2*i+1;
}

int right(i){
	return 2*i+2;
}

void maxheapfy(int A[], int i, int A_tamanho){
	
	int maior, aux;
	int l = left(i);
	int r = right(i);
	
	if (l < A_tamanho && A[l]>A[i]){
		maior = l;
			
	}else maior = i;
	
	if (r < A_tamanho && A[r] > A[maior]){
		maior = r;
	} 
	if (maior != i){
		aux = A[i];
		A[i] = A[maior];
		A[maior] = aux;
		maxheapfy(A,maior,A_tamanho);
	}	
}

void buildmaxheap(int A[], int tamanho){
	int i;
	for(i = tamanho/2-1;i>=0;i--){
		maxheapfy(A,i,tamanho);
	}
}

void heapsort(int A[], int tamanho){
	int i,aux;
	buildmaxheap(A,tamanho);
	for(i = tamanho-1;i>=1;i--){
		aux = A[0];
		A[0] = A[i];
		A[i] = aux;
		maxheapfy(A,0,i);
	}
}

void imprime(int A[],int t){
	int i;
	for(i = 0; i < t; i++){
		printf("%d ", A[i]);
	}
}

int main(){
	int t = sizeof(A)/sizeof(A[0]);
	heapsort(A,t);
	imprime(A,t);
	return 0;
}




