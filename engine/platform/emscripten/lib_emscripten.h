/*
lib_emscripten.h - dladdr workaround for emscripten
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

#if XASH_EMSCRIPTEN
#ifndef LIB_EMSCRIPTEN_H
#define LIB_EMSCRIPTEN_H

#define Platform_POSIX_GetFuncName( x, y ) EMSCRIPTEN_GetFuncName(( x ), ( y ))

const char *EMSCRIPTEN_GetFuncName(void *, void *);

#endif // DLADDR_EMSCRIPTEN_H
#endif