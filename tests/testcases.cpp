#define CATCH_CONFIG_MAIN
// #define TESTING
#include "../src/main.cpp"
#include "catch.hpp"

TEST_CASE("Testing countChar()") {
    CHECK(countChar("") == 0);
    CHECK(countChar("12345") == 5);
    CHECK(countChar("12\n34\t56") == 8);
    CHECK(countChar("_^@") == 3);
}