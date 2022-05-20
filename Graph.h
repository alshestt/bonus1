//
// Created by Александр on 20.05.2022.
//
#pragma once
#include <vector>
#include <cstdint>
#include "Superstring.h"
class Graph {
private:
    // Количество вершин
    size_t n_vertex;
    // Матрица смежности
    std::vector<std::vector<size_t>> adj_matrix;
public:
    // Конструктор
    Graph(size_t n_vertex);
    // Добавление ребра
    void AddEdge(size_t from, size_t to, size_t length);
    // Возвращение списка смежности вершины
    std::vector<size_t> GetEdgesFrom(size_t from) const;
    // Возвращение размера графа
    size_t GetSize() const;

};

//Жадный поиск максимального назначения
std::vector<size_t> max_assignment(const Graph& string_graph);

//Покрытие циклами минимальной длины
std::vector<std::vector<size_t>> minimal_cycle_cover(const std::vector<size_t>& assignment);

