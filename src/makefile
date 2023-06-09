CCFLAGS = g++ -std=c++17 -Wall -Wextra -Werror -lgtest_main
OS = $(shell uname)
ifeq ($(OS), Linux)
	GTEST_FLAGS = -lgtest -lm -pthread -lrt -lsubunit
else
	GTEST_FLAGS = -lgtest
endif

all: test install clean

s21_smartcalc.a: s21_smartcalc.o
	@ar rcs libs21_smartcalc.a *.o
	@rm -rf *.o
	@ranlib libs21_smartcalc.a
	@cp libs21_smartcalc.a s21_smartcalc.a
	@cp libs21_smartcalc.a ls21_smartcalc.a

s21_smartcalc.o:
	@$(CCFLAGS) -c unit_tests/unit_tests.cc Model/model.cc Controller/controller.cc

install:
	@echo "Please wait..."
	@cd View && qmake && make && make clean && rm Makefile
	@mv View/SmartCalc.app/Contents/MacOS/SmartCalc .
	@./SmartCalc

uninstall:
	@rm -rf View/SmareCalc.app SmartCalc

test: s21_smartcalc.a
	@$(CCFLAGS) unit_tests/unit_tests.cc s21_smartcalc.a $(GTEST_FLAGS) -L. -ls21_smartcalc
	@./a.out

dvi: clean
	@doxygen conf && mv html documentation
	@open documentation/index.html

dist: clean
	@mkdir SmartCalc
	@cp -r Controller/*.cc Controller/*.h Model/*.cc Model/*.h View/*.cc View/*.h View/*.ui View/*.pro Makefile unit_tests/ SmartCalc
	@tar -cvzf dist.tar.gz SmartCalc
	@-rm -rf SmartCalc

gcov_report: test
	@echo "Please wait..."
	@rm -f *.g*
	@$(CCFLAGS) unit_tests/unit_tests.cc Model/model.cc Controller/controller.cc $(GTEST_FLAGS) -L. --coverage -ls21_smartcalc
	@./a.out
	@lcov -t a.out -o rep.info --no-external -c -d .
	@genhtml -o report rep.info
	@open ./report/index.html
	@rm -rf *.gcda *.gcno *.info

leaks: test
	@CK_FORK=no leaks --atExit -- ./a.out

style:
	@echo "Please wait..."
	@clang-format -style=google -n Controller/*.cc Controller/*.h Model/*.cc Model/*.h View/*.cc View/*.h

clean: uninstall
	@rm -rf View/*.o View/*.tmp *.a *.gcda *.gcno *.gz *.info documentation html s21_test report s21_calc s21_test a.out

rebuild: clean uninstall all