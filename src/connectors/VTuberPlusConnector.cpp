/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>

#include "../core/EventBus.hpp"
#include "Connector.hpp"

class VTuberPlusConnector : public Connector {
public:
    VTuberPlusConnector(EventBus& bus)
        : bus(bus)
    {
        bus.subscribe("vtuberplus.trigger", [this](const Event& e) {
            handleTrigger(e);
            });
    }

    void start() override {}
    void stop() override {}

private:
    void handleTrigger(const Event& e)
    {
        auto action = e.payload.at("action");

        // TODO: vyber podle configu (WS / OSC)
        sendOSC(action);
    }

    void sendOSC(const std::string& action)
    {
        Poco::Net::DatagramSocket socket;
        Poco::Net::SocketAddress addr("127.0.0.1", 9000);

        std::string msg = "/avatar/" + action;
        socket.sendTo(msg.data(), static_cast<int>(msg.size()), addr);
    }

    EventBus& bus;
};
