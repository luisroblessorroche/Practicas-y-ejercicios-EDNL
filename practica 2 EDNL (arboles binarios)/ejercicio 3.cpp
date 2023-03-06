//Ejercicio 3

/*
El TAD árbol binario puede albergar expresiones matemáticas mediante un árbol de
expresión. Dentro del árbol binario los nodos hojas contendrán los operandos, y el resto
de los nodos los operadores.
a) Define el tipo de los elementos del árbol para que los nodos puedan almacenar
operadores y operandos.
b) Implementa una función que tome un árbol binario de expresión (aritmética) y
devuelva el resultado de la misma. Por simplificar el problema se puede asumir que el
árbol representa una expresión correcta. Los operadores binarios posibles en la expresión
aritmética serán suma, resta, multiplicación y división.

Nota: En el programa de prueba podemos usar las funciones rellenarAbin() de abin_ES.h para introducir por teclado o desde un fichero el árbol de expresión a evaluar. Sin
embargo, en este caso, será necesario sobrecargar los operadores utilizados internamente
en dichas funciones, es decir >>, << y != para el tipo de los elementos del árbol.
*/

struct op
{
	double operando;
	char operador;
};


double abin_expresion(const Abin<op> &A)
{
	if(A.raiz() != Abin<op>::NODO_NULO)
	{
		return abin_expresion_rec(A.raiz(),A);	
	}
	else
	{
		return NULL;
	}
}

double abin_expresion_rec(Abin<op>::nodo n, const Abin<op> &A)
{
	if(n_es_nodo_hoja(n,A))
	{
		return A.elemento(n).operando;
	}
	else
	{
		switch (A.elemento(n).operador)
		{
			case +:
				return abin_expresion_rec(A.hijoIzqdo(n),A) + abin_expresion_rec(A.hijoDrcho(n),A);
				break;
			case -:
				return abin_expresion_rec(A.hijoIzqdo(n),A) - abin_expresion_rec(A.hijoDrcho(n),A);
				break;
			case *:
				return abin_expresion_rec(A.hijoIzqdo(n),A) * abin_expresion_rec(A.hijoDrcho(n),A);
				break;
			case /:
				return abin_expresion_rec(A.hijoIzqdo(n),A) / abin_expresion_rec(A.hijoDrcho(n),A);
				break;
		}
	}
}

bool n_es_nodo_hoja(typename Abin<T>::nodo n, const Abin<T> &A)
{
	return A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO;
}


