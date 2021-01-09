//
// Created by leanne on 1/9/21.
//

#ifndef INSEL_PARSER_UTILITY_H
#define INSEL_PARSER_UTILITY_H

#include<string>
#include<utility>
#include<vector>
#include<cassert>

using Edges = std::vector<std::pair<int,int>>;

extern std::vector<int> strToVecInts(const std::string &graph_string);

extern Edges parseGraph(const std::string &graph_string);

#endif //INSEL_PARSER_UTILITY_H