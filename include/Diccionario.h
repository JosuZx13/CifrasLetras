#ifndef Diccionario_h
#define Diccionario_h

#include <list>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

typedef list<string>::iterator ite_lista;
typedef list<string>::const_iterator const_ite_lista;

/**
  *  @brief T.D.A. Diccionario STL
  *
  * Diccionario es un Tipo de Dato Abstracto que está compuesto
  * por una list de la STL donde se guardan palabras
  * 
  * @author Jose Manuel Osuna Luque
  * @date Diciembre 2018
  */
class Diccionario {


private:

  list<string> palabras;

public:

  /**
    * @brief Constructor por defecto de la clase
    */
  Diccionario();

  /**
    * @brief Constructor por parámetros de la clase
    * @param array serán los terminos que formarán el diccionario
    */
  Diccionario(list<string> &lista);

  /**
    * @brief Constructor de copia de la clase
    * @param origen un objeto de la clase Diccionario
    * @pre origen no puede ser nulo
    */
  Diccionario(const Diccionario & origen);

  /**
    * @brief Destructor de la clase
    */
  ~Diccionario();


//CONSULTORES

  /**
    * @brief Consultor de Terminos
    * @return devuelve todos los términos del diccionario
    */
  list<string>& getPalabras();

  /**
    * @brief Consultor de Terminos
    * @return devuelve todos los términos del diccionario
    */
  const list<string>& getPalabras() const;

  /**
    * @brief Obtiene todas las palabras en el diccionario de una longitud dada
    * @param longitud, la longitud de las palabras que buscara
    * @return una lista con las palabras de longitud específicada por el parámetro
    */
  list<string> palabrasLongitud(const unsigned int& longitud);

  /**
    * @brief Consultor del número de términos de un Diccionario
    * @return devuelve el número de elementos que contiene el vector de Diccionario
    */
  int totalPalabras();

  /**
    * @brief Consultor del número de términos de un Diccionario
    * @return devuelve el número de elementos que contiene el vector de Diccionario
    */
  const int totalPalabras() const;

  /**
		* @brief busca una palabra
		* @param palabra, palabra a buscar
		* @return true si está en la lista
		*/
  bool buscarPalabra(const string& palabra);

  /**
    * @brief Devuelve la palabra tras dar una posicion concreta
    * @param pos, la palabra que se quiere
    * @return un iterator apuntando a la direccion de la palabra
    */
  ite_lista getPalabraPos(const unsigned& pos);

  /**
    * @brief Devuelve la palabra tras dar una posicion concreta
    * @param pos, la palabra que se quiere
    * @return un iterator constante apuntando a la direccion de la palabra
    */
  const_ite_lista getPalabraPos(const unsigned& pos) const;


//METODOS

  /**
    * @brief Añade un termino a la lista
    * @param pal string que será añadido al Diccionario
    * @pre pal no puede ser nulo
    */
  void addPalabra(const string& pal);

  /**
    * @brief Muestra por pantalla el diccionario
    */
  void mostrarDiccionario();


//ITERADORES

  /**
    * @brief Metodo begin del diccionario
    * @return devuelve un iterador de la primera posicion de la list de diccionario
    */
  ite_lista begin();

  /**
    * @brief Metodo begin del diccionario
    * @return devuelve un iterador constante de la primera posicion de la list de diccionario
    */
  const_ite_lista cbegin() const;
  
  /**
    * @brief Metodo end del diccionario
    * @return devuelve un iterador a la siguiente posicion de la última de la list de diccionario
    */
  ite_lista end();
  
  /**
    * @brief Metodo end del diccionario
    * @return devuelve un iterador constante a la siguiente posicion de la última de la list de diccionario
    */
  const_ite_lista cend() const;


//OPERADORES

  /**
   * @brief Operador de Asignacion de Diccionario
   * @param origen, el Diccionario que será asignado al que llama al operador
   * @return Diccionario, el propio diccionario que lo llama modificado
   */
  Diccionario& operator=(const Diccionario & origen);

  /**
   * @brief Operador de Igualdad de Diccionario
   * @param dic, un Diccionario con el que será comparado
   * @return bool, true si son iguales, false en el caso contrario
   */
  bool operator==(const Diccionario& dic);

  /**
   * @brief Operador de Desigualdad de Diccionario
   * @param dic, un Diccionario con el que será comparado
   * @return bool, true si no son iguales, false en el caso contrario
   */
  bool operator!=(const Diccionario& dic);

  /**
    * @brief Operador de acceso a la lista de Diccionario
    * @param pos indica la posicion de la lista a la que se quiere acceder
    * @return un valor de referencia con el dato de dicha posición
    */
  string& operator[](const unsigned& pos);

  /**
    * @brief Operador de acceso a la lista de Diccionario
    * @param pos indica la posicion de la lista a la que se quiere acceder
    * @return un valor constante con el dato de dicha posición
    */
  const string& operator[](const unsigned& pos) const;


//FLUJOS

  /**
		* @brief Salida de un Diccionario a ostream
		* @param f stream de salida
		* @param dic Diccionario a escribir
		* @return referencia a flujo de escritura
		*/
	friend ostream& operator<<(ostream& f, const Diccionario& dic);

	/**
		* @brief Entrada de un Diccionario desde istream
		* @param f stream de entrada
		* @param dic Diccionario que recibe los elementos
		* @return referencia a flujo de lectura
		*/
	friend istream& operator>>(istream& f, Diccionario& dic);

};

#endif // Diccionario_h
