#include "s21_smart_calc.h"

double stack[STACK_DEPTH];
void dijkstra_algorithm(char *out_str) {
  struct stack *operands = NULL;  // стек
  int input_char_number = 0;  // номер символа во входной строке
  int output_char_number = 0;  // номер символа в выходной строке
  char str_arr[STACK_DEPTH];  // массив для символов преобразованной строки
  strncpy(str_arr, "", STACK_DEPTH - 1);  // зануляем str_arr
  int bracket = 0;                        // скобка
  // Пока в исходной строке есть необработанные лексемы, считываем очередную
  while (out_str[input_char_number] != '\0' &&
         out_str[input_char_number] != '=') {
    // Если лексема открывающая скобка - помещаем в стек
    if (out_str[input_char_number] == '(') bracket++;
    if (out_str[input_char_number] == ')' && bracket > 0) {
      while (operands->c != '(') {
        str_arr[output_char_number++] = del(&operands);
        str_arr[output_char_number++] = ' ';
      }
      del(&operands);
      bracket--;
    }
    // Если лексема аргумент функции - помещаем в стек
    if (out_str[input_char_number] == 'x')
      str_arr[output_char_number++] = 'x', str_arr[output_char_number++] = ' ';
    // Если лексема число - помещаем в стек
    if (out_str[input_char_number] >= '0' &&
        out_str[input_char_number] <= '9') {
      while (strchr("0123456789.,", out_str[input_char_number]) != NULL &&
             out_str[input_char_number] != '\0')
        str_arr[output_char_number++] = (out_str[input_char_number++] != ',')
                                            ? out_str[input_char_number - 1]
                                            : '.';
      input_char_number--;
      str_arr[output_char_number++] = ' ';
    }
    // Если лексема оператор или функция - помещаем в стек
    if (strchr("(+-/*asctlm^", out_str[input_char_number]) != NULL) {
      int flag = 1;
      char str = out_str[input_char_number];
      if (!strncmp(&out_str[input_char_number], "sin", 3) ||
          !strncmp(&out_str[input_char_number], "cos", 3) ||
          !strncmp(&out_str[input_char_number], "tan", 3) ||
          !strncmp(&out_str[input_char_number], "log", 3) ||
          !strncmp(&out_str[input_char_number], "mod", 3))
        input_char_number += 2, flag = 0;
      if (flag) {
        if (!strncmp(&out_str[input_char_number], "asin", 4))
          str = 'S', input_char_number += 3;
        if (!strncmp(&out_str[input_char_number], "acos", 4))
          str = 'C', input_char_number += 3;
        if (!strncmp(&out_str[input_char_number], "atan", 4))
          str = 'T', input_char_number += 3;
        if (!strncmp(&out_str[input_char_number], "sqrt", 4))
          str = 'q', input_char_number += 3;
        if (!strncmp(&out_str[input_char_number], "ln", 2))
          str = 'L', input_char_number += 1;
      }
      // Пока лексема на вершине стека не станет открывающей скобкой,
      // перекладываем лексемы-операторы из стека в выходную очередь
      while (operands != NULL && out_str[input_char_number] != '(' &&
             priority(operands->c) >= priority(str))
        str_arr[output_char_number++] = del(&operands),
        str_arr[output_char_number++] = ' ';
      if ((out_str[input_char_number] == '(' &&
           out_str[input_char_number + 1] == '-') ||
          (input_char_number == 0 && out_str[input_char_number] == '-')) {
        if (out_str[input_char_number] == '(')
          operands = push(operands, '('), input_char_number++;
        operands = push(operands, 'M');
      } else {
        operands = push(operands, str);
      }
    }
    input_char_number++;
  }
  while (operands != NULL) {
    str_arr[output_char_number++] = del(&operands);
    str_arr[output_char_number++] = ' ';
  }
  str_arr[output_char_number] = '\0';
  strncpy(out_str, str_arr, STACK_DEPTH);
}

