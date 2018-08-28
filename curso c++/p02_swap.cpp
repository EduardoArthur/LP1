// Neste programa, vamos estudar a manipulação de ponteiros e o uso de templates.
// 1. Rode o programa como ele está.
// 2. Altere as funções swapPointers() e swapValues() para que a primeira
//    troque os ponteiros de 'a' e 'b' e a segunda altera os valores a
//    que apontam os ponteiros 'a' e 'b' sem que sejam alterados os ponteiros.
//    Não altere nada além das funções referidas.
// 3. Descomente o código de main(). Agora temos outras duas variáveis
//    'c' e 'd', mas do tipo double. Altere as funções swapPointers(), 
//    swapValues() e imprime() para que possam receber valores do tipo int
//    ou double. Será necessário alterar a chamada das funções em main().
//

#include <iostream>
#include <stdlib.h>
using namespace std;

void imprime(int *p1, int *p2, char c1, char c2){
	cout << "Valor de "<< c1 << " = " << *p1 << endl;
	cout << "Endereço de "<< c1 << " = " << p1 << endl;
	cout << "Valor de "<< c2 << " = " << *p2 << endl;
	cout << "Endereço de "<< c2 << " = " << p2 << endl;
	cout << c1 << " + " << c2 << " = " << (*p1)+(*p2) << endl;
	cout << endl << endl;
}

void swapPointers(int **a, int **b){
	int *aux;
	aux = *a;
	*a = *b;
	*b = aux;

}

void swapValues(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;

}

int main() {
	int *a, *b;
	double *c, *d;
	
	a = (int*) malloc(sizeof(int));
	b = (int*) malloc(sizeof(int));
	*a = 13;
	*b = 27;
	
	cout << "Depois das as atribuições de a e b:" << endl;
	imprime(a, b, 'a', 'b');
	
	swapPointers(&a, &b);
	
	cout << "Depois da função swapPointers(a, b):" << endl;
	imprime(a, b, 'a', 'b');
	
	swapValues(a, b);
	
	cout << "Depois da função swapValues(a, b):" << endl;
	imprime(a, b, 'a', 'b');
	
	
	/*
	Descomente esta parte para resolver a questão 3
	
	c = (double*) malloc(sizeof(double));
	d = (double*) malloc(sizeof(double));
	*c = 2.5;
	*d = 3.7;
	
	cout << "Depois das as atribuições de c e d:" << endl;
	imprime(c, d, 'c', 'd');
	
	swapPointers(&c, &d);
	
	cout << "Depois da função swapPointers(c, d):" << endl;
	imprime(c, d, 'c', 'd');
	
	swapValues(c, d);
	
	cout << "Depois da função swapValues(c, d):" << endl;
	imprime(c, d, 'c', 'd');
	*/
	
	return 0;
}
