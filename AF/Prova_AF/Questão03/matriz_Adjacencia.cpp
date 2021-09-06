#include <vector>
#include <iostream>
using namespace std;

class Graph{
	public:
	vector<vector<int>> node;
	int size;
	
	Graph(int size){
		if (size <= 0){
			return;
		}
		
		node.resize(size);
		
		for (int i = 0; i < size; i++){
			node[i].resize(size);
			for (int j = 0; j < size; j++){
				node[i][j] = 0;
			}
		}
		
		this->size = size;
	}
	
	void addEdge(int start, int end){
		this->node[start][end] = 1;
	}
	
	void transposedNode(){
		if (this->size > 0){
			for (int row = 0; row < this->size; row++){
				for (int col = 1; col < this->size; col++){
					if (this->node[row][col] == true){
				        cout << " " << col << " " << row << endl;
					}
				}
			}
		}
	}
	
};

int main(){
    int N;
	int u;
	int v;

    cin>>N;
    
	Graph *g = new Graph(N);
	
	for(int i=0; i<N; i++){
	    cin >> u >> v;
	    g->addEdge(u,v);
	}
	
	g->transposedNode();

	return 0;
}