#include "model.h"

namespace s21 {
bool Model::Input(const char* input, const char* input_x) {
  bool return_value = true;
  if ((int)strlen(input) > SIZE) return_value = false;
  InputStringParsing input_string_parsing_obj(input);
  if (return_value) {
    return_value = input_string_parsing_obj.Parsing();
    if (return_value) {
      long double x;
      bool x_correct = false;
      for (int i = 0; input_string_parsing_obj.lexemes_[i].type != -1; i++) {
        if (input_string_parsing_obj.lexemes_[i].type == VARIABLE) {
          if (!x_correct) {
            x_correct = CheckDoubleCorrectness(input_x, x);
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
      return_value = input_string_parsing_obj.Parsing();
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
  ReversePolishNotationCalculation reverse_polish_notation_obj;
  reverse_polish_notation_obj.TranslateToRpn(input_string_parsing_obj.lexemes_);
  return_value =
      reverse_polish_notation_obj.ReversePolishNotationCalculator(result_);
  if (return_value && isnan(result_)) return_value = false;
  return return_value;
}

void Model::InputStringParsing::ClearMassiveForLexemes() {
  for (int i = 0; i < SIZE; i++) lexemes_[i].type = -1;
}

bool Model::InputStringParsing::Parsing() {
  for (; input_[input_count] != '\0'; input_count++) {
    switch (input_[input_count]) {
      case '(':
        CaseOpenBracket();
        break;
      case ')':
        CaseCloseBracket();
        break;
      case '-':
        CaseMinus();
        break;
      case '+':
        CasePlus();
        break;
      case '*':
        CaseMul();
        break;
      case '/':
        CaseDiv();
        break;
      case '^':
        CasePow();
        break;
      case 'x':
        CaseX();
        break;
      case 's':
        input_count++;
        if (input_[input_count] == 'i') {
          input_count++;
          if (input_[input_count] == 'n') {
            CaseSin();
          } else {
            return_value_ = false;
          }
        } else if (input_[input_count] == 'q') {
          input_count++;
          if (input_[input_count] == 'r') {
            input_count++;
            if (input_[input_count] == 't') {
              CaseSqrt();
            } else {
              return_value_ = false;
            }
          } else {
            return_value_ = false;
          }
        } else {
          return_value_ = false;
        }
        break;
      case 'c':
        input_count++;
        if (input_[input_count] == 'o') {
          input_count++;
          if (input_[input_count] == 's') {
            CaseCos();
          } else {
            return_value_ = false;
          }
        } else {
          return_value_ = false;
        }
        break;
      case 't':
        input_count++;
        if (input_[input_count] == 'a') {
          input_count++;
          if (input_[input_count] == 'n') {
            CaseTan();
          } else {
            return_value_ = false;
          }
        } else {
          return_value_ = false;
        }
        break;
      case 'm':
        input_count++;
        if (input_[input_count] == 'o') {
          input_count++;
          if (input_[input_count] == 'd') {
            CaseMod();
          } else {
            return_value_ = false;
          }
        } else {
          return_value_ = false;
        }
        break;
      case 'a':
        input_count++;
        if (input_[input_count] == 's') {
          input_count++;
          if (input_[input_count] == 'i') {
            input_count++;
            if (input_[input_count] == 'n') {
              CaseAsin();
            } else {
              return_value_ = false;
            }
          } else {
            return_value_ = false;
          }
        } else if (input_[input_count] == 'c') {
          input_count++;
          if (input_[input_count] == 'o') {
            input_count++;
            if (input_[input_count] == 's') {
              CaseAcos();
            } else {
              return_value_ = false;
            }
          } else {
            return_value_ = false;
          }
        } else if (input_[input_count] == 't') {
          input_count++;
          if (input_[input_count] == 'a') {
            input_count++;
            if (input_[input_count] == 'n') {
              CaseAtan();
            } else {
              return_value_ = false;
            }
          } else {
            return_value_ = false;
          }
        } else {
          return_value_ = false;
        }
        break;
      case 'l':
        input_count++;
        if (input_[input_count] == 'n') {
          CaseLn();
        } else if (input_[input_count] == 'o') {
          input_count++;
          if (input_[input_count] == 'g') {
            CaseLog();
          } else {
            return_value_ = false;
          }
        } else {
          return_value_ = false;
        }
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
        CaseNumber();
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

void Model::InputStringParsing::CaseOpenBracket() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == UNARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD ||
        lexemes_[lexeme_amount - 1].type == SIN ||
        lexemes_[lexeme_amount - 1].type == COS ||
        lexemes_[lexeme_amount - 1].type == TAN ||
        lexemes_[lexeme_amount - 1].type == ACOS ||
        lexemes_[lexeme_amount - 1].type == ASIN ||
        lexemes_[lexeme_amount - 1].type == ATAN ||
        lexemes_[lexeme_amount - 1].type == SQRT ||
        lexemes_[lexeme_amount - 1].type == LN ||
        lexemes_[lexeme_amount - 1].type == LOG) {
      lexemes_[lexeme_amount].type = OPEN_BRACKET;
      lexemes_[lexeme_amount].priority = -1;
      bracket_count++;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = OPEN_BRACKET;
    lexemes_[lexeme_amount].priority = 3;
    bracket_count++;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseCloseBracket() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == NUMBER ||
        lexemes_[lexeme_amount - 1].type == VARIABLE ||
        lexemes_[lexeme_amount - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_amount].type = CLOSE_BRACKET;
      lexemes_[lexeme_amount].priority = -1;
      lexeme_amount++;
      bracket_count--;
    } else {
      return_value_ = false;
    }
  } else {
    return_value_ = false;
  }
}

void Model::InputStringParsing::CaseMinus() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == NUMBER ||
        lexemes_[lexeme_amount - 1].type == VARIABLE ||
        lexemes_[lexeme_amount - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_amount].type = BINARY_MINUS;
      lexemes_[lexeme_amount].priority = 1;
      lexeme_amount++;
    } else if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET) {
      lexemes_[lexeme_amount].type = UNARY_MINUS;
      lexemes_[lexeme_amount].priority = 1;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = UNARY_MINUS;
    lexemes_[lexeme_amount].priority = 1;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CasePlus() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == NUMBER ||
        lexemes_[lexeme_amount - 1].type == VARIABLE ||
        lexemes_[lexeme_amount - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_amount].type = BINARY_PLUS;
      lexemes_[lexeme_amount].priority = 1;
      lexeme_amount++;
    } else if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET) {
      lexemes_[lexeme_amount].type = UNARY_PLUS;
      lexemes_[lexeme_amount].priority = 1;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = UNARY_PLUS;
    lexemes_[lexeme_amount].priority = 1;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseMul() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == NUMBER ||
        lexemes_[lexeme_amount - 1].type == VARIABLE ||
        lexemes_[lexeme_amount - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_amount].type = MUL;
      lexemes_[lexeme_amount].priority = 2;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    return_value_ = false;
  }
}

void Model::InputStringParsing::CaseDiv() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == NUMBER ||
        lexemes_[lexeme_amount - 1].type == VARIABLE ||
        lexemes_[lexeme_amount - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_amount].type = DIV;
      lexemes_[lexeme_amount].priority = 2;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    return_value_ = false;
  }
}

