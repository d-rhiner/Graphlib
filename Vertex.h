#ifndef VERTEX_H
#define VERTEX_H

template <class v_type>
class Vertex {
 public: 
  Vertex() {
    value = 0; 
    indegree = 0; 
    outdegree = 0; 
}
  Vertex(const Vertex&  old) {
	value = old.value;
	indegree = old.indegree;
	outdegree = old.outdegree;
  }
  Vertex(v_type value) {
    this->value = value; 
  }
  /* void set_indeg(int n) {
    indegree++; 
  }
  void set_outdeg(int n) {
    outdegree++; 
    }*/

  void incIn(){
    indegree++;
  }
  v_type getVert() {
    return value;
  }
  template <class U>
  friend bool operator==(const Vertex<U>&, const Vertex<U>&);
  template <class M>
  friend std::ostream &operator<<(std::ostream &, const Vertex<M>&);
  template <class X>
  Vertex<v_type> &operator=(const Vertex<X> &v) {
    value = v.getVert(); 
  //indegree = v.indegree; 
  // outdegree = v.outdegree; 
}

 private: 
  v_type value; 
  int indegree; 
  int outdegree; 
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Vertex<T> &v) {
  os << v.value;
  }
template <class V>
bool operator==(const Vertex<V> &v1, const Vertex<V> &v2) {
  bool equals = (v1.value == v2.value);
  return equals;
}


#endif
