//EJERCICIO comprobar si un arbol binario es completo

template <typename T> bool abin_completo(const Abin<T>& A)
{
	int altura_abin = calcular_altura(A.raiz(),A);
	std::vector<Abin<T>::nodo> v;
	int num_nodos_penultimo_nivel = 0;
	rellenar_vector_y_contar_nodos(A.raiz(),A,altura_abin-1,v,num_nodos_penultimo_nivel);
	if(num_nodos_penultimo_nivel == pow(2,altura_abin -1))
	{
		return comprobar_vector(v,A);
	}
	else
	{
		return false;
	}
}


template <typename T> int calcular_altura(typename Abin<T>::nodo n, const Abin<T>)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + std::max(calcular_altura(A.hijoIzqdo(n),A),calcular_altura(A.hijoDrcho(n),A));
	}
}

template <typename T> void rellenar_vector_y_contar_nodos(typename Abin<T>::nodo n, const Abin<T>& A, int alt_p_n,std::vector<Abin<T>::nodo>& v, int& num_nodos)
{
	if(n != Abin<T>::NODO_NULO)
	{
		if(profundidad_nodo(n,A) == alt_p_n)
		{
			num_nodos++;
			v.push_back(A.hijoIzqdo(n));
			v.push_back(A.hijoDrcho(n));
			
			rellenar_vector_y_contar_nodos(A.hijoIzqdo(n),A,alt_p_n,v,num_nodos);
			rellenar_vector_y_contar_nodos(A.hijoDrcho(n),A,alt_p_n,v,num_nodos);
		}
		else
		{
			rellenar_vector_y_contar_nodos(A.hijoIzqdo(n),A,alt_p_n,v,num_nodos);
			rellenar_vector_y_contar_nodos(A.hijoDrcho(n),A,alt_p_n,v,num_nodos);
		}
	}

}

template <typename T> int profundidad_nodo(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + profundidad_nodo(A.padre(n),A);
	}
}

template <typename T> bool comprobar_vector(std::vector<Abin<T>::nodo>& v, const Abin<T>& A)
{
	bool completo = true;
	bool primer_nodo_encontrado = false;
	std::vector<Abin<T>::nodo>::iterator i = v.end();
	while(i != v.begin())
	{
		if(A.elemento(v.at(i)) != Abin<T>::NODO_NULO && primer_nodo_encontrado == false)
		{
			primer_nodo_encontrado = true;
		}
		
		if(A.elemento(v.at(i)) == Abin<T>::NODO_NULO)
		{
			return completo = false;
		}
		i--;
	}
	return completo;
}


