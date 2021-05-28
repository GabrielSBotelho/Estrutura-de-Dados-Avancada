/*
    Description: 
        1 - Escreva uma função que devolva a soma de todas as chaves de uma árvore binária. (Sum of all node keys)
        2 - Escreva uma função que devolva o valor da menor chave de uma árvore binária. (Small value in a BT)
        3 - Escreva uma função que conte o número de nós internos de uma árvore binária. (Count the total internal nodes)
        4 - Escreva uma função que retorne a quantidade de nós de uma árvore binária que possuem apenas um filho. (Number of node that have exactly one child)
*/ 

int Tree::_sum_keys(Node *node) { 
    if(node == nullptr) return 0;
    else return node->key + _sum_keys(node->left) + _sum_keys(node->right);
}

int Tree::_min_key(Node *node) { 
    if(node == nullptr) return 0;
    
    int min_value = node->key;
    if(node->left != nullptr) min_value = std::min(min_value, _min_key(node->left));
    if(node->right != nullptr) min_value = std::min(min_value, _min_key(node->right));

    return min_value;
}
    
int Tree::_total_internal_nodes(Node *node) {
    if(node == nullptr) return 0;
    
    if(node->left != nullptr || node->right != nullptr){
        return 1 + _total_internal_nodes(node->left) + _total_internal_nodes(node->right);
    }
}

int Tree::_um_filho(Node *node) { 
    if(node == nullptr) return 0;
    
    int one_child = 0;
    if((node->left != nullptr && node->right == nullptr) || (node->left == nullptr && node->right != nullptr)){
        one_child++;
    }
    one_child = one_child +_um_filho(node->left) + _um_filho(node->right);
    
    return one_child;
}