#ifndef DATA_INGESTION_H
#define DATA_INGESTION_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <variant>

std::vector<std::vector<std::string> > get_csv_data(const std::string& filename);

void print_csv_data(const std::vector<std::vector<std::string> >& data);

#endif
