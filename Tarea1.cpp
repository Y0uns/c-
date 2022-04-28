#include <iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *next;
};
void AgregarLista (nodo **, int);
void Listar (nodo *);
void CantidadElementos (nodo *);
void EliminarLista (nodo *&, int &);
void InvertirOrden (nodo *);
void elim (nodo *&);

int main(){
	int dato;
	int x, a, n;
	a = 1;
	nodo* pBuscado;
	nodo*lista = NULL;
	while (a != 0){
		
	cout << "\n 	---Elija la opcion---" << endl;
	cout << "1.- Agregar un numero al inicio de la lista"<< endl;
	cout << "2.- Agregar un numero al final de la lista" << endl;
	cout << "3.- Eliminar el primer elemento de la lista" << endl;
	cout << "4.- Borrar toda la lista" << endl;
	cout << "5.- Mostrar la cantidad de elementos que tiene la lista" << endl;
	cout << "6.- Imprimir lista por pantalla" << endl;
	cout << "7.- Invertir lista e imprimirla" << endl;
	cout << "8.- Invertir lista mediante un subproceso recursivo" << endl;
	cout << "9,. Salir."<< endl; 
	cout <<  "Opcion elegida: ";
	cin >> x;
	
	switch (x){
		case 1:
			cout << "Ingrese numero que quiere agregar: ";
			cin >> n;
			AgregarLista(&lista, n);
			break;
		case 3:
			elim(lista);
			break;
		case 4:
			EliminarLista(lista, n);
			break;
		case 5:
			CantidadElementos(lista);
			break;
		case 6:
			Listar(lista);
			break;
		case 7:
			InvertirOrden(lista);
			break;
		case 9:
			a=0;
			cout <<"Muchas gracias por usar el programa"<< endl;
			break;
	
	}		
	}
	
}


void AgregarLista (nodo **head, int dato){
	nodo *nuevo;
	nuevo = new nodo;
	
	nuevo -> dato = dato;
	nuevo -> next = NULL;
	
	nuevo -> next = *head;
	*head = nuevo; 
}

void Listar(nodo *head){
	nodo *p;
	cout << "Lista: ";
	for (p = head; p!= NULL; p = p-> next){
		cout << p -> dato << " ->";
	}
	cout << "\n";
}
void CantidadElementos (nodo *head){
	int cont;
	nodo *p;
	cont = 0;
	for(p = head; p!= NULL; p = p-> next){ 
		cont++;
	}
	cout << "La cantidad de elementos que contiene la lista es de: "<< cont;
}
void EliminarLista (nodo *&lista, int &n){
	if (lista != NULL){
		
	while (lista != NULL){
		nodo *aux = lista;
		n = aux -> dato;
		lista = aux -> next;
		delete aux;
	}
	cout << "Se ha eliminado la lista" << endl;
}else{
	cout << "No hay listas para eliminar" << endl;
}	
	}
void InvertirOrden (nodo *head){
	nodo *p;
	nodo *lista2 = NULL;
	for(p = head; p!= NULL; p = p-> next){
		
		AgregarLista(&lista2, p -> dato);
	}	
	Listar(lista2);
}
void elim(nodo *&lista){
	if (lista != NULL)
	{
		lista = lista -> next;
		cout << "El primer elemento ha sido eliminado!";
	}
	else{
		cout << "La lista no contiene elementos";
	}	
}
