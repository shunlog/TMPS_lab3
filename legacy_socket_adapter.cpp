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

    void send_file(std::string file) override {
        legacySocket->sendDataLegacy(file);
    }
};

