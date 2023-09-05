#include <concepts>
#include <functional>
#include <string_view>

namespace cpp_test
{

template <typename RetType, typename... FuncParams>
using test_func = std::function<RetType( FuncParams... )>;

namespace runtime
{};

namespace compile_time
{

template <typename RetType, typename... ParamTypes>
    requires std::equality_comparable<RetType>
consteval inline bool
evaluate( RetType expected, RetType ( *f )( ParamTypes... ),
          ParamTypes... f_inputs ) {
    return expected == f( f_inputs... );
}

template <typename RetType, typename... ParamTypes>
using gen_func = std::function<RetType(ParamTypes...)>;

}; // namespace compile_time

}; // namespace cpp_test
