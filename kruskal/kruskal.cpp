// UniqueStudio Game Task3:Kruskal Algorithm
// Created By 78ij in 2017.11

#include"kruskal.hpp"

int main(){
    Graph graph;
    graph.vertexcount = 6;
    graph.arcs.push_back(Arc(0,1,6));
    graph.arcs.push_back(Arc(0,2,1));
    graph.arcs.push_back(Arc(0,3,5));
    graph.arcs.push_back(Arc(1,2,5));
    graph.arcs.push_back(Arc(1,4,3));
    graph.arcs.push_back(Arc(2,3,5));
    graph.arcs.push_back(Arc(2,4,6));
    graph.arcs.push_back(Arc(2,5,4));
    graph.arcs.push_back(Arc(3,5,2));
    graph.arcs.push_back(Arc(4,5,6));
    Kruskal(graph);
}
