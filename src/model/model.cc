#include "model.h"

namespace s21 {
bool Model::Input(const char* input, const char* input_x) {
  bool return_value = true;
  if ((int)strlen(input) > SIZE) return_value = false;
  InputStringParsing input_string_parsing_obj(input);
  if (return_value) {
    return_value = input_string_parsing_obj.Menu();
    if (return_value) {
      long double x;
      bool x_correct = false;
      for (int i = 0; input_string_parsing_obj.lexemes_[i].type != -1; i++) {
        if (input_string_parsing_obj.lexemes_[i].type == VARIABLE) {
          if (!x_correct) {
            x_correct = CheckDouble(input_x, x);
            if (!x_correct) {
              return_value = false;
              break;
            }
          }
          input_string_parsing_obj.lexemes_[i].type = NUMBER;
          input_string_parsing_obj.lexemes_[i].value = x;
        }
      }
      if (return_value) return_value = Calculation(input_string_parsing_obj);
    }
  }
  return return_value;
}

bool Model::Input(const char* input, long double x) {
  bool return_value = true;
  return_value = CheckStrlen(input);
  if (return_value) {
    InputStringParsing input_string_parsing_obj(input);
    if (return_value) {
      return_value = input_string_parsing_obj.Menu();
      if (return_value) {
        for (int i = 0; input_string_parsing_obj.lexemes_[i].type != -1; i++) {
          if (input_string_parsing_obj.lexemes_[i].type == VARIABLE) {
            input_string_parsing_obj.lexemes_[i].type = NUMBER;
            input_string_parsing_obj.lexemes_[i].value = x;
          }
        }
        return_value = Calculation(input_string_parsing_obj);
      }
    }
  }
  return return_value;
}

bool Model::CheckStrlen(const char* input) {
  return (int)strlen(input) > SIZE ? false : true;
}

bool Model::Calculation(InputStringParsing& input_string_parsing_obj) {
  bool return_value = true;
  PolishNotation polishNotationObj;
  polishNotationObj.TranslateToRpn(input_string_parsing_obj.lexemes_);
  return_value = polishNotationObj.PolishNotationCalculation(result_);
  if (return_value && isnan(result_)) return_value = false;
  return return_value;
}

void Model::InputStringParsing::ClearMassiveForLexemes() {
  for (int i = 0; i < SIZE; i++) lexemes_[i].type = -1;
}

bool Model::InputStringParsing::Menu() {
  for (; input_[input_count] != '\0'; input_count++) {
    switch (input_[input_count]) {
      case '(':
        OpenBracket();
        break;
      case ')':
        CloseBracket();
        break;
      case '-':
        Minus();
        break;
      case '+':
        Plus();
        break;
      case '*':
        Mul();
        break;
      case '/':
        Div();
        break;
      case '^':
        Pow();
        break;
      case 'x':
        X();
        break;
      case 's':
        input_count++;
        if (input_[input_count] == 'i') {
          input_count++;
          if (input_[input_count] == 'n')
            Sin();
          else
            return_value_ = false;
        } else if (input_[input_count] == 'q') {
          input_count++;
          if (input_[input_count] == 'r') {
            input_count++;
            if (input_[input_count] == 't')
              Sqrt();
            else
              return_value_ = false;
          } else
            return_value_ = false;
        } else
          return_value_ = false;
        break;
      case 'c':
        input_count++;
        if (input_[input_count] == 'o') {
          input_count++;
          if (input_[input_count] == 's')
            Cos();
          else
            return_value_ = false;
        } else
          return_value_ = false;
        break;
      case 't':
        input_count++;
        if (input_[input_count] == 'a') {
          input_count++;
          if (input_[input_count] == 'n')
            Tan();
          else
            return_value_ = false;
        } else
          return_value_ = false;
        break;
      case 'm':
        input_count++;
        if (input_[input_count] == 'o') {
          input_count++;
          if (input_[input_count] == 'd')
            Mod();
          else
            return_value_ = false;
        } else
          return_value_ = false;
        break;
      case 'a':
        input_count++;
        if (input_[input_count] == 's') {
          input_count++;
          if (input_[input_count] == 'i') {
            input_count++;
            if (input_[input_count] == 'n')
              Asin();
            else
              return_value_ = false;
          } else
            return_value_ = false;
        } else if (input_[input_count] == 'c') {
          input_count++;
          if (input_[input_count] == 'o') {
            input_count++;
            if (input_[input_count] == 's')
              Acos();
            else
              return_value_ = false;
          } else
            return_value_ = false;
        } else if (input_[input_count] == 't') {
          input_count++;
          if (input_[input_count] == 'a') {
            input_count++;
            if (input_[input_count] == 'n')
              Atan();
            else
              return_value_ = false;
          } else
            return_value_ = false;
        } else
          return_value_ = false;
        break;
      case 'l':
        input_count++;
        if (input_[input_count] == 'n')
          Ln();
        else if (input_[input_count] == 'o') {
          input_count++;
          if (input_[input_count] == 'g')
            Log();
          else
            return_value_ = false;
        } else
          return_value_ = false;
        break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '.':
        Number();
        break;
      case ' ':
        break;
      default:
        return_value_ = false;
        break;
    }
    if (!return_value_) break;
  }

  FinalCheck();

  return return_value_;
}

void Model::InputStringParsing::OpenBracket() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == UNARY_PLUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD ||
        lexemes_[lexeme_count - 1].type == SIN ||
        lexemes_[lexeme_count - 1].type == COS ||
        lexemes_[lexeme_count - 1].type == TAN ||
        lexemes_[lexeme_count - 1].type == ACOS ||
        lexemes_[lexeme_count - 1].type == ASIN ||
        lexemes_[lexeme_count - 1].type == ATAN ||
        lexemes_[lexeme_count - 1].type == SQRT ||
        lexemes_[lexeme_count - 1].type == LN ||
        lexemes_[lexeme_count - 1].type == LOG) {
      lexemes_[lexeme_count].type = OPEN_BRACKET;
      lexemes_[lexeme_count].priority = -1;
      bracket_count++;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = OPEN_BRACKET;
    lexemes_[lexeme_count].priority = 3;
    bracket_count++;
    lexeme_count++;
  }
}

