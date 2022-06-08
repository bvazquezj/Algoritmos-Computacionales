/*partieron de la justificación de la palabra de Dios para apoderarse de la riqueza que había en
las Indias. Vinieron como los grandes civilizados y se representaron como las verdaderas
bestias de la conquista, extrayendo riquezas, violentando, matando e imponiendo órdenes.*/


#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

int arr[10];
int dato,flg=0;

void obtenarr(){
    cout<<"introduce los numeros que quieras insertar"<<endl;
    for(int i=0;i<10;i++){
        cout<<"dato numero "<<i+1<<endl;
        cin>>arr[i];
    }
    system("cls");
}
int obtenvalbus(){
    cout<<"introduce el valor a buscar"<<endl;
    cin>>dato;
    return dato;
}
void buscar(int dato){
    for(int i=0;i<10;i++){
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
    obtenvalbus();
    buscar(dato);
    mostrar(dato);
    getch();
    return 0;
}
