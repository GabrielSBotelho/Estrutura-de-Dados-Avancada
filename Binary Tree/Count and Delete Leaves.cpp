/*
    Description: 
        1 - Escreva uma função que conte o número de folhas de uma árvore binária. (Function that count the number of leaves in BT)
        2 - Escreva uma função que exclua todas as folhas de uma árvore binária. (Function that delete all leaves of a BT)
        3 - Escreva uma função recursiva que apaga todas as folhas de uma árvore que tenham a chave igual a um valor dado. (Function that delete leaves of BT that have a key equal to a value)
*/ 

int Tree::_count_leaves(Node *node) {
    if(node == nullptr) return 0;
    
    if(node->left == nullptr && node->right == nullptr) return 1;
    else return _count_leaves(node->left) + _count_leaves(node->right);
}

Node* Tree::_delete_leaves(Node *node) { // TODO
    if(node == nullptr) return 0;
    
    if(node->left == nullptr && node->right == nullptr){
        delete node;
        return nullptr;
    }
    
    node->left = _delete_leaves(node->left);
    node->right = _delete_leaves(node->right);
    
    return node;

}

Node* Tree::_delete_leaves_with_value(int key, Node *node) { // TODO
    if(node == nullptr) return 0;
    
    if(node->left == nullptr && node->right == nullptr && node->key == key){
        delete node;    
        return nullptr;    
    }
    
    node->left = _delete_leaves_with_value(key,node->left);
    node->right = _delete_leaves_with_value(key,node->right);
    
    return node;    
}