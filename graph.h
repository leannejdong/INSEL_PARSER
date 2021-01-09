//
// Created by leanne on 1/9/21.
//

#ifndef INSEL_PARSER_GRAPH_H
#define INSEL_PARSER_GRAPH_H
#include "utility.h"

class graph {
    std::vector<int> v_;
    Edges e_;
    std::vector<int> parents;
    bool cycle_found = false;

public:

    graph(std::vector<int> &v, Edges &e);

    static std::vector<int> findNeighbors(int node_id, const Edges &edges);
    bool has_cycle() const;
    bool has_vertex(int index) const;
    void compute_cycles();
    void print_cycle(int first_vertex, int last_vertex) const;


private:
    void dfs_compute_cycle(std::vector<bool>& visited, int current_vertex);
};

#endif //INSEL_PARSER_GRAPH_H
