#include "controller.h"

/*
Метод контроллера вызываемый из view
возвращает результат вида:
{[ответ], NUM} в случае, если выражение было корректным, и
{[0.0], ERROR} в случае, если выражение было некорректным
*/
void s21::Controller::InputNewExpression(std::string expression) {
  model_.InputNewExpression(expression);
}

/*
Метод контроллера вызываемый из view
возвращает результат вида:
{[ответ], NUM} в случае, если выражение было корректным, и
{[0.0], ERROR} в случае, если выражение было некорректным
*/
s21::Controller::lexem s21::Controller::GetResult() {
  return model_.GetCalculated();
}

/*
Метод контроллера вызываемый из view
высчитывает точки для графика используя метод из model
возвращает
0 - все прошло успешно
1 - выражение не содержало переменную x
*/
int s21::Controller::GraphCalculation(GraphData *data) {
  return model_.GraphCalculation(data);
}
