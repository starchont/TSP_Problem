#ifndef _TSP_H_
#define _TSP_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <random>
#include <algorithm>
#include <utility>



class tsp{
private:
    size_t num_nodes{0};
    int min_val_dist{0};
    int max_val_dist{0};
    std::vector<std::pair<double, double>> nodes;
    std::vector<std::vector<double>> distance_matrix;
    double total_distance(const std::vector<int> &path);

public:
    double calculate_dist(const std::pair<double,double> &node_1, const std::pair<double, double> &node_2);
    void generate_random_nodes();
    std::vector<std::vector<double>> compute_distance_matrix();
    void print_distance_matrix(const std::vector<std::vector<double>> &distance_matrix);
    std::pair<std::vector<int>,double> tsp_brute_force();

    tsp(const size_t &num_nodes);
    tsp(const size_t &num_nodes, const int &min_val_dist, const int &max_val_dist);
    tsp();
    ~tsp();

};

#endif