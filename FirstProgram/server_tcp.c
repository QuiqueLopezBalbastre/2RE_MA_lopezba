/**
 * @file server_tcp.c
 * @author Quique López (lopezba@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <winsock2.h>

// IPs
// 0.0.0.0         --> Todo el mundo se puede conectar al servidor
// 127.0.0.1       --> Solo desde la consola de comandos del mismo servidor
//                     se puede conectar al servidor
// XXX.XXX.XXX.XXX --> Solo los dispositivos de la misma red se pueden conectar
//                     a la aplicación

int main()
{
  WSADATA wsa;
  SOCKET sock_server, sock_client;
  struct sockaddr_in ip;

  if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0) //== 0 Todo Ok
  {
    printf("Error WSA: %s", WSAGetLastError());
    return 1;
  }
  sock_server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sock_server == 0) //== 0 No se ha asignado socket
  {
    printf("Error assigning socket: %s", SOCKET_ERROR);
  }
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr = inet_addr("0.0.0.0");
  ip.sin_port = htons(7979);

  bind(sock_server, (SOCKADDR *)&ip, sizeof(ip)); //==0 Todo Ok
  listen(sock_server, SOMAXCONN);
  while(1)
  {};
  printf("Todo OK\n");
  WSACleanup();
  return 0;
}