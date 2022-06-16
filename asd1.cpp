//========CODIGO DE LA PREGUNTA=======
void agregar_hash(nodo* tabla_hash[], empleado nuevo){
	int pos = funcion_hash(nuevo.id);
	agregar_lista(&tabla_hash[nuevo.id],nuevo); //Aqui esta el error
}

void agregar_lista(nodo **head, empleado nuevo){
	nodo* nuevo_nodo;
	nuevo_nodo = new nodo;
	
	nuevo_nodo->emp = nuevo;
	nuevo_nodo->next = *head;

	*head = nuevo_nodo;
}/*
=======PRIMERA PREGUNTA========
a) ¿Que está causando la falla?
R// La falla es causada porque se da uso a la "funcion_hash" pero no se usa la variable al momento de agregar la posición a la lista, en lugar de añadir los ultimos dos dígitos del id,
agrega el id completo.
b) ¿Cómo se puede reparar el bug?
R// La forma de arreglarlo es fácil, sólo habría que cambiar en la linea 3(4 en este caso), el contenido de los corchetes "agregar_lista(&tabla_hash[nuevo.id],nuevo);" se debería
cambiar por "agregar_lista(&tabla_hash[pos],nuevo);" y debería funcionar correctamente ya que se usa la variable que tiene la funcion aplicada para solo insertar los últimos dos
dígitos del id. */
