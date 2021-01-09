#include <iostream>
#include <fstream>
#include <sstream>
//#include <ranges>
#include <algorithm>
#include <numeric>
#include <array>
#include <string>
#include <cassert>
#include "utility.h"
#include "graph.h"

//using namespace std::ranges;
using std::cerr;
using std::string;
using std::make_pair;
using std::ranges::sort;


int main() {
    Edges e = parseGraph("model0.txt");
    for (auto &ee : e)
    {
        std::cerr << ee.first << " and " << ee.second << "\n";
    }
    std::cerr << "End of Print " << "\n";

//    }


    string each;
    std::vector<int> v;
#if 1   // via std::transform, copy a vec-pair to vec
    std::transform(begin(e), end(e), std::back_inserter(v),
                   [&v](const std::pair<int, int> &pair)
                   {v.push_back(pair.first);
                       return pair.second ;});
#else
    for (auto p : e) { // loop over all pairs and add both node_ids to a single vec
        v.push_back(p.first);
        v.push_back(p.second);
    }
#endif
    sort(v);
    auto last = std::unique(begin(v), end(v));
    v.erase(last, v.end());
    for (auto &s : v)
    {
        std::cerr << s << "\n";
    }
    std::cerr << "End of Print " << "\n";

    graph g(v, e);

    g.compute_cycles();


}

// Parsing is all about turning a sequence of characters into something more meaningful