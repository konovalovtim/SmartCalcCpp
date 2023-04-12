#include <gtest/gtest.h>

#include "../Controller/controller.h"

namespace s21 {
const double EPS = 1e-7;

TEST(test, 1) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("cos)(21-42)/", "0");
    EXPECT_EQ(return_value, false);
}

TEST(test, 2) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("16*sin(2)^2+(cos(2)^2/sin(2)^2)-7", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 6.4385994, EPS);
}

TEST(test, 3) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "15/(7-(1 + 1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
         "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))",
        "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -30.0721649484536082, EPS);
}

TEST(test, 4) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("acos(5)", "0");
    EXPECT_EQ(return_value, false);
}

TEST(test, 5) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("asin(1.000001)", "0");
    EXPECT_EQ(return_value, false);
}

TEST(test, 6) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("1+2/(1-1)", "0");
    EXPECT_EQ(return_value, false);
}

TEST(test, 7) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(1+2)mod(1-1)", "");
    EXPECT_EQ(return_value, false);
}

TEST(test, 8) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("3.5-acos(0.5)+asin(1)-atan(100)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 2.4628021, EPS);
}

TEST(test, 9) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("sqrt(0.25)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.5, EPS);
}

TEST(test, 10) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("0+sqrt(0.25)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.5, EPS);
}

TEST(test, 11) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("-sqrt(0.25)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -0.5, EPS);
}

TEST(test, 12) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(ln(25.9))", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 3.2542429, EPS);
}

TEST(test, 13) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("-log(982.465)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -2.992317, EPS);
}

TEST(test, 14) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("+(-1+(+1))", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, 15) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("7*(2)*1", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 14, EPS);
}

TEST(test, 16) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("2^sin(3)/1", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.1027608, EPS);
}

TEST(test, 17) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("sin(-1000000)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.3499935, EPS);
}

TEST(test, 18) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("cos(123456)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -0.6722948, EPS);
}

TEST(test, 19) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("atan(1000000)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.5707953, EPS);
}

TEST(test, 20) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("tan(2)+ln(40)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.5038395, EPS);
}

TEST(test, 21) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("log(2)+log(3)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.7781512, EPS);
}

TEST(test, 22) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("sin(x)+cos(-x)+tan(+x)", "654123.891357");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.5927179, EPS);
}

TEST(test, 23) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("sin(x)+cos(-x)+tan(+x)", "24e-4");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.0047971223053938,
                EPS);
}

TEST(test, 24) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(2.7e3+2)+sin(x)", "1");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 2702.841470984808,
                EPS);
}

TEST(test, 25) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("x-x*x/x", "1");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, 26) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(-0)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, 27) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(-1*0)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, 28) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(0*(-1))", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, 29) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(0*(-1))", "aboba");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, EPS);
}

TEST(test, 30) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -4.3521688871149582,
                EPS);
}

TEST(test, 31) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("", "0");
    EXPECT_EQ(return_value, false);
}

TEST(test, 32) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("", 0.);
    EXPECT_EQ(return_value, false);
}

TEST(test, 33) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)", 0.);
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -4.3521688871149582,
                EPS);
}

TEST(test, 34) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)", 0.);
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -4.3521688871149582,
                EPS);
}

TEST(test, 35) {
    Controller my_controller;
    long double x_min, x_max, y_min, y_max, step;
    bool return_value = my_controller.CheckGraphicParameters(
        "10", "-10", "10", "-10", "0.1", x_min, x_max, y_min, y_max, step);
    EXPECT_EQ(return_value, true);
}

TEST(test, 36) {
    Controller my_controller;
    long double x_min, x_max, y_min, y_max, step;
    bool return_value = my_controller.CheckGraphicParameters(
        "2000000", "it's a char", "2000000", "-2000000", "0.1", x_min, x_max, y_min, y_max, step);
    EXPECT_EQ(return_value, false);
}
}