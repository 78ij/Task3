// UniqueStudio Game Task3:Kruskal Algorithm
// Created By 78ij in 2017.11

#include<algorithm>
#include<set>
#include<iterator>
#include<iostream>

//A minimum defination of graph(web)

class Arc{
public:
    std::pair<int,int> arcdata;
    int weight;
    Arc(int _first,int _second,int _weight):weight(_weight){
        arcdata = std::make_pair(_first,_second);
    }
};

class Graph{
public:
    int vertexcount;
    std::vector<Arc> arcs;
};

//auxiliary class

class UnionSet{
public:
    int *father;
    int *rank;
    int size;
    UnionSet(int _size):size(_size){
        father = new int[_size];
        rank = new int[_size];
    }
    void make_set(int x){
        father[x] = x;
        rank[x] = 0;
    }
    int find_set(int x){
        if(x != father[x]){
            father[x] = find_set(father[x]);
        }
        return father[x];
    }
    void union_set(int x,int y){
        link(find_set(x),find_set(y));
    }
    void link(int x,int y){
        if(rank[x] > rank[y]){
            father[y] = x;
        }
        else{
            father[x] = y;
            if(rank[x] == rank[y]){
                rank[y]++;
            }
        }
    }
    
};

bool compare(Arc a,Arc b){
    if(a.weight < b.weight)
        return true;
    else
        return false;
}

void Kruskal(Graph graph){
    UnionSet vertex(graph.vertexcount);
    for(int i = 0;i<graph.vertexcount;i++){
        vertex.make_set(i);
    }
    std::sort(graph.arcs.begin(),graph.arcs.end(),compare);
    for(auto arc : graph.arcs){
        if(vertex.find_set(arc.arcdata.first) != vertex.find_set(arc.arcdata.second)){
            std::cout << "<v" << arc.arcdata.first + 1 << ",v" << arc.arcdata.second + 1 << ">" << std::endl;
            vertex.union_set(arc.arcdata.first,arc.arcdata.second);
        }
    }
}



