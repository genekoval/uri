#pragma once

#include <stdexcept>
#include <string>
#include <string_view>
#include <uriparser/Uri.h>
#include <vector>

namespace uri {
    class uri_format_exception : public std::runtime_error {
        std::string value;
        std::size_t error_pos;
    public:
        uri_format_exception(std::string_view value, std::size_t error_pos);
    };

    class uri {
        UriUriA value = UriUriA();
    public:
        uri(const std::string& url);
        ~uri();

        auto host() -> std::string_view;

        auto fragment() -> std::string_view;

        auto scheme() -> std::string_view;

        auto pathname() -> std::string;

        auto path_segments() -> std::vector<std::string_view>;

        auto port() -> std::string_view;

        auto query() -> std::string_view;
    };
}
