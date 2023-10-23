#pragma once

class SocketInterface {
public:
    virtual void connect() = 0;
    virtual void sendData() = 0;
};

