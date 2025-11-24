#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/brussels.hpp"

TEST_CASE("Starts as soil")
{

    Brussels brussels;
    REQUIRE(brussels.symbol() == "-");
}

TEST_CASE("Sprouts after 5 days")
{

    Brussels brussels;
    brussels.grow();
    brussels.grow();
    brussels.grow();
    brussels.grow();
    brussels.grow();

    REQUIRE(brussels.symbol() == "'");
}

TEST_CASE("Matures after 10 days")
{

    Brussels brussels;
    for (int i = 0; i < 15; i++)
    {
        brussels.grow();
    }

    REQUIRE(brussels.symbol() == "R");
}
