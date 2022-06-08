// Autores: Edna Martha Miranda Chávez
//          Sergio Fuenlabrada Velázquez
//
//                       Ordenamiento por cuentas -Counting Sort-
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
int maxi;
int mini;
int rango;
int valorsalva;
int LeeArchivo();
void countSort();
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
    i=0;
    fscanf (archivo1, "%i", &entrada.valor);
    a[0]=entrada.valor;
    maxi=mini=a[0];
    do{
        if (mini > a[i]){             // el ordenamiento cuentas utiliza el valor min del arreglo
            mini=a[i];
        }
        if (maxi < a[i]){            // el ordenamiento cuentas utiliza el valor max del arreglo
            maxi=a[i];
        }
        fscanf (archivo1, "%i", &entrada.valor);
        i++;
        a[i]=entrada.valor;
        cn++;

    }while (!feof(archivo1));

   	printf("valor de n es:  %i\n",cn);
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
    for (i=0; i<=cn-1; i++) {
        entrada1.valor1=a[i];
        fprintf(archivo2, "%i\n", entrada1.valor1);
    }
	printf("valor de n es:  %i\n",cn);
	fclose(archivo2);
	return (0);
}


Ordenamiento(int a[], int cn, int rango, int mini){
    printf("Ordenamiento por cuentas \n");
   	int counter[rango+mini] = {0};
// Cuenta el numero de ocurrencias de cada elemento
	for(i=0; i<cn; i++){
        j=a[i]-mini;
		counter[j]=counter[j]+1;
	}
	j=0;
// colocando los elementos nuevamente en el arreglo
	for (i=0; i < rango+1; i++){
        f=0;
        for (k=counter[i]; k>0; k--){
            a[j]= f+i+mini;
            f++;
            j++;
         //   counter[i]--;
        }
    }



}       // fin del ordenamiento


main(){
    si=1;
    do{

        LeeArchivo();
        rango=maxi-mini+1;
// Inicia area de medicion de tiempo
        t_ini = clock();                        // almacena tiempo inicial

        Ordenamiento(a, cn, rango, mini);       // realiza el ordenamiento

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
