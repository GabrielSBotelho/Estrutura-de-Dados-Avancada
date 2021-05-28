/*
    Description: 
        1 - Escreva uma função não-recursiva que calcula o número de nós de uma árvore binária dada como entrada. 
        (Iterative function that return the total number of nodes in BT)
*/ 

int Tree::_size_iterativo(Node *node) { // TODO
    
    int counter = 0;
    
    std::stack<Node*> p; 
    p.push(node); 
    
    while (p.size() > 0){
        
        Node * no = p.top(); 
        p.pop(); 
        
        if (no != nullptr){
            counter = 1 + counter;
            
            p.push(no->left); 
            p.push(no->right); 
        }
    }
    
    std::cout<<counter<<std::endl;
    
}