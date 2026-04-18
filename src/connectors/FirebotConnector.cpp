/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#include "Connector.hpp"
#include "../core/EventBus.hpp"

#include <Poco/Net/WebSocket.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>

#include <thread>
#include <atomic>
#include <iostream>

class FirebotConnector : public Connector {
public:
    FirebotConnector(EventBus& bus)
        : bus(bus), running(false) {
    }

    void start() override {
        running = true;
        worker = std::thread(&FirebotConnector::run, this);
    }

    void stop() override {
        running = false;
        if (worker.joinable()) worker.join();
    }

private:
    void run() {
        while (running) {
            try {
                Poco::Net::HTTPClientSession cs("localhost", 7472);
                Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/");
                Poco::Net::HTTPResponse response;

                Poco::Net::WebSocket ws(cs, request, response);

                char buffer[1024];

                while (running) {
                    int flags;
                    int n = ws.receiveFrame(buffer, sizeof(buffer), flags);

                    if (n > 0) {
                        std::string msg(buffer, n);

                        Event e;
                        e.type = "firebot.raw";
                        e.payload["data"] = msg;

                        bus.emit(e);
                    }
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Firebot WS error: " << e.what() << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(5));
            }
        }
    }

    EventBus& bus;
    std::thread worker;
    std::atomic<bool> running;
};
