#include <gtest/gtest.h>

#include "../Controller/controller.h"

namespace s21 {
const double EPS = 1e-7;

TEST(test, test_1) {
    // Некорректный ввод
    Controller my_controller;
    bool return_value = my_controller.Calculate(")cos)(17+4)*", "0");
    EXPECT_EQ(return_value, false);
}

TEST(test, test_2) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("16*sin(2)^2+(cos(2)^2/sin(2)^2)-7", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 6.4385994, EPS);
}

TEST(test, test_3) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "3.5-acos(0.5)+asin(1)-atan(100)+3.5-acos(0.5)+asin(1)-atan(100)+3.5-"
        "acos(0.5)+asin(1)-atan(100)",
        "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 7.3884063464702026,
                EPS);
}

TEST(test, test_4) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("acos(7)", "0");
    EXPECT_EQ(return_value, false);
}

TEST(test, test_5) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("asin(1.000001)", "0");
    EXPECT_EQ(return_value, false);
}

TEST(test, test_6) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("1+2/(1-1)", "0");
    EXPECT_EQ(return_value, false);
}

TEST(test, test_7) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(1+2)mod(1-1)", "");
    EXPECT_EQ(return_value, false);
}

TEST(test, test_8) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("3.5-acos(0.5)+asin(1)-atan(100)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 2.4628021, EPS);
}

TEST(test, test_9) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("sqrt(0.25)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.5, EPS);
}

TEST(test, test_10) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("0+sqrt(0.25)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.5, EPS);
}

TEST(test, test_11) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("-sqrt(0.25)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -0.5, EPS);
}

TEST(test, test_12) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(ln(25.9))", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 3.2542429, EPS);
}

TEST(test, test_13) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("-log(982.465)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -2.992317, EPS);
}

TEST(test, test_14) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("+(-1+(+1))", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, test_15) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("7*(2)*1", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 14, EPS);
}

TEST(test, test_16) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("2^sin(3)/1", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.1027608, EPS);
}

TEST(test, test_17) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("sin(-1000000)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.3499935, EPS);
}

TEST(test, test_18) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("cos(123456)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -0.6722948, EPS);
}

TEST(test, test_19) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("atan(1000000)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.5707953, EPS);
}

TEST(test, test_20) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("tan(2)+ln(40)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.5038395, EPS);
}

TEST(test, test_21) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("log(2)+log(3)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.7781512, EPS);
}

TEST(test, test_22) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("sin(x)+cos(-x)+tan(+x)", "654123.891357");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.5927179, EPS);
}

TEST(test, test_23) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("sin(x)+cos(-x)+tan(+x)", "24e-4");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.0047971223053938,
                EPS);
}

TEST(test, test_24) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(2.7e3+2)+sin(x)", "1");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 2702.841470984808,
                EPS);
}

TEST(test, test_25) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("x-x*x/x", "1");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, test_26) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(-0)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, test_27) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(-1*0)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, test_28) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(0*(-1))", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, test_29) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(0*(-1))", "aboba");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, test_30) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -4.3521688871149582,
                EPS);
}

TEST(test, test_31) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("", "0");
    EXPECT_EQ(return_value, false);
}

TEST(test, test_32) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("", 0.);
    EXPECT_EQ(return_value, false);
}

TEST(test, test_33) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)", 0.);
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -4.3521688871149582,
                EPS);
}

TEST(test, test_34) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)", 0.);
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -4.3521688871149582,
                EPS);
}

TEST(test, test_35) {
    Controller my_controller;
    long double x_min, x_max, y_min, y_max, step;
    bool return_value = my_controller.CheckGraphicParameters(
        "10", "-10", "10", "-10", "0.1", x_min, x_max, y_min, y_max, step);
    EXPECT_EQ(return_value, true);
}

TEST(test, test_36) {
    Controller my_controller;
    long double x_min, x_max, y_min, y_max, step;
    bool return_value = my_controller.CheckGraphicParameters(
        "10", "-10e+8bbb", "g10", "-10", "0.1", x_min, x_max, y_min, y_max, step);
    EXPECT_EQ(return_value, false);
}
}