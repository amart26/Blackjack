#pragma once
#include "shared/Protocol.h"
#include <vector>

struct Server
{
    SocketType serverSocket;
    std::vector<SocketType> clientSockets;
    int playerCount;
    int maxPlayers = 4;

    void startServer(int port);
    void acceptPlayers();
    void broadcastMessage(const Message& message);
};
