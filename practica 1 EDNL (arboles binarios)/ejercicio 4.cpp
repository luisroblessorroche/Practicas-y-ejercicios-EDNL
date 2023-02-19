//ejercicio 4

/*
A�ade dos nuevas operaciones al TAD �rbol binario, una que calcule la profundidad de un
nodo y otra que calcule la altura de un nodo en un �rbol dado. Implementa esta operaci�n para
la representaci�n vectorial (�ndices del padre, hijo izquierdo e hijo derecho). 
*/

template <typename T> inline int Abin<T>::profundad_vectorial(nodo n) const
{
	assert(n >= 0 && n < numNodos);
	int p = 0;
	while(nodos[n].padre != NODO_NULO)
	{
		p++;
		n = nodos[n].padre;
	}
	return p;
}

template <typename T> inline int Abin<T>::altura_vectorial(nodo n) const
{
	if(nodos[n].elto == NODO_NULO)
  	{
    	return -1;
  	}
  	else
  	{
    	return 1 + std::max(altura_vectorial(nodos[n].hizq),altura_vectorial(nodos[n].hder));
  	}
}
