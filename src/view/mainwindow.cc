#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_0_clicked() {
  ui->result->setText(ui->result->text() + "0");
}
void MainWindow::on_pushButton_1_clicked() {
  ui->result->setText(ui->result->text() + "1");
}
void MainWindow::on_pushButton_2_clicked() {
  ui->result->setText(ui->result->text() + "2");
}
void MainWindow::on_pushButton_3_clicked() {
  ui->result->setText(ui->result->text() + "3");
}
void MainWindow::on_pushButton_4_clicked() {
  ui->result->setText(ui->result->text() + "4");
}
void MainWindow::on_pushButton_5_clicked() {
  ui->result->setText(ui->result->text() + "5");
}
void MainWindow::on_pushButton_6_clicked() {
  ui->result->setText(ui->result->text() + "6");
}
void MainWindow::on_pushButton_7_clicked() {
  ui->result->setText(ui->result->text() + "7");
}
void MainWindow::on_pushButton_8_clicked() {
  ui->result->setText(ui->result->text() + "8");
}
void MainWindow::on_pushButton_9_clicked() {
  ui->result->setText(ui->result->text() + "9");
}
void MainWindow::on_pushButton_dot_clicked() {
  ui->result->setText(ui->result->text() + ".");
}
void MainWindow::on_pushButton_plus_clicked() {
  ui->result->setText(ui->result->text() + "+");
}
void MainWindow::on_pushButton_subtracting_clicked() {
  ui->result->setText(ui->result->text() + "-");
}
void MainWindow::on_pushButton_multiply_clicked() {
  ui->result->setText(ui->result->text() + "*");
}
void MainWindow::on_pushButton_division_clicked() {
  ui->result->setText(ui->result->text() + "/");
}
void MainWindow::on_pushButton_leftBracket_clicked() {
  ui->result->setText(ui->result->text() + "(");
}
void MainWindow::on_pushButton_rightBracket_clicked() {
  ui->result->setText(ui->result->text() + ")");
}
void MainWindow::on_pushButton_x_clicked() {
  ui->result->setText(ui->result->text() + "x");
}
void MainWindow::on_pushButton_sin_clicked() {
  ui->result->setText(ui->result->text() + "sin(");
}
void MainWindow::on_pushButton_cos_clicked() {
  ui->result->setText(ui->result->text() + "cos(");
}
void MainWindow::on_pushButton_tan_clicked() {
  ui->result->setText(ui->result->text() + "tan(");
}
void MainWindow::on_pushButton_atan_clicked() {
  ui->result->setText(ui->result->text() + "atan(");
}
void MainWindow::on_pushButton_acos_clicked() {
  ui->result->setText(ui->result->text() + "acos(");
}
void MainWindow::on_pushButton_asin_clicked() {
  ui->result->setText(ui->result->text() + "asin(");
}
void MainWindow::on_pushButton_log_clicked() {
  ui->result->setText(ui->result->text() + "log(");
}
void MainWindow::on_pushButton_sqrt_clicked() {
  ui->result->setText(ui->result->text() + "sqrt(");
}
void MainWindow::on_pushButton_mod_clicked() {
  ui->result->setText(ui->result->text() + "mod");
}
void MainWindow::on_pushButton_ln_clicked() {
  ui->result->setText(ui->result->text() + "ln(");
}
void MainWindow::on_pushButton_AC_clicked() { ui->result->setText(""); }
void MainWindow::on_pushButton_degree_clicked() {
  ui->result->setText(ui->result->text() + "^");
}

void MainWindow::on_pushButton_answer_clicked() {
  QByteArray tmp = ui->result->text().toLocal8Bit();
  const char* expression = tmp.data();
  QByteArray tmp_x = ui->lineEdit_xValue->text().toLocal8Bit();
  const char* expression_x = tmp_x.data();
  s21::Controller my_controller;
  bool return_value = my_controller.Calculate(expression, expression_x);
  if (return_value) {
    QString result = QString::number(my_controller.GetResult(), 'g', 15);
    ui->result->setText(result);
  } else {
    ui->result->setText("invalid expression");
    ui->result->setReadOnly(true);
  }
}

void MainWindow::on_pushButton_Graphics_clicked() {
  ui->widget->clearGraphs();
  QByteArray xMa = ui->lineEdit_xMax->text().toLocal8Bit();
  const char* x_max_char_str = xMa.data();
  QByteArray xMi = ui->lineEdit_xMin->text().toLocal8Bit();
  const char* x_min_char_str = xMi.data();
  QByteArray yMa = ui->lineEdit_yMax->text().toLocal8Bit();
  const char* y_max_char_str = yMa.data();
  QByteArray yMi = ui->lineEdit_yMin->text().toLocal8Bit();
  const char* y_min_char_str = yMi.data();
  QByteArray ste = ui->lineEdit_step->text().toLocal8Bit();
  const char* step_char_str = ste.data();
  long double x_max, x_min, y_max, y_min, step;
  QByteArray tmp = ui->result->text().toLocal8Bit();
  char* expression = tmp.data();
  s21::Controller my_controller;
  if (my_controller.CheckGraph(x_max_char_str, x_min_char_str, y_max_char_str,
                               y_min_char_str, step_char_str, x_max, x_min,
                               y_max, y_min, step) &&
      my_controller.Calculate(expression, x_min)) {
    ui->widget->xAxis->setRange(x_min, x_max);
    ui->widget->yAxis->setRange(y_min, y_max);
    for (long double counter = x_min, step = fabs(x_min - x_max) / 20000.; counter <= x_max; counter += step) {
      x.push_back(counter);
      my_controller.Calculate(expression, counter);
      y.push_back(my_controller.GetResult());
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
    x.clear();
    y.clear();
  } else
    QMessageBox::about(this, "Error", "Incorrect imput");
}
