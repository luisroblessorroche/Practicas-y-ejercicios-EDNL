/*
El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas,
Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2
ciudades son costeras (obviamente C1 <= N1 y C2 <= N2). Se desea construir un puente
que una ambas islas. Nuestro problema es elegir el puente a construir entre todos los
posibles, sabiendo que el coste de construcción del puente se considera irrelevante. Por
tanto, escogeremos aquel puente que minimice el coste global de viajar entre todas las
ciudades de las dos islas, teniendo en cuenta las siguientes premisas:
1. Se asume que el coste viajar entre las dos ciudades que una el puente es 0.
2. Para poder plantearse las mejoras en el transporte que implica la construcción de
un puente frente a cualquier otro, se asume que se realizarán exactamente el
mismo número de viajes entre cualesquiera ciudades del archipiélago. Por
ejemplo, se considerará que el número de viajes entre la ciudad P de Fobos y la
Q de Deimos será el mismo que entre las ciudades R y S de la misma isla. Dicho
de otra forma, todos los posibles trayectos a realizar dentro del archipiélago son
igual de importantes.
Dadas las matrices de costes directos de Fobos y Deimos y las listas de ciudades
costeras de ambas islas, implementa un subprograma que calcule las dos ciudades que
unirá el puente.
*/

struct puente
{
	GrafoP<tCoste>::vertice ciudad1;
	GrafoP<tCoste>::vertice ciudad2;
}

template <typename tCoste> Grecoland(GrafoP<tCoste>& N1, GrafoP<tCoste>& N2, vector<GrafoP<tCoste>::vertice>& C1, vector<GrafoP<tCoste>::vertice>& C2)
{
	matriz<GrafoP<tCoste>::vertice> P1;
	matriz<GrafoP<tCoste>::vertice> P2;
	
	matriz<tCoste> floyd_N1 = Floyd(N1,P1);
	matriz<tCoste> floyd_N2 = Floyd(N2,P2);
	
	//inicializar minimo de c1 con un valor ilegal;
	GrafoP<tCoste>::vertice v_min_c1 = -1;	
	tCoste c_min_c1 = Grafo<tCoste>::INFINITO
	
	//inicializar minimo de c2 con un valor ilegal;
	GrafoP<tCoste>::vertice v_min_c2 = -1;
	tCoste c_min_c2 = Grafo<tCoste>::INFINITO;
	

	for(int i = 0; i < C1.size();i++)
	{
		tCoste sum_ida_vuelta = 0;
		for(int j = 0; j < N1.size();j++)
		{
			sum_ida_vuelta = suma(suma_ida_vuelta,suma(floyd_N1[C1[i]][j],floyd_N1[j][C1[i]]));
		}
		if(sum_ida_vuelta < c_min_c1)
		{
			c_min_c1 = sum_ida_vuelta;
			v_min_c1 = C1[i];
		}
	}
	
	for(int i = 0; i < C2.size();i++)
	{
		tCoste sum_ida_vuelta = 0;
		for(int j = 0; j < N2.size();j++)
		{
			sum_ida_vuelta = suma(suma_ida_vuelta,suma(floyd_N2[C2[i]][j],floyd_N2[j][C2[i]]));
		}
		if(sum_ida_vuelta < c_min_c2)
		{
			c_min_c2 = sum_ida_vuelta;
			v_min_c2 = C2[i];
		}
	}
	
	puente P;
	P.ciudad1 = v_min_c1;
	P.ciudad2 = v_min_c2;
	
	return P;
	
	
}
