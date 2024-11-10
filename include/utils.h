#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <variant>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>

int count_of_characteristics(const std::vector<std::vector<std::string> >& leaf_data, const std::vector<std::pair<int, std::string> >& conditions_data, size_t current_condition_index = 0, size_t current_row_index = 0);

int count_of_characteristics_array(const std::vector<std::string>& individual_leaf_data, const std::vector<std::pair<int, std::string> >& conditions_data, size_t current_condition_index = 0);

double conditional_probability(const std::vector<std::vector<std::string> >& leaf_data, const std::vector<std::pair<int, std::string> >& a_conditions, const std::vector<std::pair<int, std::string> >& b_conditions, int total_leaves = 174);

double probability(const std::vector<std::vector<std::string> >& leaf_data, const std::vector<std::pair<int, std::string> >& conditions, int total_leaves = 174);

const std::vector<std::string> leaf_type_vector = {"1", "2"};

double shannon_entropy(const std::vector<std::vector<std::string> >& leaf_data, const std::vector<std::pair<int, std::string> >& conditions, const std::vector<std::string>& leaf_types = leaf_type_vector);
 
std::vector<std::string> get_unique_characteristics(const std::vector<std::vector<std::string> >& leaf_data, int characteristic_column_index);

double calculate_expected_outcome(const std::vector<std::vector<std::string> >& leaf_data, std::vector<int>& index_data, const std::vector<std::pair<int, std::string> >& conditions_data = {});
 
#endif
