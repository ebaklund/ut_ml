
#include <catch2/catch_amalgamated.hpp>
#include <cstdint>
#include <random>
#include <iostream>
#include <src/ternary.hpp>


uint32_t test_learning(const float target_w1, const float target_w2, const float target_wr, float err, float& w1, float& w2, float& wr)
{
    std::mt19937 gen(1729);
    std::uniform_real_distribution<> distr(-1.f, +1.f);

    w1 = 0.f;
    w2 = 0.f;
    wr = 0.f;

    int N = 5000;
    int i;

    for (i = 1; i < N; ++i)
    {
        float t1 = distr(gen);
        float t2 = distr(gen);

        float target = tzw_and(target_w1, target_w2, target_wr, t1, t2);
        tzw_learn(target, t1, t2, w1, w2, wr);
/*/
        std::cout << std::format("{}, ", tzw_and(w1, w2, -1.f, -1.f));
        std::cout << std::format("{}, ", tzw_and(w1, w2,  1.f, -1.f));
        std::cout << std::format("{}, ", tzw_and(w1, w2,  1.f,  1.f));
        std::cout << std::format("{}, ", tzw_and(w1, w2, -1.f,  1.f));
        std::cout << std::format("{}\n", tzw_and(w1, w2,  0.f,  0.f));
*/
        if (teq(target_w1, w1, err) && teq(target_w2, w2, err))
            break;
    }

    std::cout << std::format("i: {}, w1: {}, w2: {}, wr: {}\n", i, w1, w2, wr);

    return i;
}

TEST_CASE( "learn_and", "[learn_and]" )
{
    const float err = 0.0000001f;
    float w1, w2, wr;
    test_learning(1.f, 1.f, 1.f, err, w1, w2, wr);

    REQUIRE( true == teq(1.f, w1, err) );
    REQUIRE( true == teq(1.f, w2, err) );
    REQUIRE( true == teq(1.f, wr, err) );
}

TEST_CASE( "learn_nor", "[learn_nor]" )
{
    const float err = 0.0000001f;
    float w1, w2, wr;
    test_learning(-1.f, -1.f, 1.f, err, w1, w2, wr);

    REQUIRE( true == teq(-1.f, w1, err) );
    REQUIRE( true == teq(-1.f, w2, err) );
    REQUIRE( true == teq( 1.f, wr, err) );
}
