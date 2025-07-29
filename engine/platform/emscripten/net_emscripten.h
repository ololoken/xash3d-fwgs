/*
net_emscripten.h - BSD sockets to js proxy
Copyright (C) 2025 ololoken

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/
#ifndef NET_EMSCRIPTEN_H
#define NET_EMSCRIPTEN_H

#include <netdb.h>

#define gethostbyname emscripten_net_gethostbyname

#undef ioctlsocket
#undef closesocket

#define recvfrom emscripten_net_recvfrom
#define sendto emscripten_net_sendto
#define socket emscripten_net_socket
#define ioctlsocket(...) 0
#define setsockopt(...) 0
#define gethostname emscripten_net_gethostname
#define getsockname emscripten_net_getsockname
#define connect emscripten_net_connect
#define send emscripten_net_send
#define recv emscripten_net_recv
#define bind emscripten_net_bind
#define closesocket emscripten_net_closesocket
#define select emscripten_net_select

extern int emscripten_net_recvfrom( int, void *__restrict, size_t, int, struct sockaddr *__restrict, int *__restrict );
extern int emscripten_net_sendto ( int, const void *, size_t, int, const struct sockaddr *, int );
extern int emscripten_net_socket( int, int, int );
extern struct hostent *emscripten_net_gethostbyname( const char * );
extern int emscripten_net_gethostname( char *, size_t );
extern int emscripten_net_getsockname( int, struct sockaddr *__restrict, int *__restrict );
extern int emscripten_net_send( int, const void *, size_t, int );
extern int emscripten_net_recv( int, void *, size_t, int );

extern int emscripten_net_connect( int, const struct sockaddr *, int );
extern int emscripten_net_bind( int, const struct sockaddr *, int );
extern int emscripten_net_closesocket( int );
extern int emscripten_net_select( int, fd_set *__restrict, fd_set *__restrict, fd_set *__restrict, struct timeval *__restrict );

#endif // NET_EMSCRIPTEN_H
