/*
Se dispone de tres grafos que representan la matriz de costes para viajes en un
determinado país, pero por diferentes medios de transporte (tren, autobús y avión). Por
supuesto los tres grafos tendrán el mismo número de nodos, N.
Dados los siguientes datos:
	- los tres grafos,
	- una ciudad de origen,
	- una ciudad de destino,
	- el coste del taxi para cambiar, dentro de una ciudad, de la estación de tren a la
	  de autobús o viceversa (taxi-tren-bus) y
	- el coste del taxi desde el aeropuerto a la estación de tren o la de autobús, o
	  viceversa (taxi-aeropuerto-tren/bus)
	  
y asumiendo que ambos costes de taxi (distintos entre sí, son dos costes diferentes) son
constantes e iguales para todas las ciudades, implementa un subprograma que calcule el
camino y el coste mínimo para ir de la ciudad origen a la ciudad destino.
*/

struct camino_y_coste
{
	tCoste coste_minimo;
	vector<GrafoP<tCoste>::vertice> camino;
}

template <typename tCoste> camino_y_coste mejor_ruta_3_grafos(GrafoP<tCoste>& tren, GrafoP<tCoste>& autobus, GrafoP<tCoste>& avion,
GrafoP<tCoste>::vertice origen, GrafoP<tCoste>::vertice destino, tCoste taxi_tren_autobus, tCoste taxi_avion)
{
	
	int N = tren.numvert();
	
	matriz<tCoste> Grafo_conjunto(3*N);
	
	//rellenar la matriz con los costes minimos de inr en cada medio de transporte	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			Grafo_conjunto[i][j] = tren[i][j];
			Grafo_conjunto[i+N][j+N] = autobus[i][j];
			Grafo_conjunto[i+2*N][j+2*N] = avion[i][j];
		}
	}
	
	//rellenar la matriz con los costes de los taxis de tren_autobus y autobus_tren
	for(int i = 0; i<N;i++)
	{
		Grafo_conjunto[i][i+N] = taxi_tren_autobus;
		Grafo_conjunto[i+N][i] = taxi_tren_autobus;
		
		Grafo_conjunto[i][i+2*N] = taxi_avion;
		Grafo_conjunto[i+2*N][i] = taxi_avion;
		Grafo_conjunto[i+2*N][i+2*N] = taxi_avion;
		Grafo_conjunto[i+2*N][i+N] = taxi_avion;
		
	}
	
	
	typename vector<typename GrafoP<tCoste>::vertice> T;
	typename vector<typename GrafoP<tCoste>::vertice> AU;
	typename vector<typename GrafoP<tCoste>::vertice> AV;
	
	vector<tCoste> dijkstra_tren = dijkstra(Grafo_conjunto,origen,T);
	vector<tCoste> dijkstra_autobus = dijkstra(Grafo_conjunto,origen+N,AU);
	vector<tCoste> dijkstra_avion = dijkstra(Grafo_conjunto,origen+2*N,AV);
	
	
	
	tCoste coste_min = std::min(dijkstra_tren[destino],std::min(dijkstra_tren[destino+N],dijkstra_tren[destino+2*N]));
	typename vector<typename GrafoP<tCoste>::Vertice> camino_min = T;
	
	if(coste_min > std::min(dijkstra_autobus[destino],std::min(dijkstra_autobus[destino+N],dijkstra_autobus[destino+2*N])))
	{
		coste_min = std::min(dijkstra_autobus[destino],std::min(dijkstra_autobus[destino+N],dijkstra_autobus[destino+2*N]));
		camino_min = AU;
	}
	
	if(coste_min > std::min(dijkstra_avion[destino],std::min(dijkstra_avion[destino+N],dijkstra_avion[destino+2*N])))
	{
		coste_min = std::min(dijkstra_avion[destino],std::min(dijkstra_avion[destino+N],dijkstra_avion[destino+2*N]));
		camino_min = AV;
	}
	
	camino_y_coste camino_coste;
	
	camino_coste.coste_minimo = coste_min;
	camino_coste.camino = camino_min;
	
	return camino_coste;
	
}
