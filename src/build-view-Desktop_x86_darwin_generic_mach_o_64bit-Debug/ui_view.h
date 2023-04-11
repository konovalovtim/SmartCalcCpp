/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

namespace s21 {

class Ui_View
{
public:
    QWidget *centralwidget;
    QSpinBox *spin_max;
    QPushButton *button_2;
    QPushButton *button_tan;
    QTextEdit *x_value;
    QPushButton *button_7;
    QRadioButton *radio_value;
    QPushButton *button_4;
    QPushButton *button_8;
    QRadioButton *radio_graph;
    QPushButton *button_acos;
    QLineEdit *result_show;
    QLabel *label;
    QLabel *label_2;
    QPushButton *button_dot;
    QPushButton *button_asin;
    QPushButton *button_atan;
    QPushButton *button_sqrt;
    QPushButton *button_1;
    QSpinBox *spin_min;
    QPushButton *button_3;
    QPushButton *button_close;
    QPushButton *button_9;
    QPushButton *button_minus;
    QPushButton *button_sin;
    QPushButton *button_make_graph;
    QPushButton *button_6;
    QLabel *label_3;
    QPushButton *button_pow;
    QPushButton *button_clear;
    QPushButton *button_cos;
    QPushButton *button_equal;
    QPushButton *button_5;
    QPushButton *button_mult;
    QPushButton *button_delete;
    QPushButton *button_x;
    QPushButton *button_ln;
    QPushButton *button_log;
    QPushButton *button_open;
    QPushButton *button_0;
    QPushButton *button_plus;
    QPushButton *button_div;
    QPushButton *button_mod;
    QCustomPlot *widget;

