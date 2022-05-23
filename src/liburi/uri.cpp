#include <uri/uri.h>

#include <ext/string.h>

namespace {
    auto to_string(const UriTextRangeA& text) -> std::string_view {
        return std::string_view(text.first, text.afterLast);
    }
}

namespace uri {
    uri::uri(const std::string& url) : storage(ext::trim(url)) {
        const char* error_pos = nullptr;

        if (uriParseSingleUriA(
            &value,
            storage.data(),
            &error_pos
        ) != URI_SUCCESS) {
            const auto diff = error_pos - storage.data();
            throw uri_format_exception(storage, diff);
        }
    }

    uri::~uri() {
        uriFreeUriMembersA(&value);
    }

    auto uri::host() const -> std::string_view {
        return to_string(value.hostText);
    }

    auto uri::fragment() const -> std::string_view {
        return to_string(value.fragment);
    }

    auto uri::scheme() const -> std::string_view {
        return to_string(value.scheme);
    }

    auto uri::pathname() const -> std::string {
        return "/" + ext::join(path_segments(), "/");
    }

    auto uri::path_segments() const -> std::vector<std::string_view> {
        auto result = std::vector<std::string_view>();

        for (auto segment = value.pathHead; segment; segment = segment->next) {
            result.push_back(to_string(segment->text));
        }

        return result;
    }

    auto uri::port() const -> std::string_view {
        return to_string(value.portText);
    }

    auto uri::query() const -> std::string_view {
        return to_string(value.query);
    }

    auto parse(const std::string& url) -> std::optional<uri> {
        try {
            return make_optional<uri>(url);
        }
        catch (const uri_format_exception&) {
            return {};
        }
    }
}
