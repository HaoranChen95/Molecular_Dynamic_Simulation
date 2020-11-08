#ifndef READ_DATA_HPP_
#define READ_DATA_HPP_

#include <fstream>
#include <iterator>
#include <utility>
#include <vector>

#include "additional.hpp"
#include "is_reg.hpp"
#include "str_split.hpp"


std::pair<Unsign, Unsign> get_rows_cols(const std:: string& path, const std::string& suffix = ".txt");

Mat read_data(const std::string& path = "init_data", const std::string& suffix = ".txt");

void read_data(Mat& M, const Unsign rows, const Unsign cols = 3, const std::string& path = "init_data", const std::string suffix = ".txt");


#endif

