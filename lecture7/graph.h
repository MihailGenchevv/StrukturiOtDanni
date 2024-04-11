#pragma once 

#include <unordered_map>
#include <map>
template <class Verteces, class Costs>
class Graph { 

    public:

    void addVertex(const Verteces&);
    void addEdge(const Verteces&, const Verteces&, const Costs&);

    bool hasVertex(const Verteces&) const;
    bool hasEdge(const Verteces&, const Verteces&) const;

    const std::map<Verteces,Costs>& operator[] (const Verteces&) const;


    private:
    using OriginalIter = typename std::unordered_map<Verteces, std::map<Verteces, Costs>>::const_iterator;


    public:

    class Iterator {
        public:
        Iterator(const OriginalIter&);
        Iterator& operator++();
        bool operator !=(const Iterator&);

        Verteces operator*();

        private:

        OriginalIter it;

    };

    Iterator begin();
    Iterator end();

    private:
    std::unordered_map<Verteces, std::map<Verteces, Costs>> graph;



}