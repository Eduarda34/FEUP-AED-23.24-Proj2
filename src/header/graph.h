#ifndef AIRPORT_GRAPH_H
#define AIRPORT_GRAPH_H


#include <cstddef>
#include <vector>
#include <queue>
#include "airlines.h"

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;


/****************** Provided structures  ********************/

template <class T>
class Vertex {
    T info;                // contents
    vector<Edge<T> > adj;  // list of outgoing edges
    bool visited = false;          // auxiliary field
    bool processing;       // auxiliary field

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
    vector<Vertex<T> *> vertexSet;    // vertex set
    void dfsVisit(Vertex<T> *v,  vector<T> & res) const;
    bool dfsIsDAG(Vertex<T> *v) const;
public:
    Vertex<T> *findVertex(const T &in) const;
    int getNumVertex() const;
    bool addVertex(const T &in);
    bool removeVertex(const T &in);
    bool addEdge(const T &sourc, const T &dest, Airlines w);
    bool removeEdge(const T &sourc, const T &dest);
    vector<Vertex<T> * > getVertexSet() const;
    vector<T> dfs() const;
    vector<T> dfs(const T & source) const;
    vector<T> bfs(const T &source) const;
    vector<pair<Vertex<T> *, int>> LongestBfs( T source);
    vector<Airport> newBfs(const T &source, const T &dest) const;
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
vector<Airport> Graph<T>::newBfs(const T & source, const T & dest) const {
    auto s = findVertex(source);
    auto d = findVertex(dest);
    queue<pair<Vertex<T> *, vector<Airport>>> q;
    for (auto f : vertexSet)
        f->visited = false;
    vector<Airport> res;
    q.push({s,res});
    s->visited = true;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        v.second.push_back(v.first->info);
        if (v.first == d) {
            return v.second;
        }
        for (auto & e : v.first->adj) {
            auto w = e.dest;
            if ( ! w->visited ) {
                q.push({w, v.second});
                w->visited = true;
            }
        }
    }
}

/****************** Provided constructors and functions ********************/

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
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
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
bool Graph<T>::addVertex(const T &in) {
    if ( findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, Airlines w) {
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
