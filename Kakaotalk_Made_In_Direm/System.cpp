
#include <iostream>
#include <string>
#include <winsock2.h>
#include <thread> //��Ƽ�����带 ����ϱ�����!!!

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
//	//proc1�̶�� �̸��� thread����������� "proc_recv"����Լ��� ��Ƽ������� ����Ұ̴ϴ�
//	char buffer[PACKET_SIZE] = { 0 };
//
//
//	cout << "�ڽ��� �̸��� �Է��� �ּ��� : ";
//	getline(cin, myName);
//
//	while (1) {
//		cout << myName << " : ";
//		getline(cin, s_chating);
//
//
//		if (s_chating == "stop plz") {
//			cout << "ä���� �����մϴ�." << endl;
//			break;
//		}
//	}
//
//	//proc1.join();
//	//proc1�̶�� �����庯���� �� �Լ����� ���������� ��ٸ��ϴ�!
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
	cout << "[�����߻�]: " << message << '\n';
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
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) // Winsock���ʱ�ȭ�մϴ�.
		ShowErrorMessage("WSAStartup()");
	clientSocket = socket(PF_INET, SOCK_STREAM, 0); // TCP �����������մϴ�.
	if (clientSocket == INVALID_SOCKET)
		ShowErrorMessage("socket()");
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = Inetpton("127.0.0.1"); // ���ڿ�IP����Ʈ��ũ����Ʈ��������
	serverAddress.sin_port = htons(serverPort); // 2����Ʈ������Ʈ��ũ����Ʈ��������

	if (connect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		ShowErrorMessage("connect()");
	cout << "[�������] connect()\n";
	while (1) { // �ݺ������μ����θ޽����������ϰ��ڸ޽��������޹޽��ϴ�.
		cout << "[�޽�������]: ";
		getline(cin, sent);
		if (sent == "") continue;
		send(clientSocket, sent.c_str(), sent.length(), 0);
		int length = recv(clientSocket, received, sizeof(received), 0);
		received[length] = '\0';
		if (strcmp(received, "[exit]") == 0) {
			cout << "[��������]\n";
			break;
		}
		cout << "[�����޽���]: " << received << '\n';
	}
	closesocket(clientSocket);
	WSACleanup();
	system("pause");
	return 0;
}

bool emoTiCon() {
	return true;
}