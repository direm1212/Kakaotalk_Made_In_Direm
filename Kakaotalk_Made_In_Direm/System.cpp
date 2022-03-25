
#include <iostream>
#include <string>
#include <winsock2.h>
#include <thread> //멀티쓰레드를 사용하기위한!!!

using namespace std; 
#define PACKET_SIZE 1024 
SOCKET skt;

bool emoTiCon();

//SOCKET skt;
//
//int main() {
//	WSADATA wsa; 
//	WSAStartup(MAKEWORD(2, 2), &wsa);
//
//	skt = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//	SOCKADDR_IN addr = {};
//	addr.sin_family = AF_INET;
//	addr.sin_port = htons(4444);
//	addr.sin_addr.s_addr = inet_addr("1.224.192.178");
//
//	while (1) {
//		if (!connect(skt, (SOCKADDR*)&addr, sizeof(addr))) break;
//	}
//
//	//thread proc1(proc_recv);
//	//proc1이라는 이름의 thread변수를만들어 "proc_recv"라는함수를 멀티쓰레드로 사용할겁니다
//	char buffer[PACKET_SIZE] = { 0 };
//
//
//	cout << "자신의 이름을 입력해 주세요 : ";
//	getline(cin, myName);
//
//	while (1) {
//		cout << myName << " : ";
//		getline(cin, s_chating);
//
//
//		if (s_chating == "stop plz") {
//			cout << "채팅을 종료합니다." << endl;
//			break;
//		}
//	}
//
//	//proc1.join();
//	//proc1이라는 쓰레드변수가 이 함수에서 끝날때까지 기다립니다!
//	closesocket(skt);
//	WSACleanup();
//}

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<string>
#include<winsock2.h>

using namespace std;
void ShowErrorMessage(string message)
{
	cout << "[오류발생]: " << message << '\n';
	system("pause");
	exit(1);
}

int main()
{
	WSADATA wsaData;
	SOCKET clientSocket;
	SOCKADDR_IN serverAddress;
	int serverPort = 9876;
	char received[256];
	string sent;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) // Winsock을초기화합니다.
		ShowErrorMessage("WSAStartup()");
	clientSocket = socket(PF_INET, SOCK_STREAM, 0); // TCP 소켓을생성합니다.
	if (clientSocket == INVALID_SOCKET)
		ShowErrorMessage("socket()");
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = Inetpton("127.0.0.1"); // 문자열IP를네트워크바이트형식으로
	serverAddress.sin_port = htons(serverPort); // 2바이트정수네트워크바이트형식으로

	if (connect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		ShowErrorMessage("connect()");
	cout << "[현재상태] connect()\n";
	while (1) { // 반복적으로서버로메시지를전송하고에코메시지를전달받습니다.
		cout << "[메시지전송]: ";
		getline(cin, sent);
		if (sent == "") continue;
		send(clientSocket, sent.c_str(), sent.length(), 0);
		int length = recv(clientSocket, received, sizeof(received), 0);
		received[length] = '\0';
		if (strcmp(received, "[exit]") == 0) {
			cout << "[서버종료]\n";
			break;
		}
		cout << "[서버메시지]: " << received << '\n';
	}
	closesocket(clientSocket);
	WSACleanup();
	system("pause");
	return 0;
}

bool emoTiCon() {
	return true;
}