void Model::InputStringParsing::CasePow() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == NUMBER ||
        lexemes_[lexeme_amount - 1].type == VARIABLE ||
        lexemes_[lexeme_amount - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_amount].type = POW;
      lexemes_[lexeme_amount].priority = 3;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    return_value_ = false;
  }
}

void Model::InputStringParsing::CaseX() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == UNARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD) {
      lexemes_[lexeme_amount].type = VARIABLE;
      lexemes_[lexeme_amount].priority = -1;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = VARIABLE;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseSin() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD) {
      lexemes_[lexeme_amount].type = SIN;
      lexemes_[lexeme_amount].priority = 4;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = SIN;
    lexemes_[lexeme_amount].priority = 4;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseSqrt() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD) {
      lexemes_[lexeme_amount].type = SQRT;
      lexemes_[lexeme_amount].priority = 4;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = SQRT;
    lexemes_[lexeme_amount].priority = 4;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseCos() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD) {
      lexemes_[lexeme_amount].type = COS;
      lexemes_[lexeme_amount].priority = 4;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = COS;
    lexemes_[lexeme_amount].priority = 4;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseTan() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD) {
      lexemes_[lexeme_amount].type = TAN;
      lexemes_[lexeme_amount].priority = 4;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = TAN;
    lexemes_[lexeme_amount].priority = 4;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseMod() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == NUMBER ||
        lexemes_[lexeme_amount - 1].type == VARIABLE ||
        lexemes_[lexeme_amount - 1].type == CLOSE_BRACKET) {
      lexemes_[lexeme_amount].type = MOD;
      lexemes_[lexeme_amount].priority = 2;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    return_value_ = false;
  }
}

