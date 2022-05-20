//
// Created by Александр on 20.05.2022.
//

#pragma once
#include "Graph.h"

Graph::Graph(size_t n_vertex) : n_vertex(n_vertex), adj_matrix(n_vertex, std::vector<size_t>(n_vertex, 0)) {}

void Graph::AddEdge(size_t from, size_t to, size_t length) {
    adj_matrix[from][to] = length;
}

std::vector<size_t> Graph::GetEdgesFrom(size_t from) const {
    return adj_matrix[from];
}

size_t Graph::GetSize() const {
    return n_vertex;
}

std::vector<size_t> max_assignment(const Graph& string_graph){
    size_t size = string_graph.GetSize();
    std::vector<std::vector<bool>> not_allow(size, std::vector<bool>(size, false));
    std::vector<size_t> max_assignment(size);

    while (true) {
        int max = -1;
        size_t max_i = 0, max_j = 0;

        for (size_t i = 0; i < size; ++i){
            for (size_t j = 0; j < size; ++j){

                if (not_allow[i][j]) continue;
                if (int(string_graph.GetEdgesFrom(i)[j]) > max){
                    max = string_graph.GetEdgesFrom(i)[j];
                    max_i = i; max_j = j;
                }
            }
        }

        if (max == -1) break;

        max_assignment[max_i] = max_j;

        for (size_t i = 0; i < size; ++i){
            not_allow[max_i][i] = true;
            not_allow[i][max_j] = true;
        }
    }
    return max_assignment;
}

std::vector<std::vector<size_t>> minimal_cycle_cover (const std::vector<size_t>& assignment){
    std::vector<std::vector<size_t>> cycles;
    std::vector<size_t> cycle;
    std::vector<bool> mark(assignment.size(), false);

    for (int i = 0; size_t(i) < assignment.size(); ++i){
        if (mark[i]) continue;

        cycle.push_back(i);
        mark[i] = true;

        if (assignment[i] == cycle[0]){
            cycles.push_back(cycle);
            cycle.clear();
            i = 0;
        } else {
            i = int(assignment[i] - 1);
        }
    }
    return cycles;
}