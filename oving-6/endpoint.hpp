#pragma once

#include <string>
#include <vector>

class Endpoint {
public:
    Endpoint(const std::string &path);
    std::function<std::string()> create_response;
    const std::string path;
};
