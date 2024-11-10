#include "utils.h"

int count_of_characteristics(const std::vector<std::vector<std::string> >& leaf_data, const std::vector<std::pair<int ,std::string> >& conditions_data, size_t  current_condition_index, size_t current_row_index) {
    // if (current_condition_index == conditions_data.size()){
     //   std::cout << "adding " << std::stoi(leaf_data[current_row_index].back()) << std::endl;
     //   return std::stoi(leaf_data[current_row_index].back());
    //}
    int count = 0;
    for (const auto& row : leaf_data) {
        count += count_of_characteristics_array(row, conditions_data);
    }
    return count;
}

int count_of_characteristics_array(const std::vector<std::string>& individual_leaf_data, const std::vector<std::pair<int, std::string> >& conditions_data, size_t current_condition_index) {
    if (current_condition_index == conditions_data.size()) {
        return std::stoi(individual_leaf_data.back());
    }
    int count = 0;
    auto [char_index, char_value] = conditions_data[current_condition_index];
    if (char_index >= 0 && char_index < individual_leaf_data.size() && individual_leaf_data[char_index] == char_value) {
        count +=  count_of_characteristics_array(individual_leaf_data, conditions_data, current_condition_index + 1);
    }
    return count;
}

std::vector<std::string> get_unique_characteristics(const std::vector<std::vector<std::string> >& leaf_data, int characteristic_column_index) {
    std::vector<std::string> unique_values = {};
    for (const auto& row : leaf_data) {
        int count1 = count(unique_values.begin(), unique_values.end(), row[characteristic_column_index]);
        if (count1 == 0) {
            unique_values.push_back(row[characteristic_column_index]);
        }
    }
    return unique_values;
}

double probability(const std::vector<std::vector<std::string> >& leaf_data, const std::vector<std::pair<int, std::string> >& conditions, int total_leaves) {
    double count = static_cast<double>(count_of_characteristics(leaf_data, conditions));
    double final_answer = count/total_leaves;
    return final_answer;
};

double conditional_probability(const std::vector<std::vector<std::string> >& leaf_data, const std::vector<std::pair<int, std::string> >& a_conditions, const std::vector<std::pair<int, std::string> >& b_conditions, int total_leaves) {
    std::vector<std::pair<int, std::string> > combined_conditions_data;
    for (const auto& pair : a_conditions) {
        combined_conditions_data.push_back(pair);
    }
    for (const auto& pair : b_conditions) {
        combined_conditions_data.push_back(pair);
    }
    int numerator_count = count_of_characteristics(leaf_data, combined_conditions_data);
    int denominator_count = count_of_characteristics(leaf_data, b_conditions);
    if (denominator_count == 0) {
        return 0.0;
    }
    double final_answer = (static_cast<double>(numerator_count))/total_leaves;
    double final_answer2 = (static_cast<double>(denominator_count))/total_leaves;
    double final_final = final_answer/final_answer2;
    return final_final; 
}

double shannon_entropy(const std::vector<std::vector<std::string> >& leaf_data, const std::vector<std::pair<int, std::string> >& conditions, const std::vector<std::string>& leaf_types) {
    double final_entropy = 0.0;
    for(const auto& leaf : leaf_types) {
        std::vector<std::pair<int, std::string> > type_vector;
        type_vector.push_back({1, leaf});
        double leaf_conditional = conditional_probability(leaf_data, type_vector, conditions);
        double individual_entropy;
        if(leaf_conditional == 0){
            individual_entropy = 0;
        }
        else if (leaf_conditional == 1) {
            return 0.0;
        }
        else {
            individual_entropy = leaf_conditional * log2(leaf_conditional);
        }
        final_entropy += individual_entropy;
    }
    final_entropy = -1 * final_entropy;
    return final_entropy;
}
double calculate_expected_outcome(const std::vector<std::vector<std::string> >& leaf_data, std::vector<int>& index_data,  const std::vector<std::pair<int, std::string> >& conditions_data) {
    if (index_data.empty()) {
        if (shannon_entropy(leaf_data,conditions_data) == 0) {
            return 0.0;
        }
        else {
            std::cout << "The shannon entropy is " <<  shannon_entropy(leaf_data, conditions_data) << std::endl;
            return shannon_entropy(leaf_data, conditions_data);
        }
    }
    int current_index = index_data[0];
    std::vector<std::string> unique_values = get_unique_characteristics(leaf_data, current_index);
    std::vector<int> remainingIndices(index_data.begin()+1, index_data.end());
    double expected_outcome = 0.0;

    for (const auto& value : unique_values) {

        std::vector<std::pair<int, std::string> > new_conditions = conditions_data;
        new_conditions.push_back({current_index, value});

        double value_probability = probability(leaf_data, new_conditions);

        double value_entropy = calculate_expected_outcome(leaf_data, remainingIndices, new_conditions);

        if (value_entropy != 0 ) {
            for (auto& pair : new_conditions){
                std::cout << pair.second;
            }
            std::cout << " the probability is " << value_probability << std::endl;
            expected_outcome += value_probability * value_entropy;
        }
    }
    return expected_outcome;
}
