/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#pragma once

#include <Poco/NotificationQueue.h>
#include <string>

struct LogMessage : public Poco::Notification {
    std::string text;

    LogMessage(std::string t) : text(std::move(t)) {}
};

class Logger {
public:
    static void log(const std::string& msg);
    static Poco::NotificationQueue& queue();

private:
    static Poco::NotificationQueue logQueue;
};
