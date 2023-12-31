//Esteban Sanchez Cardona - C.C 1089379280
//Fecha: 30/08/2023 
//Docente: Gustavo Adolfo Gutierrez Sabogal
//Universidad Tecnologica de Pereira
//Facultad de Ingenieria de Sistemas y Computacion

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

template<typename T>
class Vector {
private:
  unsigned int capacity;  // Capacidad máxima del vector
  unsigned int sz;        // Tamaño actual del vector
  T *storage;             // Almacenamiento de los elementos

public:
  Vector() {
    capacity = 5;
    sz = 0;
    storage = new T[capacity];  // Crear un arreglo dinámico para almacenar elementos
  }

  Vector(unsigned int count, const T& value){
    capacity = count;
    sz = count;
    storage = new T[capacity];
    for(unsigned int i = 0; i < count; i++){
      storage[i] = value;  // Inicializar el vector con 'count' elementos de 'value'
    }
  }

  unsigned int size() { return sz; }  // Devuelve el tamaño actual del vector

private:  
  void resize() {
    int newcapacity = sz * 2;
    T *newstorage = new T[newcapacity];  // Crear un nuevo arreglo con el doble de capacidad
    for (int i = 0; i < sz; i++) {
      newstorage[i] = storage[i];  // Copiar los elementos al nuevo arreglo
    }
    delete[] storage;  // Liberar la memoria del antiguo arreglo
    storage = newstorage;
    capacity = newcapacity;
  }

public:
  void push_back(int e) {
    if(sz == capacity) {
      resize();  // Redimensionar si el vector está lleno
    }
    storage[sz] = e;  // Agregar el elemento al final del vector
    sz++;
  }

  void line(){
    cout << "<--------------------------------->" << endl;
  }
  void print() { // Imprimir el contenido del vector (con size) 
    if (size() == 0) {
      cout << "<>" << endl;
    } else {
      cout << "<";
      for (int i = 0; i < size(); i++) {
        cout << " " << storage[i];  
      }
      cout << ">" << endl;
    }
  }

  void printC(){ // Imprimir el contenido del vector (con capacity)
    if (size() == 0) {
      cout << "<>" << endl;
    } else {
      cout << "<";
      for (int i = 0; i < capacity; i++) {
        cout << " " << storage[i];  
      }
      cout << ">" << endl;
    }
  }

    // EJERCICIO 1):
  int waste(){ //Calcula y muestra cuántos espacios sin usar hay en el vector.
    if(sz < capacity){
      int espacios = capacity - sz;
      cout << "1) Hay " << espacios << " espacios sin utilizar" << endl;
      return espacios;
    }
    else{
      cout << "1) No hay posiciones sin utilizar" << endl;
    }
  }

    // EJERCICIO 2):
  void pop_back(){ //Elimina el último elemento del vector.
    if(sz == 0){
      cout << "2) No hay elementos en el vector" << endl;
    }
    else{
      cout << "Vector original:" << endl;
      print();
      sz--;
      cout << "2) Se elimino el ultimo elemento" << endl;
      print();
    }
  }

    // EJERCICIO 3):
  T& push_front(int e){ //Agrega un elemento e al inicio del vector.
    if(sz == capacity){
        cout << "Resize - line 110" << endl;
        resize();
    }
    for(int i = sz; i > 0; i--){
      storage[i] = storage[i-1];  // Desplazar los elementos a la derecha
    }
    storage[0] = e;  // Agregar el elemento al inicio
    sz++;
    cout << "3) Se agrego un elemento al inicio" << endl;
    print();
  }

    //EJERCICIO 4):
  void pop_front(){ //Elimina el primer elemento del vector.
    if(sz == 0){
      cout << "4) no hay elementos en el vector" << endl;
    }
    else{
      cout << "4) Vector original:" << endl;
      print();
      for( int i = 0; i < sz; i++){
        storage[i] = storage[i+1];  // Desplazar los elementos a la izquierda
      }
      sz--;
      cout << "4) Se elimino el primer elemento" << endl;
      print();
    }
  }

