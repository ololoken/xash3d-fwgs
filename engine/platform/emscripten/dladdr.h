/*
dladdr.h - dladdr workaround for emscripten
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


#ifndef DLADDR_EMSCRIPTEN_H
#define DLADDR_EMSCRIPTEN_H

#include <dlfcn.h>

#define dladdr emscripten_dladdr

int emscripten_dladdr(void *address, Dl_info* dl);

#endif // DLADDR_EMSCRIPTEN_H
