#ifndef GRAPH_H
#define GRAPH_H

#include "Edges.h"
#include "Vertex.h"
#include <vector>
using namespace std;
template <class T>
class Graph{
 public: 
  Graph() {
    directed = false; 
}
  Graph(bool directed) {
    this->directed = directed;
}
  ~Graph() {
	//delete v;
	//delete E;
	//delete v2;
	//delete v1;
	//delete v;
}
 void newVertex(T val) {
   v = new Vertex<T>(val); 
   vertexArr.push_back(*v);
   delete v;
 
}
 void newEdge(T a, T b) {
   v1 = new Vertex<T>(a); 
   v2 = new Vertex<T>(b);
   int test = searchVerts(*v1, *v2);
   int loc1, loc2; 
   switch(test) {
   case 0:
	 //check to see if edge exists between them
	 break;
   case 1:
	 std::cout << "Test = " << test << std::endl;
     loc2 = findVertex(v2);
     *v2 = vertexArr[loc2];
     vertexArr.push_back(*v1);
     break; 
   case 2:
	 std::cout << "Test = " << test << std::endl;
     loc1 = findVertex(v1);
     *v1 = vertexArr[loc1]; 
     vertexArr.push_back(*v2); 
     break; 
   case 3:
	 std::cout << "Test = " << test << std::endl;
     vertexArr.push_back(*v1); 
     vertexArr.push_back(*v2);
	 break;
   default:
     std::cout << "ERROR!" << std::endl;
   }
     
   E = new Edges<T> (*v1, *v2);
   v1->incIn(); 
   v2->incIn();
   edgeArr.push_back(*E);
   delete v1;
   delete v2;
   delete E;
}
 int findVertex(Vertex <T> * v) {
   for (int i = 0; i < vertexArr.size(); i++) 
     if (vertexArr[i] == *v)
       return i;
}

 int searchVerts(Vertex <T> a, Vertex <T> b) {
   bool aExists = false; 
   bool bExists = false;
   std::cout <<"Size of the edge array is now " << edgeArr.size() << std::endl;
   std::cout << "\n size of the vertex array is now " << vertexArr.size() << "\n\n\n";
   //std::cout << vertexArr.size(); 
   for (int i = 0; i < vertexArr.size(); i++) {
     if (vertexArr[i] == a)
       aExists = true;
     if (vertexArr[i] == b)
       bExists = true;
   }
   if (aExists && bExists)
     return 0; 
   if (bExists && !aExists)
     return 1; 
   if (aExists && !bExists) 
     return 2;
   return 3;
}

 void readEdgeArr() {
   for (int i = 0; i < edgeArr.size(); i++)
       cout << edgeArr[i] << endl;
     }
 void readvertArr() {
   for (int i = 0; i < vertexArr.size(); i++)
     std:: cout << vertexArr[i] << endl;
 }

 private: 
  bool directed;
  std::vector <Vertex<T> > vertexArr; 
  std::vector <Edges<T> > edgeArr;
  Vertex <T> *v, *v1, *v2; 
  Edges <T> *E;
};

#endif