#include <iostream>
#include <cstring>
#include <string>
using namespace std;
 class Nodo
{
 	public:
 	
 		string nombre;
 		int hijos;
 		Nodo* primerHijo;
 		Nodo* siguiente; 
 		Nodo* ultimoHijo;
 	public:
		  Nodo(string dato)
		  { 
		  nombre=dato;
		  siguiente=NULL;
		  primerHijo=0;		
		  ultimoHijo=0;  
		  hijos=0;
		  }	
		  friend class Arbol;
};
	class Arbol
{
	public:
		Nodo * raiz;
	public:
		Arbol()
		{
			raiz=NULL;
		}
friend class Nodo;
	void insertar2(string n)
	{
		Nodo* nuevo= new Nodo(n);
			raiz=nuevo;		
}
void recorrer(Nodo* nodo)
{
	cout<<nodo->nombre<<endl;;;;;;
	if(nodo->hijos>0)
	{
		Nodo* i = nodo->primerHijo;
		while(i != NULL)
		{
			recorrer(i);
			i=i->siguiente;
		}
	}
}
void hijos(Nodo* nodo,string dato)
{
if(dato==nodo->nombre )
			{
				cout<<"Hijos: "<<endl;
				Nodo*aux=nodo->primerHijo;
			 
				while(aux != NULL)
		{
			cout<<aux->nombre<<" ";
			aux=aux->siguiente;
		
		}

			system("pause");
			}
			else{
	 
	if(nodo->hijos>0)
	{
		Nodo* i = nodo->primerHijo;
		while(i != NULL)
		{
			hijos(i,dato);
			i=i->siguiente;
		}
	}
}
}
void insertar(Nodo* nodo,string dato,string dato2)
{
if(dato==nodo->nombre )
			{
				Nodo* nuevo= new Nodo(dato2);
				if(nodo->hijos==0)	
		{
			nodo->hijos=nodo->hijos+1;
			nodo->primerHijo=nuevo;
			nodo->ultimoHijo=nuevo;
		}
		 else
		 {
		 	nodo->hijos=nodo->hijos+1;
		 	nodo->ultimoHijo->siguiente=nuevo;
		 	nodo->ultimoHijo=nuevo;
		 }
			}
			else{
	 
	if(nodo->hijos>0)
	{
		Nodo* i = nodo->primerHijo;
		while(i != NULL)
		{
			insertar(i,dato,dato2);
			i=i->siguiente;
		}
	}
}
}	
};
int main()
{
	int t,xx;
	string dato,dato2;		
		Arbol uno;	
	while (xx != 4)

{
	system("cls");	
	cout<<"\n    Arbol nHijos\n1-Insertar raiz del arbol\n2-Salir\n3-Recorrer arbol\n4-Ver hijos de alguien\n5-Insertarle hijo a \n";
	cin>>t;	
	switch(t)
	{	
	case 1:
		cout<<"\nNombre de la raiz:  ";
		cin>>dato;
		uno.insertar2(dato);		
	break;	
	case 2: 
	xx=4;
	break;	
	case 3:
		uno.recorrer(uno.raiz); 
		system("pause");
	break;
	case 4:
		 cout<<"Hijos de:? "<<endl;
		 cin>>dato;
		 uno.hijos(uno.raiz,dato);
		break;
	case 5:
		 cout<<"\nInsertar hijo a:  ";
		cin>>dato;
		cout<<"\nNombre del hijo: \n";
		cin>>dato2;
		uno.insertar(uno.raiz,dato,dato2);
		break;
   }
}
}
