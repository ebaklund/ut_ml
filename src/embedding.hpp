
#pragma once

#include "ternary.hpp"

template<uint32_t N>
std::array<float,N> embed(uint32_t val)
{
    std::array<float,N> embedding;
    float* p = embedding.data();

    for (uint32_t i = 0; i < N; ++i)
        *(p++) = b_to_t((val >> i)&1);

    return embedding;
}

template<uint32_t N>
uint32_t disbed(std::array<float,N> embedding)
{
    uint32_t disbedding = 0;
    float* p = embedding.data();

    for (uint32_t i = 0; i < N; ++i)
        disbedding += ((uint32_t) t_to_b(*(p++))) << i;

    return disbedding;
}
