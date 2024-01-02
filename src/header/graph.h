#ifndef AIRPORT_GRAPH_H
#define AIRPORT_GRAPH_H


#include <cstddef>
#include <vector>
#include <queue>
#include <cstdint>
#include "airlines.h"
#include "airport.h"
#include "hashTable.h"

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;



template <class T>
class Vertex {
    T info;               
    vector<Edge<T> > adj;
    bool visited = false;
    bool processing;

    void addEdge(Vertex<T> *dest, Airlines w);
    bool removeEdgeTo(Vertex<T> *d);
public:
    Vertex(T in);
    T getInfo() const;
    void setInfo(T in);
    bool isVisited() const;
    void setVisited(bool v);
    bool isProcessing() const;
    void setProcessing(bool p);
    const vector<Edge<T>> &getAdj() const;
    void setAdj(const vector<Edge<T>> &adj);
    friend class Graph<T>;
};

template <class T>
class Edge {
    Vertex<T> * dest;      // destination vertex
    Airlines weight;         // edge weight
public:
    Edge(Vertex<T> *d, Airlines w);
    Vertex<T> *getDest() const;
    void setDest(Vertex<T> *dest);
    const Airlines getWeight() const;
    void setWeight(Airlines weight);
    friend class Graph<T>;
    friend class Vertex<T>;
};

template <class T>
class Graph {
    HashTable<string, Vertex<Airport>*> vertexesHash;
    vector<Vertex<T> *> vertexSet;    // vertex set
    void dfsVisit(Vertex<T> *v,  vector<T> & res) const;
    bool dfsIsDAG(Vertex<T> *v) const;
    int i = 0;
public:
    Vertex<T> *findVertex(Airport &in) const;
    int getNumVertex() const;
    bool addVertex(Airport &in);
    bool removeVertex(const T &in);


    /**
     * @brief adds an edge to a vertex of the graph
     * @param sourc
     * @param dest
     * @param w
     * @return "true" if allows adding a directed edge between two existing vertices
     */
    bool addEdge(T &sourc, T &dest, Airlines w);
    bool removeEdge(const T &sourc, const T &dest);

    /**
     *
     * @return copy of the vertexSet vector which contains pointers to the vertices of the graph
     */
    vector<Vertex<T> * > getVertexSet() const;
    vector<T> dfs() const;
    vector<T> dfs(const T & source) const;
    vector<T> bfs(const T &source) const;

    /**
     *
     * @param source
     * @return vector with the contents of the vertices by bfs order.
     */
    vector<pair<Vertex<T> *, int>> LongestBfs( T source);
    vector<Airport> newBfs( T &source, T &dest) const;

    vector<Airport> newBfs( T &source, T &dest, vector<Edge<T>> edges) const;


    /**
     *
     * @param source
     * @param dest
     * @param edges
     * @return vector containing the valid paths found
     */
    vector<vector<Airport>> newBfs(T &source,T &dest, vector<string> edges) const;

};


template <class T>
vector<T> Graph<T>::dfs() const {
    vector<T> res;
    for (auto v : vertexSet)
        v->visited = false;
    for (auto v : vertexSet)
        if (! v->visited)
            dfsVisit(v, res);
    return res;
}
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, vector<T> & res) const {
    v->visited = true;
    res.push_back(v->info);
    for (auto & e : v->adj) {
        auto w = e.dest;
        if ( ! w->visited)
            dfsVisit(w, res);
    }
}


/****************** BFS ********************/
/*
 * Performs a breadth-first search (bfs) in a graph (this), starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by bfs order.
 */
template <class T>
vector<pair<Vertex<T> *, int>> Graph<T>::LongestBfs( T source)  {
    vector<pair<Vertex<T> *, int>> res;
    auto s = findVertex(source);
    queue<pair<Vertex<T> *, int>> q;
    for (auto f : vertexSet)
        f->visited = false;
    q.push({s,0});
    s->visited = true;
    while (!q.empty()) {
        auto v = q.front();
        for (auto & e : v.first->adj) {
            auto w = e.dest;
            if ( ! w->visited ) {
                q.push({w, v.second + 1});
                w->visited = true;
            }
        }
        res.push_back(q.front());
        q.pop();
    }
    return  res;
}


