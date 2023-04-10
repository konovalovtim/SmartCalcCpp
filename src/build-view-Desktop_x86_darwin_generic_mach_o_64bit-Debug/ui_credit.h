/********************************************************************************
** Form generated from reading UI file 'credit.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_H
#define UI_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

namespace s21 {

class Ui_Credit
{
public:
    QRadioButton *radio_diff;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *res_pay;
    QLabel *res_sum;
    QPushButton *button_calc;
    QLabel *label_6;
    QRadioButton *radio_anuitet;
    QComboBox *combo_type;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *res_overpay;
    QDoubleSpinBox *spin_percent;
    QSpinBox *spin_time;
    QSpinBox *spin_sum;
    QLabel *label;

    void setupUi(QDialog *s21__Credit)
    {
        if (s21__Credit->objectName().isEmpty())
            s21__Credit->setObjectName(QString::fromUtf8("s21__Credit"));
        s21__Credit->resize(528, 381);
        radio_diff = new QRadioButton(s21__Credit);
        radio_diff->setObjectName(QString::fromUtf8("radio_diff"));
        radio_diff->setGeometry(QRect(340, 33, 161, 20));
        label_2 = new QLabel(s21__Credit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 131, 31));
        QFont font;
        font.setPointSize(18);
        label_2->setFont(font);
        label_8 = new QLabel(s21__Credit);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 269, 191, 31));
        label_8->setFont(font);
        res_pay = new QLabel(s21__Credit);
        res_pay->setObjectName(QString::fromUtf8("res_pay"));
        res_pay->setGeometry(QRect(230, 181, 281, 31));
        res_pay->setFont(font);
        res_sum = new QLabel(s21__Credit);
        res_sum->setObjectName(QString::fromUtf8("res_sum"));
        res_sum->setGeometry(QRect(230, 265, 181, 31));
        res_sum->setFont(font);
        button_calc = new QPushButton(s21__Credit);
        button_calc->setObjectName(QString::fromUtf8("button_calc"));
        button_calc->setGeometry(QRect(140, 308, 191, 51));
        label_6 = new QLabel(s21__Credit);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 226, 191, 31));
        label_6->setFont(font);
        radio_anuitet = new QRadioButton(s21__Credit);
        radio_anuitet->setObjectName(QString::fromUtf8("radio_anuitet"));
        radio_anuitet->setGeometry(QRect(340, 13, 99, 20));
        radio_anuitet->setChecked(true);
        combo_type = new QComboBox(s21__Credit);
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->setObjectName(QString::fromUtf8("combo_type"));
        combo_type->setGeometry(QRect(280, 56, 101, 61));
        QFont font1;
        font1.setPointSize(24);
        combo_type->setFont(font1);
        label_4 = new QLabel(s21__Credit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 183, 191, 31));
        label_4->setFont(font);
        label_3 = new QLabel(s21__Credit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 126, 161, 31));
        label_3->setFont(font);
        res_overpay = new QLabel(s21__Credit);
        res_overpay->setObjectName(QString::fromUtf8("res_overpay"));
        res_overpay->setGeometry(QRect(230, 224, 181, 31));
        res_overpay->setFont(font);
        spin_percent = new QDoubleSpinBox(s21__Credit);
        spin_percent->setObjectName(QString::fromUtf8("spin_percent"));
        spin_percent->setGeometry(QRect(190, 125, 111, 31));
        spin_percent->setFont(font);
        spin_percent->setDecimals(1);
        spin_percent->setMaximum(100.000000000000000);
        spin_percent->setSingleStep(0.100000000000000);
        spin_time = new QSpinBox(s21__Credit);
        spin_time->setObjectName(QString::fromUtf8("spin_time"));
        spin_time->setGeometry(QRect(80, 69, 191, 31));
        spin_time->setFont(font);
        spin_time->setMinimum(1);
        spin_time->setMaximum(10000);
        spin_time->setSingleStep(1);
        spin_time->setValue(1);
        spin_sum = new QSpinBox(s21__Credit);
        spin_sum->setObjectName(QString::fromUtf8("spin_sum"));
        spin_sum->setGeometry(QRect(140, 19, 191, 31));
        spin_sum->setFont(font);
        spin_sum->setMinimum(0);
        spin_sum->setMaximum(100000000);
        spin_sum->setSingleStep(10000);
        spin_sum->setValue(100000);
        label = new QLabel(s21__Credit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 131, 31));
        label->setFont(font);

        retranslateUi(s21__Credit);

        QMetaObject::connectSlotsByName(s21__Credit);
    } // setupUi

    void retranslateUi(QDialog *s21__Credit)
    {
        s21__Credit->setWindowTitle(QCoreApplication::translate("s21::Credit", "Dialog", nullptr));
        radio_diff->setText(QCoreApplication::translate("s21::Credit", "\320\224\320\270\321\204\321\204\320\265\321\200-\320\271", nullptr));
        label_2->setText(QCoreApplication::translate("s21::Credit", "\320\241\321\200\320\276\320\272", nullptr));
        label_8->setText(QCoreApplication::translate("s21::Credit", "\320\236\320\261\321\211\320\260\321\217 \320\262\321\213\320\277\320\273\320\260\321\202\320\260", nullptr));
        res_pay->setText(QString());
        res_sum->setText(QString());
        button_calc->setText(QCoreApplication::translate("s21::Credit", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("s21::Credit", "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320\260 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203", nullptr));
        radio_anuitet->setText(QCoreApplication::translate("s21::Credit", "\320\220\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\271", nullptr));
        combo_type->setItemText(0, QCoreApplication::translate("s21::Credit", "\320\234\320\265\321\201.", nullptr));
        combo_type->setItemText(1, QCoreApplication::translate("s21::Credit", "\320\223\320\276\320\264\320\260", nullptr));

        label_4->setText(QCoreApplication::translate("s21::Credit", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        label_3->setText(QCoreApplication::translate("s21::Credit", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        res_overpay->setText(QString());
        spin_percent->setSuffix(QCoreApplication::translate("s21::Credit", " %", nullptr));
        spin_sum->setSuffix(QCoreApplication::translate("s21::Credit", " \342\202\275", nullptr));
        label->setText(QCoreApplication::translate("s21::Credit", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
    } // retranslateUi

};

} // namespace s21

namespace s21 {
namespace Ui {
    class Credit: public Ui_Credit {};
} // namespace Ui
} // namespace s21

#endif // UI_CREDIT_H
