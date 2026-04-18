/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#pragma once

#include <functional>
#include <unordered_map>
#include <vector>
#include <mutex>
#include "Event.hpp"

class EventBus {
public:
    using Handler = std::function<void(const Event&)>;

    void subscribe(const std::string& type, Handler handler);
    void emit(const Event& event);

private:
    std::unordered_map<std::string, std::vector<Handler>> handlers;
    std::mutex mutex;
};