void Model::InputStringParsing::CaseAsin() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD) {
      lexemes_[lexeme_amount].type = ASIN;
      lexemes_[lexeme_amount].priority = 4;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = ASIN;
    lexemes_[lexeme_amount].priority = 4;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseAcos() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD) {
      lexemes_[lexeme_amount].type = ACOS;
      lexemes_[lexeme_amount].priority = 4;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = ACOS;
    lexemes_[lexeme_amount].priority = 4;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseAtan() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD) {
      lexemes_[lexeme_amount].type = ATAN;
      lexemes_[lexeme_amount].priority = 4;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = ATAN;
    lexemes_[lexeme_amount].priority = 4;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseLn() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD) {
      lexemes_[lexeme_amount].type = LN;
      lexemes_[lexeme_amount].priority = 4;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = LN;
    lexemes_[lexeme_amount].priority = 4;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseLog() {
  if (lexeme_amount != 0) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD) {
      lexemes_[lexeme_amount].type = LOG;
      lexemes_[lexeme_amount].priority = 4;
      lexeme_amount++;
    } else {
      return_value_ = false;
    }
  } else {
    lexemes_[lexeme_amount].type = LOG;
    lexemes_[lexeme_amount].priority = 4;
    lexeme_amount++;
  }
}

void Model::InputStringParsing::CaseNumber() {
  if (((lexeme_amount != 0) &&
       (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == UNARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD)) ||
      input_count == 0) {
    char* massive_for_number = new char[SIZE]{'\0'};
    massive_for_number[0] = input_[input_count];
    int dot_counter = input_[input_count] == '.' ? 1 : 0;
    input_count++;
    int k = 1;
    for (; IsNumber(input_[input_count]) || input_[input_count] == '.'; k++) {
      if (input_[input_count] == '.') {
        dot_counter++;
      }
      if (dot_counter > 1) {
        return_value_ = false;
      }
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
        } else {
          return_value_ = false;
        }
      } else if (IsNumber(input_[input_count])) {
        for (; IsNumber(input_[input_count]); k++) {
          massive_for_number[k] = input_[input_count];
          input_count++;
        }
      } else {
        return_value_ = false;
      }
    }
    if (return_value_) {
      input_count -= 1;
      lexemes_[lexeme_amount].type = NUMBER;
      lexemes_[lexeme_amount].priority = -1;
      lexemes_[lexeme_amount].value = atof(massive_for_number);
      lexeme_amount++;
    }
    delete[] massive_for_number;
  } else {
    return_value_ = false;
  }
}

void Model::InputStringParsing::FinalCheck() {
  if (return_value_) {
    if (lexemes_[lexeme_amount - 1].type == OPEN_BRACKET ||
        lexemes_[lexeme_amount - 1].type == UNARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == UNARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_MINUS ||
        lexemes_[lexeme_amount - 1].type == BINARY_PLUS ||
        lexemes_[lexeme_amount - 1].type == MUL ||
        lexemes_[lexeme_amount - 1].type == DIV ||
        lexemes_[lexeme_amount - 1].type == POW ||
        lexemes_[lexeme_amount - 1].type == MOD ||
        lexemes_[lexeme_amount - 1].type == COS ||
        lexemes_[lexeme_amount - 1].type == SIN ||
        lexemes_[lexeme_amount - 1].type == TAN ||
        lexemes_[lexeme_amount - 1].type == ACOS ||
        lexemes_[lexeme_amount - 1].type == ASIN ||
        lexemes_[lexeme_amount - 1].type == ATAN ||
        lexemes_[lexeme_amount - 1].type == SQRT ||
        lexemes_[lexeme_amount - 1].type == LN ||
        lexemes_[lexeme_amount - 1].type == LOG)
      return_value_ = false;

    if (bracket_count != 0) return_value_ = false;

    if (input_count == 0 && lexeme_amount == 0) return_value_ = false;
  }
}

