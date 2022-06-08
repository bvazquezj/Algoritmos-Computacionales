// Autores: Edna Martha Miranda Chávez
//          Sergio Fuenlabrada Velázquez
//
//                       Crea archivo de numeros randon
//
#include <stdlib.h>
#include <stdio.h>
#include <string>       /*añadimos la biblioteca "string.h" */
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;


	FILE *archivo1;
	struct Registro{
		int valor;
	} entrada;  // el registro que tiene 0,0,n ....n representa el número de términales

int i;
int f;
int v;
int r;
int inicio;
string nombrearchivo;

int main (void){

  	srand (time(NULL));        					 		// initialisa random semilla
	printf("\n Teclea el nombre del archivo:   ");
	cin >> nombrearchivo;
	nombrearchivo+= ".txt";						 		// le agregarmos la extension ".txt"

	archivo1 = fopen(nombrearchivo.c_str(), "w");		// Abrimos archivo

	if(archivo1== NULL ){
		printf(" No se puede abrir el archivo ");
		exit(1);
	}
	else{
		printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo.c_str() );
    }
	do{
		printf ("Valor inicial:  \n");
		scanf("%i",&i);
		inicio=i;
		printf ("Valor final:    \n");
		scanf("%i",&f);
		printf("Numero de valores: \n");
		scanf("%i",&r);
	}while(f-i>=2000000);


	for (i=0;i<r;i++){
		v=inicio + rand () %(f+1 - inicio); // la formula de numeros puede variar de acuerdo a la necesidad
		entrada.valor=v;
		fprintf(archivo1, "%i\n", entrada.valor);
	}
	fclose(archivo1);
  	return (0);
}
