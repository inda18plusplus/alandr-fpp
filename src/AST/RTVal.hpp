//
// Created by lunar on 23/11/18.
//

#ifndef FIMPLUSPLUS_RTVAL_HPP
#define FIMPLUSPLUS_RTVAL_HPP


#include <variant>
#include <optional>
#include <string>

typedef std::optional<std::variant<std::monostate, bool, double, std::string>> RTVal;

#endif //FIMPLUSPLUS_RTVAL_HPP
