/*!
\file
\brief Заголовочный файл с объявлениями функций связанных с компиляцией выржания
из инфискной в постфиксную нотацию
*/

#ifndef MODEL_H_
#define MODEL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define STACK_DEPTH 500  // Глубина стека
#define ESP 1e-7

// Значения, возвращаемые функцией parse
#define VAL 0    // В стек занесено новое значение
#define ADD 1    // Сложение
#define SUB 2    // Вычитание
#define MUL 3    // Умножение
#define DIV 4    // Деление
#define SIN 5    // sin
#define COS 6    // cos
#define TAN 7    // tan
#define CTG 8    // ctg
#define SQRT 9   // sqrt
#define LN 10    // ln
#define ASIN 11  // asin
#define ACOS 12  // acos
#define ATAN 13  // atan
#define LOG 14   // log
#define MOD 15   // mod
#define POW 16   // pow
#define SOF -1   // стек переполнен
#define SUF -2   // недостаточно операндов в стеке
#define UNK -3   // неверное значение
#define ENAN -4
#define EINF -5
#define MAX 1000

// Описание стpуктуpы(элемента стека)
struct stack {
  char c;
  struct stack *next_element;
};

/* Функции */

/**
 * @brief записывает в стек
 * переменная a возвpащает указатель на последний элемент стека
 * @param head - стек
 * @param a - символ
 */
struct stack *push(struct stack *head, char a);

/**
 * @brief Удаляет последний символ стека.
 * Возвpащает удаляемый символ.
 * Изменяет указатель на веpшину стека
 * @param head - стек
 * @param a - символ с веpшины стека
 * @return Возвpащает удаляемый символ
 */
char del(struct stack **head);

/**
 * @brief Преобразование выражений из инфиксной в обратную польскую нотацию
 * @param out_str - обрабатываемая строка
 */
void dijkstra_algorithm(char *out_str);

/**
 * @brief приоритетность операций
 * @param a - символ
 * @return возвpащает индекс приоритета
 */
int priority(char a);

/**
 * @brief Обработка ошибок и Польская нотация
 * @param str строка с элементами
 * @param x указатель на строку содержащюю параметр x
 * @return  стек с элементами
 */
int operand(const char *str, double *rez, double x);

#ifdef __cplusplus
}
#endif

#endif  // MODEL_H_
