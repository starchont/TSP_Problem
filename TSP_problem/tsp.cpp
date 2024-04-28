#include <iostream>
#include "tsp.h"
#include <vector>
#include <algorithm>
#include <random>
#include <utility>
#include <cmath>

tsp::tsp()
    :num_nodes{3}, min_val_dist{0}, max_val_dist{100}, nodes{}, distance_matrix{}{

    }

tsp::tsp(const size_t &num_nodes)
    :num_nodes{num_nodes}, min_val_dist{0}, max_val_dist{100}, nodes{}, distance_matrix{}{

    }

tsp::tsp(const size_t &num_nodes, const int &min_val_dist, const int &max_val_dist)
    :num_nodes{num_nodes}, min_val_dist{min_val_dist}, max_val_dist{max_val_dist}, nodes{}, distance_matrix{}{

    }

tsp::~tsp(){

}

void tsp:: generate_random_nodes(){
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_real_distribution<double> dist(min_val_dist, max_val_dist);

    for(size_t i{0}; i<num_nodes; i++){
        nodes.push_back({dist(gen),dist(gen)});
    }

    for (const auto& node : nodes) {
        std::cout << "(" << node.first << ", " << node.second << ")" << std::endl;
    }
}

double tsp:: calculate_dist(const std::pair<double,double> &node_1, const std::pair<double, double> &node_2){
    return std::sqrt(std::pow(node_1.first - node_2.first, 2)+std::pow(node_1.second - node_2.second, 2));
}

std::vector<std::vector<double>> tsp:: compute_distance_matrix(){
    distance_matrix.assign(num_nodes,std::vector<double>(num_nodes, 0));
    for(size_t i{0};i<num_nodes;i++){
        for(size_t j{0};j<num_nodes;j++){
            distance_matrix[i][j] = calculate_dist(nodes[i],nodes[j]);
        }
    }
    return distance_matrix;
}

void tsp:: print_distance_matrix(const std::vector<std::vector<double>> &distance_matrix){
    for (const auto& row : distance_matrix) {
        for (double distance : row) {
            std::cout << distance << "\t";
        }
        std::cout << std::endl;
    }
}

double tsp:: total_distance(const std::vector<int> &path){
    double distance{0};
    for(size_t i {0};i<path.size()-1;i++){
        distance += distance_matrix[path[i]][path[i+1]];
    }
    distance += distance_matrix[path.back()][path[0]];
    return distance;
}

std::pair<std::vector<int>,double> tsp:: tsp_brute_force(){
    std::vector<int> path;
    std::vector<int> min_path;
    double min_distance {std::numeric_limits<double>::max()};

    for(size_t i {0}; i<num_nodes;i++){
        path.push_back(i);
    }

    while (std::next_permutation(path.begin(), path.end())) {
        double dist = total_distance(path);
        if (dist < min_distance) {
            min_distance = dist;
            min_path = path;
        }
    }
    return {min_path, min_distance};

}