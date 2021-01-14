#ifndef ConjuntoLetras_h
#define ConjuntoLetras_h

#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include "Letra.h"
#include <limits>

using namespace std;

typedef set<Letra>::iterator ite_conjunto;
typedef set<Letra>::const_iterator const_ite_conjunto;

/**
  *  @brief T.D.A. Conjunto de Letras
  *
  * ConjuntoLetras es un Tipo de Dato Abstracto que está compuesto por
  * un set, conjunto de Letras, donde no se repite ninguna letra
  *
  *  @author Jose Manuel Osuna Luque
  *  @date Diciembre 2018
  */
class ConjuntoLetras {


private:

  set<Letra> letras;

public:

  /**
    * @brief Constructor por defecto de la clase
    */
  ConjuntoLetras();

  /**
    * @brief Constructor por parámetros de la clase
    * @param letras, un conjunto de letras
    * @pre letras no estará vacio
    */
  ConjuntoLetras(const set<Letra>& l);

  /**
    * @brief Constructor de copia de la clase
    * @param origen un objeto de la clase ConjuntoLetras
    * @pre origen no puede ser nulo
    */
  ConjuntoLetras(const ConjuntoLetras& origen);

  /**
    * @brief Destructor de la clase
    */
  ~ConjuntoLetras();


//CONSULTORES

  /**
    * @brief Consultor de Letras
    * @return set<Letra>, el conjunto de letras no repetidas
    */
  const set<Letra> getLetras() const;

  /**
   * @brief Consultor del numero de letras que contiene el conjunto 
   * @return entero con el número de elementos del conjunto de Letras
   */
  const unsigned int getNumLetras() const;


  //MODIFICADORES

  /**
    * @brief Modificador de Letras
    * @param set<Letra> s, el nuevo valor del conjunto asociado al objeto de la clase
    * @pre set s no debe estar vacio
    */
  void setLetras(const set<Letra>& s);

  /**
   * @brief Modifica los valores de una letra que ya pertenece al conjunto de Letras
   * @param c char, usado para buscar la letra dentro del set de la clase
   * @param nueva_apar int, que contendrá el nuevo valor de las veces que apaerece la Letra
   * @param nueva_punt int, que contendrá la nueva puntuacion asignada a la Letra
   */ 
  void setValoresLetra(const char& c, const int& nueva_apar, const int& nueva_punt);


//METODOS

  /**
    * @brief Añade un termino a la lista
    * @param le Letra que será añadido al Diccionario
    * @pre le no puede ser nulo o vacio
    */
  void addLetra(const Letra& le);

  /**
   * @brief Busca una Letra en el set a través de un caracter 
   * @param c char, usado para buscar la letra en el conjunto
   * @pre c char no puede estar vacia
   */
  const Letra& buscarLetra(const char& c);

  /**
    * @brief Muestra por pantalla el ConjuntoLetras
    */
  void mostrarLetras() const;


//ITERADORES

    /**
    * @brief Metodo begin del diccionario
    * @return devuelve un iterador de la primera posicion del set de diccionario
    */
  ite_conjunto begin();

  /**
    * @brief Metodo begin del diccionario
    * @return devuelve un iterador constante de la primera posicion del set de diccionario
    */
  const_ite_conjunto cbegin() const;
  
  /**
    * @brief Metodo end del diccionario
    * @return devuelve un iterador a la siguiente posicion de la última del set de diccionario
    */
  ite_conjunto end();
  
  /**
    * @brief Metodo end del diccionario
    * @return devuelve un iterador constante a la siguiente posicion de la última del set de diccionario
    */
  const_ite_conjunto cend() const;


//OPERADORES

  /**
   * @brief Operador de igualdad
   * @param ConjuntoLetras comprob constante, el objeto usado con la clase para comprobar si son iguales o no 
   * @return bool, devuelve true si son iguales, false en caso contrario
   */
  bool operator==(const ConjuntoLetras comprob) const;

  /**
   * @brief Operador de desigualdad
   * @param ConjuntoLetras comprob constante, el objeto usado con la clase para comprobar si son iguales o no 
   * @return bool, devuelve true si son diferentes, false en caso contrario
   */
  bool operator!=(const ConjuntoLetras comprob) const;

  /**
   * @brief Operador mayor
   * @param ConjuntoLetras comprob constante, el objeto usado con la clase para comprobar si la letra es mayor 
   * @return bool, devuelve true si es mayor, false en caso contrario
   */
  bool operator>(ConjuntoLetras comprob) const;

  /**
   * @brief Operador menor
   * @param ConjuntoLetras comprob constante, el objeto usado con la clase para comprobar si la letra es menor 
   * @return bool, devuelve true si es menor, false en caso contrario
   */
  bool operator<(ConjuntoLetras comprob) const;


//FLUJOS

  /**
		* @brief Salida de un ConjuntoLetras a ostream
		* @param salida stream de salida
		* @param ConjuntoLetras fuente, a escribir
		* @return referencia a flujo de escritura
		*/
	friend ostream& operator<<(ostream& salida, const ConjuntoLetras& fuente);

	/**
		* @brief Entrada de un ConjuntoLetras desde istream
		* @param entrada stream de entrada
		* @param ConjuntoLetras destino, donde se guardará la ConjuntoLetras
		* @return referencia a flujo de lectura
		*/
	friend istream& operator>>(istream& entrada, ConjuntoLetras& destino);

};

#endif // Letra_h
