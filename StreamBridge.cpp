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
#include <sstream>
#include <iostream>

#include <Poco/Thread.h>

using namespace std;

#include "src/core/EventBus.hpp"
#include "src/core/Logger.hpp"
#include "src/utils/ExtendedStd.hpp"
//#include "src/connectors/"

//TEST EP:
//https://api.restful-api.dev/collections

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>

// TEST...
int main()
{
    try {
        Poco::Net::HTTPClientSession session("api.restful-api.dev", 80);
        session.setKeepAlive(true);

        // request
        Poco::Net::HTTPRequest request(
            Poco::Net::HTTPRequest::HTTP_GET,
            "/objects",
            Poco::Net::HTTPMessage::HTTP_1_1
        );

        session.sendRequest(request);

        // response
        Poco::Net::HTTPResponse response;
        std::istream& rs = session.receiveResponse(response);

        std::stringstream ss;
        Poco::StreamCopier::copyStream(rs, ss);

        std::cout << "Status: " << response.getStatus() << std::endl;
        std::cout << "Body:\n" << ss.str() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    return 0;
}





//int main()
//{
//    EventBus bus;
//
//    Poco::Thread cliThread;
//    Poco::Thread inputThread;
//
//    //cliThread.startFunc(inputLoop);
//    //inputThread.startFunc([&bus]() { inputLoop(bus); });
//
//    Logger::log("App started");
//
//    std::cin.get();
//
//    return 0;
//}

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
