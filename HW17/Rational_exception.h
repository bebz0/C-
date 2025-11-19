#pragma once
#include <stdexcept>
#include <string>

class RationalException : public std::runtime_error
{
public:
    explicit RationalException(const std::string &msg)
        : std::runtime_error(msg) {}
};