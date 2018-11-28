//
// Created by lunar on 15/11/18.
//

#ifndef FIMPLUSPLUS_STRUTIL_HPP
#define FIMPLUSPLUS_STRUTIL_HPP

#include <string>
#include <string_view>
#include <optional>

static const std::string_view whitespace = "\x09\x0A\x0B\x0C\x0D\x20";//Tab, LF, Vertical tab, FF, CR, space


std::string_view stripWhiteSpace(std::string_view str);

std::optional<double> asDouble(std::string_view str);

#endif //FIMPLUSPLUS_STRUTIL_HPP
