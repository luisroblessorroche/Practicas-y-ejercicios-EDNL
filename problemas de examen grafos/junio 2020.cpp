/*
Un repartidor de una empresa de distribución de bebidas tiene que visitar a todos sus
clientes cada día. Pero, al comenzar su jornada de trabajo, no conoce qué cantidad de bebidas
tiene que servir a cada cliente, por lo que no puede planificar una ruta óptima para visitarlos a
todos. Por tanto, nuestro repartidor decide llevar a cabo la siguiente estrategia:

	-	El camión parte del almacén con la máxima carga permitida rumbo a su cliente más
		próximo.
		
	-	El repartidor descarga las cajas de bebidas que le pide el cliente. Si no tiene suficientes
		cajas en el camión, le entrega todas las que tiene. Este cliente terminará de ser servido en
		algún otro momento a lo largo del día, cuando la estrategia de reparto vuelva a llevar al
		repartidor hasta él.
		
	-	Después de servir a un cliente:
	
		-	Si quedan bebidas en el camión, el repartidor consulta su sistema de navegación
			basado en GPS para conocer la ruta que le lleva hasta su cliente más próximo
			pendiente de ser servido.
			
		-	Si no quedan bebidas en el camión, vuelve al almacén por el camino más corto y
			otra vez carga el camión completamente.
			
	-	Después de cargar el camión, el repartidor consulta su sistema de navegación y se va por
		el camino más corto a visitar al cliente pendiente de ser servido más próximo.
		
Implementa un subprograma que calcule y devuelva la distancia total recorrida en un
día por nuestro repartidor, a partir de lo siguiente:

1. Grafo representado mediante matriz de costes con las distancias de los caminos directos
entre los clientes y entre ellos y la central.
2. Capacidad máxima del camión (cantidad de cajas de bebidas).
3. Asumiremos que existe una función int Pedido() que devuelve el número de cajas que
quedan por servir al cliente en el que se encuentra el repartidor.
*/


template <typename tCoste> tCoste repartir_bebidas(GrafoP<tCoste>& costes_directos_clientes, int capacidad, GrafoP<tCoste>::vertice central)
{
	matriz<GrafoP<tCoste>::vertice> P;
	matriz<tCoste> floyd_distribuir_bebidas = Floyd(costes_directos_clientes,P);
	
	vector<bool> ciudad_visitada(costes_directos_clientes.numVert());
	
	for(int i = 0; i < ciudad_vistada.size();i++)
	{
		ciudad_visitada[i] = false;
	}
	
	ciudad_visitada[central] = true;
	
	int c = capacidad;
	Grafo<tCoste>::vertice actual = central;
	tCoste coste_total = 0;
	
	while(num_ciudades_visitadas(ciudades_visitadas) == ciudades_visitadas.size())
	{
		Grafo<tCoste>::vertice min = buscar_min(actual,floyd_distribuir_bebidas,ciudad_visitada);
		coste_total = coste_total + floyd_distribuir_bebidas[actual][min];
		
		int ped = pedido();
		if(ped < c)
		{
			llenar_almacen(); //? de alguna forma tendra que variar algo para que pedido no de siempre lo mismo, o deposital la mercancia
			c = c - ped;
			ciudad_visitada[min] = true;
			actual = min;
		}
		else
		{
			
			llenar_almacen(); //? de alguna forma tendra que variar algo para que pedido no de siempre lo mismo, o deposital la mercancia
			c = 0;
			coste_total = coste_total + floyd_distribuir_bebidas[min][central];
			c = capacidad;
			actual = central;
		}
	}
	return coste_total;
	
}

int num_ciudades_visitadas(vector<bool>v)
{
	int cont = 0;
	for(int i = 0; i < v.size();i++)
	{
		if(v[i] == true)
		{
			cont++;
		}
	}
	return cont;
}

GrafoP<tCoste>::vertice buscar_min(GrafoP<tCoste>::vertice i, matriz<tCoste> m, vector<bool>v)
{
	int N = v.size();
	tCoste coste_min = m[i][0];
	GrafoP<tCoste>::vertice vertice_min = 0;
	
	for(int j = 0; j < N;j++)
	{
		if(m[i][j] < coste_min && v[j] == false)
		{
			coste_min = m[i][j];
			vertice_min = j;
		}
	}
	return vertice_min;
}
