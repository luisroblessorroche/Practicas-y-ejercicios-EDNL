/*
�UN SOLO TRANSBORDO, POR FAVOR�. Este es el t�tulo que reza en tu
flamante compa��a de viajes. Tu publicidad explica, por supuesto, que ofreces viajes
combinados de TREN y/o AUTOB�S (es decir, viajes en tren, en autob�s, o usando
ambos), entre N ciudades del pa�s, que ofreces un servicio inmejorable, precios muy
competitivos, y que garantizas ante notario algo que no ofrece ninguno de tus
competidores: que en todos tus viajes COMO M�XIMO se har� un solo transbordo
(cambio de medio de transporte).
Bien, hoy es 1 de Julio y comienza la temporada de viajes.
�Qu� suerte! Acaba de aparecer un cliente en tu oficina. Te explica que quiere viajar
entre dos ciudades, Origen y Destino, y quiere saber cu�nto le costar�.
Para responder a esa pregunta dispones de dos grafos de costes directos (matriz de
costes) de viajar entre las N ciudades del pa�s, un grafo con los costes de viajar en tren y
otro en autob�s.
Implementa un subprograma que calcule la tarifa m�nima en estas condiciones.
Mucha suerte en el negocio, que la competencia es dura.
*/

template <typename tCoste> matriz<tCoste> tarifa_minima(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& autobus,typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino)
{
	typename vector<typename GrafoP<tCoste>::vertice> P;
	
	vector<tCoste> costes_tren_dijkstra = dijkstra(tren,origen,P);
	vector<tCoste> costes_autobus_dijkstra = dijkstra(autobus,origen,P);
	
	vector<tCoste> costes_tren_dijkstra_inv = dijkstraInv(tren,destino,P);
	vector<tCoste> costes_autobus_dijkstra_inv = dijkstraInv(autobus,destino,P);

	tCoste tarifa_minima = std::min(costes_tren_dijkstra[destino],costes_autobus_dijkstra[destino])
	
	for(int i = 0; i < tren.numVert();i++)
	{
		tarifa_minima = std::min(tarifa_minima,std::min(suma(costes_tren_dijkstra[i],costes_autobus_dijkstra_inv[i]),suma(costes_autobus_dijkstra[i],costes_tren_dijkstra_inv[i])));
	}
	return tarifa_minima;
}
