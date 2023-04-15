//Ejercicio 5

/*
Implementa el operador ? para conjuntos definido como A ? B = (A ? B) - (A ? B).
La implementación del operador ? debe realizarse utilizando obligatoriamente la
operación ?, que nos indica si un elemento dado pertenece o no a un conjunto. La
representación del tipo Conjunto debe ser tal que la operación de pertenencia esté en el
caso promedio en O(log n).
*/

template <typename T> Abb<T> union_menos_interseccion(Abb<T> &A, Abb<T> &B)
{
	typename Abb<T> Abb_union = A;
	union_abb_rec(Abb_union,B);
	std::vector<T> vec;
	rellenar_vector(vec,Abb_union);
	vaciar_abb(Abb_union);
	equilibrar_abb(vec,0,vec.size()-1,Abb_union);
	
	typename Abb<T> Abb_interseccion;
	interseccion_abb_rec(Abb_interseccion,A,B);
	vaciar_vec(vec);
	rellenar_vec(vec,Abb_interseccion);
	vaciar_abb(Abb_interseccion);
	equilibrar_abb(vec,0,vec.size()-1,Abb_interseccion);
	
	typename Abb<T> Abb_resta;
	resta(Abb_resta,Abb_union,Abb_interseccion);
	vaciar_vec(vec);
	rellenar_vec(vec,Abb_resta);
	vaciar_abb(Abb_resta);
	equilibrar_abb(vec,0,vec.size()-1,Abb_resta);
	
	return Abb_union_menos_interseccion;
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

template <typename T> void resta(Abb<T> &Abb_resta, Abb<T> &A, Abb<T> &B)
{
	if(!A.vacio())
	{
		typename Abb<T> Abb_buscar = B.buscar(A.elemento());
		if(Abb_buscar.vacio())
		{
			Abb_resta.insertar(A.elemento());
		}
		
		resta(Abb_resta,A.izqdo(),B);
		resta(Abb_resta,A.drcho(),B);
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

template <typename T> void vaciar_vec(std::vector<T> &vec)
{
	while(vec.begin() != vec.end())
	{
		vec.pop_back();
	}
}
