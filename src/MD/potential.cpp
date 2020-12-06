#include "potential.hpp"

using namespace std;
/**
 * @brief the difine of LJ potential and Force Field
 *
 * @param[in] para the global parameter of MD simulation
 * @param[in] r the radius to the center of partical
 * @return double
 */

double Cut_LJ_Potential(const MDParameter parm, const Vec x_a, const Vec x_b) {
  double r{periodic_vector(parm, x_a, x_b).norm()};
  if (r > pow(2.0, 1.0 / 6.0) * parm.sigma() || r == 0) {
    return 0.0;
  }
  return 4.0 * parm.epsilon() *
             (pow((parm.sigma() / r), 12) - pow((parm.sigma() / r), 6)) +
         parm.epsilon();
}

Vec Cut_LJ_Force(const MDParameter parm, const Vec x_a, const Vec x_b) {
  Vec r{periodic_vector(parm, x_a, x_b)};
  double norm_r = r.norm();
  if (norm_r > pow(2.0, 1.0 / 6.0) * parm.sigma() || norm_r == 0) {
    return Vec::Zero(3);
  } else {
    norm_r = norm_r / parm.sigma();
    return -r * 48.0 * parm.epsilon() * pow(parm.sigma(), -2.0) *
           (pow(norm_r, -14) - 0.5 * pow(norm_r, -8));
  }
}

void test_Cut_LJ_Potential(const MDParameter parm) {
  Vec zero{Vec::Zero(3)};
  Vec test{Vec::Zero(3)};
  Vec data{Vec::Zero(2)};
  for (int i{0}; i < 2000; ++i) {
    test(0) = i * 0.001 * parm.boundary_width();

    data(0) = test.norm();
    data(1) = Cut_LJ_Potential(parm, zero, test);
    write_data(data, "test_Cut_LJ_Potential");
  }
}