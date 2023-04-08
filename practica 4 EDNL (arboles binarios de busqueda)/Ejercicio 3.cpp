//Ejercicio 3

/*
Dados dos conjuntos representados mediante árboles binarios de búsqueda,
implementa la operación unión de dos conjuntos que devuelva como resultado otro
conjunto que sea la unión de ambos, representado por un ABB equilibrado.
*/


template <typename T> Abb<T> union_abb(Abb<T> &A, Abb<T> &B)
{
	typename Abb<T> Abb_union = A;
	union_abb_rec(Abb_union,B);
	std::vector<T> vec;
	rellenar_vector(vec,Abb_union);
	vaciar_abb(Abb_union);
	equilibrar_abb(vec,0,vec.size()-1,Abb_union);
	return Abb_union;
}


template <typename T> void union_abb_rec(Abb<T> &A, Abb<T> &B)
{
	if(!B.vacio())
	{
		A.insertar(B.elemento());
		union_abb_rec(A,B.izqdo());
		union_abb_rec(A,B.drcho());
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


