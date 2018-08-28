// Neste programa, vamos estudar atribuições de ponteiros.
// 1. Rode o programa como ele está. Observe que a variável i está sendo
//	inicializada e que as variáveis pi e pppi contêm lixo pois
//	não são declaradas como variáveis globais e ppi é iniciado
//	com zero pois é declarada como variável global.
// 2. Faça as seguintes atribuições de modo que
//	pi deve apontar para o endereço de i
//	ppi deve apontar para o endereço de pi
//	pppi deve apontar para o endereço de ppi
//

#include <iostream>
#include <string>
using namespace std;

int **ppi;

template <typename T>
void imprime(T i, string s){
	cout << "Endereço de " << s << " = " << i << endl;
	cout << "Valor de " << s << " = " << *i << endl;
	cout << endl << endl;
}

int main() {
	int i;
	int *pi;
	int ***pppi;
	
	i = 27;
	
	pi = &i;
	ppi = &pi;
	pppi = &ppi;
	
	imprime<int*>(&i, "i");
	imprime<int**>(&pi, "pi");
	imprime<int***>(&ppi, "ppi");
	imprime<int****>(&pppi, "pppi");
	
	return 0;
}
