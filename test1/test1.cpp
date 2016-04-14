#include "iostream"
#include "cstring"
using namespace std;
char *findC (const char *source, const char *obj) {
    int lenObj = strlen(obj);
    int lenSource = strlen(source);
    int j;
    int pNext[lenObj];
    pNext[0] = 0;
    for (int i = 1, j = 0; i < lenObj; i++) {
        while (j > 0 && *(obj+j) != *(obj+i))
            j = pNext[j];
        if (*(obj+j) == *(obj+i))
            j++;
        pNext[i] = j;
    }

    for (int i = 0, j = 0; i < lenObj; i++) {
        while (j > 0 && *(obj+j) != *(source+i))
            j = pNext[j-1];
        if (*(obj+j) == *(source+i))
            j++;
        if (j == lenObj-1)
            return (char *)obj;
    }
    return NULL;
}

int main (){
    const char *source = "abababc";
    const char *obj = "ababc";
    char *result = findC(source, obj);
    cout << result << endl;
    return 0;
}
