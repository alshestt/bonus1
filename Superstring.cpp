//
// Created by Александр on 20.05.2022.
//
#pragma once
#include "Superstring.h"
#include <iterator>
#include <algorithm>
size_t overlap(const std::string& s_1, const std::string& s_2){
    size_t s1_last = s_1.size() - 1;
    size_t s2_len = s_2.size();
    size_t overlap = 0;
    for (size_t i = s1_last, j = 1; i > 0 && j < s2_len; i--, j++){
        std::string suff, preff;
        copy(s_1.begin()+i, s_1.end(), back_inserter(suff));
        copy(s_2.begin(), s_2.begin()+j, back_inserter(preff));
        if (suff == preff)
            overlap = j;
    }
    return overlap;
}

std::string prefix(const std::string& s_1,const size_t& ov){
    std::string preff;
    copy(s_1.begin(), s_1.end()-ov, back_inserter(preff));
    return preff;
}

void cycle_shift(std::vector<std::string>& cycle){
    size_t size = cycle.size();
    if (size > 2) {
        size_t min_overlap = overlap(cycle[size - 1], cycle[0]), shift = 0;
        for (size_t i = 1; i < size; ++i) {
            if (overlap(cycle[i-1], cycle[i]) < min_overlap) {
                shift = i;
                min_overlap = overlap(cycle[i-1], cycle[i]);
            }
        }
        std::rotate(cycle.begin(), cycle.begin()+shift, cycle.end());
    }
}

void major_shift(std::vector<std::vector<std::string>>& cycles){
    for (auto& elem : cycles){
        cycle_shift(elem);
    }
}

std::string one_cycle_string(const std::vector<std::string>& cycle){
    std::string result;
    size_t size = cycle.size();
    if (size == 1){
        result += cycle[0];
    } else {
        for (size_t i = 0; i < size - 1; ++i){
            result += prefix(cycle[i], overlap(cycle[i],cycle[i+1]));
        }
        result += cycle[size-1];
    }
    return result;
}

std::string cycles_string(const std::vector<std::vector<std::string>>& cycles){
    std::string result;
    for (const auto& elem : cycles){
        result += one_cycle_string(elem);
    }
    return result;
}