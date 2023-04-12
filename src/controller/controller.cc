#include "controller.h"

namespace s21 {
Controller::Controller() { model = new Model; }

Controller::~Controller() { delete model; }

bool Controller::Calculate(const char* input, const char* input_x) {
  bool return_value = model->Input(input, input_x);
  if (return_value) {
    result = model->GetResult();
  }
  return return_value;
}
bool Controller::Calculate(const char* input, long double x) {
  bool return_value = model->Input(input, x);
  if (return_value) {
    result = model->GetResult();
  }
  return return_value;
}

long double Controller::GetResult() { return result; }

bool Controller::CheckGraphicParameters(
    const char* x_min_char_str, const char* x_max_char_str,
    const char* y_min_char_str, const char* y_max_char_str,
    const char* step_char_str, long double& x_min, long double& x_max,
    long double& y_min, long double& y_max, long double& step) {
  return model->CheckGraphicParameters(
      x_min_char_str, x_max_char_str, y_min_char_str, y_max_char_str,
      step_char_str, x_min, x_max, y_min, y_max, step);
}
}  // namespace s21
