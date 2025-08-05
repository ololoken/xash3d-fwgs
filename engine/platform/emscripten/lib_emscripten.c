/*
lib_emscripten.c - dladdr workaround for emscripten
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

#include "lib_emscripten.h"
#include <emscripten.h>

const char *EMSCRIPTEN_GetFuncName(void *hInstance, void *address)
{
    return EM_ASM_PTR({
        const hInstance = $0;
        const address = $1;
        const funcJsRef = getWasmTableEntry(address).name;
        const exports = Object.entries(instance.LDSO.loadedLibsByHandle[hInstance]?.exports ?? {});
        for (const [fn, { name }] of exports)
            if (name === funcJsRef)
                return stringToUTF8OnStack(fn);
        return 0;
    }, hInstance, address);
}