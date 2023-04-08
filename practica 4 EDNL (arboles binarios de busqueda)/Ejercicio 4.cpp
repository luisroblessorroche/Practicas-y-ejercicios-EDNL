//Ejercicio 4

/*
Dados dos conjuntos representados mediante árboles binarios de búsqueda,
implementa la operación intersección de dos conjuntos, que devuelva como resultado
otro conjunto que sea la intersección de ambos. El resultado debe quedar en un árbol
equilibrado.
*/

template <typename T> Abb<T> interseccion_abb(Abb<T> &A, Abb<T> &B)
{
	typename Abb<T> Abb_intereseccion;
	interseccion_abb_rec(Abb_interseccion,A,B);
	std::vector<T> vec;
	rellenar_vec(vec,Abb_interseccion);
	vaciar_abb(Abb_interseccion);
	equilibrar_abb(vec,0,vec.size()-1,Abb_interseccion);
	return Abb_interseccion;
}

template <typename T> void interseccion_abb_rec(Abb<T> &Interseccion, Abb<T> &A, Abb<T> &B)
{
	if(!A.vacio())
	{
		typename Abb<T> Abb_buscar = B.buscar(A.elemento());
		if(!Abb_buscar.vacio())
		{
			Interseccion.insertar(Abb_buscar.elemento());
		}
		
		interseccion_abb_rec(interseccion,A.izqdo(),B);
		interseccion_abb_rec(interseccion,A.drcho(),B);
	}
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

template <typename T> void equilibrar_abb(std::vector<T> vec,int ini, int fin, Abb<T> &A)
{
	if(ini < fin)
	{
		int centro = (fin + ini)/2;
		A.insertar(vec.at(centro));
		equilibrar_abb(vec,ini,centro-1,A);
		equilibrar_abb(vec,centro+1,fin,A);	
	} 
}
