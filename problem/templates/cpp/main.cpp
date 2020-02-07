#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

void solve() {
  // Löse das Problem hier
}

void initialize(const int n, const int m) {
  // Initialisiere Graph-Datenstruktur hier
  // n ist die Anzahl and Knoten und m ist die Anzahl an Kanten
}

void addEdge(const int u, const int v) {
  // Füge Kante der Graph-Datenstruktur hier hinzu
  // Achtung: Knoten sind von 1 bis N nummeriert
}

void readGraph(const std::string& graph_file) {
  std::ifstream input(graph_file);
  std::string line;
  while ( std::getline(input, line, ' ') ) {
    if ( line[0] == 'c' ) {
      // Skip comments
      std::getline(input, line);
      continue;
    } else if ( line[0] == 'p' ) {
      // Header
      std::getline(input, line, ' ');
      std::getline(input, line, ' ');
      const int n = std::stoi(line);
      std::getline(input, line);
      const int m = std::stoi(line);
      initialize(n, m);
    } else {
      // Kante
      const int u = std::stoi(line);
      std::getline(input, line);
      const int v = std::stoi(line);
      addEdge(u, v);
    }
  }
}

// Kompilieren: g++ -std=c++11 -O3 main.cpp
// Ausführen: ./a.out <graph-file>
int main(int argc, char *argv[])
{
  if ( argc != 2 ) {
    std::cerr << "Invalid number of arguments" << std::endl;
    return -1;
  }

  std::string graph_file(argv[1]);
  readGraph(graph_file);

  solve();

  return 0;
}