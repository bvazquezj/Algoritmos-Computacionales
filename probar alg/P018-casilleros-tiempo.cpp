// Autores: Edna Martha Miranda Chávez
//          Sergio Fuenlabrada Velázquez
//
//                       Ordenamiento Burbuja
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
// definición de la clase

class element            //element
{
public:
	int value;
	element *next;
	element()
	{
	bool value=NULL;
	next=NULL;
	}
};

class bucket           //bucket containing a perticular range of values
{
public:
element *firstElement;
bucket()
{
firstElement = NULL;
}
};

struct Entrada {
		int valor;
} entrada;

struct Entrada1 {
		int valor1;
} entrada1;

int i=0, j=0, k=0;
int array[1000000];
int n=0;
int cn=0;
int temp;
int si;
int valorsalva;
int LeeArchivo();
int Ordenamiento();
int GrabaArchivo();
clock_t t_ini, t_fin;
double secs;
int lowend=0;         // minimum element
int highend=0;       //max element
int interval=0;      //number of intervals

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
        array[i]=entrada.valor;
        cn++;
	}
	printf("valor de n es:  %i\n",cn-1);
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
    valorsalva=array[0];
    for (i=1; i<=cn-1; i++) {
        if (valorsalva!=array[i]){
            entrada1.valor1=valorsalva;
            valorsalva=array[i];
            fprintf(archivo2, "%i\n", entrada1.valor1);
        }
    }
	printf("valor de n es:  %i\n",cn-1);
	fclose(archivo2);
	return (0);
}

Ordenamiento(){
    printf("Ordenamiento casilleros\n");
    const int noBuckets=(highend-lowend)/interval; //number of buckets required
	bucket *buckets=new bucket[noBuckets];
	bucket *temp;

	for(int i=0;i<noBuckets;i++)   //creation of required buckets
	{
		temp=new bucket;
		buckets[i]=*temp;
	}
    printf("Numero de Buckets %i\n",noBuckets);
	cout<<"--------The Elements to be Sorted using Bucket sort are ------------------\n";
	// int array[]={12,2,22,33,44,55,66,77,85,87,81,83,89,82,88,86,84,88,99};

	for(j=0;j<noBuckets;j++)   //sending elments into appropriate buckets
	{
        cout<<array[j]<<endl;
        element *temp,*pre;
        temp=buckets[array[j]/interval].firstElement;
		if(temp==NULL)//if it is the first element of the bucket
		{
			printf("estoy creando el primero nodos del bucket %i\n", array[j]);
			temp=new element;
			buckets[array[j]/interval].firstElement=temp;
			temp->value=array[j];
			printf("ya cree el primero nodos del bucket %i\n", array[j]);
		}
		else
		{
			pre=NULL;
				while(temp!=NULL){             //move till the appropriate position in the bucket
				     if(temp->value>array[j]){
                            break;
                    }
                        pre=temp;
                        temp=temp->next;
                }
				if(temp->value>array[j]) //if the new value is in betwen or at the begining
				{
					if(pre==NULL)  //insertion at first if the bucket has elements already
					{
					    printf("estoy creando el primero nodos %i\n", array[j]);
						element *firstNode;
						firstNode=new element();
						firstNode->value=array[j];
						firstNode->next=temp;
						buckets[array[j]/interval].firstElement=firstNode;
						printf("ya cree el priemro nodos %i\n", array[j]);
					}
					else  //insertion at middle
					{
						printf("estoy creando el de enmedio nodos %i\n", array[j]);
						element *firstNode;
						firstNode=new element();
						firstNode->value=array[j];
						firstNode->next=temp;
						pre->next=firstNode;
						printf("ya cree el de enmedio nodos %i\n", array[j]);
					}
				}
				else// if the new value is to be created at last of bucket
				{
					temp=new element;
					pre->next=temp;
					temp->value=array[j];
					printf("estoy creando el ultimo nodos %i\n", array[j]);
				}

		}
 }

	cout<<"------------------------The Sorted Elements Are---------------\n";
	for(int jk=0;jk<10;jk++)
	{
		element *temp;
		temp= buckets[jk].firstElement;
			while(temp!=NULL)
			{
				cout<<"*"<<temp->value<<endl;
				temp=temp->next;
			}
	}
	cout<<"--------------------------------END--------------------------------\n";

}       // fin del ordenamiento

main(){
    si=1;
    do{

        LeeArchivo();
        lowend=0;         // minimum element
        highend=cn;      //max element
	    interval=cn/10;      //number of intervals
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



