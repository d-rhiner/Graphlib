#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
  Graph <int> G;
  G.newEdge(1,2);
  G.newEdge(2,3);
  G.newEdge(3,4);
  G.newEdge(4,1);
  G.readvertArr();
}
