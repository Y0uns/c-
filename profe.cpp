#include <iostream>
#include <cstdlib>
#define LARGO 10

using namespace std;
/*
1.1 La falla radica en en la funcion de agregarm ya que en vez de trabajar
en la tercera linea con la pos que saco, funciona con la id completa, entonces debido a esto
lo manda a otra celda
1.2 cambiando la nueva id por la pos


3.1 el nuemero 15 se encuentra en el nivel 3
3.2 el orden sería 4-7-5-9-8-14-13-17-15-10
*/

struct Pila{
	int top;
	int elm[LARGO];
};

void cPila(Pila &p){
	p.top = -1;
}

void push(Pila &p, int num){
		p.top++;
		p.elm[p.top] = num;
}

void vPila(Pila p){
	int i;
	for(i = p.top ; i>=0; i--){
		cout << "|" << p.elm[i] << "|" << endl;
		
	}
}


int pop(Pila &p){
		return p.elm[p.top--];
	
}

void pil(){
	Pila pila;
	Pila pila2;
	Pila pila3;
	cPila(pila);
	cPila(pila2);
	cPila(pila3);
	
	int i;
		for (i = 1; i <= 10; i++ ){
			push(pila,rand()%100);
		}
	cout<<"\nPila Original:D \n\n";
	vPila(pila);
	
	int a;
	for (i = 1; i <= 10; i++ ){
			a = pop(pila);
			if(i%2 == 0){
				push(pila2,a);
			}else{
				push(pila3,a);
			}
		}
	cout<<"\nPila 2:D \n\n";
	vPila(pila2);
	cout<<"\nPila 3:D \n\n";
	vPila(pila3);
}

struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
};

void insertar(nodo *&n, int dato){
    if(n==NULL){
        n = new nodo;
        n->dato = dato;
        n->izq = NULL;
        n->der = NULL;
    }else{
        if(dato < n->dato) insertar(n->izq,dato);
        if(dato > n->dato) insertar(n->der,dato);
    }
}

void inorden(nodo *n){
	if(n!= NULL){
		if(n->izq != NULL) inorden(n->izq);
		cout << n->dato << " ";
		if(n->der != NULL) inorden(n->der);
	}
}

int b;
int inorden1(nodo *n){
    if(n!= NULL){
        if(n->izq != NULL) inorden1(n->izq);
        if(n->dato%2==0){
            b++;
        }
        if(n->der != NULL) inorden1(n->der);
    }
	return b;
}

void tree(){
    nodo *arbol;
    arbol = NULL;
	insertar(arbol,3);
	insertar(arbol,4);
	insertar(arbol,5);
	insertar(arbol,2);
    inorden(arbol);
    
cout << "\nCantidad de pares "<<inorden1(arbol);
}


int main(){
		int num;
		
		cout<< "Bienvenida al menu del c2 :D\npara acceder a la pregunta 2 pulse 1, y para la 4 pulse 2: ";
		cin >> num;
		
		switch(num){
			case 1: 
				pil();
				break;
			case 2: 
				tree();
				break;
			default: 
				break;
		}
}