void Model::InputStringParsing::CloseBracket() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == NUMBER ||
        lexemes_[lexeme_count - 1].type == VARIABLE ||
        lexemes_[lexeme_count - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_count].type = CLOSE_BRACKET;
      lexemes_[lexeme_count].priority = -1;
      lexeme_count++;
      bracket_count--;
    } else
      return_value_ = false;
  } else
    return_value_ = false;
}

void Model::InputStringParsing::Minus() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == NUMBER ||
        lexemes_[lexeme_count - 1].type == VARIABLE ||
        lexemes_[lexeme_count - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_count].type = BINARY_MINUS;
      lexemes_[lexeme_count].priority = 1;
      lexeme_count++;
    } else if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET) {
      lexemes_[lexeme_count].type = UNARY_MINUS;
      lexemes_[lexeme_count].priority = 1;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = UNARY_MINUS;
    lexemes_[lexeme_count].priority = 1;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Plus() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == NUMBER ||
        lexemes_[lexeme_count - 1].type == VARIABLE ||
        lexemes_[lexeme_count - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_count].type = BINARY_PLUS;
      lexemes_[lexeme_count].priority = 1;
      lexeme_count++;
    } else if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET) {
      lexemes_[lexeme_count].type = UNARY_PLUS;
      lexemes_[lexeme_count].priority = 1;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = UNARY_PLUS;
    lexemes_[lexeme_count].priority = 1;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Mul() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == NUMBER ||
        lexemes_[lexeme_count - 1].type == VARIABLE ||
        lexemes_[lexeme_count - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_count].type = MUL;
      lexemes_[lexeme_count].priority = 2;
      lexeme_count++;
    } else
      return_value_ = false;
  } else
    return_value_ = false;
}

void Model::InputStringParsing::Div() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == NUMBER ||
        lexemes_[lexeme_count - 1].type == VARIABLE ||
        lexemes_[lexeme_count - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_count].type = DIV;
      lexemes_[lexeme_count].priority = 2;
      lexeme_count++;
    } else
      return_value_ = false;
  } else
    return_value_ = false;
}

void Model::InputStringParsing::Pow() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == NUMBER ||
        lexemes_[lexeme_count - 1].type == VARIABLE ||
        lexemes_[lexeme_count - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_count].type = POW;
      lexemes_[lexeme_count].priority = 3;
      lexeme_count++;
    } else
      return_value_ = false;
  } else
    return_value_ = false;
}

