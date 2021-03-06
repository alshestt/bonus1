#include <iostream>
#include "Graph.h"
#include "Superstring.h"

int main() {
    size_t strings_n;
    std::shared_ptr<vertex> root = std::make_shared<vertex>();
    std::string tmp, result;
    std::vector<std::string> strings_vector;
    std::vector<size_t> assignment;
    std::vector<std::vector<size_t>> cycle_cover;
    std::vector<std::vector<std::string>> strings_split;
    std::cin >> strings_n;
    for (size_t i = 0; i < strings_n; ++i){
        std::cin >>  tmp;
        if (!tmp.empty()){
            if (!check_string(tmp,root)) {
                strings_vector.push_back(tmp);
            }
        }
    }
    strings_n = strings_vector.size();
    Graph overlap_graph(strings_n);
    for (size_t i = 0; i < strings_n; ++i){
        for (size_t j = 0; j < strings_n; ++j){
            if (i == j){
                overlap_graph.AddEdge(i,j,0);
            } else {
                overlap_graph.AddEdge(i,j,overlap(strings_vector[i], strings_vector[j]));
            }
        }
    }
    assignment = max_assignment(overlap_graph);
    cycle_cover = minimal_cycle_cover(assignment);
    for (const auto& elem_vector : cycle_cover){
        std::vector<std::string> sizet_to_string_vector;
        for (const auto& elem_item : elem_vector){
            sizet_to_string_vector.push_back(strings_vector[elem_item]);
        }
        strings_split.push_back(sizet_to_string_vector);
    }
    major_shift(strings_split);
    result = cycles_string(strings_split);
    std::cout << std::endl << "The 4-answer is " << result << std::endl;

    return 0;
}
