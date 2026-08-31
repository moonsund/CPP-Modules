#include "Test.hpp"
#include "Replace.hpp"

Test::Test() : _test_passed(0), _test_failed(0) {}

void Test::check(const std::string& test_name, const std::string& actual, const std::string& expected) {
    if (actual == expected) {
        std::cout << test_name << " PASSED" << std::endl;
        _test_passed++;
    }
    else {
        std::cout << test_name << " FAILED" << std::endl;
        std::cout << "actual: " << actual << std::endl;
        std::cout << "expected: " << expected << std::endl;
        _test_failed++;
    }
}

void Test::testBasicReplacement(void) {
    std::string test_name = "'Basic Replacement'";
    std::string actual = ft_replace("Hello world", "world", "C++");
    std::string expected = "Hello C++";
    check(test_name, actual, expected);
}

void Test::testMultipleOccurrences(void) {
    std::string test_name = "'Multiple Occurrences'";
    std::string actual = ft_replace("cat dog cat", "cat", "fox");
    std::string expected = "fox dog fox";
    check(test_name, actual, expected);
}

void Test::testNoMatches(void) {
    std::string test_name = "'No Matches'";
    std::string actual = ft_replace("Hello world", "cat", "fox");
    std::string expected = "Hello world";
    check(test_name, actual, expected);
}

void Test::testAdjacentOccurrences(void) {
    std::string test_name = "'Adjacent Occurrences'";
    std::string actual = ft_replace("aaaa", "aa", "bbb");
    std::string expected = "bbbbbb";
    check(test_name, actual, expected);
}

void Test::testInvalidArgumentCount(void) {
    std::string test_name = "'Invalid Argument Count'";
    std::system("./ex04 file 2> test_error.txt");

    std::ifstream file("test_error.txt");
    std::string actual;
    std::getline(file, actual);

    std::string expected = "Error. Usage: ./ex04 <filename> <old_value> <new_value>";
    check(test_name, actual, expected);
}

void Test::testNoOldValue(void) {
    std::string test_name = "'No Old Value'";
    std::system("./ex04 file '' new_value 2> test_error.txt");

    std::ifstream file("test_error.txt");
    std::string actual;
    std::getline(file, actual);

    std::string expected = "Error. <old_value> can not be empty";
    check(test_name, actual, expected);
}

void Test::runAll() {
    _test_passed = 0;
    _test_failed = 0;
    testBasicReplacement();
    testMultipleOccurrences();
    testNoMatches();
    testAdjacentOccurrences();
    testInvalidArgumentCount();
    testNoOldValue();

    if (_test_failed == 0) {
        std::cout << "All tests passed" << std::endl;
    }
    else {
        std::cout << "tests passed: " << _test_passed << std::endl;
        std::cout << "tests failed: " << _test_failed << std::endl;
    }
}