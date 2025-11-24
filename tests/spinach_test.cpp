#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/spinach.hpp"

TEST_CASE("Starts as soil")
{

    Spinach spinach;
    REQUIRE(spinach.symbol() == "-");
}

TEST_CASE("Sprouts after 2 days")
{

    Spinach spinach;
    spinach.grow();
    spinach.grow();

    REQUIRE(spinach.symbol() == "'");
}

TEST_CASE("Matures after 5 days")
{

    Spinach spinach;
    spinach.grow();
    spinach.grow();
    spinach.grow();
    spinach.grow();
    spinach.grow();

    REQUIRE(spinach.symbol() == "S");
}
