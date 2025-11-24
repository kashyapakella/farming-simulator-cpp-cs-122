#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/lettuce.hpp"

TEST_CASE("Starts as soil")
{

    Lettuce lettuce;
    REQUIRE(lettuce.symbol() == "-");
}

TEST_CASE("Sprouts after 2 days")
{

    Lettuce lettuce;
    lettuce.grow();
    lettuce.grow();

    REQUIRE(lettuce.symbol() == "'");
}

TEST_CASE("Matures after 4 days")
{

    Lettuce lettuce;
    lettuce.grow();
    lettuce.grow();
    lettuce.grow();
    lettuce.grow();

    REQUIRE(lettuce.symbol() == "L");
}
