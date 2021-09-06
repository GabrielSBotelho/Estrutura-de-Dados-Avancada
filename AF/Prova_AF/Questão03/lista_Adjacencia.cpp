#include <vector>
#include <iostream>
using namespace std;

struct Edge{
  int node, src, dest;
};

typedef pair < int, int > Pair;

class Graph{
    public:
        vector<vector<Pair>> adjList;
    
        Graph (vector < Edge > const &edges, int N){
            adjList.resize (N);
        
            for (auto & edge:edges){
                int node = edge.node;
                int src = edge.src;
                int dest = edge.dest;
                
                adjList[node].push_back (make_pair (dest, src));  
            }
        }
};

void printGraph (Graph const &graph, int N){
    for (int i = 0; i < N - 1; i++){
        for (Pair v:graph.adjList[i]){
            cout << v.first << " " << v.second;
        }
        cout << endl;
    }
}

void TransposedGraph (Graph const &graph, int N){
    for (int i = 0; i < N - 1; i++){
        for (Pair v : graph.adjList[i]){
            int aux1 = v.first;
            int aux2 = v.second;
            
            v.first  = aux2;
            v.second = aux1;
        }
    }
}


int main (){
    int N;
    int u;
    int v;

    std::cin >> N;

    vector < Edge > edges = {};

    for (int a = 0; a < N; a++){
        cin >> u >> v;
        edges.push_back ({a, u, v});
    }


    Graph graph (edges, N);
    TransposedGraph(graph, N);
    printGraph (graph, N);

    return 0;
}
