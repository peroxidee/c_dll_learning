#include <stdio.h>
#include <windows.h>


#define k(msg, ...) printf("[+] " msg "\n", ##__VA_ARGS__)
#define w(msg, ...) printf("[-] " msg "\n", ##__VA_ARGS__)
#define i(msg, ...) printf("[i] " msg "\n", ##__VA_ARGS__)


int main(void) {
    HMODULE hInjDLL = NULL;
    wchar_t dllPath[MAX_PATH] = L"C:\\Users\\djkri\\CLionProjects\\dummyprog\\lib\\libc_dll_inject.dll";

    i("attempting to handle to %S", dllPath);

    hInjDLL= LoadLibraryW(dllPath);


    if (hInjDLL == NULL) {
        w("cannot get handle to dll, error: 0x%lx",GetLastError());
    }
    k("handle gotten!");
    i("---0x%p", hInjDLL);

    i("freeing mod");
    FreeLibrary(hInjDLL);
    k("fin, p <enter> to exit");

    getchar();



    return EXIT_SUCCESS;
}
