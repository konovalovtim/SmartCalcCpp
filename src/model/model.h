/*!
\file
\brief Заголовочный файл с объявлениями функций связанных с компиляцией выржания
из инфискной в постфиксную нотацию, обработкой ввода и графика
*/

#ifndef SRC_MODEL_H_
#define SRC_MODEL_H_

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
 * @brief Проверка ввода чисел и X
 * @param input - числа
 * @param input_x - X
 * @return Возвpащает false если значение не корректно или X не валиден
 */
  bool Input(const char* input, const char* input_x);
  bool Input(const char* input, long double x);
  bool CheckGraph(const char* x_min_char_str, const char* x_max_char_str,
                  const char* y_min_char_str, const char* y_max_char_str,
                  const char* step_char_str, long double& x_min,
                  long double& x_max, long double& y_min, long double& y_max,
                  long double& step);
  long double GetResult() { return result_; }

 private:
  struct Lexeme {
    long double value;
    int priority;
    int type;
  };
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
  bool CheckDoubleCorrectness(const char* input_expr_x_, long double& x);
  class InputStringParsing;
  class ReversePolishNotationCalculation;
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
  void ClearMassiveForLexemes();
};

class Model::ReversePolishNotationCalculation {
 public:
  ReversePolishNotationCalculation() {
    stack_.reserve(SIZE);
    output_.reserve(SIZE);
    stack_count = output_amount = -1;
  }
  ~ReversePolishNotationCalculation() {}
  void TranslateToRpn(std::vector<Lexeme>& lexemes_);
  int IsOperator(Lexeme lexeme);
  int ReversePolishNotationCalculator(long double& result);

 private:
  std::vector<Lexeme> stack_;
  std::vector<Lexeme> output_;
  int stack_count, output_amount;
};
}  // namespace s21

#endif  // SRC_MODEL_H_
