#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"

TEST_CASE("it returns a v as its when it is a seedling")
{
    Carrot carrot;
    REQUIRE(carrot.symbol() == "v");
}

TEST_CASE("it grows after 1 day")
{
    Carrot carrot;
    carrot.grow();

    REQUIRE(carrot.symbol() == "V");
}

TEST_CASE("it can't grow past mature")
{

    Carrot carrot;
    carrot.grow();
    carrot.grow();
    REQUIRE(carrot.symbol() == "V");
}
