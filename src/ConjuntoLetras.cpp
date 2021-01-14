#include "ConjuntoLetras.h"

using namespace std;

ConjuntoLetras::ConjuntoLetras(){

}

ConjuntoLetras::ConjuntoLetras(const set<Letra>& l){
  letras = l;
}

ConjuntoLetras::ConjuntoLetras(const ConjuntoLetras& origen){

    letras = origen.getLetras();
}

ConjuntoLetras::~ConjuntoLetras(){}


        //CONSULTORES

const set<Letra> ConjuntoLetras::getLetras() const{
  return letras;
}

const unsigned int ConjuntoLetras::getNumLetras() const{
  return letras.size();
}


        //MODIFICADORES

void ConjuntoLetras::setLetras(const set<Letra>& s){
  letras = s;
}

void ConjuntoLetras::setValoresLetra(const char& c, const int& nueva_apar, const int& nueva_punt){
  ite_conjunto recorrido;
  bool encontrado = false;
  Letra aux;
  for(recorrido = letras.begin(); recorrido != letras.end() && !encontrado; recorrido++){
    if(recorrido->getCaracter() == c){
      encontrado = true;
      aux.setCaracter(c);
      aux.setAparicion(nueva_apar);
      aux.setPuntuacion(nueva_punt);

      letras.erase(recorrido);
      letras.insert(aux);
            
    }
  }
}


        //METODOS

void ConjuntoLetras::addLetra(const Letra& le){
  letras.insert(le);
}

const Letra& ConjuntoLetras::buscarLetra(const char& c){
  const_ite_conjunto c_ite;
  for(c_ite = letras.cbegin(); c_ite != letras.cend(); c_ite++){
    if(c_ite->getCaracter() == c){
      return (*c_ite);
    }
  }

  //Aqui vale nulo tras salir del for
  c_ite = letras.end();
  return (*c_ite);
}

void ConjuntoLetras::mostrarLetras() const{
  for(const_ite_conjunto c_ite = letras.begin(); c_ite != letras.end(); ++c_ite){
    //Llama al ostream de Letra
    cout << (*c_ite);
  }
}


        //ITERADORES

ite_conjunto ConjuntoLetras::begin(){
  return letras.begin();
}

const_ite_conjunto ConjuntoLetras::cbegin() const{
  return letras.cbegin();
}

ite_conjunto ConjuntoLetras::end(){
  return letras.end();
}

const_ite_conjunto ConjuntoLetras::cend() const{
  return letras.cend();
}


        //OPERADORES

bool ConjuntoLetras::operator==(const ConjuntoLetras comprob) const{
  if(getNumLetras() == comprob.getNumLetras() ){
    if(getLetras() == comprob.getLetras()){
      return true;
    }
  }
    
  return false;
}

bool ConjuntoLetras::operator!=(const ConjuntoLetras comprob) const{
  if(*this == comprob){
    return false;
  }
  return true;
}

bool ConjuntoLetras::operator>(ConjuntoLetras comprob) const{
  if(getNumLetras() > comprob.getNumLetras() ){
    return true;
  }
  return false;
}

bool ConjuntoLetras::operator<(ConjuntoLetras comprob) const{
  if(*this > comprob){
    return false;
  }
  return true;
}


        //FLUJOS

ostream& operator<<(ostream& salida, const ConjuntoLetras& fuente){
  salida << "Conjunto de Letras" << endl;
  const_ite_conjunto conj;
  for(conj = fuente.cbegin(); conj != fuente.cend(); conj++){
    salida << "\t" << (*conj);
  }

  return salida;
}

istream& operator>>(istream& entrada, ConjuntoLetras& destino){
  if(entrada){
    string primeraLinea;
    getline(entrada, primeraLinea);

		while( !entrada.eof() ){
			Letra le;
      
			entrada >> le;

			destino.addLetra(le);
		}
	}

  return entrada;
}