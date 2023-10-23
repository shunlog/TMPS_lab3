#include <iostream>
#include "legacySocket/legacy_socket.h"
#include "legacy_socket_adapter.cpp"
#include "socket_interface.h"


int main() {
    LegacySocketAdapter adapter(new LegacySocket);

    adapter.connect();
    adapter.sendData();

    return 0;
}


