#ifndef EDGES_H
#define EDGES_H

#include <iostream>
#include "Vertex.h"

template <class v_type>
class Edges {
 public:
  Edges(const Edges & old) {
	a = old.a;
	b = old.b;
  }
  Edges(Vertex <v_type> a, Vertex <v_type> b) {
    this->a = a; 
    this->b = b; 
  }
  template <class T>
  friend std::ostream &operator<<(std::ostream &, const Edges<T>&); 
 private: 
  Vertex <v_type> a; 
  Vertex <v_type> b; 
};

template <class U>
std::ostream &operator<<(std::ostream &os, const Edges<U> &e) {
  os << e.a << '-' << e.b << '\n'; 
}
#endif
