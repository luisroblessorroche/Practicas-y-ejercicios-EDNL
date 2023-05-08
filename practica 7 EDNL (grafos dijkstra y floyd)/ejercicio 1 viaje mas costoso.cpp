/*
Tu agencia de viajes “OTRAVEZUNGRAFO S.A.” se enfrenta a un curioso cliente.
Es un personaje sorprendente, no le importa el dinero y quiere hacer el viaje más caro
posible entre las ciudades que ofertas. Su objetivo es gastarse la mayor cantidad de
dinero posible (ojalá todos los clientes fueran así), no le importa el origen ni el destino
del viaje.
Sabiendo que es imposible pasar dos veces por la misma ciudad, ya que casualmente
el grafo de tu agencia de viajes resultó ser acíclico, devolver el coste, origen y destino
de tan curioso viaje. Se parte de la matriz de costes directos entre las ciudades del grafo. 
*/

struct viaje
{
	grafo<tCoste>::vertice origen;
	grafo<tCoste>::vertice destino;
	tCoste dist_max;
};

template <typename tCoste>matriz<tCoste> Floyd(const GrafoP<tCoste>& G,
matriz<typename GrafoP<tCoste>::vertice>& P)
{
	typedef typename GrafoP<tCoste>::vertice vertice;
	const size_t n = G.numVert();
	matriz<tCoste> A(n);
	P = matriz<vertice>(n);
	
	for (vertice i = 0; i <= n-1; i++)
	{
		A[i] = G[i];
		A[i][i] = 0;
		P[i] = vector<vertice>(n, i);
	}
	for (vertice k = 0; k <= n-1; k++)
		for (vertice i = 0; i <= n-1; i++)
			for (vertice j = 0; j <= n-1; j++)
			{
				tCoste ikj = suma(A[i][k], A[k][j]);
				if (ikj > A[i][j])
				{
					A[i][j] = ikj;
					P[i][j] = k;
				}
			}
	return A;
}




template <typename tCoste> viaje viaje_mas_costoso(grafo<tCoste>& G)
{
	typename matriz<tCoste> A = Floyd(G);
	
	viaje v;
	v.origen = 0;
	v.destino = 0;
	v.dist_max = A[0][0];
	
	for(int i = 0; i < G.numvert(),i++)
	{
		for(int j = 0; j < G.numvert(),j++)
		{
			if(A[i][j] > v.dist_max)
			{
				v.origen = i;
				v.destino = j;
				v.dist_max = A[i][j];
			}
		}
	}
	return v;
}
