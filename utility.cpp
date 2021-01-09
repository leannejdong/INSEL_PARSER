//
// Created by leanne on 1/6/21.
//

#include "utility.h"
#include<algorithm>
#include<sstream>
#include<fstream>

using std::string;
using std::vector;
using std::istringstream;

vector<int> strToVecInts(const string &graph_string)
{
    vector<int> vecInts;
    istringstream input_stream(graph_string);
    int number;
    while(input_stream >> number) {
        vecInts.push_back(number);
    }
    return vecInts;
}

Edges parseGraph(const string &graph_string)
{
    std::ifstream split(graph_string);
    string each;
    Edges V;

    while (std::getline(split, each)) {
        vector<int> vec1 = strToVecInts(each);
        std::getline(split, each);
        vector<int> vec2 = strToVecInts(each);

        for (int x : vec2) {
            V.push_back(std::make_pair(vec1[0] - 1, x - 1));
        }
    }

    return V;
}

