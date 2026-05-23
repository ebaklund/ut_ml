
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

TEST_CASE( "tbumpz", "[tbumpz]" ) {
    REQUIRE( tbumpz(-1.0f, -1.0f) == 0.0f );
    REQUIRE( tbumpz(-1.0f,  0.0f) == 0.0f );
    REQUIRE( tbumpz(-1.0f,  1.0f) == 0.0f );
    REQUIRE( tbumpz( 0.0f, -1.0f) == 0.0f );
    REQUIRE( tbumpz( 0.0f,  0.0f) == 0.5f );
    REQUIRE( tbumpz( 0.0f,  1.0f) == 0.0f );
    REQUIRE( tbumpz( 1.0f, -1.0f) == 0.0f );
    REQUIRE( tbumpz( 1.0f,  0.0f) == 0.0f );
    REQUIRE( tbumpz( 1.0f,  1.0f) == 0.0f );
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

TEST_CASE( "tandz", "[tandz]" ) {
    REQUIRE( tandz(-1.0f, -1.0f) == -1.0f );
    REQUIRE( tandz(-1.0f,  0.0f) == -1.0f );
    REQUIRE( tandz(-1.0f,  1.0f) == -1.0f );
    REQUIRE( tandz( 0.0f, -1.0f) == -1.0f );
    REQUIRE( tandz( 0.0f,  0.0f) ==  0.0f );
    REQUIRE( tandz( 0.0f,  1.0f) ==  0.0f );
    REQUIRE( tandz( 1.0f, -1.0f) == -1.0f );
    REQUIRE( tandz( 1.0f,  0.0f) ==  0.0f );
    REQUIRE( tandz( 1.0f,  1.0f) ==  1.0f );
}

TEST_CASE( "tnif1z", "[tnif1z]" ) {
    REQUIRE( tnif1z(-1.0f, -1.0f) == -1.0f );
    REQUIRE( tnif1z(-1.0f,  0.0f) ==  0.0f );
    REQUIRE( tnif1z(-1.0f,  1.0f) ==  1.0f );
    REQUIRE( tnif1z( 0.0f, -1.0f) == -1.0f );
    REQUIRE( tnif1z( 0.0f,  0.0f) ==  0.0f );
    REQUIRE( tnif1z( 0.0f,  1.0f) ==  0.0f );
    REQUIRE( tnif1z( 1.0f, -1.0f) == -1.0f );
    REQUIRE( tnif1z( 1.0f,  0.0f) == -1.0f );
    REQUIRE( tnif1z( 1.0f,  1.0f) == -1.0f );
}

TEST_CASE( "tnif2z", "[tnif2z]" ) {
    REQUIRE( tnif2z(-1.0f, -1.0f) == -1.0f );
    REQUIRE( tnif2z(-1.0f,  0.0f) == -1.0f );
    REQUIRE( tnif2z(-1.0f,  1.0f) == -1.0f );
    REQUIRE( tnif2z( 0.0f, -1.0f) ==  0.0f );
    REQUIRE( tnif2z( 0.0f,  0.0f) ==  0.0f );
    REQUIRE( tnif2z( 0.0f,  1.0f) == -1.0f );
    REQUIRE( tnif2z( 1.0f, -1.0f) ==  1.0f );
    REQUIRE( tnif2z( 1.0f,  0.0f) ==  0.0f );
    REQUIRE( tnif2z( 1.0f,  1.0f) == -1.0f );
}

TEST_CASE( "tnorz", "[tnorz]" ) {
    REQUIRE( tnorz(-1.0f, -1.0f) ==  1.0f );
    REQUIRE( tnorz(-1.0f,  0.0f) ==  0.0f );
    REQUIRE( tnorz(-1.0f,  1.0f) == -1.0f );
    REQUIRE( tnorz( 0.0f, -1.0f) ==  0.0f );
    REQUIRE( tnorz( 0.0f,  0.0f) ==  0.0f );
    REQUIRE( tnorz( 0.0f,  1.0f) == -1.0f );
    REQUIRE( tnorz( 1.0f, -1.0f) == -1.0f );
    REQUIRE( tnorz( 1.0f,  0.0f) == -1.0f );
    REQUIRE( tnorz( 1.0f,  1.0f) == -1.0f );
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
