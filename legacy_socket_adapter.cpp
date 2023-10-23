#include "legacySocket/legacy_socket.h"
#include "socket_interface.h"

class LegacySocketAdapter : public SocketInterface {
private:
    LegacySocket* legacySocket;

public:
    LegacySocketAdapter(LegacySocket* legacySocket) : legacySocket(legacySocket) {}

    void connect() override {
        legacySocket->connectLegacy();
    }

    void sendData() override {
        legacySocket->sendDataLegacy();
    }
};

