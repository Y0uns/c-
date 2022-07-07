#include <iostream>

using namespace std;

struct node
{
    int id;
    int price;
    string description;
    struct node *next;
};

struct nGraph{
    int dato;
    nGraph *next;        
};

struct adjacentList
{
    nGraph *head;
};

struct Grafo
{
    string *nombres;
    int nGraphs;
    adjacentList *enlaces;
};

struct linkedList
{
    node * head = NULL;
    node *sorted = NULL;
    int size = 0;
};
node* gethead()
{
    return head;
}
void addNode(int n, string tx)
{
    node *tmp = new node;
    tmp->id = size;
    tmp->price = n;
    tmp->description = tx;
    tmp->next = NULL;
    size++;

    if(head == NULL)
    {
        head = tmp;
    }
    else
    {
        tmp->next = head;
        head = tmp;
    }
}
void sortbyid()
{
    node *h = head, *i, *j, *next_i;
    for(i = h; i!=NULL && i->next!=NULL; i=i->next)
    {
        node *min;
        min = i;
        for(j = i->next; j!=NULL ; j=j->next)
        {
            if(j->id < min->id)
                min=j;
        }
        if(min!=i)
        {
            int tmp;
            tmp = min->id;
            min->id = i->id;
            i->id = tmp;
        }

    }
    head = h;
    display(head);
}
void insertionSort()
{
    sorted = NULL;
    node* current = head;
    while (current != NULL)
    {
        node* next = current->next;
        sortedInsert(current);
        current = next;
    }
    head = sorted;
    display(head);
}

void sortedInsert(node* newnode)
{
    if (sorted == NULL || sorted->price >= newnode->price)
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else
    {
        node* current = sorted;
        while (current->next != NULL && current->next->price < newnode->price)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void display(node *head)
{
    if(head == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << "ID: "<< head->id << endl;
        cout <<"Precio: "<< head->price << endl;
        cout << "Descripcion: "<< head->description <<"\n" <<endl;
        display(head->next);
    }
}

//RESPUESTA 1
void ordenamiento(linkedList lList)
{
    int choiceOrd = 0;
    int price;
    string nProduct;
    
    do
    {
        cout << "\nBienvenida al almacén Sansano\n" << endl;
        cout << "1- Agregar un nuevo producto" << endl;
        cout << "2- Ver listado de productos ordenados por código" << endl;
        cout << "3- Ver listado de productos ordenados por precio" << endl;
        cout << "\n(-1) para volver." << endl;
        cout << "R: ";  cin >> choiceOrd;
        switch (choiceOrd)
        {
        case 1:
            cout << "Ingrese el precio deseado: "; cin >> price;
            cout << "Ingrese el nombre del producto a agregar: "; cin >> nProduct; cout << endl;
            lList.addNode(price, nProduct); cout << endl;
            linkedList::display(lList.gethead());
            break;
        
        case 2:
            lList.sortbyid();
            break;
        
        case 3:
            lList.insertionSort();
            break;
        }
    } 
    while (choiceOrd != -1);
    
}


nGraph* leNode(int dato)
{
    nGraph *nuevo = new nGraph;
    nuevo->dato = dato;
    nuevo->next = NULL;
    return nuevo;
}

Grafo* crearGrafo(int size, string names[])
{
 Grafo *grafo = new Grafo;
 grafo->nGraphs = size;
 grafo->nombres = names;
 grafo->enlaces    = new adjacentList[size];
 
 for(int i=0; i<size; i++){
     grafo->enlaces[i].head = NULL;
 }
 return grafo;
}

void recorrerGrafo(Grafo* grafo)
{
    for(int i=0; i<grafo->nGraphs; i++)
	{
        nGraph* head = grafo->enlaces[i].head;
        cout << "Lista de Adyacencia de " << grafo->nombres[i] << ":";
        while(head!=NULL)
		{
            cout << grafo->nombres[head->dato] << " ->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }
    
}

void crearLineas(Grafo *grafo, int cola, int cabeza)
{
    nGraph *aux = leNode(cabeza);
    
    aux->next = grafo->enlaces[cola].head;
    grafo->enlaces[cola].head = aux;
}



//RESPUESTA 2
int Graph()
{
    int n,n1,n2;
    string nombre;
    cout << "Ingrese el numero de ciudades" << "\n";
    
    cin >> n;
    string nombres[n];
    for(int i = 0; i < n; i++)
    {  
        nombre = "";
        cin.ignore();
        getline(cin, nombre);
        nombres[i] = nombre;
    }
    Grafo *grafito = crearGrafo(n,nombres);
    for(int i = 0; i < n; i++) 
    {
        cout << nombres[i] << "    " << i << "\n";
    }
    while(1)
    {
        cout << "\nIngrese numero del par de nGraphs a conectar\n";
        cout << "Ingrese dos numeros iguales para salir\n";
        cin >>n1 >>n2;
        if (n1 == n2)
        {
            break;
        }
        else
        {
            crearLineas(grafito,n1,n2);
        }
    }
    
    recorrerGrafo(grafito);
}

int main()
{
    linkedList skere;
    int choice = 0;
    do
    {
        cout << "\nBienvenida al certamen!\n" << endl;
        cout << "1- Ordenamiento" << endl;
        cout << "2- Grafos" << endl;
        cout << "\n(-1) para salir." << endl;
        cout << "R: ";  cin >> choice;
        if (choice == 1)
        {
            ordenamiento(skere);
        }
        else if (choice == 2)
        {
            Graph();
        }

        else if(choice != -1)
        {
            cout << "Ingrese una opción válida";
        }
        
    } while(choice != -1);
}