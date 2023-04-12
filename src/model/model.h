#ifndef SRC_MODEL_H_
#define SRC_MODEL_H_

#include <math.h>
#include <string.h>

#include <stack>
#include <vector>
#define SIZE 255

namespace s21 {
bool IsNumber(char c);
class Model {
 public:
  bool Input(const char* input, const char* input_x);
  bool Input(const char* input, long double x);
  bool CheckGraphicParameters(const char* x_min_char_str,
                              const char* x_max_char_str,
                              const char* y_min_char_str,
                              const char* y_max_char_str,
                              const char* step_char_str, long double& x_min,
                              long double& x_max, long double& y_min,
                              long double& y_max, long double& step);
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
    input_count = lexeme_amount = bracket_count = 0;
    lexemes_.reserve(SIZE);
    ClearMassiveForLexemes();
    input_ = input;
  }
  bool Parsing();
  void CaseOpenBracket();
  void CaseCloseBracket();
  void CaseMinus();
  void CasePlus();
  void CaseMul();
  void CaseDiv();
  void CasePow();
  void CaseX();
  void CaseSin();
  void CaseSqrt();
  void CaseCos();
  void CaseTan();
  void CaseMod();
  void CaseAsin();
  void CaseAcos();
  void CaseAtan();
  void CaseLn();
  void CaseLog();
  void CaseNumber();
  void FinalCheck();

 private:
  bool return_value_;
  int input_count, lexeme_amount, bracket_count;
  const char* input_;

  void ClearMassiveForLexemes();
};

class Model::ReversePolishNotationCalculation {
 public:
  ReversePolishNotationCalculation() {
    stack_.reserve(SIZE);
    output_.reserve(SIZE);
    stack_cnt_ = output_amount_ = -1;
  }
  ~ReversePolishNotationCalculation() {}
  void TranslateToRpn(std::vector<Lexeme>& lexemes_);
  int IsOperator(Lexeme lexeme);
  int ReversePolishNotationCalculator(long double& result);

 private:
  std::vector<Lexeme> stack_;
  std::vector<Lexeme> output_;
  int stack_cnt_, output_amount_;
};
}  // namespace s21

#endif  // SRC_MODEL_H_
