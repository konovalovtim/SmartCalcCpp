#include <gtest/gtest.h>

#include "../Controller/controller.h"

namespace s21 {
const double EPS = 1e-7;

TEST(calculate, 1) {
  Controller tmp;
  bool val =
      tmp.Calculate("16*sin(2)^2+(cos(2)^2/sin(2)^2)-7", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 6.4385994, EPS);
}

TEST(calculate, 2) {
  Controller tmp;
  bool val = tmp.Calculate(
      "15/(7-(1 + 1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))",
      "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), -30.0721649484536082, EPS);
}

TEST(calculate, 3) {
  Controller tmp;
  bool val =
      tmp.Calculate("3.5-acos(0.5)+asin(1)-atan(100)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 2.4628021, EPS);
}

TEST(calculate, 4) {
  Controller tmp;
  bool val = tmp.Calculate("sqrt(0.25)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 0.5, EPS);
}

TEST(calculate, 5) {
  Controller tmp;
  bool val = tmp.Calculate("-sqrt(0.25)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), -0.5, EPS);
}

TEST(calculate, 6) {
  Controller tmp;
  bool val = tmp.Calculate("(ln(25.9))", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 3.2542429, EPS);
}

TEST(calculate, 7) {
  Controller tmp;
  bool val = tmp.Calculate("-log(982.465)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), -2.992317, EPS);
}

TEST(calculate, 8) {
  Controller tmp;
  bool val = tmp.Calculate("+(-1+(+1))", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 0, EPS);
}

TEST(calculate, 9) {
  Controller tmp;
  bool val = tmp.Calculate("7*(2)*1", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 14, EPS);
}

TEST(calculate, 10) {
  Controller tmp;
  bool val = tmp.Calculate("2^sin(3)/1", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 1.1027608, EPS);
}

TEST(calculate, 11) {
  Controller tmp;
  bool val = tmp.Calculate("sin(-1000000)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 0.3499935, EPS);
}

TEST(calculate, 12) {
  Controller tmp;
  bool val = tmp.Calculate("cos(123456)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), -0.6722948, EPS);
}

TEST(calculate, 13) {
  Controller tmp;
  bool val = tmp.Calculate("atan(1000000)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 1.5707953, EPS);
}

TEST(calculate, 14) {
  Controller tmp;
  bool val = tmp.Calculate("tan(2)+ln(40)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 1.5038395, EPS);
}

TEST(calculate, 15) {
  Controller tmp;
  bool val = tmp.Calculate("log(2)+log(3)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 0.7781512, EPS);
}

TEST(calculate, 16) {
  Controller tmp;
  bool val =
      tmp.Calculate("sin(x)+cos(-x)+tan(+x)", "654123.891357");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 1.5927179, EPS);
}

TEST(calculate, 17) {
  Controller tmp;
  bool val =
      tmp.Calculate("sin(x)+cos(-x)+tan(+x)", "24e-4");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 1.0047971223053938, EPS);
}

TEST(calculate, 18) {
  Controller tmp;
  bool val = tmp.Calculate("(2.7e3+2)+sin(x)", "1");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 2702.841470984808, EPS);
}

TEST(calculate, 19) {
  Controller tmp;
  bool val = tmp.Calculate("x-x*x/x", "1");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 0, EPS);
}

TEST(calculate, 20) {
  Controller tmp;
  bool val = tmp.Calculate("(-0)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 0, EPS);
}

TEST(calculate, 21) {
  Controller tmp;
  bool val = tmp.Calculate("(-1*0)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 0, EPS);
}

TEST(calculate, 22) {
  Controller tmp;
  bool val = tmp.Calculate("(0*(-1))", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 0, EPS);
}

TEST(calculate, 23) {
  Controller tmp;
  bool val = tmp.Calculate("(0*(-1))", "ups");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 0, EPS);
}

TEST(calculate, 24) {
  Controller tmp;
  bool val = tmp.Calculate(
      "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), -4.3521688871149582, EPS);
}

TEST(errors, 25) {
  Controller tmp;
  bool val = tmp.Calculate("", "0");
  EXPECT_EQ(val, false);
}

TEST(errors, 26) {
  Controller tmp;
  bool val = tmp.Calculate("", 0.);
  EXPECT_EQ(val, false);
}

TEST(errors, 27) {
  Controller tmp;
  bool val = tmp.Calculate(
      "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)", 0.);
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), -4.3521688871149582, EPS);
}

TEST(errors, 28) {
  Controller tmp;
  long double x_min, x_max, y_min, y_max, step;
  bool val = tmp.CheckGraph(
      "10", "-10", "10", "-10", "0.1", x_min, x_max, y_min, y_max, step);
  EXPECT_EQ(val, true);
}

TEST(errors, 29) {
  Controller tmp;
  long double x_min, x_max, y_min, y_max, step;
  bool val =
      tmp.CheckGraph("2000000", "it's a char", "2000000", "-2000000",
                               "0.1", x_min, x_max, y_min, y_max, step);
  EXPECT_EQ(val, false);
}

TEST(errors, 30) {
  Controller tmp;
  bool val = tmp.Calculate("cos)/", "0");
  EXPECT_EQ(val, false);
}

TEST(errors, 31) {
  Controller tmp;
  bool val = tmp.Calculate("acos(5)", "0");
  EXPECT_EQ(val, false);
}

TEST(errors, 32) {
  Controller tmp;
  bool val = tmp.Calculate("asin(1.000001)", "0");
  EXPECT_EQ(val, false);
}

TEST(errors, 33) {
  Controller tmp;
  bool val = tmp.Calculate("1+2/(1-1)", "0");
  EXPECT_EQ(val, false);
}

TEST(errors, 34) {
  Controller tmp;
  bool val = tmp.Calculate("(1+2)mod(1-1)", "");
  EXPECT_EQ(val, false);
}

TEST(errors, 35) {
  Controller tmp;
  bool val = tmp.Calculate("0+sqrt(0.25)", "0");
  EXPECT_EQ(val, true);
  EXPECT_NEAR(tmp.GetResult(), 0.5, EPS);
}

TEST(errors, wrongFunctionsInput) {
  Controller tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9, tmp10, tmp11,
      tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20;
  bool val1 = tmp1.Calculate("sa(2)", "0");
  bool val2 = tmp2.Calculate("sqa(2)", "0");
  bool val3 = tmp3.Calculate("sqra(2)", "0");
  bool val4 = tmp4.Calculate("ca(2)", "0");
  bool val5 = tmp5.Calculate("coa(2)", "0");
  bool val6 = tmp6.Calculate("tn(2)", "0");
  bool val7 = tmp7.Calculate("taa(2)", "0");
  bool val8 = tmp8.Calculate("ma(2)", "0");
  bool val9 = tmp9.Calculate("moa(2)", "0");
  bool val10 = tmp10.Calculate("asa(2)", "0");
  bool val11 = tmp11.Calculate("asia(2)", "0");
  bool val12 = tmp12.Calculate("acoa(2)", "0");
  bool val13 = tmp13.Calculate("aca(2)", "0");
  bool val14 = tmp14.Calculate("aa(2)", "0");
  bool val15 = tmp15.Calculate("ato(2)", "0");
  bool val16 = tmp16.Calculate("atao(2)", "0");
  bool val17 = tmp17.Calculate("al(2)", "0");
  bool val18 = tmp18.Calculate("loa(2)", "0");
  bool val19 = tmp19.Calculate("la(2)", "0");
  bool val20 = tmp20.Calculate("sig(2)", "0");
  EXPECT_EQ(val1, false);
  EXPECT_EQ(val2, false);
  EXPECT_EQ(val3, false);
  EXPECT_EQ(val4, false);
  EXPECT_EQ(val5, false);
  EXPECT_EQ(val6, false);
  EXPECT_EQ(val7, false);
  EXPECT_EQ(val8, false);
  EXPECT_EQ(val9, false);
  EXPECT_EQ(val10, false);
  EXPECT_EQ(val11, false);
  EXPECT_EQ(val12, false);
  EXPECT_EQ(val13, false);
  EXPECT_EQ(val14, false);
  EXPECT_EQ(val15, false);
  EXPECT_EQ(val16, false);
  EXPECT_EQ(val17, false);
  EXPECT_EQ(val18, false);
  EXPECT_EQ(val19, false);
  EXPECT_EQ(val20, false);
}
}  // namespace s21