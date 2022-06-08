// Autores: Edna Martha Miranda Chávez
//          Sergio Fuenlabrada Velázquez
//
//                       Ordenamiento Burbuja bidirecional
//
// Los datos de entrada los toma de un archivo guardado en el mismo directorio que el programa,
// esto se realizo con el objetivo de que en las pruebas no se tecleen todas las veces
// los datos de entrada
//

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;
struct Entrada {
		int valor;
} entrada;

struct Entrada1 {
		int valor1;
} entrada1;

int i=0, j=0, k=0, f=0;
int a[1000000];
int izq;
int der;
int n=0;
int cn=0;
int salvacn=0;
int temp;
int si;
int valorsalva;
int LeeArchivo();
int Ordenamiento();
int GrabaArchivo();
clock_t t_ini, t_fin;
double secs;

string nombrearchivo;
string nombrearchivo1;

int LeeArchivo(){
	FILE *archivo1;
    string valorInt;

    printf("\n Teclea el nombre del archivo de entrada:   ");
	cin >> nombrearchivo;
	nombrearchivo+= ".txt";						 		// le agregarmos la extension ".txt"

	archivo1 = fopen(nombrearchivo.c_str(), "r");		        // Abrimos archivo

	if(archivo1== NULL ){
		printf(" No se puede abrir el archivo ");
		exit(1);
	}
	else{
		printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo.c_str() );
    }
    cn=0;
    for (int i=0; !feof(archivo1); i++) {
        fscanf (archivo1, "%i", &entrada.valor);
        a[i]=entrada.valor;
        cn++;
	}
	printf("valor de n es:  %i\n",cn-1);
	salvacn=cn;
	fclose(archivo1);
	return (0);
}
int GrabaArchivo(){
	FILE *archivo2;
    string valorInt;

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
    valorsalva=a[0];
    cn=salvacn;
    for (i=1; i<=cn-1; i++) {
        if (valorsalva!=a[i]){
            entrada1.valor1=valorsalva;
            valorsalva=a[i];
            fprintf(archivo2, "%i\n", entrada1.valor1);
        }
    }
	printf("valor de n es:  %i\n",cn-1);
	fclose(archivo2);
	return (0);
}

Ordenamiento(){
    printf("Ordenamiento burbuja bidireccional\n");
    izq=0;
    der=cn=salvacn-2;
    do{
        for(j=izq+1;j<=der;j++){
// burbuja a la izquierda los menores van a la izquierda
            if(a[j-1]>a[j]){
                k=a[j]; a[j]=a[j-1]; a[j-1]=k;
            }
        }

        der=der-1;
        for(i=der;i>izq;i--){
            if(a[i-1]>a[i]){
                k=a[i-1]; a[i-1]=a[i]; a[i]=k;
            }
        }
        izq=izq+1;
    }while (der>=izq);

}       // fin del ordenamiento

main(){
    si=1;
    do{

        LeeArchivo();
// Inicia area de medicion de tiempo
        t_ini = clock();                        // almacena tiempo inicial

        Ordenamiento();                         // realiza el ordenamiento

        t_fin = clock();						// almacena tiempo final
// Termina area de medicion de tiempo
        secs = (double)(t_fin - t_ini) / (double)CLOCKS_PER_SEC; // determina los milisegundo utilizados
        printf("%.16g milisegundos\n", secs * 1000.0);   // muestra el tiempo utilizado
        system("pause");
        GrabaArchivo();
        printf("Deseas probar con otro archivo (Si=1, NO=0) ");
        cin >> si;
    }while(si==1);
    return(0);
}



