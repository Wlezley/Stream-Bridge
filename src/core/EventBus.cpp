/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#include "EventBus.hpp"

void EventBus::subscribe(const std::string& type, Handler handler)
{
    std::lock_guard lock(mutex);
    handlers[type].push_back(handler);
}

void EventBus::emit(const Event& event)
{
    std::lock_guard lock(mutex);

    if (!handlers.contains(event.type)) return;

    for (const auto& handler : handlers[event.type]) {
        handler(event);
    }
}