bool IsNumber(char c) {
  if (strchr("0123456789", c) && c != '\0') return true;
  return 0;
}

void Model::ReversePolishNotationCalculation::TranslateToRpn(
    std::vector<Lexeme>& lexemes_) {
  for (int lex_cnt = 0; lexemes_[lex_cnt].type != -1; lex_cnt++) {
    if (lexemes_[lex_cnt].type == NUMBER) {
      output_amount_++;
      output_[output_amount_] = lexemes_[lex_cnt];
    } else if (lexemes_[lex_cnt].type == OPEN_BRACKET) {
      stack_cnt_++;
      stack_[stack_cnt_] = lexemes_[lex_cnt];
    } else if (IsOperator(lexemes_[lex_cnt])) {
      if (stack_cnt_ >= 0) {
        while (IsOperator(stack_[stack_cnt_]) &&
               stack_[stack_cnt_].priority >= lexemes_[lex_cnt].priority) {
          output_amount_++;
          output_[output_amount_] = stack_[stack_cnt_];
          stack_cnt_--;
        }
      }
      stack_cnt_++;
      stack_[stack_cnt_] = lexemes_[lex_cnt];
    } else if (lexemes_[lex_cnt].type == CLOSE_BRACKET) {
      while (stack_[stack_cnt_].type != OPEN_BRACKET) {
        output_amount_++;
        output_[output_amount_] = stack_[stack_cnt_];
        stack_cnt_--;
      }
      stack_cnt_--;
    }
  }

  while (stack_cnt_ >= 0) {
    output_amount_++;
    output_[output_amount_] = stack_[stack_cnt_];
    stack_cnt_--;
  }
}

int Model::ReversePolishNotationCalculation::IsOperator(Lexeme lexeme) {
  int return_value = 0;
  if (UNARY_MINUS <= lexeme.type && lexeme.type <= LOG) return_value = 1;
  return return_value;
}

int Model::ReversePolishNotationCalculation::ReversePolishNotationCalculator(
    long double& result) {
  int return_value = true;
  std::vector<Lexeme> stack;
  stack.reserve(SIZE);
  int stack_cnt_ = -1;
  for (int output_cnt = 0; output_cnt <= output_amount_; output_cnt++) {
    if (output_[output_cnt].type == NUMBER) {
      stack_cnt_++;
      stack[stack_cnt_].value = output_[output_cnt].value;
    } else if (output_[output_cnt].type == UNARY_MINUS) {
      stack[stack_cnt_].value *= -1;
    } else if (output_[output_cnt].type == BINARY_MINUS) {
      stack[stack_cnt_ - 1].value =
          stack[stack_cnt_ - 1].value - stack[stack_cnt_].value;
      stack_cnt_--;
    } else if (output_[output_cnt].type == UNARY_PLUS) {
      stack[stack_cnt_].value *= 1;
    } else if (output_[output_cnt].type == BINARY_PLUS) {
      stack[stack_cnt_ - 1].value =
          stack[stack_cnt_ - 1].value + stack[stack_cnt_].value;
      stack_cnt_--;
    } else if (output_[output_cnt].type == MUL) {
      stack[stack_cnt_ - 1].value =
          stack[stack_cnt_ - 1].value * stack[stack_cnt_].value;
      stack_cnt_--;
    } else if (output_[output_cnt].type == DIV) {
      if (stack[stack_cnt_].value == 0) {
        return_value = false;
      } else {
        stack[stack_cnt_ - 1].value =
            stack[stack_cnt_ - 1].value / stack[stack_cnt_].value;
        stack_cnt_--;
      }
    } else if (output_[output_cnt].type == POW) {
      stack[stack_cnt_ - 1].value =
          powl(stack[stack_cnt_ - 1].value, stack[stack_cnt_].value);
      stack_cnt_--;
    } else if (output_[output_cnt].type == MOD) {
      if (stack[stack_cnt_].value == 0) {
        return_value = false;
      } else {
        stack[stack_cnt_ - 1].value =
            fmodl(stack[stack_cnt_ - 1].value, stack[stack_cnt_].value);
        stack_cnt_--;
      }
    } else if (output_[output_cnt].type == COS) {
      stack[stack_cnt_].value = cosl(stack[stack_cnt_].value);
    } else if (output_[output_cnt].type == SIN) {
      stack[stack_cnt_].value = sinl(stack[stack_cnt_].value);
    } else if (output_[output_cnt].type == TAN) {
      stack[stack_cnt_].value = tanl(stack[stack_cnt_].value);
    } else if (output_[output_cnt].type == ACOS) {
      if (fabsl(stack[stack_cnt_].value) > 1) {
        return_value = false;
      } else {
        stack[stack_cnt_].value = acosl(stack[stack_cnt_].value);
      }
    } else if (output_[output_cnt].type == ASIN) {
      if (fabsl(stack[stack_cnt_].value) > 1) {
        return_value = false;
      } else {
        stack[stack_cnt_].value = asinl(stack[stack_cnt_].value);
      }
    } else if (output_[output_cnt].type == ATAN) {
      stack[stack_cnt_].value = atanl(stack[stack_cnt_].value);
    } else if (output_[output_cnt].type == SQRT) {
      if (stack[stack_cnt_].value < 0) {
        return_value = false;
      } else {
        stack[stack_cnt_].value = sqrtl(stack[stack_cnt_].value);
      }
    } else if (output_[output_cnt].type == LN) {
      if (stack[stack_cnt_].value < 0) {
        return_value = false;
      } else {
        stack[stack_cnt_].value = logl(stack[stack_cnt_].value);
      }
    } else if (output_[output_cnt].type == LOG) {
      if (stack[stack_cnt_].value < 0) {
        return_value = false;
      } else {
        stack[stack_cnt_].value = log10l(stack[stack_cnt_].value);
      }
    }
    if (return_value == false) break;
  }
  if (return_value) result = stack[stack_cnt_].value;
  return return_value;
}

