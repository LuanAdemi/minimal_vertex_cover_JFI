#!/usr/bin/python
#-*- coding:utf-8 -*-

import sys

def solve():
  # Löse das Problem hier
  pass

def initialize(n, m):
  # Initialisiere Graph-Datenstruktur hier
  # n ist die Anzahl and Knoten und m ist die Anzahl an Kanten
  pass

def addEdge(u, v):
  # Füge Kante der Graph-Datenstruktur hier hinzu
  # Achtung: Knoten sind von 1 bis N nummeriert
  pass

def readGraph(graph_file):
  input = open(graph_file, "r")
  for line in input:
    if line[0] == 'c':
      continue
    elif line[0] == 'p':
      # Header
      tokens = line.split()
      n = int(tokens[2])
      m = int(tokens[3])
      initialize(n, m)
    else:
      # Kante
      tokens = line.split()
      u = int(tokens[0])
      v = int(tokens[1])
      addEdge(u, v)
  input.close()

# Ausführen: python main.py <graph-file>

if len(sys.argv) != 2:
  sys.exit("Invalid number of arguments")

graph_file = sys.argv[1]
readGraph(graph_file)

solve()
