/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#pragma once

#include <vector>
#include <iostream>

namespace std
{
    bool replace(std::string& str, const std::string& from, const std::string& to);
    void replaceAll(std::string& str, const std::string& from, const std::string& to);
    vector<string> explode(const string& delimiter, const string& explodeme);
};