    //EJERCICIO 5):
    T& insert(unsigned int p, int e){ //Inserta un elemento e en la posición p.
    if (p > capacity){
        cout << "Resize - line 142" << endl;
        resizeONE(sz + p);  // Redimensionar si la posición excede la capacidad
        for (int i = sz; i <= p; i++){
            storage[i] = 0; // se le asigna un valor nulo a los elementos del vector
        }
    }
    for(int i = sz; i > p; i--){
      storage[i] = storage[i-1];  // Desplazar los elementos a la derecha desde 'p'
    }
    storage[p] = e;  // Insertar el elemento en la posición 'p'
    sz++;
    for(int i = 0; sz <= p; i++ ){
        sz++;
        }
    cout << "5) Se agrego un elemento en la posicion " << p << endl;
    print();
  }

    //EJERCICIO 6):
  T& remove(unsigned int p){ //Elimina el elemento en la posición p.
    if(p > capacity){
      cout << "6) No se puede eliminar el elemento porque no esta en el arreglo" << endl; 
    }
    else{
      cout << "Posicion a eliminar: " << p << endl;
      cout << "Vector Original:" <<  endl;
      print();
      int erase;
      for(int i = 0; i < capacity; i++){
        if(i == p){
          erase = p;
          storage[i]= 0;  // Marcar el elemento en la posición 'p' como eliminado
        }
        if(i > p){
          storage[i-1]= storage[i];  // Desplazar los elementos a la izquierda desde 'p'
        }
      }
      sz--;
      cout << "6) Vector con el elemento eliminado" << endl;
      print();
    }
  }

    //EJERCICIO 7):
  void shrink_to_fit(){ //Reduce la capacidad del vector para que coincida con el tamaño.
    int unused = capacity - sz;
    cout << "7) Vector Original" << endl;
    print();
    for(int i = 0; i < unused; i++){
      capacity--;  // Reducir la capacidad del vector
    }
    cout << "Vector Completo:" << endl;
    printC();
    cout << "7) Eliminando espacios sin utilizar en el vector" << endl;
    print();
  }

    //EJERCICIO 8):
  T& at(unsigned int pos){
    cout << "8) " << endl;
    if(pos >= sz){
      cout << "Intento acceder a la posicion " << pos << ", Esta posicion no esta en el rango del arreglo." << endl;
    }
    else{
      cout << "En la posicion " << pos << " : " << storage[pos] << endl;
      return storage[pos];  // Devolver el elemento en la posición 'pos'
    }
  }

  void resizeONE(int a) {
    int newcapacity = capacity; 
    while (newcapacity <= a) {
      newcapacity *= 2;
    }
    T *newstorage = new T[newcapacity];
    for (int i = 0; i < sz; i++) {
      newstorage[i] = storage[i];
    }
    delete[] storage;
    storage = newstorage;
    capacity = newcapacity;
  }

    //EJERCICIO 9):
  void insert_Vec(Vector<T> v, unsigned int pos){
    cout << "9) " << endl;
    if(pos > sz){
      cout << "Intento acceder a la posicion "<< pos << ", Esta posicion no esta en el rango del arreglo." << endl;
      return;
    }
    if(v.size()+sz > capacity){
      resizeONE(v.size() + sz);  // Redimensionar si no hay suficiente capacidad
    }
    cout << "Posicion donde se insertará el vector :" << pos << endl;
    cout << "Vector Original" << endl;
    print();
    cout << "Vector a insertar" << endl;
    v.print();

    for(int i = sz-1; i >= pos; i--){
      storage[i + v.size()] = storage[i];  // Desplazar elementos para hacer espacio para el nuevo vector
    }

    for(int i = 0; i < v.size(); i++){
      storage[pos + i] = v.storage[i];  // Insertar elementos del nuevo vector en la posición 'pos'
    }

    sz += v.size();  // Actualizar el tamaño del vector
    cout << "Se inserto el vector en la posicion " << pos << endl;
    print();
  }
};

int main () {
  Vector <int> b;
  for(unsigned int i = 0; i < 10; i++){
    b.push_back(i);
  }

  b.line();
  cout << "Vector Original:" << endl;
  b.print();
  b.line();
  
  // 1:
  b.waste();
  b.line();
  
  // 2:
  b.pop_back();
  b.line();
    
  // 3:
  b.push_front(222);
  b.line();

  // 4:
  b.pop_front();
  b.line();

  // 5:
  b.insert(8, 888);
  b.line();

  // 6;
  b.remove(2);
  b.line();

  // 7:
  b.shrink_to_fit();
  b.line();

  // 8:
  b.at(17);
  b.line();

  // 9:
  Vector <int> d;
  for(unsigned int i = 0; i < 5; i++){
    d.push_back(i+80);
  }
  b.insert_Vec(d, 8);
  b.line();

  return 0;
}
