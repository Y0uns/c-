#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


struct nodo{
	int dato;
	nodo *next;
	

};

void crearLista(nodo **);
void listar(nodo*);
int buscar(nodo*, int);
float promedio (nodo *);
//pregunta 1
/*
void multiplos();
int factorial(int);
int main(){
	int op,num;
	
	
	do {
		cout << "\n\nMenu" << endl;
		cout << "1. Multiplos" << endl;
		cout << "2. Factorial" << endl;
		cout << "0. Salir" << endl;
		cout << "Opcion "; cin >> op;
		
		switch (op){
			case 1:
				multiplos();
				break;
			case 2:
				cout << "Ingresa numero: "; cin >> num;
				cout << num << "! 0 " << factorial(num);
				break;
			
			case 0:
				break;
			default: 
				cout<< "Opcion no valida";
		
		}
		
		
	}while(op!=0);
}



int factorial(int n){
	int fact=1;
	for (int i=1; i<=n;i++){
		fact *=i;
	}
	return fact;
}

void multiplos (){
	int mult, n;
	cout << "\nIngresa un numero: "; cin >> mult;
	cout << "Cantidad de multiplos a imprimir: "; cin >> n;
	
	for (int i=1; i<=n; i++){
		cout << mult*i << " ";
		
		
		
	}
	
	
}
*/
//Pregunta 3
void crearLista(nodo ** head){
	
	srand(time(NULL));
	
	int n;
	cout << "Cantidad de nodos a crear: "; cin >> n;
	
	for (int i=0; i<n;i++){
		
		nodo *nuevo;
		nuevo = new nodo;
	
		nuevo ->dato = rand()%100;
		nuevo ->next = NULL;
	
		nuevo ->next = *head;
		*head = nuevo;		
	}	
}

//pregunta 4

int buscar(nodo *head, int num){
	int pos=0;
	nodo *p;
	for (p=head; p!=NULL; p=p->next){
		pos++;
		if(p->dato == num){
			return pos;
		}
	}
	return -1;
}


//pregunta 5
float promedio(nodo *head){
	float sum=0, prom, cont=0;
	nodo *p;
	for (p=head; p!=NULL; p=p->next){
		cont ++;
		sum+=p->dato;
		
	}
	
	prom =sum / cont;
	
	return prom;
	
	
	
}









//pregunta 6
int main (){
	nodo* lista = NULL;
	int num;
	
	crearLista(&lista);
	listar(lista);
	cout << "\n\nIngresa el numero buscado: " ; cin >> num;
	cout << "Posicion: " << buscar (lista,num);
	
	cout <<"\n\nPromedio de los numeros:" << promedio(lista);
	
}



//Funciones adicionales

void listar(nodo *head){
	nodo *p;
	for (p=head; p!=NULL; p=p->next){
		cout << p->dato << "->";
		
	}
	
}
