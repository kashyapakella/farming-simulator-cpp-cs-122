#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/beet.hpp"

TEST_CASE("Starts as soil")
{

    Beet beet;
    REQUIRE(beet.symbol() == "-");
}

TEST_CASE("Sprouts after 2 days")
{

    Beet beet;
    beet.grow();
    beet.grow();

    REQUIRE(beet.symbol() == "'");
}

TEST_CASE("Matures after 7 days")
{

    Beet beet;
    beet.grow();
    beet.grow();
    beet.grow();
    beet.grow();
    beet.grow();
    beet.grow();
    beet.grow();

    REQUIRE(beet.symbol() == "B");
}
