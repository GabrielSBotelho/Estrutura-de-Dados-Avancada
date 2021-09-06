#ifndef DSETS_H
#define DSETS_H
#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

/**
 * Implementation of the disjoint-sets data structure
 * using path compression and union by rank
 */
class DisjointSets {
public:
    explicit DisjointSets( int numElements );
    int findSet( int x );
    void unionSets( int x, int y );
    void printset(const int elem );

private:
    struct Node { int parent; int rank; int next;};
    std::vector<Node> sets;

};

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */ 
DisjointSets::DisjointSets( int numElements ) {
    sets.resize( numElements );
    for( int i = 0; i < numElements; ++i ) {
        sets[i].parent = i;
        sets[i].rank = 1;
        sets[i].next = i;
    }
}

/**
 * Performs a find-Set with path compression.
 * Returns the representative of the set containing x.
 */
int DisjointSets::findSet( int x ) {
    if ( sets[x].parent != x )
        sets[x].parent = findSet( sets[x].parent );
    return sets[x].parent;
}

/**
 * Union of two disjoint sets using union by rank
 */
void DisjointSets::unionSets( int x, int y ) {
    int xroot = findSet(x);
    int yroot = findSet(y);

    if( sets[xroot].rank < sets[yroot].rank ){
        sets[xroot].parent = yroot;
        
        int curr = sets[yroot].next;
        sets[yroot].next = sets[xroot].next;
        sets[xroot].next = curr;

        if(sets[xroot].rank == sets[yroot].rank){
            sets[yroot].rank++;
        }
    }else{
        sets[yroot].parent = xroot;

        int curr = sets[xroot].next;
        sets[xroot].next = sets[yroot].next;
        sets[yroot].next = curr;
    }
}

/*
 * Print all elements in a set
*/
void DisjointSets::printset(const int elem){
        int set1 = findSet(elem);
        int aux;
        
        aux = set1;

        std::cout << set1 << " ";
        set1 = sets[set1].next;

        do{
            std::cout << set1 << " ";
            set1 = sets[set1].next;
        }while(aux != set1);

        std::cout<<"\n";
}

#endif