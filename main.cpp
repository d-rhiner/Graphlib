#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
  Graph <char> G;
  G.newEdge('a','b');
  G.newEdge('b','c');
  G.newEdge('c','a');
  G.newEdge('a','b');
  G.newEdge('c','d'); 
  G.readEdgeArr();
}