#include <iostream>
#include "data_ingestion.h"
#include "utils.h"

int main()
{
    std::cout << "DataCSV" << std::endl;
    std::string filename = "../data/training_data.csv";
    std::vector< std::vector<std::string> > data = get_csv_data(filename);
    print_csv_data(data);     
    std::vector<std::pair<int, std::string> > conditions;
    conditions.push_back({2, "Simple"});
    //conditions.push_back({2, "Simple"});
    std::vector<std::pair<int, std::string> > conditions2;
    //conditions2.push_back({1, "Dogwood"});
    conditions2.push_back({1, "1"});
    std::cout << "============array function test" << std::endl;




    std::cout << "===========probability test" << std::endl;
    int temp_count_3 = count_of_characteristics(data, conditions);
    std::cout << "the count is " << temp_count_3 << std::endl;
    double temp_count_5 = probability(data, conditions);
    std::cout << "the percentage of Simple leaves are " << temp_count_5 << std::endl;

    std::cout << "the count of type 1 is " <<  count_of_characteristics(data, conditions2) << std::endl;
    double temp_count_4 = conditional_probability(data, conditions2, conditions);
    std::cout << "the probability of type 1  given simple is " << temp_count_4 << std::endl;

    std::cout << "=============single shannon entropy test" << std::endl;
    std::vector<std::pair<int, std::string> > conditions3;
    //conditions3.push_back({2, "Compound"});
    double shannon_test = shannon_entropy(data, conditions);
    std::cout << "the single information entropy for shannon entropy I(Simple -> Type) is " << shannon_test << std::endl;



    
    std::cout << "=============unique column features test" << std::endl;
    std::vector<std::string> temp_split = get_unique_characteristics(data, 2);
    for (const auto& value : temp_split) {
        std::cout << value << std::endl;
    }
    

    std::cout << "===============begin expected outcome test" << std::endl << std::endl;
    double min_expected_outcome = 100;;
    int min_cal_value;

    for (int x = 3 ; x < 4 ; x++) { 
        std::cout << "===============expected outcome test for column " << x <<  std::endl;
        std::vector<int> temp_index_vector;
        temp_index_vector.push_back(2);
        temp_index_vector.push_back(4);
        temp_index_vector.push_back(x);
        double temp_expected = calculate_expected_outcome(data, temp_index_vector);
        std::cout << "The expected outcome of asking column " << x << " is " << temp_expected << std::endl << std:: endl;
        min_expected_outcome = fmin(min_expected_outcome, temp_expected);
    }
    std::cout << std::endl << "the min expected outcome is " << min_expected_outcome << std::endl << std::endl;
        
    return 0;
}  
