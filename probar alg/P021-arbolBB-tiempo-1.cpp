// Autores: Edna Martha Miranda Chávez
//          Sergio Fuenlabrada Velázquez
//
//                       Ordenamiento Arbol Binario
// Modificado a partir del codigo de
//                      (C) Abril 2002, Salvador Pozo
//                      C con Clase: http://c.conclase.net

#include <iostream>
#include <time.h>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

// definión de la estructra del archivo de entrada
FILE *archivo1;
	struct Registro{
		int num;
	} entrada;
// definición de la estructura del archivo de salida con tiempos de ejecución
FILE *archivo2;
    struct Registro1{
        int num1;   // es el nodo que se busco
    } entrada1;
int salvan=0;
int cn=0;
int n=0;
int bandera=0;
int i;
clock_t t_ini, t_fin;
double secs;
int arreglo[1000000];
string nombrearchivo;
string nombrearchivo1;



class ArbolABB {
  public:
   //// Clase local de Lista para Nodo de ArbolBinario:
   class Nodo {
     public:
      // Constructor:
      Nodo(const int dat, Nodo *izq=NULL, Nodo *der=NULL) :
        dato(dat), izquierdo(izq), derecho(der) {}
      // Miembros:
      int dato;
      Nodo *izquierdo;
      Nodo *derecho;
   };

// Punteros de la lista, para cabeza y nodo actual:
   Nodo *raiz;
   Nodo *actual;
   int contador;
   int altura;

  public:
// Constructor y destructor básicos:
   ArbolABB() : raiz(NULL), actual(NULL) {}
   ~ArbolABB() { Podar(raiz); }
// Insertar en árbol ordenado:
   void Insertar(const int dat);
// Borrar un elemento del árbol:
   int Borrar(const int dat);
// Función de búsqueda:
   int Buscar(const int dat);
// Comprobar si el árbol está vacío:
   bool Vacio(Nodo *r) { return r==NULL; }
// Comprobar si es un nodo hoja:
   bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
// Contar número de nodos:
   const int NumeroNodos();
   const int AlturaArbol();
// Calcular altura de un int:
   int Altura(const int dat);
// Devolver referencia al int del nodo actual:
   int &ValorActual() { return actual->dato; }
// Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
// Aplicar una función a cada elemento del árbol:
   void InOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
// Obtencion del archivo de entrada
    int Obtencion();
// Agregar otro nodo
    int Otronodo();
// Borrar nodo
    int Borrarnodo();
  private:
// Funciones auxiliares
   void Podar(Nodo* &);
   void auxContador(Nodo*);
   void auxAltura(Nodo*, int);
}ArbolInt;



// Poda: borrar todos los nodos a partir de uno, incluido
void ArbolABB::Podar(Nodo* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un int en el árbol ABB
void ArbolABB::Insertar(const int dat)
{
   Nodo *padre = NULL;

   actual = raiz;
   // Buscar el int en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat > actual->dato) actual = actual->derecho;
      else if(dat < actual->dato) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new Nodo(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->dato) padre->izquierdo = new Nodo(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat > padre->dato) padre->derecho = new Nodo(dat);
}

// Eliminar un elemento de un árbol ABB
int ArbolABB::Borrar(const int dat)
{
   Nodo *padre = NULL;
   Nodo *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat == actual->dato) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre) // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            delete actual; // Borrar el nodo
            actual = NULL;
            return 0;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
     return 1;
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::InOrden(void (*func)(int&) , Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PreOrden(void (*func)(int&), Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   func(nodo->dato);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PostOrden(void (*func)(int&), Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato);
}

// Buscar un valor en el árbol
int ArbolABB::Buscar(const int dat)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return 1; // int encontrado
      else if(dat > actual->dato) actual = actual->derecho; // Seguir
      else if(dat < actual->dato) actual = actual->izquierdo;
   }
   return -1; // No está en árbol
}

