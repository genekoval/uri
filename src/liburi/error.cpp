#include <uri/uri.h>

namespace uri {
    uri_format_exception::uri_format_exception(
        std::string_view value,
        std::size_t error_pos
    ) :
        uri_format_exception::runtime_error("invalid URI"),
        m_value(value),
        m_error_pos(error_pos)
    {}

    auto uri_format_exception::error_pos() -> std::size_t {
        return m_error_pos;
    }

    auto uri_format_exception::value() -> std::string_view {
        return m_value;
    }
}
