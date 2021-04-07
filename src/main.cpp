//
//  main.cpp
//  exittime
//
//  Created by Ricardo on 05/03/21.
//

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>


int main(int argc, const char* argv[]) {
    
    const std::time_t now = std::time(nullptr);
    const std::tm calendar_time = *std::localtime( std::addressof(now) );
    
    //    std::cout << "              year: " << calendar_time.tm_year + 1900 << '\n'
    //              << "    month (jan==1): " << calendar_time.tm_mon + 1 << '\n'
    //              << "      day of month: " << calendar_time.tm_mday << '\n'
    //              << "hour (24-hr clock): " << calendar_time.tm_hour << '\n'
    //              << "            minute: " << calendar_time.tm_min << '\n'
    //              << "            second: " << calendar_time.tm_sec << '\n';
    
    int entry_hour = calendar_time.tm_hour;
    int entry_minute = calendar_time.tm_min;
    int lunch_hour = 1;
    int lunch_minute = 0;
    int total_hour = 8;
    int total_minute = 48;
    bool debug = false;
    
    for (int i = 1; i < argc; i = i + 2) {
        std::string parameter = argv[i];
        if (parameter == "-e" || parameter == "--entry-time") {
            std::string value = argv[i + 1];
            long pos = value.find(":");
            entry_hour = std::stoi(value.substr(0, pos));
            entry_minute = std::stoi(value.substr(pos + 1, value.length()));

        } else if (parameter == "-l" || parameter == "--lunch-time") {
            std::string value = argv[i + 1];
            long pos = value.find(":");
            lunch_hour = std::stoi(value.substr(0, pos));
            lunch_minute = std::stoi(value.substr(pos + 1, value.length()));

        } else if (parameter == "-t" || parameter == "--total-time") {
            std::string value = argv[i + 1];
            long pos = value.find(":");
            total_hour = std::stoi(value.substr(0, pos));
            total_minute = std::stoi(value.substr(pos + 1, value.length()));
        } else if (parameter == "-d" || parameter == "--debbug") {
            debug = true;

        } else if (parameter == "-h" || parameter == "--help") {
            std::cout << std::endl;
            std::cout << " ---------- calculate exit time ----------" << std::endl;
            std::cout << std::endl;
            std::cout << "  usage: exittime [flag] [value (HH:MM)] " << std::endl;
            std::cout << std::endl;
            std::cout << "  -e, --entry-time   entry time" << std::endl;
            std::cout << "  -l, --lunch-time   lunch time" << std::endl;
            std::cout << "  -t, --total-time   total time" << std::endl;
            std::cout << std::endl;
            std::cout << "  -h, --help         display this help" << std::endl;
            std::cout << std::endl;
            exit(0);
        }
    }
    
    int exit_hour = entry_hour + lunch_hour + total_hour;
    int exit_minute = entry_minute + lunch_minute + total_minute;
    
    std::cout << std::endl;
    if (debug) std::cout << "exit_minute: " << exit_minute << std::endl;
    if (debug) std::cout << "exit_hour: " << exit_hour  << std::endl;

    if (exit_minute > 59) {
        if (debug) std::cout << "recalculating exit minute..."  << std::endl;

        exit_hour += exit_minute / 60;
        exit_minute = exit_minute % 60;

        if (debug) std::cout << "new exit_minute: " << exit_minute  << std::endl;
        if (debug) std::cout << "new exit_hour: " << exit_hour  << std::endl;
    }
    
    if (exit_hour > 23) {
        if (debug) std::cout << "recalculating exit hour..."  << std::endl;
        exit_hour = exit_hour % 24;
        if (debug) std::cout << "new exit_hour: " << exit_hour  << std::endl;
    }
    
    if (debug) std::cout << std::endl;
    if (exit_hour < 10) {
        std::cout << "0";
    }
    std::cout << exit_hour << ":";
    if (exit_minute < 10) {
        std::cout << "0";
    }
    std::cout << exit_minute << std::endl;
    
    return 0;
}
