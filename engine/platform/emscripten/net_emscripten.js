addToLibrary({
    emscripten_net_recvfrom: (fd, buf, len, flags, sockaddr, socklen) =>
        Module.net?.recvfrom?.(fd, buf, len, flags, sockaddr, socklen) ?? -1,

    emscripten_net_sendto: (fd, buf, len, flags, sockaddr, socklen) =>
        Module.net?.sendto?.(fd, buf, len, flags, sockaddr, socklen) ?? -1,

    emscripten_net_socket: (family, type, protocol) =>
        Module.net?.socket?.(family, type, protocol) ?? -1,

    emscripten_net_gethostbyname: (hostname) =>
        Module.net?.gethostbyname?.(hostname) ?? 0,

    emscripten_net_gethostname: (name, namelen) =>
        Module.net?.gethostname?.(name, namelen) ?? -1,

    emscripten_net_getsockname: (fd, sockaddr, socklen) =>
        Module.net?.getsockname?.(fd, sockaddr, socklen) ?? -1,

    emscripten_net_connect: (fd, sockaddr, socklen) =>
        Module.net?.connect?.(fd, sockaddr, socklen) ?? -1,

    emscripten_net_send: (fd, buf, len, flags) =>
        Module.net?.send?.(fd, buf, len, flags) ?? -1,

    emscripten_net_recv: (fd, buf, len, flags) =>
        Module.net?.recv?.(fd, buf, len, flags) ?? -1,

    emscripten_net_bind: (fd, sockaddr, socklen) =>
        Module.net?.bind?.(fd, sockaddr, socklen) ?? -1,

    emscripten_net_closesocket: (fd) =>
        Module.net?.closesocket?.(fd) ?? -1,

    emscripten_net_select: (n, rfds, wfds, efds, tv) =>
        Module.net?.select?.(n, rfds, wfds, efds, tv) ?? -1,
});