#ifndef CAPI_MODULE
#define CAPI_MODULE

#ifndef __linux__
#include <Windows.h>

#define SEPARATOR "\\\\"
#define LOAD_LIB(path) LoadLibrary(path)
#define GET_FUNC(module, name, type) (type) GetProcAddress(module, name);

typedef HINSTANCE Module;
#else
#include <stddef.h>
#include <dlfcn.h>

#define SEPARATOR "/"
#define LOAD_LIB(name) dlopen(name, RTLD_NOW);
#define GET_FUNC(module, name, type) (type) dlsym(module, name);

typedef void *Module;
#endif

int load_module(const char *path);