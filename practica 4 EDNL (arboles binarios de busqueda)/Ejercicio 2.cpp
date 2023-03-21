//Ejercicio 2

/*
Un árbol binario de búsqueda se puede equilibrar realizando el recorrido en inorden
del árbol para obtener el listado ordenado de sus elementos y a continuación, repartir
equitativamente los elementos a izquierda y derecha colocando la mediana en la raíz y
construyendo recursivamente los subárboles izquierdo y derecho de cada nodo.
Implementa este algoritmo para equilibrar un ABB.
*/

template <typename T> Abb<T> equilibrar_abb(Abb<T> &A)
{
	std::vector<T> vec;
	rellenar_vector(vec,A);
	vaciar_abb(A);
	montar_abb_equilibrado(vec,0,vec.size()-1,A);
	return A;
}

template <typename T> void rellenar_vector(std::vector<T> &vec, Abb<T> &A)
{
	if(!A.vacio())
	{
		rellenar_vector(vec,A.izqdo());
		vec.push_back(A.elemento());
		rellenar_vector(vec,A.drcho());
	}
}

template <typename T> void vaciar_abb(Abb<T> &A)
{
	while(!A.vacio())
	{
		A.eliminar(A.elemento());
	}
}

template <typename T> void montar_abb_equilibrado(std::vector<T> &vec, int ini, int fin, Abb<T> &A)
{
	if(ini < fin)
	{
		int medio = (fin+ini)/2;
		A.insertar(vec.at(medio));
		montar_abb_equilibrado(vec,ini,medio-1,A);
		montar_abb_equilibrado(vec,medio+1,fin,A);
	}	
}


