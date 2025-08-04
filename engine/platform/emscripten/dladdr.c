/*
dladdr.c - dladdr workaround for emscripten
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

#include <emscripten.h>
#include <dlfcn.h>

// todo: consider if it worth to submit dladdr patch for emscripten,  but it will require writing tests ... doh
int emscripten_dladdr(void *address, Dl_info* dl)
{
    dl->dli_sname = EM_ASM_PTR({
        const address = $0;
        const funcJsRef = getWasmTableEntry(address).name;
        for (const hInstance in LDSO.loadedLibsByHandle) {
            const exports = Object.entries(LDSO.loadedLibsByHandle[hInstance].exports);
            for (const [fn, { name }] of exports) {
                if (name === funcJsRef)
                    return stringToUTF8OnStack(name);
           }
        }
        return 0;
    }, address);
    return dl->dli_sname ? 1 : 0;
}