void Model::InputStringParsing::X() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == UNARY_PLUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD) {
      lexemes_[lexeme_count].type = VARIABLE;
      lexemes_[lexeme_count].priority = -1;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = VARIABLE;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Sin() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD) {
      lexemes_[lexeme_count].type = SIN;
      lexemes_[lexeme_count].priority = 4;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = SIN;
    lexemes_[lexeme_count].priority = 4;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Sqrt() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD) {
      lexemes_[lexeme_count].type = SQRT;
      lexemes_[lexeme_count].priority = 4;
      lexeme_count++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_count].type = SQRT;
    lexemes_[lexeme_count].priority = 4;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Cos() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD) {
      lexemes_[lexeme_count].type = COS;
      lexemes_[lexeme_count].priority = 4;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = COS;
    lexemes_[lexeme_count].priority = 4;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Tan() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD) {
      lexemes_[lexeme_count].type = TAN;
      lexemes_[lexeme_count].priority = 4;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = TAN;
    lexemes_[lexeme_count].priority = 4;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Mod() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == NUMBER ||
        lexemes_[lexeme_count - 1].type == VARIABLE ||
        lexemes_[lexeme_count - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_count].type = MOD;
      lexemes_[lexeme_count].priority = 2;
      lexeme_count++;
    } else
      return_value_ = false;
  } else
    return_value_ = false;
}

void Model::InputStringParsing::Asin() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD) {
      lexemes_[lexeme_count].type = ASIN;
      lexemes_[lexeme_count].priority = 4;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = ASIN;
    lexemes_[lexeme_count].priority = 4;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Acos() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD) {
      lexemes_[lexeme_count].type = ACOS;
      lexemes_[lexeme_count].priority = 4;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = ACOS;
    lexemes_[lexeme_count].priority = 4;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Atan() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD) {
      lexemes_[lexeme_count].type = ATAN;
      lexemes_[lexeme_count].priority = 4;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = ATAN;
    lexemes_[lexeme_count].priority = 4;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Ln() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD) {
      lexemes_[lexeme_count].type = LN;
      lexemes_[lexeme_count].priority = 4;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = LN;
    lexemes_[lexeme_count].priority = 4;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Log() {
  if (lexeme_count != 0) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD) {
      lexemes_[lexeme_count].type = LOG;
      lexemes_[lexeme_count].priority = 4;
      lexeme_count++;
    } else
      return_value_ = false;
  } else {
    lexemes_[lexeme_count].type = LOG;
    lexemes_[lexeme_count].priority = 4;
    lexeme_count++;
  }
}

void Model::InputStringParsing::Number() {
  if (((lexeme_count != 0) &&
       (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == UNARY_PLUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD)) ||
      input_count == 0) {
    char* massive_for_number = new char[SIZE]{'\0'};
    massive_for_number[0] = input_[input_count];
    int dot_counter = input_[input_count] == '.' ? 1 : 0;
    input_count++;
    int k = 1;
    for (; IsNumber(input_[input_count]) || input_[input_count] == '.'; k++) {
      if (input_[input_count] == '.') dot_counter++;
      if (dot_counter > 1) return_value_ = false;
      massive_for_number[k] = input_[input_count];
      input_count++;
    }
    if (input_[input_count] == 'e' && return_value_) {
      massive_for_number[k] = input_[input_count];
      k++;
      input_count++;
      if (input_[input_count] == '-' || input_[input_count] == '+') {
        massive_for_number[k] = input_[input_count];
        k++;
        input_count++;
        if (IsNumber(input_[input_count])) {
          for (; IsNumber(input_[input_count]); k++) {
            massive_for_number[k] = input_[input_count];
            input_count++;
          }
        } else
          return_value_ = false;
      } else if (IsNumber(input_[input_count])) {
        for (; IsNumber(input_[input_count]); k++) {
          massive_for_number[k] = input_[input_count];
          input_count++;
        }
      } else
        return_value_ = false;
    }
    if (return_value_) {
      input_count -= 1;
      lexemes_[lexeme_count].type = NUMBER;
      lexemes_[lexeme_count].priority = -1;
      lexemes_[lexeme_count].value = atof(massive_for_number);
      lexeme_count++;
    }
    delete[] massive_for_number;
  } else
    return_value_ = false;
}

