//EJERCICIO agenda

/*
Haz una agenda usando una arbol de busqueda. Utiliza una estructura con los campos nombre y telefono

supondremos que queremos las siguientes operaciones:
	
	- insertar contacto
	- eliminar contacto por nombre
	- buscar numero contacto por nombre
*/

struct contacto
{
	string nombre;
	string telefono;	
};

//asumiremos que la estructura tiene sobrecargada el operador < para contacto mediante el nombre

void insertar_contacto(string nombre, string telefono, Abb<contacto>& A);
{
	contacto C;
	C.nombre = nombre;
	C.telefono = telefono;
	
	A.insertar(C);
}


void eliminar_contacto(string nombre,Abb<contacto>&A)
{
	if(!A.vacio())
	{	
		if(A.elemento().nombre == nombre)
		{
			A.eliminar();
		}
		else
		{
			if(nombre < A.elemento().nombre)
			{
				eliminar_contacto(nombre,A.izqdo());
			}
			else
			{
				eliminar_contacto(nombre,A.drcho());
			}
			
		}
	}
}

string buscar_numero(string nombre, const Abb<contacto>& A)
{
	if(A.vacio())
	{
		throw std::invalid_argument("no existe el contacto en la agenda");
	}
	else
	{
		if(A.elemento().nombre == nombre)
		{
			return A.elemento().numero;
		}
		else
		{
			if(nombre < A.elemento().nombre)
			{
				return buscar_numero(nombre,A.izqdo());
			}
			else
			{
				return buscar_numero(nombre,A.drcho());
			}
		}
	}
}

