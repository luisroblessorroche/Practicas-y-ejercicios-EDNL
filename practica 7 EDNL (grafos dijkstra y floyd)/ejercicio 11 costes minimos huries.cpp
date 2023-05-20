/*
Disponemos de tres grafos (matriz de costes) que representan los costes directos de
viajar entre las ciudades de tres de las islas del archipiélago de las Huríes (Zuelandia).
Para poder viajar de una isla a otra se dispone de una serie de puentes que conectan
ciudades de las diferentes islas a un precio francamente asequible (por decisión del
Prefecto de las Huríes, el uso de los puentes es absolutamente gratuito).
Si el alumno desea simplificar el problema, puede numerar las N1 ciudades de la isla
1, del 0 al N1-1, las N2 ciudades de la isla 2, del N1 al N1+N2-1, y las N3 de la última, del
N1+ N2 al N1+N2+ N3-1.
Disponiendo de las tres matrices de costes directos de viajar dentro de cada una de
las islas, y la lista de puentes entre ciudades de las mismas, calculad los costes mínimos
de viajar entre cualesquiera dos ciudades de estas tres islas.
¡¡¡ QUE DISFRUTÉIS EL VIAJE !!!
*/

struct puente
{
	GrafoP<tCoste>::vertice ciudad1;
	GrafoP<tCoste>::vertice ciudad2;
}

template <typename tCoste> tCoste costes_minimos_Huries(GrafoP<tCoste>& isla1, GrafoP<tCoste>& isla2, GrafoP<tCoste>& isla3, vector<puente>& puentes)
{
	int N1 = isla1.numVert();
	int N2 = N1 + isla2.numVert();
	int N3 = N2 + isla3.numVert();
	
	Matriz<tCoste> archipielago(N3);
	
	for(int i = 0; i < N1;i++)
	{
		for(int j = 0; j< N1; j++)
		{
			archipielago[i][j] = isla1[i][j];
		}
	}
	
	for(int i = N1; i < N2;i++)
	{
		for(int j = N1; j< N2; j++)
		{
			archipielago[i][j] = isla2[i-N1][j-N1];
		}
	}
	
	for(int i = N2; i < N3; i++)
	{
		for(int j = N2; j < N3; j++)
		{
			archipielago[i][j] = isla3[i-N2][j-N2];
		}
	}
	
	for(int i = 0; i < puentes.size();i++)
	{
		archipielago[puentes.ciudad1][puentes.ciudad2] = 0;
		archipielago[puentes.ciudad2][puentes.ciudad1] = 0;
	}
	
	typename matriz<GrafoP<tCoste>::vertice> P;
	archipielago = Floyd(archipielago,P);
	
	return archipielago;
	
}
