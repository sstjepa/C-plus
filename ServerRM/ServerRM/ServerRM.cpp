#include <iostream>
#include <string>
#include <winsock.h>
#include <vector>
#pragma comment(lib, "wsock32.lib")
#define BUF_SIZE 1024
using namespace std;
void ExitWithError(const string& message)
{
	cout << message << "Error code:" << WSAGetLastError() << endl;
	WSACleanup();
	exit(1);
}
void printMessage(const string& message, int len)
{
	cout << "Primljena poruka:";
	for (auto i = 0; i < len; cout << message[i++]);
	cout << endl;
}

int main()
{
	WSAData wsa;
	SOCKET listensock;
	if (WSAStartup(0x0202, &wsa) != 0)
		ExitWithError("Startup failed.");

	if ((listensock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		ExitWithError("Listening socket not created");

	cout << "Port SRVR:\n";
	int port;
	cin >> port;
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);
	if (bind(listensock, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
		ExitWithError("bind() failed!");
	//Osluskivanje
	if ((listen(listensock, 3)) < 0)
		ExitWithError("listen() failed!");

	while (true) {
		sockaddr_in client;
		int cLen = sizeof(struct sockaddr_in);
		SOCKET clientSock;
		if ((clientSock = accept(listensock, (struct sockaddr*)&client, &cLen)) < 0)
			ExitWithError("accept() failed!");
		// Primanje poruke od klijenta
		vector<char> echoBuf(BUF_SIZE);
		int recvMsgSize = recv(clientSock, echoBuf.data(), echoBuf.size(), 0);
		if (recvMsgSize < 0)
			ExitWithError("recv() failed");
		printMessage(echoBuf.data(), recvMsgSize);
		while (recvMsgSize > 0)
		{
			if (send(clientSock, echoBuf.data(), recvMsgSize, 0) != recvMsgSize)
				ExitWithError("send() failed");
			if ((recvMsgSize = recv(clientSock, echoBuf.data(), echoBuf.size(), 0)) < 0)
				ExitWithError("recv() failed");
			printMessage(echoBuf.data(), recvMsgSize);
		} // while (recvMsgSize > 0)
		closesocket(clientSock);
	} //while (true)

	while (true) {
		sockaddr_in client;
		int cLen = sizeof(struct sockaddr_in);
		SOCKET clientSock;
		if ((clientSock = accept(listensock, (struct sockaddr*)&client, &cLen)) < 0)
			ExitWithError("accept() failed!");
		// Primanje poruke od klijenta
		vector<char> echoBuf(BUF_SIZE);
		int recvMsgSize = recv(clientSock, echoBuf.data(), echoBuf.size(), 0);
		if (recvMsgSize < 0)
			ExitWithError("recv() failed");
		printMessage(echoBuf.data(), recvMsgSize);
		while (recvMsgSize > 0)
		{
			if (send(clientSock, echoBuf.data(), recvMsgSize, 0) != recvMsgSize)
				ExitWithError("send() failed");
			if ((recvMsgSize = recv(clientSock, echoBuf.data(), echoBuf.size(), 0)) < 0)
				ExitWithError("recv() failed");
			printMessage(echoBuf.data(), recvMsgSize);
		} // while (recvMsgSize > 0)
		closesocket(clientSock);
	} //while (true)

	closesocket(listensock);
	WSACleanup();
}