int priority(char a) {
  int i = 0;
  switch (a) {
    case 's':
    case 'S':
    case 'c':
    case 'C':
    case 't':
    case 'T':
    case 'q':
    case 'L':
    case 'l':
      i = 7;
      break;
    case '^':
      i = 6;
      break;
    case 'M':
      i = 5;
      break;
    case '*':
    case '/':
      i = 4;
      break;
    case 'm':
      i = 3;
      break;
    case '-':
    case '+':
      i = 2;
      break;
    case '(':
      i = 1;
      break;
  }
  return i;
}

char del(struct stack **head) {
  char a = 0;
  struct stack *ptr = 0;
  if (*head == NULL) a = '\0';
  ptr = *head;
  a = ptr->c;
  *head = ptr->next_element;
  free(ptr);
  return a;
}

struct stack *push(struct stack *head, char a) {
  struct stack *ptr = 0;
  if ((ptr = (struct stack *)malloc(sizeof(struct stack))) == NULL) exit(1);
  ptr->c = a;
  ptr->next_element = head;
  return ptr;
}

int operand(const char *str, double *rez, double x) {
  char *endptr = NULL;  // ошибка перевода в число
  int error = 0;        // ошибки
  int scount = 0;       // счетчик элементов в стеке
  char s[STACK_DEPTH] = "";
  strcpy(s, str);
  char *str_temp = strtok(s, " ");  // элемент из нотации

  while (str_temp && !error) {
    if ((strchr("+*/m^", *str_temp) != NULL && scount < 2) ||
        (strchr("-asScCtTqLl", *str_temp) != NULL && scount < 1)) {
      error = SUF;
    } else {
      --scount;
      switch (*str_temp) {
        case '-':
          stack[scount - 1] -= stack[scount];
          break;
        case '+':
          stack[scount - 1] += stack[scount];
          break;
        case '*':
          stack[scount - 1] *= stack[scount];
          break;
        case '^':
          stack[scount - 1] = pow(stack[scount - 1], stack[scount]);
          break;
        case '/':
          if (stack[scount] != 0 && stack[scount - 1] != 0)
            stack[scount - 1] /= stack[scount];
          else if (stack[scount] == 0 && stack[scount - 1] == 0)
            error = ENAN;
          else if (stack[scount] == 0)
            error = EINF;
          else
            stack[scount - 1] = 0;
          break;
        case 'm':
          if (stack[scount] != 0 && stack[scount - 1] != 0)
            stack[scount - 1] = fmod(stack[scount - 1], stack[scount]);
          else if (stack[scount] == 0 && stack[scount - 1] == 0)
            error = ENAN;
          else if (stack[scount] == 0)
            error = EINF;
          else
            stack[scount - 1] = 0;
          break;
        case 'M':
          stack[scount] = -stack[scount];
          break;
        case 's':
          stack[scount] = sin(stack[scount]);
          break;
        case 'S':
          stack[scount] = asin(stack[scount]);
          break;
        case 'c':
          stack[scount] = cos(stack[scount]);
          break;
        case 'C':
          stack[scount] = acos(stack[scount]);
          break;
        case 't':
          stack[scount] = tan(stack[scount]);
          break;
        case 'T':
          stack[scount] = atan(stack[scount]);
          break;
        case 'q':
          if (stack[scount] < 0)
            error = ENAN;
          else
            stack[scount] = sqrt(stack[scount]);
          break;
        case 'L':
          if (stack[scount] < 0)
            error = ENAN;
          else
            stack[scount] = log10(stack[scount]);
          break;
        case 'l':
          if (stack[scount] < 0)
            error = ENAN;
          else
            stack[scount] = log(stack[scount]);
          break;
        default: {
          scount++;
          if (str_temp[0] == 'x') {
            stack[scount++] = x;
          } else {
            double tval;  // хранит операнд для загрузки в стек
            if (str_temp[0] == '_') str_temp[0] = '-';
            tval = strtod(str_temp, &endptr);
            if (*endptr != '\0') {
              error = UNK;
            } else {
              if (scount < STACK_DEPTH)
                stack[scount++] = tval;
              else
                error = SOF;
            }
          }
          break;
        }
      }
      if (strchr("MasScCtTqLl", *str_temp) != NULL) scount++;
      str_temp = strtok(NULL, " ");
    }
  }
  *rez = stack[0];
  return error;
}
