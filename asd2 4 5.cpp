#include <iostream>
#include <cstdlib>

#define LENGHTDELARGO 10 // Se define un largo para luego usarlo en las pilas 

using namespace std;

struct Pila //Estructura de la pila
{
    int top;
    int entranas[LENGHTDELARGO];
};

struct noute //Estructura del arbol
{
	int featureDeContenido;	
	struct noute *lft;
    struct noute *rght;
};

//Funciones pregunta 2
void pregunta2();
void createPila(Pila&);
void ingresamiento(Pila&, int num);
void aberPila(Pila, string);
//=====================


//Funciones pregunta 4
void ingresarNum(noute *&, int);
void evenCount(struct noute*, int *);
void pregunta4();

//=====================


//========== PREGUNTA 5 =============
int main()
{
    int choice = 0; // Se define una variable para usarla en el menu
    while (choice != -1)
    {
        cout << "===============CERTAMEN 2===============" << endl;
        cout << "1- Pregunta 2 del certamen (Pilas)" << endl;
        cout << "2- Pregunta 4 del certamen (Arbol)" << endl;
        cout << "(Ingresar -1 apagara el programa)" << endl << endl;
        cout << "Ingrese su opción en base a lo que quiera revisar: "; cin >> choice; cout << endl;
        if (choice < -1 | choice == 0 | choice > 2) // Para evitar errores referente a los numeros
        {
            cout << "Ingresar una opción válida..." << endl << endl;
        }
        if (choice == 1)
        {
            pregunta2();
        }
        else if (choice == 2)
        {
            pregunta4();
        }
    }
}

//======== PREGUNTA 2 ========
void pregunta2()
{
    int i = 0; // Se define el contador del while para poder ingresar automaticamente los elementos a la pila
    Pila pilaMain; // se define la variable de la pila
    createPila(pilaMain); // Se llama la funcion Create pila para crear la pila

    while(i < LENGHTDELARGO) //Bucle nombrado anteriormente
    {
        int leRandome = rand(); // Se le asigna a una variable dentro del bucle un numero al azar, asi cada vez que se ejecuta el bucle es un numero nuevo
        ingresamiento(pilaMain, leRandome); //Se llama la funcion Ingresamiento para poder ingresar los numeros a la pila
        i++; // Se aumenta el contador
    }
    aberPila(pilaMain, "Principal"); // Se muestra en pantalla la pila con la funcion aberPila

    Pila pilaAux1; // Se definen pilas auxiliares a las que se le ingresaran los elementos de la pila principal
    Pila pilaAux2;
    createPila(pilaAux1);//Aqui se crean dichas pilas
    createPila(pilaAux2);
    bool flag = true; //Hago un flag para al momento de dividir la pila principal se puedan repartir igual

    for(int i = pilaMain.top; i >= 0; i--) // Bucle for para recorrer la pila y poder repartir los elementos en las pilas auxiliares
    {
        if(flag == true) // Condición que si es true se ingresan los elementos en la pila auxiliar 1
        {
            ingresamiento(pilaAux1, pilaMain.entranas[i]);
            flag = false; // Se pone false el flag para que el siguiente elemento se ingrese en la pila aux 2
        }
        else // y si es false se ingresan los elementos en la pila auxiliar 2
        {
            ingresamiento(pilaAux2, pilaMain.entranas[i]);
            flag = true; // Se pone true el flag para que el siguiente elemento se ingrese en la pila aux 1
        }
    }

    aberPila(pilaAux1, "Auxiliar 1"); //Simplemente se imprime ambas pilas para mostrarlas
    aberPila(pilaAux2, "Auxiliar 2");
}

void createPila(Pila &p) //Función que crea la pila
{
    p.top = -1; //Se define el indice del tope de la pila, es decir en que lugar se encuentra
}

