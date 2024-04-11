#ifndef __BINTREE_H
#define __BINTREE_H

#include <iostream>


template <class T>
class BinTree {

    public:
    BinTree();

    void add (const T&, const char*);

    void printall(std::ostream&);

    T operator[](const char*) const;
    void set(const T &x, const char *trace);

    bool member(const T&) const;

    bool operator== (const BinTree<T>&) const;

    void toScheme(std::ostream&);
    void fromScheme(std::ostream&);

    void insertOrdered(const T&);

    ~BinTree();

    private:
    struct node 
    {
        T data;
        node *left, *right;
    };

    node *root;

    void printhelp(std::ostream&, node*);
    void toScheme(std::ostream&, node*);
    node* locate(const char*) const;

    bool memberhelp(const T&, node*) const;

    void deleteTree(node*);

    bool equalTrees(node*, node*);

    node* readScheme(std::istream&);

    void insertOrdered(const T&, node*);

    public:

    class Position {
        public:

        Position(node*&);
        Position left() const;
        Position right() const;

        bool empty() const;
        void set(const T&);
        T get() const;
        private:

        node *current;

    };

    Position rootPoosition();
};



#endif