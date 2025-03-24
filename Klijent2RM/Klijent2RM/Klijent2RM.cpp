#include <iostream>
#include <string>
#include <winsock.h>
#include <vector>
#pragma comment(lib, "wsock32.lib")
#define BUF_SIZE 1024
using namespace std;

void ExitWithError(const string& message) {
    cout << message << " Error code: " << WSAGetLastError() << endl;
    WSACleanup();
    exit(1);
}

void printMessage(const string& message, int len) {
    cout << "Primljena poruka: ";
    for (auto i = 0; i < len; cout << message[i++]);
    cout << endl;
}

int main() {
    WSAData wsa;
    SOCKET clientSocket;
    if (WSAStartup(0x0202, &wsa) != 0)
        ExitWithError("Startup failed.");

    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
        ExitWithError("Listening socket not created");

    sockaddr_in server;
    char* adresa = new char[16];
    int port;

    cout << "Adresa:\n";
    cin >> adresa;
    cout << "Port:\n";
    cin >> port;
    cin.ignore();

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(adresa);
    server.sin_port = htons(port);

    if (connect(clientSocket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
        ExitWithError("connect() failed!");

    while (true) {
        string echoBuf;
        cout << "Unesite poruku: ";
        getline(cin, echoBuf);

        if (send(clientSocket, echoBuf.c_str(), echoBuf.length(), 0) != echoBuf.length())
            ExitWithError("send() failed");

        int recvMsgSize = 0;
        vector<char> buff(BUF_SIZE);

        do {
            if ((recvMsgSize = recv(clientSocket, buff.data(), buff.size(), 0)) < 0)
                ExitWithError("recv() failed");
            printMessage(buff.data(), recvMsgSize);
        } while (recvMsgSize == BUF_SIZE);
    }

    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
