
#include <catch2/catch_amalgamated.hpp>
#include <cstdint>
#include <src/embedding.hpp>

TEST_CASE( "embedding", "[embedding]" ) {
    static const uint32_t N = 8;
    REQUIRE( disbed<N>(embed<N>(0)) == 0);
    REQUIRE( disbed<N>(embed<N>(1)) == 1);
    REQUIRE( disbed<N>(embed<N>(2)) == 2);
    REQUIRE( disbed<N>(embed<N>(3)) == 3);
    REQUIRE( disbed<N>(embed<N>(4)) == 4);
    REQUIRE( disbed<N>(embed<N>(5)) == 5);
    REQUIRE( disbed<N>(embed<N>(6)) == 6);
    REQUIRE( disbed<N>(embed<N>(7)) == 7);
    REQUIRE( disbed<N>(embed<N>(8)) == 8);
    REQUIRE( disbed<N>(embed<N>(9)) == 9);
    REQUIRE( disbed<N>(embed<N>(10)) == 10);
}
