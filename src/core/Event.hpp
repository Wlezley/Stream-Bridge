/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#pragma once

#include <string>
#include <unordered_map>

struct Event {
    std::string type;
    std::unordered_map<std::string, std::string> payload;
};
