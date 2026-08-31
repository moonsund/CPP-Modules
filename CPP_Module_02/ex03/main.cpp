#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>


struct TestCase {
    const char* name;
    Point       a;
    Point       b;
    Point       c;
    Point       point;
    bool        expected;

    TestCase(
        const char* testName,
        const Point& triangleA,
        const Point& triangleB,
        const Point& triangleC,
        const Point& testedPoint,
        bool expectedResult
    )
        : name(testName),
          a(triangleA),
          b(triangleB),
          c(triangleC),
          point(testedPoint),
          expected(expectedResult) {
    }
};

TestCase tests[] = {
    TestCase(
        "point inside",
        Point(0.0f, 0.0f),
        Point(4.0f, 0.0f),
        Point(0.0f, 4.0f),
        Point(1.0f, 1.0f),
        true
    ),
    TestCase(
        "point outside",
        Point(0.0f, 0.0f),
        Point(4.0f, 0.0f),
        Point(0.0f, 4.0f),
        Point(4.0f, 4.0f),
        false
    ),
    TestCase(
        "point on edge",
        Point(0.0f, 0.0f),
        Point(4.0f, 0.0f),
        Point(0.0f, 4.0f),
        Point(2.0f, 0.0f),
        false
    ),
    TestCase(
        "matching point",
        Point(0.0f, 0.0f),
        Point(4.0f, 0.0f),
        Point(0.0f, 4.0f),
        Point(0.0f, 0.0f),
        false
    )
};

int main(void) { 
    int passed = 0;
    int testCount = sizeof(tests) / sizeof(tests[0]);
    
    std::cout << std::boolalpha; // bool representation

    for (int i = 0; i < testCount; ++i) {
        bool actual = bsp(
            tests[i].a,
            tests[i].b,
            tests[i].c,
            tests[i].point
    );

    bool result = actual == tests[i].expected;

    std::cout
        << (result ? "[PASS] " : "[FAIL] ")
        << tests[i].name
        << " | expected: " << tests[i].expected
        << ", actual: " << actual
        << std::endl;

    if (result)
        ++passed;
}

std::cout
    << "\nPassed: " << passed
    << "/" << testCount
    << std::endl;
    return 0; 
}



// Чтобы выводить true и false, а не 1 и 0, перед циклом можно включить:
// std::cout << std::boolalpha;