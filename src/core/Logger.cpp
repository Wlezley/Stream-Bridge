/*
 * Copyright (c) 2026 LISHACK.CZ Simulation Software, Wlezley Lishack <hovnovolenasersi@gmail.com>
 */

#include "Logger.hpp"

Poco::NotificationQueue Logger::logQueue;

void Logger::log(const std::string& msg)
{
    logQueue.enqueueNotification(new LogMessage(msg));
}

Poco::NotificationQueue& Logger::queue()
{
    return logQueue;
}
