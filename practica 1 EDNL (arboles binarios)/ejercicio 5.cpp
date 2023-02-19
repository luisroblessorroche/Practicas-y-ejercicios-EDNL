//ejercicio 5

/*
 Repite el ejercicio anterior para la representación enlazada de árboles binarios (punteros al
padre, hijo izquierdo e hijo derecho).
*/

template <typename T> inline int Abin<T>::profundidad_enlazada(nodo n) const
{
	assert(n != NODO_NULO);
	int p = -1;
  	while(n != NODO_NULO)
  	{
		n = n->padre;
		p++;
  	}
	return p;
}


template <typename T> inline int Abin<T>::altura_enlazada(nodo n) const
{
	if(n == NODO_NULO)
  	{
		return -1;
  	}
  	else
  	{
		return 1 + std::max(altura_enlazada(n->hizq),altura_enlazada(n->hder));
  	}
}
