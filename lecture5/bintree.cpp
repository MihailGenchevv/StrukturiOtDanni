#ifndef __BINTREE_CPP
#define __BINTREE_CPP

#include "bintree.h"
#include <cassert>

template <class T>
BinTree<T>::BinTree() : root(nullptr) {

}

template <class T>
void BinTree<T>::add(const T &x, const char *trace) {

    if (root == nullptr || trace[0] == 0) {
        assert(root == nullptr && trace[0] == 0);
        root = new BinTree<T>::node {x, nullptr, nullptr};
        return;
    }

    BinTree<T>::node *current = root;

    while (current != nullptr && trace[1] != 0) {

        assert(trace[0] == 'L' || trace[0] == 'R');
        if (trace[0] == 'L'){
            current = current->left;
        } else {
            current = current->right;
        }
        ++trace;
    }

    assert(current != nullptr);
    assert(trace[0] == 'L' || trace[0] == 'R');

    if (trace[0] == 'L'){
        assert(current->left == nullptr);
        current->left = new node{x, nullptr, nullptr};
    } else {
        assert(current->right == nullptr);
        current->right = new node{x, nullptr, nullptr};
    }


}

template <class T>
void BinTree<T>::printall(std::ostream &out) {

    printhelp(out, root);

} 

template <class T>
void BinTree<T>::printhelp(std::ostream &out, BinTree<T>::node *current) {
    if (current == nullptr) {
        return;
    }
    printhelp(out, current->left);
    out << (long) current << "[label\"" << current->data << "\"]\n";

    if (current->left != nullptr) {
        out << (long)current << "->" << (long)(current->left) << std::endl;
    }
    if (current->right != nullptr) {
        out << (long)current << "->" << (long)(current->right) << std::endl;
    }
    printhelp(out, current->right);
} 

template <class T>
T BinTree<T>::operator[](const char *trace) const {
    return locate(trace)->data;
}

template <class T> 
void BinTree<T>::set(const T &x, const char *trace) {

    locate(trace)->data = x;

}

template <class T>
typename BinTree<T>::node* BinTree<T>::locate(const char *trace)const {
    assert( root != nullptr );
    
    if (trace[0] == 0) {
        return root;
    }

    BinTree<T>::node *current = root;
    while (current != nullptr && trace[0] != 0) {
        assert(trace[0] == 'L' || trace[0] == 'R');

        if (trace[0] == 'L'){
            current = current->left;
        } else {
            current = current->right;
        }
        ++trace;
    }

    assert(current != nullptr);

    return current; 
}


template <class T>
bool BinTree<T>::member(const T &x) const{
    return memberhelp(x, root);
}

template <class T>
bool BinTree<T>::memberhelp(const T &x, node *current) const {

    return current != nullptr && 
            (
                x == current->data ||
                memberhelp(x, current->left) ||
                memberhelp(x, current->right)
            );

    // if (current == nullptr) {
    //     return false;
    // }

    // if (curent->data == x) {
    //     return true;
    // }

    // if (memberhelp(x, current->left)){

    //     return true;
    // }
    
    // if (memberhelp(x, current->right)){
    //     return true;
    // }
    // return false;
}
template <class T>
void BinTree<T>::toScheme(std::ostream &out){

    this->toScheme(out, root);
}


template <class T>
void BinTree<T>::toScheme(std::ostream &out, BinTree<T>::node *current) {

    if (current == nullptr) {
        out << "()";
        return;
    }

    out << "("
        << current->data
        << " ";

    toScheme(out, current->left);
    toScheme(out, current->right);

    out << ")";

}



template <class T>
void BinTree<T>::deleteTree (node *current) {
    if (current == nullptr) {
        return;
    }

    deleteTree(current->left);
    deleteTree(current->right);

    delete current;
}

template <class T>
BinTree<T>::~BinTree () {

    deleteTree(root);
}


template <class T>
bool BinTree<T>::operator==(const BinTree<T> &other){

    return equalTrees(root, other.root);

}


template <class T>
bool BinTree<T>::equalTrees(BinTree<T>::node* root1, BinTree<T>::node* root2){

    if (root1 == nullptr || root2 == nullptr {

        return root1 == nullptr && root2 == nullptr;
    }

    if (root1->data != root2->data) {
        return false;
    }


    return equalTrees(root1->left, root2->left) && 
            equalTrees(root1->right, root2->right);
}


template <class T>
void BinTree<T>::fromScheme(std::istream &in) {
    deleteTree(root);

    root = readTree(in);
}
template <class T>
BinTree<T>::node* BinTree<T>::readScheme(std::istream &int){

    assert(in.get() == '(');

    if (in.peek() == ')') {
        //prazno durvo
        in.get();
        return nullptr;
    }

    T data;

    in >> data;

    BinTree<T>::node *left = readScheme(in);
    BinTree<T>::node *right = readScheme(in);

    assert(in.get() == ')');

    return new BinTree<T>::node {data, left, right};
}



template <class T>
void BinTree<T>::insertOrdered(const T &x){

    insertOrdered(x, root);

}


template <class T>
void BinTree<T>::insertOrdered(const T &x, node *&current) {

    if (current == nullptr) {
        current = new node {x, nullptr, nullptr};
    }

    if (x <= current->data) {
        insertOrdered(x, current->left);
    } else {
        insertOrdered(x, current->right);
    }

}


template <class T>
BinTree<T>::Position::Position(node *&_current) : current(_current) {

}

template <class T>
typename BinTree<T>::Position BinTree<T>::Position::left() const {
    assert( current != nullptr );
    return Position(current->left);
}

template <class T>
typename BinTree<T>::Position BinTree<T>::Position::right() const  {
    assert( current != nullptr );
    return Position(current->right);
}

typename <class T>
bool BinTree<T>::Position::empty() const {

    return current == nullptr;
}


typename <class T>
void BinTree<T>::Position::set(const T &x) {

    if (current != nullptr) {
        current->data = x;
    } else {
        current = new node (x , nullptr, nullptr);

    }

}

typename <class T>
T BinTree<T>::Position::get() const {

    assert( current != nullptr );
    return current->data;

}


typename <class T>
BinTree<T>::Position BinTree<T>::rootPosition() {

    return BinTree<T>::Position(root);
}



#endif