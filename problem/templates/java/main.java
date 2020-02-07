import java.lang.*;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

class Solver
{

  private static void solve() {
    // Löse das Problem hier
  }

  private static void initialize(int n, int m) {
    // Initialisiere Graph-Datenstruktur hier
    // n ist die Anzahl and Knoten und m ist die Anzahl an Kanten
  }

  private static void addEdge(int u, int v) {
    // Füge Kante der Graph-Datenstruktur hier hinzu
    // Achtung: Knoten sind von 1 bis N nummeriert
  }

  private static void readGraph(String graph_file) {
    try ( BufferedReader br = Files.newBufferedReader(Paths.get(graph_file)) ) {
      String line;
      while ( ( line = br.readLine() ) != null ) {
        if ( line.charAt(0) == 'c' ) {
          // Skip comments
          continue;
        } else if ( line.charAt(0) == 'p' ) {
          // Header
          StringTokenizer tokenizer = new StringTokenizer(line, " ");
          tokenizer.nextToken();
          tokenizer.nextToken();
          int n = Integer.parseInt(tokenizer.nextToken());
          int m = Integer.parseInt(tokenizer.nextToken());
          initialize(n, m);
        } else {
          // Kante
          StringTokenizer tokenizer = new StringTokenizer(line, " ");
          int u = Integer.parseInt(tokenizer.nextToken());
          int v = Integer.parseInt(tokenizer.nextToken());
          addEdge(u, v);
        }
      }
    } catch (IOException e) {
      System.err.format("IOException: %s%n", e);
      System.exit(-1);
    }
  }

  // Kompilieren: javac main.java
  // Ausführen: java Solver <graph-file>
  public static void main (String args[])
  {
    if ( args.length != 1 ) {
      System.out.println("Invalid number of arguments");
      System.exit(-1);
    }

    String graph_file = args[0];
    readGraph(graph_file);

    solve();
  }
}