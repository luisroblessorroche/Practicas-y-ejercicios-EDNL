//EJERCICIO cuadrante blanco y negro

/*
Una forma de representar una figura plana en blanco y negro consiste en utilizar un
árbol cuaternario en el que cada nodo o tiene exactamente cuatro hijos, o bien es una
hoja. Un nodo hoja puede ser blanco o negro y un nodo interno no tiene color.
Una figura dibujada dentro de un cuadrado de lado 2k se representa de la forma siguiente: 

Se divide el cuadrado en cuatro cuadrantes y cada uno se representa como un
hijo del nodo raíz. Si un cuadrante está completamente negro corresponde a una hoja
negra; si, por el contrario, el cuadrante está completamente blanco, éste corresponde a
una hoja blanca; y si un cuadrante está parcialmente ocupado por negro y blanco,
entonces corresponde a un nodo interno del árbol y este cuadrante se representa
siguiendo el mismo método subdividiéndolo en otros cuatro cuadrantes. Como ejemplo
se muestra una figura en blanco y negro y su árbol asociado, tomando los cuadrantes en
el sentido de las agujas del reloj a partir del cuadrante superior izquierdo.

Implementa una función que dado un árbol de esta clase, con k+1 niveles,
devuelva la figura asociada, representada como una matriz cuadrada de tamaño 2k en la
que cada celda representa un punto blanco o negro.
*/


char** rellenar_matriz(const Agen<char>& A)
{
	if(A.vacio() || agen_cuaternario(A.raiz(),A))
	{
		throw std::invalid_argument("el arbol es invalido para representar una figura");
	}
	else
	{
		int k = altura_agen(A.raiz(),A);
		char** matriz = new char*[pow(2,k)];
		for(int i = 0; i < pow(2,k); i++)
		{
			matriz[i] = new char[pow(2,k)];
		}
		rellenar_matriz_rec(A.raiz(),A,matriz);
		return matriz;
	}
}

bool agen_cuaternario(Agen<char>::nodo n, const Agen<char>& A)
{
	if(n == Agen<char>::NODO_NULO)
	{
		return true;
	}
	else
	{
		bool cuaternario = cuaternario(n,A);
		Agen<char>::nodo hijo = A.hijoIzqdo(n);
		while(hijo != Agen<char>::NODO_NULO)
		{
			cuaternario = cuaternario && agen_cuaternario(hijo,A);
			hijo = A.hermDrcho(hijo);
		}
		return cuaternario;
	}
}

bool cuaternario(Agen<char>::nodo n, const Agen<char>& A)
{
	Agen<char>::nodo hijo = A.hijoIzqdo(n);
	int cont_hijos = 0;
	while(hijo != Agen<char>::NODO_NULO)
	{
		cont_hijos++;
		hijo = A.hermDrcho(hijo);
	}
	return (cont_hijos == 0 || cont_hijos == 4);
}


int altura_agen(Agen<char>::nodo n, const Agen<char>& A)
{
	if(n == Agen<char>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		int altura = -1;
		Agen<char>::nodo hijo = A.hijoIzqdo(n);
		while(hijo != Agen<char>::NODO_NULO)
		{
			altura = std::max(altura,altura_agen(hijo,A));
			hijo = A.hermDrcho(hijo);
		}
		return altura +1;
	}
}


void rellenar_matriz_rec(Agen<char>::nodo n, const Agen<char>&A, char** matriz)
{
	char opcion = A.elemento(n);
	
	switch(op)
	{
		case 'B':
			
			
			break;
		case 'N':
			
			break;
		case ' ':
			Agen<char>::nodo hijo = A.hijoIzqdo(n);
			while(hijo != Agen<char>::NODO_NULO)
			{
				rellenar_matriz_rec(hijo,A,matriz);
				hijo = A.hermDrcho(hijo);
			}
			
			break;
		defualt:
			throw std::invalid_argument("el arbol no contiene los elementos correctamente");		
	}
}



