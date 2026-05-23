
#include <catch2/catch_amalgamated.hpp>
#include <src/ternary.hpp>

TEST_CASE( "b_to_t", "[b_to_t]" ) {
    REQUIRE( b_to_t(0.0f) == -1.0f );
    REQUIRE( b_to_t(0.5f) ==  0.0f );
    REQUIRE( b_to_t(1.0f) ==  1.0f );
}

TEST_CASE( "t_to_b", "[t_to_b]" ) {
    REQUIRE( t_to_b(-1.0f) ==  0.0f );
    REQUIRE( t_to_b( 0.0f) ==  0.5f );
    REQUIRE( t_to_b( 1.0f) ==  1.0f );
}

TEST_CASE( "tz_bump", "[tz_bump]" ) {
    REQUIRE( tz_bump(-1.0f, -1.0f) == 0.0f );
    REQUIRE( tz_bump(-1.0f,  0.0f) == 0.0f );
    REQUIRE( tz_bump(-1.0f,  1.0f) == 0.0f );
    REQUIRE( tz_bump( 0.0f, -1.0f) == 0.0f );
    REQUIRE( tz_bump( 0.0f,  0.0f) == 0.5f );
    REQUIRE( tz_bump( 0.0f,  1.0f) == 0.0f );
    REQUIRE( tz_bump( 1.0f, -1.0f) == 0.0f );
    REQUIRE( tz_bump( 1.0f,  0.0f) == 0.0f );
    REQUIRE( tz_bump( 1.0f,  1.0f) == 0.0f );
}

TEST_CASE( "tand", "[tand]" ) {
    REQUIRE( tand(-1.0f, -1.0f) == -1.0f );
    REQUIRE( tand(-1.0f,  0.0f) == -1.0f );
    REQUIRE( tand(-1.0f,  1.0f) == -1.0f );
    REQUIRE( tand( 0.0f, -1.0f) == -1.0f );
    REQUIRE( tand( 0.0f,  0.0f) == -0.5f );
    REQUIRE( tand( 0.0f,  1.0f) ==  0.0f );
    REQUIRE( tand( 1.0f, -1.0f) == -1.0f );
    REQUIRE( tand( 1.0f,  0.0f) ==  0.0f );
    REQUIRE( tand( 1.0f,  1.0f) ==  1.0f );
}

TEST_CASE( "tz_and", "[tz_and]" ) {
    REQUIRE( tz_and(-1.0f, -1.0f) == -1.0f );
    REQUIRE( tz_and(-1.0f,  0.0f) == -1.0f );
    REQUIRE( tz_and(-1.0f,  1.0f) == -1.0f );
    REQUIRE( tz_and( 0.0f, -1.0f) == -1.0f );
    REQUIRE( tz_and( 0.0f,  0.0f) ==  0.0f );
    REQUIRE( tz_and( 0.0f,  1.0f) ==  0.0f );
    REQUIRE( tz_and( 1.0f, -1.0f) == -1.0f );
    REQUIRE( tz_and( 1.0f,  0.0f) ==  0.0f );
    REQUIRE( tz_and( 1.0f,  1.0f) ==  1.0f );
}

TEST_CASE( "tz_nif1", "[tz_nif1]" ) {
    REQUIRE( tz_nif1(-1.0f, -1.0f) == -1.0f );
    REQUIRE( tz_nif1(-1.0f,  0.0f) ==  0.0f );
    REQUIRE( tz_nif1(-1.0f,  1.0f) ==  1.0f );
    REQUIRE( tz_nif1( 0.0f, -1.0f) == -1.0f );
    REQUIRE( tz_nif1( 0.0f,  0.0f) ==  0.0f );
    REQUIRE( tz_nif1( 0.0f,  1.0f) ==  0.0f );
    REQUIRE( tz_nif1( 1.0f, -1.0f) == -1.0f );
    REQUIRE( tz_nif1( 1.0f,  0.0f) == -1.0f );
    REQUIRE( tz_nif1( 1.0f,  1.0f) == -1.0f );
}

TEST_CASE( "tz_nif2", "[tz_nif2]" ) {
    REQUIRE( tz_nif2(-1.0f, -1.0f) == -1.0f );
    REQUIRE( tz_nif2(-1.0f,  0.0f) == -1.0f );
    REQUIRE( tz_nif2(-1.0f,  1.0f) == -1.0f );
    REQUIRE( tz_nif2( 0.0f, -1.0f) ==  0.0f );
    REQUIRE( tz_nif2( 0.0f,  0.0f) ==  0.0f );
    REQUIRE( tz_nif2( 0.0f,  1.0f) == -1.0f );
    REQUIRE( tz_nif2( 1.0f, -1.0f) ==  1.0f );
    REQUIRE( tz_nif2( 1.0f,  0.0f) ==  0.0f );
    REQUIRE( tz_nif2( 1.0f,  1.0f) == -1.0f );
}

TEST_CASE( "tz_nor", "[tz_nor]" ) {
    REQUIRE( tz_nor(-1.0f, -1.0f) ==  1.0f );
    REQUIRE( tz_nor(-1.0f,  0.0f) ==  0.0f );
    REQUIRE( tz_nor(-1.0f,  1.0f) == -1.0f );
    REQUIRE( tz_nor( 0.0f, -1.0f) ==  0.0f );
    REQUIRE( tz_nor( 0.0f,  0.0f) ==  0.0f );
    REQUIRE( tz_nor( 0.0f,  1.0f) == -1.0f );
    REQUIRE( tz_nor( 1.0f, -1.0f) == -1.0f );
    REQUIRE( tz_nor( 1.0f,  0.0f) == -1.0f );
    REQUIRE( tz_nor( 1.0f,  1.0f) == -1.0f );
}

TEST_CASE( "tmin3", "[tmin3]" ) {
    REQUIRE( tmin3(-1.0f, -1.0f) == -1.0f );
    REQUIRE( tmin3(-1.0f,  0.0f) == -1.0f );
    REQUIRE( tmin3(-1.0f,  1.0f) == -1.0f );
    REQUIRE( tmin3( 0.0f, -1.0f) == -1.0f );
    REQUIRE( tmin3( 0.0f,  1.0f) ==  0.0f );
    REQUIRE( tmin3( 0.0f,  1.0f) ==  0.0f );
    REQUIRE( tmin3( 1.0f, -1.0f) == -1.0f );
    REQUIRE( tmin3( 1.0f,  0.0f) ==  0.0f );
    REQUIRE( tmin3( 1.0f,  1.0f) ==  1.0f );
}
