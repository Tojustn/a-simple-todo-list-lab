#pragma once

#include <string>
#include <vector>

struct Task {
    std::string description;
    bool is_complete;
    std::vector<std::string> tags;

};


