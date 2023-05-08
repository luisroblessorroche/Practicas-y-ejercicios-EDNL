/*
Definiremos el pseudocentro de un grafo conexo como el nodo del mismo que
minimiza la suma de las distancias m�nimas a sus dos nodos m�s alejados. Definiremos
el di�metro del grafo como la suma de las distancias m�nimas a los dos nodos m�s
alejados del pseudocentro del grafo.
 Dado un grafo conexo representado mediante matriz de costes, implementa un
subprograma que devuelva la longitud de su di�metro.
*/

template <typename tcoste> grafo<tCoste>::vertice pseudocentro(GrafoP<tCoste>& G)
{
	floyd(G);//esto es provisional ya que no me han explicado floyd todavia
	grafo<tCoste>::vertice pseudocentro = 0;
	tCoste pseudocentro_dist = GrafoP<tCoste>::INFINITO -1;
	for(int i = 0; i < G.numvert(); i++)
	{
		grafo<tCoste>::vertice max1 = 0;
		grafo<tCoste>::vertice max2 = 0;
		for(int j = 0; j < G.numvert();j++)
		{
			if(G[i][j] > G[i][max1])
			{
				max1 = j;
			}
		}
		
		for(int k = 0; k < G.numvert(); k++)
		{
			if(G[i][k] > G[i][max2] && k != max1)
			{
				max2 = k;
			}
		}
		
		if(suma(j,k) < pseudocentro_dist)
		{
			pseudocentro_dist = suma(j,k);
			pseudocentro = i;
		} 
	}
	
	return pseudocentro;
}
