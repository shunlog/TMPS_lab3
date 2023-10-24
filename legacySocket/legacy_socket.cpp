#include <iostream>
#include "legacy_socket.h"

void LegacySocket::connectLegacy() {
    std::cout << "Connected using legacy socket." << std::endl;
}

void LegacySocket::sendDataLegacy(std::string f) {
    std::cout << "Sending file: " << f << std::endl;
}
