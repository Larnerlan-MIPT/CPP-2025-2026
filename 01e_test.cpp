#include <iostream>
#include <dlfcn.h>
#include <unistd.h>

int main() {
    sleep(2);
    void* handle = dlopen("./libmiptlib.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error: " << dlerror() << std::endl;
        return 1;
    }
    typedef void (*func_t)();
    func_t func = (func_t) dlsym(handle, "run_tests");
    if (!func) {
        std::cerr << "Error: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }
    func();
    dlclose(handle);
    return 0;
}