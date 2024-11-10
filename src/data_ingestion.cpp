#include "data_ingestion.h"

std::vector<std::vector<std::string> > get_csv_data(const std::string& filename)
{
    std::vector<std::vector<std::string> > data;
    std::ifstream file(filename);
    if(file.is_open()) {
        std::string line;
        std::getline(file, line);
        while(std::getline(file,line)){
            std::vector<std::string> row;
            row.push_back("Leaf");
            std::stringstream ss(line);
            std::string word;

            while(std::getline(ss, word, ',')) {
                row.push_back(word);
            }
            data.push_back(row);
        }
        file.close();
    }else {
        std::cerr << "Error opening files: " << filename << std::endl;
    }
    return data;
}

void print_csv_data(const std::vector<std::vector<std::string> >& data) {
    for(int y = 0 ; y < 5 ; y++) {
        for(int x = 0 ; x < 6 ; x++) {
            std::cout << " "  << data[y][x]; 
        }
        std::cout << std::endl;
    }
}


