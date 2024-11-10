#include <iostream>
#include "decision_tree.h"
#include <vector>
#include <optional>
#include <string>

class decision_tree {
    public:
        struct Node {
            int characteristic_index;
            std::string characteristic_value;
            std::vector<Node*> children;
            std::optional<std::string> leaf_type;

            Node(int char_index, const std::string& char_value):
                characteristic_index(char_index), characteristic_value(char_value) {}

            Node(const std::string& type) : leaf_type(type) {}
        };

};
//
//        int calculate_entropy(const std::vector<std::vector<std::string> >& data){
//
//        int get_unique_characteristic_values(const std::vector<std::vector<std::string> >& data){
//
//        std::vector<std::vector<std::vector<int, std::string> > > split_data(){
//
//        int information_gain()
//
//        int find_best_split