void Model::InputStringParsing::FinalCheck() {
  if (return_value_) {
    if (lexemes_[lexeme_count - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_count - 1].type == UNARY_PLUS ||
        lexemes_[lexeme_count - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_count - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_count - 1].type == MUL ||
        lexemes_[lexeme_count - 1].type == DIV ||
        lexemes_[lexeme_count - 1].type == POW ||
        lexemes_[lexeme_count - 1].type == MOD ||
        lexemes_[lexeme_count - 1].type == COS ||
        lexemes_[lexeme_count - 1].type == SIN ||
        lexemes_[lexeme_count - 1].type == TAN ||
        lexemes_[lexeme_count - 1].type == ACOS ||
        lexemes_[lexeme_count - 1].type == ASIN ||
        lexemes_[lexeme_count - 1].type == ATAN ||
        lexemes_[lexeme_count - 1].type == SQRT ||
        lexemes_[lexeme_count - 1].type == LN ||
        lexemes_[lexeme_count - 1].type == LOG)
      return_value_ = false;
    if (bracket_count != 0) return_value_ = false;
    if (input_count == 0 && lexeme_count == 0) return_value_ = false;
  }
}

bool IsNumber(char c) {
  if (strchr("0123456789", c) && c != '\0') return true;
  return 0;
}

void Model::PolishNotation::TranslateToRpn(std::vector<Lexeme>& lexemes_) {
  for (int lex_cnt = 0; lexemes_[lex_cnt].type != -1; lex_cnt++) {
    if (lexemes_[lex_cnt].type == NUMBER) {
      output_amount++;
      output_[output_amount] = lexemes_[lex_cnt];
    } else if (lexemes_[lex_cnt].type == OPEN_BRACKET) {
      stack_count++;
      stack_[stack_count] = lexemes_[lex_cnt];
    } else if (IsOperator(lexemes_[lex_cnt])) {
      if (stack_count >= 0) {
        while (IsOperator(stack_[stack_count]) &&
               stack_[stack_count].priority >= lexemes_[lex_cnt].priority) {
          output_amount++;
          output_[output_amount] = stack_[stack_count];
          stack_count--;
        }
      }
      stack_count++;
      stack_[stack_count] = lexemes_[lex_cnt];
    } else if (lexemes_[lex_cnt].type == CLOSE_BRACKET) {
      while (stack_[stack_count].type != OPEN_BRACKET) {
        output_amount++;
        output_[output_amount] = stack_[stack_count];
        stack_count--;
      }
      stack_count--;
    }
  }

  while (stack_count >= 0) {
    output_amount++;
    output_[output_amount] = stack_[stack_count];
    stack_count--;
  }
}

int Model::PolishNotation::IsOperator(Lexeme lexeme) {
  int return_value = 0;
  if (UNARY_MINUS <= lexeme.type && lexeme.type <= LOG) return_value = 1;
  return return_value;
}

