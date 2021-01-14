#include "Diccionario.h"

using namespace std;

      //CONSTRUCTORES

Diccionario::Diccionario(){}

Diccionario::Diccionario(list<string>& lista){
  palabras = lista;
}

Diccionario::Diccionario(const Diccionario & fuente){
  *this = fuente;
}

Diccionario::~Diccionario(){}


      //CONSULTORES

list<string>& Diccionario::getPalabras() {
  return palabras;
}

const list<string>& Diccionario::getPalabras() const {
  return palabras;
}

list<string> Diccionario::palabrasLongitud(const unsigned int& longitud){
  list<string> segunLong;
  const_ite_lista recorrido;

  for( recorrido = palabras.begin(); recorrido != palabras.end(); recorrido++){
    if( (*recorrido).size() == longitud){
      segunLong.push_back( (*recorrido) );
    }
  }

  return segunLong;

}

int Diccionario::totalPalabras(){
  return palabras.size();
}

const int Diccionario::totalPalabras() const{
  return palabras.size();
}

bool Diccionario::buscarPalabra(const string& palabra){
  for(const_ite_lista c_ite = palabras.begin(); c_ite != palabras.end(); c_ite++){
    if( (*c_ite) == palabra){
      return true;
    }
  }
  return false;
}

ite_lista Diccionario::getPalabraPos(const unsigned& pos){
  
  ite_lista buscado = palabras.begin();

  for(unsigned p = 1; p<=pos; p++){
    buscado++;
  }

  return buscado;
}

const_ite_lista Diccionario::getPalabraPos(const unsigned& pos) const{
  
  const_ite_lista buscado = palabras.begin();

  for(unsigned p = 1; p<=pos; p++){
    buscado++;
  }

  return buscado;
}


      //METODOS

void Diccionario::addPalabra(const string& pal){
  palabras.push_back(pal);
}

void Diccionario::mostrarDiccionario(){
  if(totalPalabras() > 0){

    cout << *this << endl;

  }else{
    cout << "El diccionario no tiene palabras" << endl;
  }

}


      //OPERADORES E ITERADORES

Diccionario& Diccionario::operator=(const Diccionario & origen){

  if(this != &origen){
    palabras = origen.getPalabras();
  }
  return *this;
}

bool Diccionario::operator==(const Diccionario& dic) {
  if( palabras == dic.getPalabras() ) {
    return true;
  }
  return false;

}

bool Diccionario::operator!=(const Diccionario& dic) {
  if(*this == dic) {
    return false;
  }

  return true;
}

string& Diccionario::operator[](const unsigned& pos){
  ite_lista it_lis = getPalabraPos(pos);
  return *it_lis;
  
}

const string& Diccionario::operator[](const unsigned& pos) const{
  const_ite_lista c_ite_lis = getPalabraPos(pos);
  return *c_ite_lis;
}

ite_lista Diccionario::Diccionario::begin(){
  return palabras.begin();
}

const_ite_lista Diccionario::Diccionario::cbegin() const{
  return palabras.cbegin();
}

ite_lista Diccionario::Diccionario::end(){
  return palabras.end();
}

const_ite_lista Diccionario::Diccionario::cend() const{
  return palabras.cend();
}


      //FLUJOS

ostream& operator<<(ostream& salida, const Diccionario& dic){

  salida << "\t";

  for(int t = 0; t < dic.totalPalabras(); t++) {
    salida << dic[t] << " ; ";
    
  }
  salida << '\n';

  return salida;

}

istream& operator>>(istream& entrada, Diccionario& dic){
  if(entrada) {

    while( !entrada.eof() ){
      string linea;
      //El diccionario.txt está compuesto por 1 palabra, 1 linea
      getline(entrada, linea);
      dic.addPalabra(linea);
    }
  }

  return entrada;

}
