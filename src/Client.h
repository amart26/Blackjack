#pragma once

#include "shared/Protocol.h"
#include <iostream>
#include <thread>
#include <vector>

struct Client
{
    SocketType clientSocket;
    int playerId;
    bool isConnected;
    bool isMyTurn;

    void connectToServer(const std::string& ip, int port);
    void sendAction(MessageType type, int data);
    void listenForMessages();
};