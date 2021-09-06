#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "DisjointSets.h"

using namespace std;

int main(){
	int N;
	int elem;
	int first;
    int second;
	
	cin >> N;

	DisjointSets *ds = new DisjointSets(N);

	while(cin >> first && cin >> second) {		
		if(first == 0 && second == 0){
			break;
		}else{
			ds->unionSets(first, second);
		}
	}

	while(cin>>elem){
		ds->printset(elem);
	}	

	return 0;
}