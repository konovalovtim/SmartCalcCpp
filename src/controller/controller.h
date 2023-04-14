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
  /**
   * @brief Передача значения из UI в Input
   * @param input - значения
   * @param input_x - X
   * @return если выходное значение удовлетворяет всем условиям то возвращаю
   * true
   */
  bool Calculate(const char* input, const char* input_x);
  /**
   * @brief Перегрузка Calculate для long double x
   */
  bool Calculate(const char* input, long double x);
  /**
   * @brief Геттер для result_
   */
  long double GetResult();
  /**
   * @brief Проверка на корректность вводимых значений диапазона и шага для
   * графа
   * @param step - шаг отрисовки
   * @return Возвpащает false если значение не корректно или step не валиден
   */
  bool CheckGraph(const char* x_min_char_str, const char* x_max_char_str,
                  const char* y_min_char_str, const char* y_max_char_str,
                  const char* step_char_str, long double& x_min,
                  long double& x_max, long double& y_min, long double& y_max,
                  long double& step);
};
}  // namespace s21

#endif  // SRC_CONTROLLER_H_