// Calcular la altura del nodo que contiene el int dat
int ArbolABB::Altura(const int dat)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
   return -1; // No está en árbol
}

// Contar el número de nodos
const int ArbolABB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // Función auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolABB::auxContador(Nodo *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int ArbolABB::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void ArbolABB::auxAltura(Nodo *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

// Función de prueba para recorridos del árbol
void Mostrar(int &d)
{
    if (bandera==0){
        printf ("Se muestra arbol inorder si=1, no=0: ");
        cin >> bandera;
        printf("\n");
        if (bandera==0){
            bandera=2;
        }
    }
    if (bandera==1){
        cout << d << ",";

    }

/*
    FILE *archivo2;
    string valorInt;

    if (bandera==0){
        bandera=1;
        printf("\n Teclea el nombre del archivo de salida:   ");
        cin >> nombrearchivo1;
        nombrearchivo1+= ".txt";						 		// le agregarmos la extension ".txt"
        archivo2 = fopen(nombrearchivo1.c_str(), "w");		        // Abrimos archivo
    	if(archivo2== NULL ){
            printf(" No se puede abrir el archivo ");
            exit(1);
        }
        else{
            printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo1.c_str() );
        }
    }

    entrada1.num1=d;
 //   printf("valor de entrada1.num1: %i y de d: %i\n", entrada1.num1, d);
//    fprintf(archivo2, "%i\n", entrada1.num1);
*/
    cn++;


//    if (cn==n-1){
   //     printf("\nvalor de n es:  %i\n",cn);
      //  fclose(archivo2);
  //  }
}


// Obtencion: Obtiene arreglo ordenado a la inversa
int ArbolABB::Obtencion(){
    int j;
    int tnodo;
    printf("\n Teclea numero de nodos:   ");
	cin >> tnodo;


    for (j=tnodo+1; j>0 ; j--) {
         arreglo[j]=j;
         n++;
    }
    salvan=n;

}


// Borrar un nodo
int ArbolABB::Borrarnodo()
{
    int nodo2;
    int si=1;
    int enc=-1;
    do{
        printf("Indica nodo a borrar: ");
        cin >> nodo2;
        enc=ArbolInt.Borrar(nodo2);
        if (enc==0){
            printf ("El nodo %i fue borrado", nodo2);
        }
        else{
            printf("El nodo %i no existe", nodo2);
        }
        printf("\n desea borrar otros (si= 1, no=0): ");
        cin >> si;
    }while (si==1);
}

// Agrega otro nodo
int ArbolABB::Otronodo()
{
    int numnod;
    int nodo1;
    int k;
    do{
        printf ("cuantos nodos nodos deseas agregar: ");
        cin >> numnod;
    }while (numnod<0);
    for (k=1;k<=numnod;k++){
        printf ("\n Tenclea numero de nodo: ");
        cin >> nodo1;
        ArbolInt.Insertar(nodo1);
    }

}


int main()
{
    int nodo;
    int ss=0;
    printf(" Ordenamiento Arbol Binario\n");

    do {
        ArbolInt.Obtencion();

        printf("valor de n es:  %i\n",n-1);
// Inicia area de medicion de tiempo

        t_ini = clock();                        // almacena tiempo inicial
        for (i=0;i<n;i++){
            nodo=arreglo[i];
            ArbolInt.Insertar(nodo);            // realiza el ordenamiento al crear el arbol
        }
        t_fin = clock();						// almacena tiempo final
// Termina area de medicion de tiempo
        secs = (double)(t_fin - t_ini) / (double)CLOCKS_PER_SEC; // determina los milisegundo utilizados
        printf("%.16g milisegundos\n", secs * 1000.0);   // muestra el tiempo utilizado
        system("pause");
        ArbolInt.InOrden(Mostrar);
        printf("\nvalor de n es:  %i\n",cn-1);
        printf("Desea probar otro arbol (si=1,no=2): ");
      cin>> ss;
    }while (ss!=0);
    return(0);
}
