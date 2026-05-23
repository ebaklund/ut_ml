
#include <catch2/catch_amalgamated.hpp>
#include <cstdint>
#include <random>
#include <iostream>
#include <src/ternary.hpp>


uint32_t test_learning(const float target_w1, const float target_w2, float err, float& w1, float& w2)
{
    std::mt19937 gen(1729);
    std::uniform_real_distribution<> distr(-1.f, +1.f);

    w1 = 0.f;
    w2 = 0.f;

    int N = 50;
    int i;

    for (i = 1; i < N; ++i)
    {
        float t1 = distr(gen);
        float t2 = distr(gen);

        float target = twandz(target_w1, target_w2, t1, t2);
        twlearnz(target, t1, t2, w1, w2);
/*/
        std::cout << std::format("{}, ", twandz(w1, w2, -1.f, -1.f));
        std::cout << std::format("{}, ", twandz(w1, w2,  1.f, -1.f));
        std::cout << std::format("{}, ", twandz(w1, w2,  1.f,  1.f));
        std::cout << std::format("{}, ", twandz(w1, w2, -1.f,  1.f));
        std::cout << std::format("{}\n", twandz(w1, w2,  0.f,  0.f));
*/
        if (teq(target_w1, w1, err) && teq(target_w2, w2, err))
            break;
    }

    std::cout << std::format("i: {}, w1: {}, w2: {}\n", i, w1, w2);

    return i;
}

TEST_CASE( "learn_and", "[learn_and]" )
{
    const float err = 0.0000001f;
    float w1;
    float w2;
    test_learning(1.f, 1.f, err, w1, w2);

    REQUIRE( true == teq(1.f, w1, err) );
    REQUIRE( true == teq(1.f, w2, err) );
}

TEST_CASE( "learn_nor", "[learn_nor]" )
{
    const float err = 0.0000001f;
    float w1;
    float w2;
    test_learning(-1.f, -1.f, err, w1, w2);

    REQUIRE( true == teq(-1.f, w1, err) );
    REQUIRE( true == teq(-1.f, w2, err) );
}
