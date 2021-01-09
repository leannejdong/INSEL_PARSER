//
// Created by leanne on 1/6/21.
//

#include "graph.h"
#include <iostream>
#include <ranges>
#include <algorithm>

using std::vector;
using namespace std::ranges;
//  If we have a vector v where v[i], i is a node number, then v.size() > max node number
// has to be satisfied.These node numbers are like IDs, serial numbers.
graph::graph(std::vector<int> &v, Edges &e)
        :  v_(v), e_(e), parents( *max_element(v_)+1 , -1) {}

vector<int> graph::findNeighbors(int node_id, const Edges &edges)
{
    vector<int> neighbors;
    for (auto u : edges)
    {
        if ((node_id  == u.first))
        {
            neighbors.push_back(u.second);
        } else if (node_id  == u.second) {
            neighbors.push_back(u.first);
        }
    }
    return neighbors;
}

bool graph::has_cycle() const
{
    return cycle_found;
}

bool graph::has_vertex(int index) const
{
    return index >= 0 && index < (int)(*max_element(v_)+1);
}

void graph::compute_cycles()
{
    auto const visited_size= *max_element(v_)+1;
    //  std::cerr << vertices_count << "\n";
    std::vector<bool> visited(visited_size, false);
    int cnt = 0;
    vector<int> cycles;
    for (size_t i = 0; i < visited_size  ; ++i)
    {
        if (!visited[i]) dfs_compute_cycle(visited, i, cnt);
    }
}
void graph::dfs_compute_cycle(std::vector<bool>& visited, int current_vertex, int &cnt)
{
    assert(has_vertex(current_vertex));

    visited[current_vertex] = true;
    // mark the current vertex as visited
    vector<int> neighbors;
    neighbors = findNeighbors(current_vertex, e_);
    // go through each element of the neighbor
    for (auto v : neighbors)
    {
        //   std::cerr << neighbors.size() << "\n";
        //std::cout << v << "\n";
        // check to see if the neighbor of the current vertex is visited
        if (!visited[v])
        {
            // the neighbor of the current vertex is not visited

            parents[v] = current_vertex;
            // set the parent of the neighbor of the current vertex to the current vertex

            dfs_compute_cycle(visited, v, cnt);
            // recursively compute the cycle with the neighbor of the current vertex
        }
        else
        {
            // the neighbor of the current vertex is visited
            if (v != parents[current_vertex] && current_vertex > v)
            {
                // The neighbor of the current vertex is not the parent of the current vertex.
                // The current vertex has a higher index than the neighbor.

                cycle_found = true;
                // set cycle_found to true

                std::cerr << "cycle found: ";
                cnt++;
                print_cycle(current_vertex, v, cnt);
                // print out the cycle using the current vertex and the neighbor of the current
                // vertex

                std::cerr << "\n";
            }
        }
    }
}

void graph::print_cycle(int first_vertex, int last_vertex, int&cnt) const
{
    vector<int> vec;
    for (;;) {
        assert(has_vertex(first_vertex));
        assert(has_vertex(last_vertex));


    if (first_vertex < last_vertex)
    {
        std::swap(first_vertex, last_vertex);
    }
    vec.push_back(first_vertex);
        if (first_vertex == last_vertex)
        {
            break;
        }
        first_vertex = parents[first_vertex];
    }
    if ( cnt == 2) {
        vec.resize(vec.size()-2);
        for (const auto &v : vec)
        {
            std::cerr << v << " ";
        }
    } else {
        for (const auto &v : vec)
        {
            std::cerr << v << " ";
        }
    }

}

