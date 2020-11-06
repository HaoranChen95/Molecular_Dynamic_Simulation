#ifndef ADDITIONAL_HPP_
#define ADDITIONAL_HPP_

#include <iostream>

#include "Eigen/Eigen"


typedef unsigned long long Unsign;
typedef long long int Int;


/// Matrix to store real numeric values of type double
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Mat;

/// Column vector to store real numeric values of type double
typedef Eigen::Matrix<double, Eigen::Dynamic, 1> Vec;

/// Row vector to store real numeric values of type double
typedef Eigen::Matrix<double, 1, Eigen::Dynamic> VecR;


#endif