int Model::PolishNotation::PolishNotationCalculation(long double& result) {
  int return_value = true;
  std::vector<Lexeme> stack;
  stack.reserve(SIZE);
  int stack_count = -1;
  for (int output_cnt = 0; output_cnt <= output_amount; output_cnt++) {
    if (output_[output_cnt].type == NUMBER) {
      stack_count++;
      stack[stack_count].value = output_[output_cnt].value;
    } else if (output_[output_cnt].type == UNARY_MINUS) {
      stack[stack_count].value *= -1;
    } else if (output_[output_cnt].type == BINARY_MINUS) {
      stack[stack_count - 1].value =
          stack[stack_count - 1].value - stack[stack_count].value;
      stack_count--;
    } else if (output_[output_cnt].type == UNARY_PLUS) {
      stack[stack_count].value *= 1;
    } else if (output_[output_cnt].type == BINARY_PLUS) {
      stack[stack_count - 1].value =
          stack[stack_count - 1].value + stack[stack_count].value;
      stack_count--;
    } else if (output_[output_cnt].type == MUL) {
      stack[stack_count - 1].value =
          stack[stack_count - 1].value * stack[stack_count].value;
      stack_count--;
    } else if (output_[output_cnt].type == DIV) {
      if (stack[stack_count].value == 0)
        return_value = false;
      else {
        stack[stack_count - 1].value =
            stack[stack_count - 1].value / stack[stack_count].value;
        stack_count--;
      }
    } else if (output_[output_cnt].type == POW) {
      stack[stack_count - 1].value =
          powl(stack[stack_count - 1].value, stack[stack_count].value);
      stack_count--;
    } else if (output_[output_cnt].type == MOD) {
      if (stack[stack_count].value == 0)
        return_value = false;
      else {
        stack[stack_count - 1].value =
            fmodl(stack[stack_count - 1].value, stack[stack_count].value);
        stack_count--;
      }
    } else if (output_[output_cnt].type == COS) {
      stack[stack_count].value = cosl(stack[stack_count].value);
    } else if (output_[output_cnt].type == SIN) {
      stack[stack_count].value = sinl(stack[stack_count].value);
    } else if (output_[output_cnt].type == TAN) {
      stack[stack_count].value = tanl(stack[stack_count].value);
    } else if (output_[output_cnt].type == ACOS) {
      if (fabsl(stack[stack_count].value) > 1)
        return_value = false;
      else
        stack[stack_count].value = acosl(stack[stack_count].value);
    } else if (output_[output_cnt].type == ASIN) {
      if (fabsl(stack[stack_count].value) > 1)
        return_value = false;
      else
        stack[stack_count].value = asinl(stack[stack_count].value);
    } else if (output_[output_cnt].type == ATAN) {
      stack[stack_count].value = atanl(stack[stack_count].value);
    } else if (output_[output_cnt].type == SQRT) {
      if (stack[stack_count].value < 0)
        return_value = false;
      else
        stack[stack_count].value = sqrtl(stack[stack_count].value);
    } else if (output_[output_cnt].type == LN) {
      if (stack[stack_count].value < 0)
        return_value = false;
      else
        stack[stack_count].value = logl(stack[stack_count].value);
    } else if (output_[output_cnt].type == LOG) {
      if (stack[stack_count].value < 0)
        return_value = false;
      else
        stack[stack_count].value = log10l(stack[stack_count].value);
    }
    if (return_value == false) break;
  }
  if (return_value) result = stack[stack_count].value;
  return return_value;
}

bool Model::CheckDouble(const char* input_expr_x, long double& x) {
  bool return_value = true;
  int str_cnt = 0, dot_flag = 0;
  int str_len = (int)strlen(input_expr_x);
  if (str_len == 0) return_value = false;
  if (str_len == 1 && input_expr_x[0] == '.') return_value = false;
  if (input_expr_x[str_cnt] == '+' || input_expr_x[str_cnt] == '-') str_cnt++;
  if (IsNumber(input_expr_x[str_cnt]) || input_expr_x[str_cnt] == '.') {
    while (IsNumber(input_expr_x[str_cnt]) || input_expr_x[str_cnt] == '.') {
      if (input_expr_x[str_cnt] == '.') dot_flag++;
      if (dot_flag > 1) {
        return_value = false;
        break;
      }
      str_cnt++;
    }
    if (input_expr_x[str_cnt] == '\0') {
    } else if (input_expr_x[str_cnt] == 'e') {
      str_cnt++;
      if (input_expr_x[str_cnt] == '\0')
        return_value = false;
      else if (input_expr_x[str_cnt] == '+' || input_expr_x[str_cnt] == '-')
        str_cnt++;
      if (return_value) {
        if (IsNumber(input_expr_x[str_cnt])) {
          while (IsNumber(input_expr_x[str_cnt])) str_cnt++;
          if (IsNumber(input_expr_x[str_cnt]) != '\0') return_value = false;
        } else
          return_value = false;
      }
    } else
      return_value = false;
  } else
    return_value = false;
  if (return_value) x = atof(input_expr_x);
  return return_value;
}

bool Model::CheckGraph(const char* x_max_char_str, const char* x_min_char_str,
                       const char* y_max_char_str, const char* y_min_char_str,
                       const char* step_char_str, long double& x_max,
                       long double& x_min, long double& y_max,
                       long double& y_min, long double& step) {
  bool return_value = true;
  return_value = CheckDouble(x_max_char_str, x_max);
  return_value =
      return_value ? CheckDouble(x_min_char_str, x_min) : return_value;
  return_value =
      return_value ? CheckDouble(y_max_char_str, y_max) : return_value;
  return_value =
      return_value ? CheckDouble(y_min_char_str, y_min) : return_value;
  return_value = return_value ? CheckDouble(step_char_str, step) : return_value;
  if (step <= 0 || x_min < -1000000 || x_max > 1000000 || y_min < -1000000 ||
      y_max > 1000000 || x_min >= x_max)
    return_value = false;
  return return_value;
}

}  // namespace s21
