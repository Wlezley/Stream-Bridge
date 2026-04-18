/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#pragma once
#define _WINSOCKAPI_ // Prevent inclusion of winsock.h in windows.h
#define __HANDLER_SERVER_NAME__     "Wlezley Lishack Stream Bridge"
#define __HANDLER_SERVER_VERSION__  "v0.1 ALPHA"

#include <string>
#include <vector>
#include <windows.h>
#include <iostream>

#include <Poco/Thread.h>

using namespace std;

#include "src/core/EventBus.hpp"
#include "src/core/Logger.hpp"
#include "src/utils/ExtendedStd.hpp"
//#include "src/connectors/"

int main()
{
    EventBus bus;

    Poco::Thread cliThread;
    Poco::Thread inputThread;

    //cliThread.startFunc(inputLoop);
    //inputThread.startFunc([&bus]() { inputLoop(bus); });

    Logger::log("App started");

    std::cin.get();

    return 0;
}

void inputLoop(EventBus& bus)
{
    std::string line;

    while (true) {
        std::getline(std::cin, line);

        Event e;
        e.type = "cli.command";
        e.payload["cmd"] = line;

        bus.emit(e);
    }
}
