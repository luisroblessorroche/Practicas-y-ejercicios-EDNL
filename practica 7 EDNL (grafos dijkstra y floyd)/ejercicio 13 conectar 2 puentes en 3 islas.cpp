/*
El archipiélago de las Huríes acaba de ser devastado por un maremoto de
dimensiones desconocidas hasta la fecha. La primera consecuencia ha sido que todos y
cada uno de los puentes que unían las diferentes ciudades de las tres islas han sido
destruidos. En misión de urgencia las Naciones Unidas han decidido construir el
mínimo número de puentes que permitan unir las tres islas. Asumiendo que el coste de
construcción de los puentes implicados los pagará la ONU, por lo que se considera
irrelevante, nuestro problema es decidir qué puentes deben construirse. Las tres islas de
las Huríes tienen respectivamente N1, N2 y N3 ciudades, de las cuales C1, C2 y C3 son
costeras (obviamente C1 = N1 , C2 = N2 y C3 = N3) . Nuestro problema es elegir los
puentes a construir entre todos los posibles. Por tanto, escogeremos aquellos puentes
que minimicen el coste global de viajar entre todas las ciudades de las tres islas,
teniendo en cuenta las siguientes premisas:
1. Se asume que el coste viajar entre las ciudades que unan los puentes es 0.
2. La ONU subvencionará únicamente el número mínimo de puentes necesario
para comunicar las tres islas.
3. Para poder plantearse las mejoras en el transporte que implica la construcción de
un puente frente a cualquier otro, se asume que se realizarán exactamente el
mismo número de viajes entre cualesquiera ciudades del archipélago. Dicho de
otra forma, todos los posibles trayectos a realizar dentro del archipiélago son
igual de importantes.
Dadas las matrices de costes directos de las tres islas y las listas de ciudades costeras
del archipiélago, implementad un subprograma que calcule los puentes a construir en las
condiciones anteriormente descritas.
*/

struct puentes
{
	GrafoP<tCoste>::vertice puente1_x;
	GrafoP<tCoste>::vertice puente1_y;
	GrafoP<tCoste>::vertice puente2_x;
	GrafoP<tCoste>::vertice puente2_y;
}

template <typename tCoste> puentes conectar_tres_islas(GrafoP<tCoste>& isla1, GrafoP<tCoste>& isla2, Grafo<tCoste>& isla3,
vector<Grafo<tCoste>::vertice>& costeras1, vector<Grafo<tCoste>::vertice>& costeras2, vector<Grafo<tCoste>::vertice>& costeras3)
{
	typename matriz<GrafoP<tCoste>::vertice> P1;
	typename matriz<GrafoP<tCoste>::vertice> P2;
	typename matriz<GrafoP<tCoste>::vertice> P3;
	
	matriz<tCoste> floyd_isla1 = Floyd(isla1,P1);
	matriz<tCoste> floyd_isla2 = Floyd(isla2,P2);
	matriz<tCoste> floyd_isla3 = Floyd(isla3,P3);
	
	Grafo<tCoste>::vertice mejor_vertice_isla1 = -1;
	Grafo<tCoste>::vertice mejor_vertice_isla3 = -1;
	Grafo<tCoste>::vertice mejor_vertice_isla3 = -1;
	
	tCoste mejor_coste_isla1 = Grafo<T>::INFINITO;
	tCoste mejor_coste_isla2 = Grafo<T>::INFINITO;
	tCoste mejor_coste_isla3 = Grafo<T>::INFINITO;
	
	
	for(int i = 0; i < costeras1.size();i++)
	{
		tCoste sum_ida_vuelta = 0;
		for(int j = 0; i < isla1.numVert();j++)
		{
			sum_ida_vuelta = suma(sum_ida_vuelta,suma(floyd_isla1[costeras1[i]][j],floyd_isla1[j][costeras1[i]]));
		}
		if(sum_ida_vuelta < mejor_coste_isla1)
		{
			mejor_coste_isla1 = sum_ida_vuelta;
			mejor_vertice_isla1 = costeras1[i];
		}
	}
	
	for(int i = 0; i < costeras2.size();i++)
	{
		tCoste sum_ida_vuelta = 0;
		for(int j = 0; i < isla2.numVert();j++)
		{
			sum_ida_vuelta = suma(sum_ida_vuelta,suma(floyd_isla2[costeras2[i]][j],floyd_isla2[j][costeras2[i]]));
		}
		if(sum_ida_vuelta < mejor_coste_isla2)
		{
			mejor_coste_isla2 = sum_ida_vuelta;
			mejor_vertice_isla2 = costeras2[i];
		}
	}
	
	for(int i = 0; i < costeras3.size();i++)
	{
		tCoste sum_ida_vuelta = 0;
		for(int j = 0; i < isla3.numVert();j++)
		{
			sum_ida_vuelta = suma(sum_ida_vuelta,suma(floyd_isla3[costeras3[i]][j],floyd_isla3[j][costeras3[i]]));
		}
		if(sum_ida_vuelta < mejor_coste_isla3)
		{
			mejor_coste_isla3 = sum_ida_vuelta;
			mejor_vertice_isla3 = costeras3[i];
		}
	}
	
	puentes conexion_puentes;
	
	if(mejor_coste_isla1 <= mejor_coste_isla2 && mejor_coste_isla1 <= mejor_coste_isla3)
	{
		conexion_puentes.puente1_x = mejor_vertice_isla1;
		conexion_puentes.puente1_y = mejor_vertice_isla2;
		conexion_puentes.puente2_x = mejor_vertice_isla1;
		conexion_puentes.puente2_y = mejor_vertice_isla3;
	}
	else
	{
		if(mejor_coste_isla2 <= mejor_coste_isla1 && mejor_coste_isla2 <= mejor_coste_isla3)
		{
			conexion_puentes.puente1_x = mejor_vertice_isla2;
			conexion_puentes.puente1_y = mejor_vertice_isla1;
			conexion_puentes.puente2_x = mejor_vertice_isla2;
			conexion_puentes.puente2_y = mejor_vertice_isla3;
		}
		else
		{
			conexion_puentes.puente1_x = mejor_vertice_isla3;
			conexion_puentes.puente1_y = mejor_vertice_isla1;
			conexion_puentes.puente2_x = mejor_vertice_isla3;
			conexion_puentes.puente2_y = mejor_vertice_isla2;
		}
	}
	
	return conexion_puentes;
}