    void setupUi(QMainWindow *s21__View)
    {
        if (s21__View->objectName().isEmpty())
            s21__View->setObjectName(QString::fromUtf8("s21__View"));
        s21__View->resize(520, 618);
        s21__View->setAcceptDrops(false);
        s21__View->setAutoFillBackground(false);
        s21__View->setStyleSheet(QString::fromUtf8("QmainWindow {\n"
"	background-color : rgb(71, 72, 81);\n"
"	border: 1px solid black;\n"
"}"));
        s21__View->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(s21__View);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        spin_max = new QSpinBox(centralwidget);
        spin_max->setObjectName(QString::fromUtf8("spin_max"));
        spin_max->setEnabled(false);
        spin_max->setGeometry(QRect(328, 490, 101, 22));
        spin_max->setMinimum(-1000000);
        spin_max->setMaximum(1000000);
        spin_max->setValue(10);
        button_2 = new QPushButton(centralwidget);
        button_2->setObjectName(QString::fromUtf8("button_2"));
        button_2->setGeometry(QRect(219, 204, 100, 80));
        QFont font;
        font.setPointSize(26);
        button_2->setFont(font);
        button_tan = new QPushButton(centralwidget);
        button_tan->setObjectName(QString::fromUtf8("button_tan"));
        button_tan->setGeometry(QRect(0, 181, 117, 48));
        button_tan->setFont(font);
        x_value = new QTextEdit(centralwidget);
        x_value->setObjectName(QString::fromUtf8("x_value"));
        x_value->setEnabled(true);
        x_value->setGeometry(QRect(318, 440, 104, 41));
        QFont font1;
        font1.setPointSize(24);
        x_value->setFont(font1);
        button_7 = new QPushButton(centralwidget);
        button_7->setObjectName(QString::fromUtf8("button_7"));
        button_7->setGeometry(QRect(118, 60, 100, 80));
        button_7->setFont(font);
        radio_value = new QRadioButton(centralwidget);
        radio_value->setObjectName(QString::fromUtf8("radio_value"));
        radio_value->setEnabled(true);
        radio_value->setGeometry(QRect(108, 431, 102, 20));
        QFont font2;
        font2.setPointSize(18);
        radio_value->setFont(font2);
        radio_value->setChecked(true);
        button_4 = new QPushButton(centralwidget);
        button_4->setObjectName(QString::fromUtf8("button_4"));
        button_4->setGeometry(QRect(118, 132, 100, 80));
        button_4->setFont(font);
        button_8 = new QPushButton(centralwidget);
        button_8->setObjectName(QString::fromUtf8("button_8"));
        button_8->setGeometry(QRect(219, 60, 100, 80));
        button_8->setFont(font);
        radio_graph = new QRadioButton(centralwidget);
        radio_graph->setObjectName(QString::fromUtf8("radio_graph"));
        radio_graph->setEnabled(true);
        radio_graph->setGeometry(QRect(108, 450, 99, 20));
        radio_graph->setFont(font2);
        button_acos = new QPushButton(centralwidget);
        button_acos->setObjectName(QString::fromUtf8("button_acos"));
        button_acos->setGeometry(QRect(0, 221, 117, 48));
        button_acos->setFont(font);
        result_show = new QLineEdit(centralwidget);
        result_show->setObjectName(QString::fromUtf8("result_show"));
        result_show->setGeometry(QRect(-1, -8, 320, 72));
        result_show->setFont(font2);
        result_show->setMaxLength(255);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(272, 443, 51, 31));
        QFont font3;
        font3.setPointSize(29);
        label->setFont(font3);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(78, 490, 51, 16));
        label_2->setFont(font2);
        button_dot = new QPushButton(centralwidget);
        button_dot->setObjectName(QString::fromUtf8("button_dot"));
        button_dot->setEnabled(true);
        button_dot->setGeometry(QRect(320, 276, 100, 80));
        QFont font4;
        font4.setPointSize(48);
        button_dot->setFont(font4);
        button_dot->setCheckable(true);
        button_asin = new QPushButton(centralwidget);
        button_asin->setObjectName(QString::fromUtf8("button_asin"));
        button_asin->setGeometry(QRect(0, 261, 117, 48));
        button_asin->setFont(font);
        button_atan = new QPushButton(centralwidget);
        button_atan->setObjectName(QString::fromUtf8("button_atan"));
        button_atan->setGeometry(QRect(0, 301, 117, 48));
        button_atan->setFont(font);
        button_sqrt = new QPushButton(centralwidget);
        button_sqrt->setObjectName(QString::fromUtf8("button_sqrt"));
        button_sqrt->setGeometry(QRect(421, 359, 100, 69));
        button_sqrt->setFont(font);
        button_1 = new QPushButton(centralwidget);
        button_1->setObjectName(QString::fromUtf8("button_1"));
        button_1->setGeometry(QRect(118, 204, 100, 80));
        button_1->setFont(font);
        spin_min = new QSpinBox(centralwidget);
        spin_min->setObjectName(QString::fromUtf8("spin_min"));
        spin_min->setEnabled(false);
        spin_min->setGeometry(QRect(138, 490, 101, 22));
        spin_min->setMinimum(-1000000);
        spin_min->setMaximum(1000000);
        spin_min->setValue(-10);
        button_3 = new QPushButton(centralwidget);
        button_3->setObjectName(QString::fromUtf8("button_3"));
        button_3->setGeometry(QRect(320, 204, 100, 80));
        button_3->setFont(font);
        button_close = new QPushButton(centralwidget);
        button_close->setObjectName(QString::fromUtf8("button_close"));
        button_close->setGeometry(QRect(219, 348, 100, 80));
        button_close->setFont(font);
        button_9 = new QPushButton(centralwidget);
        button_9->setObjectName(QString::fromUtf8("button_9"));
        button_9->setGeometry(QRect(320, 60, 100, 80));
        button_9->setFont(font);
        button_minus = new QPushButton(centralwidget);
        button_minus->setObjectName(QString::fromUtf8("button_minus"));
        button_minus->setGeometry(QRect(421, 120, 100, 67));
        button_minus->setFont(font);
        button_sin = new QPushButton(centralwidget);
        button_sin->setObjectName(QString::fromUtf8("button_sin"));
        button_sin->setGeometry(QRect(0, 100, 117, 48));
        button_sin->setFont(font);
        button_make_graph = new QPushButton(centralwidget);
        button_make_graph->setObjectName(QString::fromUtf8("button_make_graph"));
        button_make_graph->setEnabled(false);
        button_make_graph->setGeometry(QRect(78, 520, 354, 41));
        button_make_graph->setFont(font);
        button_6 = new QPushButton(centralwidget);
        button_6->setObjectName(QString::fromUtf8("button_6"));
        button_6->setGeometry(QRect(320, 132, 100, 80));
        button_6->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(268, 490, 51, 16));
        label_3->setFont(font2);
        button_pow = new QPushButton(centralwidget);
        button_pow->setObjectName(QString::fromUtf8("button_pow"));
        button_pow->setGeometry(QRect(421, 299, 100, 68));
        button_pow->setFont(font);
        button_clear = new QPushButton(centralwidget);
        button_clear->setObjectName(QString::fromUtf8("button_clear"));
        button_clear->setGeometry(QRect(320, -12, 100, 80));
        button_clear->setFont(font);
        button_cos = new QPushButton(centralwidget);
        button_cos->setObjectName(QString::fromUtf8("button_cos"));
        button_cos->setGeometry(QRect(0, 140, 117, 49));
        button_cos->setFont(font);
        button_equal = new QPushButton(centralwidget);
        button_equal->setObjectName(QString::fromUtf8("button_equal"));
        button_equal->setGeometry(QRect(320, 348, 100, 80));
        button_equal->setFont(font);
        button_5 = new QPushButton(centralwidget);
        button_5->setObjectName(QString::fromUtf8("button_5"));
        button_5->setGeometry(QRect(219, 132, 100, 80));
        button_5->setFont(font);
        button_mult = new QPushButton(centralwidget);
        button_mult->setObjectName(QString::fromUtf8("button_mult"));
        button_mult->setGeometry(QRect(421, 179, 100, 68));
        QFont font5;
        font5.setPointSize(36);
        button_mult->setFont(font5);
        button_delete = new QPushButton(centralwidget);
        button_delete->setObjectName(QString::fromUtf8("button_delete"));
        button_delete->setGeometry(QRect(421, -12, 100, 80));
        button_delete->setFont(font);
        button_x = new QPushButton(centralwidget);
        button_x->setObjectName(QString::fromUtf8("button_x"));
        button_x->setGeometry(QRect(118, 276, 100, 80));
        button_x->setFont(font);
        button_ln = new QPushButton(centralwidget);
        button_ln->setObjectName(QString::fromUtf8("button_ln"));
        button_ln->setGeometry(QRect(0, 341, 117, 47));
        button_ln->setFont(font);
        button_log = new QPushButton(centralwidget);
        button_log->setObjectName(QString::fromUtf8("button_log"));
        button_log->setGeometry(QRect(0, 380, 117, 48));
        button_log->setFont(font);
        button_open = new QPushButton(centralwidget);
        button_open->setObjectName(QString::fromUtf8("button_open"));
        button_open->setGeometry(QRect(118, 348, 100, 80));
        button_open->setFont(font);
        button_0 = new QPushButton(centralwidget);
        button_0->setObjectName(QString::fromUtf8("button_0"));
        button_0->setGeometry(QRect(219, 276, 100, 80));
        button_0->setFont(font);
        button_plus = new QPushButton(centralwidget);
        button_plus->setObjectName(QString::fromUtf8("button_plus"));
        button_plus->setGeometry(QRect(421, 60, 100, 68));
        button_plus->setFont(font5);
        button_div = new QPushButton(centralwidget);
        button_div->setObjectName(QString::fromUtf8("button_div"));
        button_div->setGeometry(QRect(421, 239, 100, 68));
        button_div->setFont(font5);
        button_mod = new QPushButton(centralwidget);
        button_mod->setObjectName(QString::fromUtf8("button_mod"));
        button_mod->setGeometry(QRect(0, 60, 117, 48));
        button_mod->setFont(font);
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(523, 0, 431, 611));
        s21__View->setCentralWidget(centralwidget);

        retranslateUi(s21__View);

        QMetaObject::connectSlotsByName(s21__View);
    } // setupUi

    void retranslateUi(QMainWindow *s21__View)
    {
        s21__View->setWindowTitle(QCoreApplication::translate("s21::View", "View", nullptr));
#if QT_CONFIG(tooltip)
        s21__View->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        s21__View->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        button_2->setText(QCoreApplication::translate("s21::View", "2", nullptr));
        button_tan->setText(QCoreApplication::translate("s21::View", "tan", nullptr));
        x_value->setHtml(QCoreApplication::translate("s21::View", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:24pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1</p></body></html>", nullptr));
        button_7->setText(QCoreApplication::translate("s21::View", "7", nullptr));
        radio_value->setText(QCoreApplication::translate("s21::View", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        button_4->setText(QCoreApplication::translate("s21::View", "4", nullptr));
        button_8->setText(QCoreApplication::translate("s21::View", "8", nullptr));
        radio_graph->setText(QCoreApplication::translate("s21::View", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        button_acos->setText(QCoreApplication::translate("s21::View", "acos", nullptr));
        label->setText(QCoreApplication::translate("s21::View", "x = ", nullptr));
        label_2->setText(QCoreApplication::translate("s21::View", "X min", nullptr));
        button_dot->setText(QCoreApplication::translate("s21::View", ".", nullptr));
        button_asin->setText(QCoreApplication::translate("s21::View", "asin", nullptr));
        button_atan->setText(QCoreApplication::translate("s21::View", "atan", nullptr));
        button_sqrt->setText(QCoreApplication::translate("s21::View", "sqrt", nullptr));
        button_1->setText(QCoreApplication::translate("s21::View", "1", nullptr));
        spin_min->setSuffix(QString());
        button_3->setText(QCoreApplication::translate("s21::View", "3", nullptr));
        button_close->setText(QCoreApplication::translate("s21::View", ")", nullptr));
        button_9->setText(QCoreApplication::translate("s21::View", "9", nullptr));
        button_minus->setText(QCoreApplication::translate("s21::View", "-", nullptr));
        button_sin->setText(QCoreApplication::translate("s21::View", "sin", nullptr));
        button_make_graph->setText(QCoreApplication::translate("s21::View", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        button_6->setText(QCoreApplication::translate("s21::View", "6", nullptr));
        label_3->setText(QCoreApplication::translate("s21::View", "X max", nullptr));
        button_pow->setText(QCoreApplication::translate("s21::View", "^", nullptr));
        button_clear->setText(QCoreApplication::translate("s21::View", "<-", nullptr));
        button_cos->setText(QCoreApplication::translate("s21::View", "cos", nullptr));
        button_equal->setText(QCoreApplication::translate("s21::View", "=", nullptr));
        button_5->setText(QCoreApplication::translate("s21::View", "5", nullptr));
        button_mult->setText(QCoreApplication::translate("s21::View", "*", nullptr));
        button_delete->setText(QCoreApplication::translate("s21::View", "AC", nullptr));
        button_x->setText(QCoreApplication::translate("s21::View", "x", nullptr));
        button_ln->setText(QCoreApplication::translate("s21::View", "ln", nullptr));
        button_log->setText(QCoreApplication::translate("s21::View", "log", nullptr));
        button_open->setText(QCoreApplication::translate("s21::View", "(", nullptr));
        button_0->setText(QCoreApplication::translate("s21::View", "0", nullptr));
        button_plus->setText(QCoreApplication::translate("s21::View", "+", nullptr));
        button_div->setText(QCoreApplication::translate("s21::View", "/", nullptr));
        button_mod->setText(QCoreApplication::translate("s21::View", "mod", nullptr));
    } // retranslateUi

};

} // namespace s21

namespace s21 {
namespace Ui {
    class View: public Ui_View {};
} // namespace Ui
} // namespace s21

#endif // UI_VIEW_H
