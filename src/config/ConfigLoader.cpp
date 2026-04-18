/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>
#include <fstream>
#include <sstream>

Poco::Dynamic::Var loadConfig(const std::string& path)
{
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();

    Poco::JSON::Parser parser;
    return parser.parse(buffer.str());
}
