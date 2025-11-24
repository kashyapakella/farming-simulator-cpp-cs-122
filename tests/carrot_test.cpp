#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"

TEST_CASE("it returns a v as its when it is a seedling")
{
    Carrot carrot;
    REQUIRE(carrot.symbol() == "-");
}

TEST_CASE("it sprouts after 1 day")
{
    Carrot carrot;
    carrot.grow();

    REQUIRE(carrot.symbol() == "'");
}

TEST_CASE("it matures after 2 days")
{

    Carrot carrot;
    carrot.grow();
    carrot.grow();
    REQUIRE(carrot.symbol() == "V");
}

TEST_CASE("it can't grow after mature")
{

    Carrot carrot;
    carrot.grow();
    carrot.grow();
    carrot.grow();

    REQUIRE(carrot.symbol() == "V");
}
