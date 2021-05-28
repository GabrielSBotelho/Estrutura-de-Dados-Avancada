/*
    Description: 
        1 - Escreva uma função que calcule a altura uma árvore binária. (Write a function that return the height of a binary tree)
        2 - Escreva uma função que calcule o número de nós de uma árvore binária. (Write a function that return the total of nodes of a binary tree)
*/ 

int Tree::_size(Node *node) { // TODO
    if(node == nullptr) return 0;
    
    return 1 + _size(node->left) + _size(node->right);
}

int Tree::_height(Node *node) { // TODO
    if(node == nullptr) return 0;
    
    int left_Height = _height(node->left);
    int right_Height = _height(node->right);
    
    return std::max(left_Height, right_Height) + 1;
}
