/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#include "../core/EventBus.hpp"
#include <iostream>

class ActionExecutor {
public:
    ActionExecutor(EventBus& bus) {
        bus.subscribe("firebot.raw", [this](const Event& e) {
            handleFirebot(e);
            });
    }

private:
    void handleFirebot(const Event& e) {
        std::cout << "Firebot event: " << e.payload.at("data") << std::endl;

        // TODO: parse JSON + trigger akce
    }
};
