/*!
\file
\brief Заголовочный файл с объявлениями функций связанных с компиляцией выржания
из инфискной в постфиксную нотацию, обработкой ввода и графика
*/

#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include <math.h>
#include <string.h>

#include <stack>
#include <vector>

#define SIZE 255

namespace s21 {
/**
 * @brief Проверка на ввод числовых значений
 * @param с - Считываемый символ
 * @return Возвpащает true если это число, false если не число
 */
bool IsNumber(char c);
class Model {
 public:
  /**
   * @brief Проверка ввода чисел и Xlong double
   * @param input - значения
   * @param input_x - X
   * @return Возвpащает false если значение не корректно или X не валиден
   */
  bool Input(const char* input, const char* input_x);
  /**
   * @brief Переопределение Input под long double
   * @param input - значения
   * @param input_x - X
   * @return Возвpащает false если значение не корректно или X не валиден
   */
  bool Input(const char* input, long double x);
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
  /**
   * @brief Геттер для result_
   */
  long double GetResult() { return result_; }

 private:
  struct Lexeme {
    long double value;
    int priority;
    int type;
  };
  /**
   * @brief Тип лексем
   */
  enum Type {
    NUMBER,
    VARIABLE,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    UNARY_MINUS,
    BINARY_MINUS,
    UNARY_PLUS,
    BINARY_PLUS,
    MUL,
    DIV,
    POW,
    MOD,
    COS,
    SIN,
    TAN,
    ACOS,
    ASIN,
    ATAN,
    SQRT,
    LN,
    LOG
  };
  long double result_;
  /**
   * @brief Проверка вводимых значений
   * @param input - значения
   * @param input_x - X
   * @return Возвpащает true если это число, false если не число
   */
  bool CheckDouble(const char* input_expr_x_, long double& x);
  class InputStringParsing;
  class PolishNotation;
  /**
   * @brief Проверка размера вводимых значений
   * @return Возвpащает false если не значение больше заданного размера SIZE
   */
  bool CheckStrlen(const char* input);
  bool Calculation(InputStringParsing& input_string_parsing_obj);
};

class Model::InputStringParsing {
 public:
  std::vector<Lexeme> lexemes_;

  explicit InputStringParsing(const char* input) {
    return_value_ = true;
    input_count = lexeme_count = bracket_count = 0;
    lexemes_.reserve(SIZE);
    ClearMassiveForLexemes();
    input_ = input;
  }
  bool Menu();
  void OpenBracket();
  void CloseBracket();
  void Minus();
  void Plus();
  void Mul();
  void Div();
  void Pow();
  void X();
  void Sin();
  void Sqrt();
  void Cos();
  void Tan();
  void Mod();
  void Asin();
  void Acos();
  void Atan();
  void Ln();
  void Log();
  void Number();
  void FinalCheck();

 private:
  bool return_value_;
  int input_count, lexeme_count, bracket_count;
  const char* input_;
  /**
   * @brief Очистить массив лексем
   */
  void ClearMassiveForLexemes();
};

class Model::PolishNotation {
 public:
  PolishNotation() {
    stack_.reserve(SIZE);
    output_.reserve(SIZE);
    stack_count = output_amount = -1;
  }
  ~PolishNotation() {}
  /**
   * @brief Перевод в нотацию
   */
  void TranslateToRpn(std::vector<Lexeme>& lexemes_);
  /**
   * @brief Проверка, является ли лексема операторов от минуса до логорифма в
   * enum Type
   * @return номер под которым лежит оператор
   */
  int IsOperator(Lexeme lexeme);
  /**
   * @brief Калькуляция
   * @param result - Поступающее значение
   * @return Возвpащает false если значение не корректно
   */
  int PolishNotationCalculation(long double& result);

 private:
  std::vector<Lexeme> stack_;
  std::vector<Lexeme> output_;
  int stack_count, output_amount;
};
}  // namespace s21

#endif  // SRC_MODEL_MODEL_H_
