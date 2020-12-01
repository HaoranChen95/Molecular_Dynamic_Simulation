#ifndef WRITE_DATA_HPP_
#define WRITE_DATA_HPP_

#include <fstream>

#include "additional.hpp"


void write_data(const Mat& mat, 
				const std::string& path = "data", 
				const std::string& suffix = ".txt",
				const std::ios::openmode mode = std::ios::app);

#endif 
