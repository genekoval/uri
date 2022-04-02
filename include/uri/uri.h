#pragma once

#include <stdexcept>
#include <string>
#include <string_view>
#include <uriparser/Uri.h>
#include <vector>

namespace uri {
    class uri_format_exception : public std::runtime_error {
        std::string m_value;
        std::size_t m_error_pos;
    public:
        uri_format_exception(std::string_view value, std::size_t error_pos);

        auto error_pos() -> std::size_t;

        auto value() -> std::string_view;
    };

    class uri {
        const std::string storage;
        UriUriA value = UriUriA();
    public:
        uri(const std::string& url);
        ~uri();

        auto host() const -> std::string_view;

        auto fragment() const -> std::string_view;

        auto scheme() const -> std::string_view;

        auto pathname() const -> std::string;

        auto path_segments() const -> std::vector<std::string_view>;

        auto port() const -> std::string_view;

        auto query() const -> std::string_view;
    };
}
