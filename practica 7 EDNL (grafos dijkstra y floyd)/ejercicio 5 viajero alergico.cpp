/*
Se dispone de tres grafos que representan la matriz de costes para viajes en un
determinado país pero por diferentes medios de transporte, por supuesto todos los grafos
tendrán el mismo número de nodos. El primer grafo representa los costes de ir por
carretera, el segundo en tren y el tercero en avión. Dado un viajero que dispone de una
determinada cantidad de dinero, que es alérgico a uno de los tres medios de transporte, y
que sale de una ciudad determinada, implementar un subprograma que determine las
ciudades a las que podría llegar nuestro infatigable viajero
*/


template <typename tCoste> std::vector<bool> viajero_alergico(tCoste dinero, String alergia,
typename GrafoP<tCoste>::vertice origen, const GrafoP<tCoste>& carretera, const GrafoP<tCoste>& tren, const GrafoP<tCoste>& avion)
{
	switch(alergia)
	{
		case "carretera":
			return calcular_costes_viaje(dinero,origen,tren,avion);
			break;
		case "tren":
			return calcular_costes_viaje(dinero,origen,carretera,avion);
			break;
		case "avion":
			return calcular_costes_viaje(dinero,origen,carretera,tren);
			break;
		default:
			std::throw_invalid("no existe dicha alergia en este problema");
	}
}

template <typename tCoste> std::vector<bool> calcular_costes_viaje(tCoste dinero, typename GrafoP<tCoste>::vertice origen,
const GrafoP<tCoste>& grafo1, const GrafoP<tCoste>& grafo2)
{
	GrafoP<tCoste> grafo3(grafo1.numVert());
	
	for(int i = 0; i < grafo3.numVert();i++)
	{
		for(int j = 0; j < grafo3.numVert();j++)
		{
			if(grafo1[i][j] < grafo2[i][j])
			{
				grafo3[i][j] = grafo1[i][j];
			}
			else
			{
				grafo3[i][j] = grafo2[i][j];
			}
		}
	}
	
	vector<tCoste> v = Dijkstra(grafo3,origen,P);
	
	std::vector<bool> posibles_viajes(grafo3.numVert());
	
	for(int i = 0; i < v.size();i++)
	{
		if(v[i] <= dinero)
		{
			posibles_viajes[i] = true;
		}
		else
		{
			posibles_viajes[i] = false;
		}
	}
	
	return posibles_viajes;
	
}
