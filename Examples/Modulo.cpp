
#include "../Primitives/Ternary.hpp"
#include <iostream>
#include <array>
#include <format>
#include <cstdint>


int main(int argc, char** argv)
{
    std::cout << "Hello, World!\n";
    const uint32_t N = 8;

    for (uint32_t i = 0; i < N; ++i)
    {
        uint32_t j = disbed<N>(embed<N>(i));
        std::cout << std::format("{} ?= {}\n", i, j);
    }
}
