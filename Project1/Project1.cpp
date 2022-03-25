
#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
#include <string>

#pragma comment(lib, "ws2_32")

#define PORT 7771
#define PACKET_SIZE 1024
#define SERVER_IP "1.224.192.178"
using namespace std;

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    
    SOCKET hSocket;
    hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    SOCKADDR_IN tAddr = {};
    tAddr.sin_family = AF_INET;
    tAddr.sin_port = htons(PORT);
    tAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    connect(hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr));

    string myName;				//자신의 이름
    string opponentName;		//상대 사용자의 이름
    string s_chating;			//채팅
    
    cout << "자신의 이름을 입력해 주세요 : ";
    getline(cin, myName);

    while (1) {
    	cout << myName << " : ";
    	getline(cin, s_chating);
    
    
    	if (s_chating == "stop plz") {
    		cout << "채팅을 종료합니다." << endl;
    		break;
    	}
    }

    closesocket(hSocket);

    WSACleanup();
    return 0;
}   