void ingresamiento(Pila &p, int num) //Función que ingresa elementos a la pila
{
    if(p.top != LENGHTDELARGO-1) //Mientras el tope de la pila no sea el tope-1 se puede añadir 1, es largo-1 ya que al iniciar el tope desde -1, si la condicion fuera normal, sobrepasaría la capacidad
    {
		p.top++; //Ya que hay espacio se le sube uno al tope indicando que se añadió un elemento
		p.entranas[p.top] = num; //Se accede a los elementos con el indice del top y se añade el parametro num que en este caso sería un número entero
	}
    else // Si estuviese llena la pila salta este mensaje
    {
		cout << "La pila esta copada, no se puede ingresar mas elementos." << endl;
	} 
}

void aberPila(Pila p, string nonvre) //Función que pasa 1 por 1 la pila
{
	cout << "\nPila " << nonvre << ":" << endl; // Se imprime un encabezado para que quede ordenadito
	for(int i = p.top; i >= 0; i--) //Bucle for para mostrar la pila de arriba hacia abajo
    {
		cout << p.entranas[i] << endl; //Cout para imprimir los elementos en base al indice de la pila
	}
}

//================= PREGUNTA 4 ===================
void pregunta4()
{
    noute *arbolBi; // se define el arbol en base a la estructura
    arbolBi = NULL; // se deja el arbol limpio
    int even = 0; // Contador en 0 para los numeros par
    ingresarNum(arbolBi, 19);// Se ingresan numeros previamente solo para no hacer tediosa la revisión
    ingresarNum(arbolBi, 27);
    ingresarNum(arbolBi, 5);
    ingresarNum(arbolBi, 13);
    ingresarNum(arbolBi, 11);
    ingresarNum(arbolBi, 97);
    ingresarNum(arbolBi, 5);
    ingresarNum(arbolBi, 25);
    ingresarNum(arbolBi, 3);
    ingresarNum(arbolBi, 1);
    evenCount(arbolBi, &even); // Se llama la función evenCount que es la que cuenta los pares
    
    if (even > 0) //Condición que discrimina si hay o no hay pares, y si los hay, cuantos hay.
        cout << "\nHay " << even << " números pares" << endl << endl;// Print que te dice cuantos pares hay
    else
        cout << "\nNo hay números par" << endl << endl; // Print de que no hay pares
}

void ingresarNum(noute *&nd, int featureDeContenido) //Función que ingresa números al arbol
{
	if (nd == NULL) // Si el nodo esta vacío se ejecuta
    {
		nd = new noute; // Se define un nodo
		nd -> featureDeContenido = featureDeContenido; // Se le otorga el elemento al nodo
		nd -> lft = NULL; // Se limpia el nodo izq
		nd -> rght = NULL; // Se limpia el nodo derecho
	}
    else
    {
		if (featureDeContenido < nd -> featureDeContenido) //Condición que te compara el número que tienes con el que ya esta en el nodo para saber si ingresarlo a la izquierda o a la derecha
        { 
			ingresarNum(nd -> lft, featureDeContenido); //Se ingresa a la izquierda si el numero a ingresar fuese menor a el numero en el nodo
		}
		if(featureDeContenido > nd -> featureDeContenido) // Misma condición de arriba pero invertida
        { 
			ingresarNum(nd -> rght, featureDeContenido); //Se ingresa a la derecha si el numero a ingresar fuese mayor a el numero en el nodo
		}
	}
}

void evenCount(struct noute* nd, int *num) // Función que itera de manera recursiva sobre el arbol del parametro, para recorrerlo y revisar los numeros si acaso son pares actualizando un contador a través de un puntero
{
    if (nd == NULL) // Es por seguridad para evitar errores, si el nodo esta vacío, no hace nada
        return;
    if(nd->lft != NULL) evenCount(nd -> lft, num); //Al momento de iterar se usa una condición para saber si el nodo a mirar esta vacío (o NULL), si no lo está, se itera recursivamente ahora con el número del nodo revisado anteriormente. Todo esto en el lado izquierdo
    if(nd->rght != NULL) evenCount(nd -> rght, num); // Lo mismo de arriba pero en el lado derecho
    if (nd -> featureDeContenido % 2 == 0) //Condición simple para calcular el elemento del nodo tomado y revisar si es par, si lo fuese se le suma uno al contador
    {
        (*num)++; //Contador nombrado previamente que actualiza la variable con un puntero.
    }
}

