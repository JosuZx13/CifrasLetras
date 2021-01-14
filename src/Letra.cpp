#include "Letra.h"

using namespace std;


/*
  char caracter;
  int aparicion;
  double puntuacion;
*/

Letra::Letra(){
  caracter = ' ';
  aparicion = 0;
  puntuacion = 0;
}

Letra::Letra(const char& car, const int& apar, const double& punt){
  caracter = car;
  aparicion = apar;
  puntuacion = punt;
}

Letra::Letra(const Letra & origen){
  caracter = origen.getCaracter();
  aparicion = origen.getAparicion();
  puntuacion = origen.getPuntuacion();
}

Letra::~Letra(){

}


    //CONSULTORES

const char& Letra::getCaracter() const{
  return caracter;
}

const int& Letra::getAparicion() const{
  return aparicion;
}

const double& Letra::getPuntuacion() const{
  return puntuacion;
}


    //MODIFICADORES

void Letra::setCaracter(const char& c){
  caracter = c;
}

void Letra::setAparicion(const int& a){
  aparicion = a;
}

void Letra::setPuntuacion(const double& p){
  puntuacion = p;
}


    //METODOS

//Metodo propio
Letra separarLinea(string& linea){
  Letra aux;
	
  //Busco un texto dentro de la cadena y obtengo la posicion
  int tab1 = linea.find('\t');
  int salto = linea.find('\n');

  string c = linea.substr(0, tab1);
  //cout << "He leidoCaracter:" << c <<"FIN" << endl;
	aux.setCaracter(c[0]);

  //Tengo el resto de la linea, después de leer el primer tabulador
  string resto = linea.substr(tab1+1, salto);

  int tab2 = resto.find('\t');

  //Obtengo una subcadena a partir del caracter siguiente a la tabulacion, tab1, hasta el siguiente tabulador, ta2
  string a = resto.substr(0, tab2);
  //cout << "He leidoAparicion:" << a <<"FIN" << endl;
  int a_entero = stoi(a);
  aux.setAparicion(a_entero);
  resto = resto.substr(tab2+1, salto);

	//Obtengo una subcadena a partir del tab2, y para pasar esa posicion, se suma 1
	string p = resto.substr (0, salto);
  //cout << "He leidoPuntuacion:" << p <<"FIN" << endl;
  double p_doble = stod(p);
 
  aux.setPuntuacion(p_doble);

  return aux;
}

void Letra::mostrarLetra() const{
  cout << *this << endl;
}


    //OPERADORES

bool Letra::operator==(const Letra comprob) const{
  if(caracter == comprob.getCaracter()){
    return true;
  }
  return false;
}

bool Letra::operator!=(const Letra comprob) const{
  if(*this == comprob){
    return false;
  }
  return true;
}

bool Letra::operator>(const Letra comprob) const{
  if(caracter > comprob.getCaracter()){
    return true;
  }
  return false;
}
//Si el char es menor, va antes alfabéticamente
bool Letra::operator<(const Letra comprob) const{
  if(*this > comprob){
    return false;
  }
  return true;
}

    //FLUJOS

ostream& operator<<(ostream& salida, const Letra& fuente){
  salida << "Letra: ";
  salida << fuente.getCaracter() << "\tAparicion: ";
  salida << fuente.getAparicion() << "\tPuntuacion: ";
  salida << fuente.getPuntuacion() << endl;

  return salida;
}

istream& operator>>(istream& entrada, Letra& destino){
  
  if(entrada){

    string linea = "";

    //Se lee una linea, y la primera no cuenta, es una cabecera
    getline(entrada, linea);

    destino = separarLinea(linea);
    
  }//Si el flujo está abierto
  
	return entrada;
}