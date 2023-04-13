#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

#include "../Model/model.h"

namespace s21 {
class Controller {
 private:
  Model* model;
  long double result;

 public:
  Controller();
  ~Controller();
  bool Calculate(const char* input, const char* input_x);
  bool Calculate(const char* input, long double x);
  long double GetResult();
  bool CheckGraph(const char* x_min_char_str,
                              const char* x_max_char_str,
                              const char* y_min_char_str,
                              const char* y_max_char_str,
                              const char* step_char_str, long double& x_min,
                              long double& x_max, long double& y_min,
                              long double& y_max, long double& step);
};
}  // namespace s21

#endif  // SRC_CONTROLLER_H_
