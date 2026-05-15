#include "Server.h"
#include <iostream>

void Server::startServer(int port)
{
#ifdef _WIN32
    WSAData wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

    listen(serverSocket, maxPlayers);

    std::cout << "Server started on port: " << port << "\n ";
}

void Server::acceptPlayers()
{
    while (playerCount < maxPlayers)
    {
        SocketType newSocket = accept(serverSocket, nullptr, nullptr);
        clientSockets.push_back(newSocket);

        playerCount++;

        std::cout << "Player connected! Total Players: " << playerCount << "\n";
    }
}

void Server::broadcastMessage(const Message& message)
{
    for (int i = 0; i < clientSockets.size(); i++)
    {
        sendMessage(clientSockets[i], message);
    }
}
