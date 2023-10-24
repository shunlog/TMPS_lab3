#pragma once
#include <iostream>

class SocketInterface {
public:
    virtual void connect() = 0;
    virtual void send_file(std::string f) = 0;
};

