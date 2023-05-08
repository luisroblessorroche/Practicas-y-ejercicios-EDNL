/*
Se dispone de dos grafos (matriz de costes) que representan los costes de viajar entre
N ciudades españolas utilizando el tren (primer grafo) y el autobús (segundo grafo).
Ambos grafos representan viajes entre las mismas N ciudades.
Nuestro objetivo es hallar el camino de coste mínimo para viajar entre dos ciudades
concretas del grafo, origen y destino, en las siguientes condiciones:

	- La ciudad origen sólo dispone de transporte por tren.
	- La ciudad destino sólo dispone de transporte por autobús.
	- El sector del taxi, bastante conflictivo en nuestros problemas, sigue en huelga,
	  por lo que únicamente es posible cambiar de transporte en dos ciudades del
	  grafo, cambio1 y cambio2, donde las estaciones de tren y autobús están
	  unidas.
	  
Implementa un subprograma que calcule la ruta y el coste mínimo para viajar entre
las ciudades Origen y Destino en estas condiciones.
*/

struct ruta_coste
{
	tCoste coste;
	std::vector<typename GrafoP<tCoste>::vertice> ruta;
}


template <typename tCoste> ruta_coste(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& autobus, typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino,
typename GrafoP<tCoste>::vertice cambio1, typename GrafoP<tCoste>::vertice cambio2)
{
	typename vector<typename GrafoP<tCoste>::vertice> P;
	typename vector<typename GrafoP<tCoste>::vertice> Q;
	vector<tCoste> tren_dijkstra = dijkstra(tren,origen,P);
	vector<tCoste> autobus_dijkstraInv = dijkstraInv(autobus,destino,Q);
	
	ruta_coste rc;
	
	if(suma(tren_dijkstra[cambio1],autobus_dijkstraInv[cambio1]) < suma(tren_dijkstra[cambio2],autobus_dijkstraInv[cambio2]))
	{
		rc.coste = suma(tren_dijkstra[cambio1],autobus_dijkstraInv[cambio1]);
		
		typename GrafoP<tCoste>::vertice i = destino;
		while(i != cambio1)
		{
			ruta.push_front(i);
			i = Q[i];
		}
		ruta.push_front(i);
		
		typename GrafoP<tCoste>::vertice j = cambio1;
		while(j != origen)
		{
			ruta.push_front(j);
			j = P[j];
		}
		ruta.push_front(j);
	}
	else
	{
		rc.coste = suma(tren_dijkstra[cambio2],autobus_dijkstraInv[cambio2]);
		
		typename GrafoP<tCoste>::vertice i = destino;
		while(i != cambio2)
		{
			ruta.push_front(i);
			i = Q[i];
		}
		ruta.push_front(i);
		
		typename GrafoP<tCoste>::vertice j = cambio2;
		while(j != origen)
		{
			ruta.push_front(j);
			j = P[j];
		}
		ruta.push_front(j);
	}
	
	return rc;
}
