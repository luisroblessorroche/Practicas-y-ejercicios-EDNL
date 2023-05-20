/*
Se dispone de dos grafos que representan la matriz de costes para viajes en un
determinado país, pero por diferentes medios de transporte (tren y autobús, por
ejemplo). Por supuesto ambos grafos tendrán el mismo número de nodos, N. Dados
ambos grafos, una ciudad de origen, una ciudad de destino y el coste del taxi para
cambiar de una estación a otra dentro de cualquier ciudad (se supone constante e igual
para todas las ciudades), implementa un subprograma que calcule el camino y el coste
mínimo para ir de la ciudad origen a la ciudad destino.
*/

struct coste_y_camino
{
	std::vector<GrafoP<tCoste>::vertice> camino;
	tCoste coste;
}

template <typename tCoste> coste_y_camino camino_mas_corto_con_precio_transbordo(GrafoP<tCoste>& autobus, Grafo<tCoste>&tren,
GrafoP<tCoste>::vertice origen,GrafoP<tCoste>::vertice destino, tCoste coste_taxi)
{
	int N = tren.numVert();
	matriz<tCoste> m_tren_autobus(2*N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			m_tren_autobus[i][j] = tren[i][j];
			m_tren_autobus[N+i][N+j] = autobus[i][j];
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		m_tren_autobus[i][i+N] = coste_taxi;
		m_tren_autobus[i+N][i] = coste_taxi;
	}
	
	typename vector<GrafoP<tCoste>::vertice> P;
	typename vector<GrafoP<tCoste>::vertice> Q;
	
	typename vector<tCoste> dijkstra_tren(m_tren_autobus,origen,P);
	typename vector<tCoste> dijkstra_autobus(m_tren_autobus,origen+N,Q);
	
	tCoste min_tren = std::min(dijkstra_tren[destino],dijkstra_tren[destino+N]);
	tCoste min_autobus = std::min(dijkstra_autobus[destino],dijkstra_autobus[destino+N]);
	
	coste_y_camino coste_camino;
	
	if(min_tren < min_autobus)
	{
		coste_camino.camino = P;
		coste_camino.coste = min_tren;	
	}
	else
	{
		coste_camino.camino = Q;
		coste_camino.coste = min_autobus;
	}
	
	return coste_camino;
}
