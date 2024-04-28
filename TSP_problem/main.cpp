#include <iostream>
#include <utility>
#include "tsp.h"
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

int main(){
    
    tsp graph{6,0,100};
    std::vector<std::vector<double>> dist_mat;
    graph.generate_random_nodes();
    dist_mat = graph.compute_distance_matrix();
    graph.print_distance_matrix(dist_mat);
    auto [path, min_distance] = graph.tsp_brute_force();


    std::cout << "Minimum Distance: " << min_distance << std::endl;
    std::cout << "Minimum Path: ";

    for (int node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}