#include <stdio.h>
#include <stdlib.h>
#include "_base64.h"
#include <string.h>

int main (int argc, char** argv)
{
    char* shelp;
    shelp = "base64.exe image_filename base64.txt_filename\n";
    if ( argc < 3 ) {
        // не заданы путь к картинке, путь к результирующему txt-файлу
        printf(shelp);
        return 1;
    } else {
        FILE* fin = fopen(argv [1], "rb");
        FILE* fout = fopen(argv [2], "w");
        if(fin) {
            base64_encode( fin, fout );
            fclose(fin);
            fclose(fout);
        }
    }
    return 0;
}
