#include "iostream"
using namespace std;
char *findC (const char *source, const char *obj) {
    const char *pointer = source;
    const char *objcpy = obj;
    while (*(pointer++) != '\0') {
        while (*(pointer) == *(objcpy)) {
            pointer++;
            objcpy++;
            if (*(pointer) != *(objcpy) && *objcpy != '\0')
                return NULL;
        }
        if(*objcpy == '\0')
            return (char *)obj;
    }
    return NULL;
}

int main (){
    const char *source = "ABCDEAB";
    const char *obj = "AB";
    char *result = findC(source, obj);
    cout << result << endl;
    return 0;
}