template <class T>
vector<vector<Airport>> Graph<T>::newBfs( T & source, T & dest, vector<string> edges) const {
    vector<vector<Airport>> res;
    res.clear();
    int stops = INT32_MAX;
    int flag = 0;
    auto s = findVertex(source);
    auto d = findVertex(dest);
    queue<pair<Vertex<T> *, vector<Airport>>> q;
    for (auto f : vertexSet)
        f->visited = false;
    q.push({s,{}});
    s->visited = true;
    while (!q.empty()) {
        auto v = q.front();
        v.first->visited = true;
        if (v.second.size() > stops){
            return res;
        }
        q.pop();
        v.second.push_back(v.first->info);
        if (v.first == d) {
            if (v.second.size() < stops){
                res.clear();
                res.push_back(v.second);
                stops = v.second.size();
            }
            else if (v.second.size() == stops){
                res.push_back(v.second);
            }
        }
        for (auto &e: v.first->adj) {
            flag = 0;
            for (auto s: edges) {
                if (e.weight.getCode() == s) {
                    flag = 1;
                }
            }
            if (flag == 0) {
                auto w = e.dest;
                if (!w->visited) {
                    q.push({w, v.second});
                }
            }
            }
        }
    }


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template <class T>
Edge<T>::Edge(Vertex<T> *d, Airlines w): dest(d), weight(w) {}


template <class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
    return vertexSet;
}

template<class T>
T Vertex<T>::getInfo() const {
    return info;
}

template<class T>
void Vertex<T>::setInfo(T in) {
    Vertex::info = in;
}

template<class T>
bool Vertex<T>::isProcessing() const {
    return processing;
}

template<class T>
void Vertex<T>::setProcessing(bool p) {
    Vertex::processing = p;
}

template<class T>
Vertex<T> *Edge<T>::getDest() const {
    return dest;
}

template<class T>
void Edge<T>::setDest(Vertex<T> *d) {
    Edge::dest = d;
}

template<class T>
const Airlines Edge<T>::getWeight() const {
    return weight;
}

template<class T>
void Edge<T>::setWeight(Airlines weight) {
    Edge::weight = weight;
}
template <class T>
Vertex<T> * Graph<T>::findVertex(Airport &in) const {
    return vertexesHash.get(in.getCode());
}

template <class T>
bool Vertex<T>::isVisited() const {
    return visited;
}

template <class T>
void Vertex<T>::setVisited(bool v) {
    Vertex::visited = v;
}

template<class T>
const vector<Edge<T>> &Vertex<T>::getAdj() const {
    return adj;
}

template <class T>
void Vertex<T>::setAdj(const vector<Edge<T>> &adj) {
    Vertex::adj = adj;
}
template <class T>
bool Graph<T>::addVertex(Airport &in) {
    Vertex<Airport>* a = new Vertex<T>(in);
    vertexesHash.insert(in.getCode(), a);
    vertexSet.push_back(a);
    i++;
    return true;
}
template <class T>
bool Graph<T>::addEdge( T &sourc, T &dest, Airlines w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2,w);
    return true;
}
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, Airlines w) {
    adj.push_back(Edge<T>(d, w));
}
template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    return v1->removeEdgeTo(v2);
}
template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
    for (auto it = adj.begin(); it != adj.end(); it++)
        if (it->dest  == d) {
            adj.erase(it);
            return true;
        }
    return false;
}
template <class T>
bool Graph<T>::removeVertex(const T &in) {
    for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
        if ((*it)->info  == in) {
            auto v = *it;
            vertexSet.erase(it);
            for (auto u : vertexSet)
                u->removeEdgeTo(v);
            delete v;
            return true;
        }
    return false;
}

#endif //AIRPORT_GRAPH_H
