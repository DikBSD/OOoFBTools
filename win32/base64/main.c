#include <stdio.h>
#include <stdlib.h>
#include "_base64.h"
#include <string.h>

int main (int argc, char** argv)
{
    char* shelp;
    shelp = "base64.exe image_filename base64.txt_filename mimetype id_image\n";
    if ( argc < 5 ) {
        // не заданы путь к картинке, путь к результирующему txt-файлу, mimetype и id картинки
        printf(shelp);
        return 1;
    } else {

        FILE* fin = fopen(argv [1], "rb");
        FILE* fout = fopen(argv [2], "w");
        if(fin) {
            fputs( "<binary content-type=\"image/", fout );
            fputs( argv [3], fout );
            fputs( "\" id=\"", fout );
            fputs( argv [4], fout );
            fputs( "\">\n", fout );

            base64_encode( fin, fout );

            fputs( "</binary>\n", fout );

            fclose(fin);
            fclose(fout);
        }
    }
    return 0;
}