bool Model::CheckDoubleCorrectness(const char* input_expr_x, long double& x) {
  bool return_value = true;
  int str_cnt = 0, dot_flag = 0;
  int str_len = (int)strlen(input_expr_x);
  if (str_len == 0) return_value = false;
  if (str_len == 1 && input_expr_x[0] == '.') return_value = false;
  if (input_expr_x[str_cnt] == '+' || input_expr_x[str_cnt] == '-') {
    str_cnt++;
  }
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
      if (input_expr_x[str_cnt] == '\0') {
        return_value = false;
      } else if (input_expr_x[str_cnt] == '+' || input_expr_x[str_cnt] == '-') {
        str_cnt++;
      }
      if (return_value) {
        if (IsNumber(input_expr_x[str_cnt])) {
          while (IsNumber(input_expr_x[str_cnt])) {
            str_cnt++;
          }
          if (IsNumber(input_expr_x[str_cnt]) != '\0') {
            return_value = false;
          }
        } else {
          return_value = false;
        }
      }
    } else {
      return_value = false;
    }
  } else {
    return_value = false;
  }

  if (return_value) {
    x = atof(input_expr_x);
  }
  return return_value;
}

bool Model::CheckGraphicParameters(
    const char* x_max_char_str, const char* x_min_char_str,
    const char* y_max_char_str, const char* y_min_char_str,
    const char* step_char_str, long double& x_max, long double& x_min,
    long double& y_max, long double& y_min, long double& step) {
  bool return_value = true;
  return_value = CheckDoubleCorrectness(x_max_char_str, x_max);
  return_value = return_value ? CheckDoubleCorrectness(x_min_char_str, x_min)
                              : return_value;
  return_value = return_value ? CheckDoubleCorrectness(y_max_char_str, y_max)
                              : return_value;
  return_value = return_value ? CheckDoubleCorrectness(y_min_char_str, y_min)
                              : return_value;
  return_value =
      return_value ? CheckDoubleCorrectness(step_char_str, step) : return_value;
  if (step <= 0 || x_min < -1000000 || x_max > 1000000 || y_min < -1000000 ||
      y_max > 1000000 || x_max - x_min < step || y_max - y_min < step) {
    return_value = false;
  }
  return return_value;
}
}  // namespace s21
