/*
Eres el orgulloso due�o de la empresa �Cementos de Zuelandia S.A�. Empresa
dedicada a la fabricaci�n y distribuci�n de cemento, sita en la capital de Zuelandia. Para
la distribuci�n del cemento entre tus diferentes clientes (ciudades de Zuelandia)
dispones de una flota de camiones y de una plantilla de conductores zuelandeses.
El problema a resolver tiene que ver con el car�cter del zueland�s. El zueland�s es
una persona que se toma demasiadas �libertades� en su trabajo, de hecho, tienes
fundadas sospechas de que tus conductores utilizan los camiones de la empresa para
usos particulares (es decir indebidos, y a tu costa) por lo que quieres controlar los
kil�metros que recorren tus camiones.
Todos los d�as se genera el parte de trabajo, en el que se incluyen el n�mero de
cargas de cemento (1 carga = 1 cami�n lleno de cemento) que debes enviar a cada
cliente (cliente = ciudad de Zuelandia). Es innecesario indicar que no todos los d�as hay
que enviar cargas a todos los clientes, y adem�s, puedes suponer razonablemente que tu
flota de camiones es capaz de hacer el trabajo diario.
Para la resoluci�n del problema quiz� sea interesante recordar que Zuelandia es un
pa�s cuya especial orograf�a s�lo permite que las carreteras tengan un sentido de
circulaci�n.
Implementa una funci�n que dado el grafo con las distancias directas entre las
diferentes ciudades zuelandesas, el parte de trabajo diario, y la capital de Zuelandia,
devuelva la distancia total en kil�metros que deben recorrer tus camiones en el d�a, para
que puedas descubrir si es cierto o no que usan tus camiones en actividades ajenas a la
empresa
*/

template <typename tCoste> tCoste kilometros_flota_camiones(GrafoP<tCoste> Zuelandia, std::vector<int>parte,GrafoP<tCoste>::vertice capital)
{
	typename vector<typename GrafoP<tCoste>::vertice> P;
	typename vector<typename GrafoP<tCoste>::vertice> Q;
	
	vector<tCoste> kilometros_ida = dijkstra(Zuelandia,capital,P);
	vector<tCoste> kilometros_vuelta = dijkstraInv(Zuelandia,capital,Q);
	tCoste kilometros_total = 0;
	
	for(int i = 0; i < Zuelandia.numVert();i++)
	{
		kilometros_total = parte[i] * suma(kilometros_total,suma(kilometros_ida[i], kilometros_vuelta[i]);
	}
	return kilometros_total;
}
