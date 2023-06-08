/*
La capital de Zuelandia está alcanzando niveles de toxicidad muy elevados, por ello se ha
decretado el cierre a la ciudad como paso de tránsito hacia otras ciudades. (Para ir de una
ciudad a otra no se podrá pasar por C.Zuelandia, pero si se podrá ir si es residente de la misma
empleándola como ciudad destino u origen).
Implemente un subprograma que dada la capital y un grafo ponderado con los km de las
carreteras existentes entre las ciudades del país, nos devuelva los caminos resultantes de
nuestra nueva política “Sin pasar por la capital, por favor”.
*/

template <typename tCoste> sin_pasar_por_la_capital(GrafoP<tCoste>::vertice capital, GrafoP<tCoste> &carreteras)
{
	matriz<GrafoP<tCoste>::vertice> caminos;
	
	GrafoP<tCoste> copia_carreteras = carreteras;
	
	int N = carreteras.numVert();
	
	for(int i = 0; i < N; i++)
	{
		copia_carreteras[capital][i] = GrafoP<tCoste>::INFINITO;
		copia_carreteras[i][capital] = GrafoP<tCoste>::INFINITO;	
	}
	
	matriz<tCoste> floyd_carreteras = floyd(copia_carreteras,caminos);
	
	vector<GrafoP<tCoste>::vertice> caminos_desde_capital;
	vector<GrafoP<tCoste>::vertice> caminos_hasta_capital;
	
	vector<tCoste> dijkstra_capital = dijkstra(carreteras,capital,caminos_desde_capital);
	vector<tCoste> dijkstra_inv_capital = dijkstraInv(carreteras,capital,caminos_hasta_capital);
	
	for(int i = 0; i < N; i++)
	{
		caminos[capital][i] = caminos_desde_capital[i];
		caminos[i][capital] = caminos_hasta_capital[i];
	}
	
	return caminos;
}
