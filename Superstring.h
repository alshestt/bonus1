//
// Created by Александр on 20.05.2022.
//
#pragma once
#include <cstdint>
#include <string>
#include <vector>
// Префикс-функция строки
std::vector<size_t> prefix_function(const std::string& pattern);

//Проверка наличия подстроки в строке, Кнут-Моррис-Пратт
bool check_substring(const std::string& text, const std::string& pattern);

// Overlap двух строк
size_t overlap(const std::string& string_1, const std::string& string_2);

// Возвращение префикса длиной length-overlap
std::string prefix(const std::string& s_1,const size_t& ov);

// Минимизация overlap первой и последней строки
void cycle_shift(std::vector<std::string>& cycle);

// Применение cycle_shift к разбиению на циклы
void major_shift(std::vector<std::vector<std::string>>& cycles);

// Сборка строки из подстрок
std::string one_cycle_string(const std::vector<std::string>& cycle);

// Сборка строки по покрытию циклами
std::string cycles_string(const std::vector<std::vector<std::string>>& cycles);








