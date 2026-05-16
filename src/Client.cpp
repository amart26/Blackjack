#include "Client.h"

void Client::connectToServer(const std::string& ip, int port)
{

#ifdef _WIN32
    WSAData wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ip.c_str());

    connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

    isConnected = true;
    std::cout << "Connected to server!\n";
}

void Client::sendAction(MessageType type, int data)
{
    Message message;
    message.type = type;
    message.data = data;
    message.playerId = playerId;

    sendMessage(clientSocket, message);
}

void Client::listenForMessages()
{
    while (isConnected)
    {
        Message message = receiveMessage(clientSocket);
        switch (message.type)
        {
        case MessageType::YOUR_TURN:
            /* code */
            isMyTurn = true;
            std::cout << "Its your turn.\n";
            break;

        case MessageType::GAME_OVER:
            if (message.data == 1)
            {
                std::cout << "Player Wins!\n";
            }
            else if (message.data == -1)
            {
                std::cout << "Player lose!\n";
            }
            else if (message.data == 0)
            {
                std::cout << "Push!\n";
            }
            else if (message.data == 2)
            {
                std::cout << "BLACKJACK! Player wins 1.5x!\n";
            }
            break;
        case MessageType::WAITING:
            std::cout << "Waiting for other players...\n";
            break;
        case MessageType::DEALER_TURN:
            std::cout << "Dealer is playing...\n";
            break;
        default:
            std::cout << "Message received\n";
            break;
        }
    }
}
