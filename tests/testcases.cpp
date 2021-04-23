#define CATCH_CONFIG_MAIN
// #define TESTING
#include "../src/main.cpp"
#include "catch.hpp"

TEST_CASE("Testing countChar()") {
    CHECK(countChar("") == 0);            // Test for empty strings
    CHECK(countChar("12345") == 5);       // A normal test
    CHECK(countChar("12\n34\t56") == 8);  // A test for whitespaces
    CHECK(countChar("_^@") == 3);         // A test for symbols
}