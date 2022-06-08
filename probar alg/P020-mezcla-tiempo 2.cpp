// Autores: Edna Martha Miranda Chávez
//          Sergio Fuenlabrada Velázquez
//
//                       Ordenamiento mezcla
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

struct Entrada1 {
		int valor1;
} entrada1;

struct Entrada2 {
		int valor2;
} entrada2;

struct Entrada3 {
		int valor3;
} entrada3;

int i=0, j=0, k=0;
int a[1000000];
int n=0;
int cn=0;
int temp;
int si;
int valorsalva;
int LeeArchivo();
int LeeArchivo1();
int Ordenamiento();
int GrabaArchivo();
clock_t t_ini, t_fin;
double secs;

string nombrearchivo1;
string nombrearchivo2;
string nombrearchivo3;

int LeeArchivo(){
	FILE *archivo1;
    string valorInt;

    printf("\n Teclea el nombre del archivo de entrada:   ");
	cin >> nombrearchivo1;
	nombrearchivo1+= ".txt";						 		// le agregarmos la extension ".txt"

	archivo1 = fopen(nombrearchivo1.c_str(), "r");		        // Abrimos archivo

	if(archivo1== NULL ){
		printf(" No se puede abrir el archivo ");
		exit(1);
	}
	else{
		printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo1.c_str() );
    }
    cn=0;
    for (int i=0; !feof(archivo1); i++) {
        fscanf (archivo1, "%i", &entrada1.valor1);
        a[i]=entrada1.valor1;
        cn++;
	}
	printf("valor de n es:  %i\n",cn);
	fclose(archivo1);
	return (0);
}

int LeeArchivo1(){
	FILE *archivo2;
    string valorInt;

    printf("\n Teclea el nombre del archivo de entrada:   ");
	cin >> nombrearchivo2;
	nombrearchivo2+= ".txt";						 		// le agregarmos la extension ".txt"

	archivo2 = fopen(nombrearchivo2.c_str(), "r");		        // Abrimos archivo

	if(archivo2== NULL ){
		printf(" No se puede abrir el archivo ");
		exit(1);
	}
	else{
		printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo2.c_str() );
    }

    for (int i=cn; !feof(archivo2); i++) {
        fscanf (archivo2, "%i", &entrada2.valor2);
        a[i]=entrada2.valor2;
        cn++;
	}
	printf("valor de n es:  %i\n",cn);
	fclose(archivo2);
	return (0);
}

int GrabaArchivo(){
	FILE *archivo3;
    string valorInt;

    printf("\n Teclea el nombre del archivo de salida:   ");
	cin >> nombrearchivo3;
	nombrearchivo3+= ".txt";						 		// le agregarmos la extension ".txt"

	archivo3 = fopen(nombrearchivo3.c_str(), "w");		        // Abrimos archivo

	if(archivo3== NULL ){
		printf(" No se puede abrir el archivo ");
		exit(1);
	}
	else{
		printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo3.c_str() );
    }
    valorsalva=a[0];
    for (i=0; i<=cn; i++) {
        if (valorsalva!=a[i]){
            entrada3.valor3=valorsalva;
            valorsalva=a[i];
            fprintf(archivo3, "%i\n", entrada3.valor3);
        }
    }
	printf("valor de n es:  %i\n",cn);
	fclose(archivo3);
	return (0);
}

// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

// A function to split array into two parts.
void Ordenamiento(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		Ordenamiento(a, low, mid);
		Ordenamiento(a, mid+1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}


main(){
    si=1;
    do{

        LeeArchivo();
        LeeArchivo1();
// Inicia area de medicion de tiempo
        t_ini = clock();                        // almacena tiempo inicial

        Ordenamiento(a, 0, cn-1);                // realiza el ordenamiento

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



