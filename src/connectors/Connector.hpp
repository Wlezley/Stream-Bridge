/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#pragma once

class Connector {
public:
    virtual ~Connector() = default;

    virtual void start() = 0;
    virtual void stop() = 0;
};
