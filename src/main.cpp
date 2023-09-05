#include "cpp_test.hpp"

#include <iostream>
#include <charconv>
#include <string>

consteval auto
square( const std::integral auto x ) {
    return x * x;
}

/*consteval std::string
make_string( const int a, const char b, const float c ) {
    std::array<char, 10> a_arr;
    auto [a_ptr, a_ec] = std::to_chars(a_arr.data(), a_arr.data() + a_arr.size(), a);
    if ( a_ec == std::errc::value_too_large ) {
        throw std::make_error_code(a_ec);
    }
    constexpr std::string a_str{ a_arr.data(), a_ptr };

    std::array<char, 10> c_arr;
    auto [c_ptr, c_ec] = std::to_chars(c_arr.data(), c_arr.data() + c_arr.size() , c, std::chars_format::fixed, 3);
    if ( c_ec == std::errc::value_too_large ) {
        throw std::make_error_code(c_ec);
    }
    constexpr std::string c_str{ c_arr.data(), c_ptr };
    
    constexpr std::string result = a_str + " " + std::string{ b } + " " + c_str;
    return result;
}*/

int
main() {
    static_assert(cpp_test::compile_time::evaluate( 25, square, 5 ));
    //static_assert(cpp_test::compile_time::evaluate( thirty, square, five ));
    //std::cout << cpp_test::compile_time::evaluate( std::string{ "5 c 3.14" },
    //                                               make_string, 5, 'c',
    //                                               static_cast<float>( 3.14 ) )
    //          << std::endl;
    //std::cout << cpp_test::compile_time::evaluate( std::string{ "5 c 3.14" },
    //                                               make_string, 5, 'c',
    //                                               static_cast<float>( 3.15 ) )
    //          << std::endl;
}
