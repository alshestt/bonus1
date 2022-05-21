//
// Created by Александр on 20.05.2022.
//
#pragma once
#include "Superstring.h"
#include <iterator>
#include <algorithm>

std::vector<size_t> prefix_function(const std::string& pattern){
    size_t size = pattern.size();
    std::vector<size_t> pi (size, 0);
    for (size_t i=1; i< size; ++i) {
        int j = pi[i-1];
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j-1];
        if (pattern[i] == pattern[j])  ++j;
        pi[i] = j;
    }
    return pi;

}
bool check_substring(const std::string& text, const std::string& pattern){
    std::string pattern_concat_text = pattern + '#' + text;
    std::vector<size_t> pi = prefix_function(pattern_concat_text);
    size_t p_size = pattern.size(), sum_size = pattern_concat_text.size();
    for(size_t i = p_size + 1; i < sum_size; ++i){
        if (pi[i] == p_size)
            return true;
    }
    return false;
}

size_t overlap(const std::string& s_1, const std::string& s_2){
    std::string s2_concat_s1 = s_2 + s_1;
    std::vector<size_t> pi = prefix_function(s2_concat_s1);
    return pi[pi.size()-1];
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