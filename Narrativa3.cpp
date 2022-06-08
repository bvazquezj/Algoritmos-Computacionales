/*partieron de la justificación de la palabra de Dios para apoderarse de la riqueza que había en
las Indias. Vinieron como los grandes civilizados y se representaron como las verdaderas
bestias de la conquista, extrayendo riquezas, violentando, matando e imponiendo órdenes.*/


#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

int arr[10];
int dato,n,flg,aux,en=0;

void obtenarr(){
    cout<<"introduce en cuantos datos buscaras"<<endl;
    cin>>n;
    cout<<"introduce los numeros que quieras insertar"<<endl;
    for(int i=0;i<n;i++){
        cout<<"dato numero "<<i+1<<endl;
        cin>>arr[i];
    }
    //metodo burbuja
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]<arr[j+1]){
                aux=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
            }
        }
    }
    system("cls");
}
int obtenvalbus(){
    cout<<"introduce el valor a buscar"<<endl;
    cin>>dato;
    return dato;
}
void buscar(int dato){
    flg=0;
    for(int i=0;i<n;i++){
        if(arr[i]==dato){
            flg++;
        }
    }
}
void mostrar(int dato){
    cout<<"el dato "<<dato<<" esta "<<flg<<" veces en el arreglo"<< endl;
}
main(){
    obtenarr();
    while(en==0){
        obtenvalbus();
        buscar(dato);
        mostrar(dato);
        getch();
        cout<<"desea seguir realizando busquedas 0=si 1=no"<<endl;
        cin>>en;
    }
    return 0;
}
