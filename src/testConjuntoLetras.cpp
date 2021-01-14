#include "ConjuntoLetras.h"

#include <string.h>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
    cout<<"Dime el nombre del fichero con el diccionario"<<endl;
    return 0;
  }

  /*ifstream lectura (argv[1]);
  if (!lectura){
  cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
  return 0;
  }*/

  
  char fichero[30]; //Variable usada para guardar la ruta completa donde se encuentra el fichero
  strcpy(fichero, "../datos/"); //Copia al inicio del char fichero esa ruta
  strcat(fichero, argv[1]); //Concatena a lo que ya hay en fichero, el nombre del texto pasado por argumento

  ifstream lectura (fichero);

  if (!lectura){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }else{
     cout << "FICHERO ABIERTO" << endl;
 }
 
   
  ConjuntoLetras conj;
  cout << "Cargando conjunto de letras...\n" << endl;

  lectura >> conj; //Cargamos en memoria el conjunto de letras
  
  cout << "conjunto de letras leído.\n" << endl;

  cout << conj << endl;

}
