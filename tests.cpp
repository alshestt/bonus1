//
// Created by Александр on 19.05.2022.
//
#pragma once
#include "Graph.h"
#include "Superstring.h"
#include "gtest/gtest.h"

TEST(integer, simple_test){
    int a = 2, b = 2;
    ASSERT_TRUE(a+b == 4);
}

TEST(graph, graph_initialize){
    Graph test_gr(5);
    ASSERT_EQ(test_gr.GetSize(), 5);
    
    test_gr =  Graph(0);
    ASSERT_EQ(test_gr.GetSize(), 0);

    test_gr = Graph(874);
    ASSERT_EQ(test_gr.GetSize(), 874);
}

TEST(graph, adding_edges){
    Graph test_gr(5);
    for (size_t i = 0; i < 5; ++i){
        test_gr.AddEdge(i, (i+1) % 5, i*i+1);
        ASSERT_EQ(test_gr.GetEdgesFrom(i)[(i+1)%5], i*i + 1);
    }
    ASSERT_EQ(test_gr.GetEdgesFrom(2)[4], 0);
}

TEST(graph, max_assignment){
    Graph test_gr(6);
    test_gr.AddEdge(0,2,1);
    test_gr.AddEdge(1,0,1);
    test_gr.AddEdge(2,1,2);
    test_gr.AddEdge(3,4,2);
    test_gr.AddEdge(3,5,1);
    test_gr.AddEdge(4,3,1);
    ASSERT_EQ(max_assignment(test_gr), std::vector<size_t>({2,0,1,4,3,5}));
}

TEST(graph, cycle_cover){
    ASSERT_EQ(minimal_cycle_cover(std::vector<size_t>({2,0,1,4,3,5})), std::vector<std::vector<size_t>>({
        std::vector<size_t>({0,2,1}),std::vector<size_t>({3,4}),std::vector<size_t>({5})
    }));
}
TEST(strings, prefix_function){
    std::string ex1 = "abcabcd", ex2 = "aabaaab";
    ASSERT_EQ(prefix_function(ex1), std::vector<size_t>({0,0,0,1,2,3,0}));
    ASSERT_EQ(prefix_function(ex2), std::vector<size_t>({0,1,0,1,2,2,3}));
}
TEST(strings, KMP){
    std::string t1 = "abcdabcfer", p1 = "cf", t2 = "acm_mipt_2022", p2 = "time";
    ASSERT_TRUE(check_substring(t1,p1));
    ASSERT_FALSE(check_substring(t2,p2));
}
TEST(strings, overlap){
    std::string s_0 = "cde", s_1 = "abc", s_2 = "eab";
    ASSERT_EQ(overlap(s_0,s_1), 0);
    ASSERT_EQ(overlap(s_0,s_2), 1);
    ASSERT_EQ(overlap(s_1,s_0), 1);
    ASSERT_EQ(overlap(s_1,s_2), 0);
    ASSERT_EQ(overlap(s_2,s_0), 0);
    ASSERT_EQ(overlap(s_2,s_1), 2);
    ASSERT_EQ(overlap("fgab", "abcd"), 2);
}
TEST(strings, prefixes){
    ASSERT_EQ("google", prefix("googletest", 4));
    ASSERT_EQ("mipt", prefix("miptacm", 3));
    ASSERT_EQ("null", prefix("null", 0));
}

TEST(combine, min_overlap){
    std::vector<std::string> n_1 = {"acm"}, n_2 = {"fgab", "abcd", "dfga"},
                            n_3 = {"cde", "eab", "abc"}, m_1 = n_1, m_3 = n_3;
    cycle_shift(n_1);
    cycle_shift(n_2);
    cycle_shift(n_3);
    ASSERT_EQ(m_1, n_1);
    ASSERT_EQ(m_3, n_3);
    ASSERT_EQ(n_2, std::vector<std::string>({"dfga", "fgab", "abcd"}));
    cycle_shift(n_2);
    ASSERT_EQ(n_2, std::vector<std::string>({"dfga", "fgab", "abcd"}));
}

TEST(combine, final_string){
    std::vector<std::string> tmp = {"dfga", "fgab", "abcd"}, sample = {"acm"};
    ASSERT_EQ(one_cycle_string(tmp), "dfgabcd");
    ASSERT_EQ(one_cycle_string(sample), "acm");
}

