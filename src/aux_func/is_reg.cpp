#include "is_reg.hpp"
using namespace std;

void is_reg(const Mat& M) {
  bool r = true;
  r = !((M.array().isNaN()).any());
  r = !((M.array().isInf()).any());

  const string s = "Matrix M is not regular containing inf or nan.";
  if (false == r) {
    cout << "Matrix M \n" << M << endl;
    throw(runtime_error(s));
  }
}
