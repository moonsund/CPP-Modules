#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

class Test {
    private:
        size_t _test_passed;
        size_t _test_failed;

        void check(
            const std::string& test_name,
            const std::string& actual,
            const std::string& expected);
        void testBasicReplacement(void);
        void testMultipleOccurrences(void);
        void testNoMatches(void);
        void testAdjacentOccurrences(void);
        void testInvalidArgumentCount(void);
        void testNoOldValue(void);

    public:
        Test();
        void runAll();
};