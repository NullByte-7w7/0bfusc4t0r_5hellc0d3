// shellcode obfuscare in C
// Credits NullByte licence!

#include <stdio.h>

// colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"




// function generate shellcode obfuscate

void obfuscate(unsigned char *shellcode, unsigned int len, unsigned char key) {
    for (int i = 0; i < len; i++){
        shellcode[i] ^= key;
        printf(GREEN "\\x%02x" RESET, shellcode[i]);
    }

}

// start magic!

int main(void){


                // set variable

                unsigned char key = 0xAA;
                unsigned char shellcode[65535];
                unsigned int len = 0;
                char input[65535];

                // stdin shellcode
                 printf(BLUE "[@] Example -> \\x90\\x90\\x90\\x90\n" RESET);
                 printf("[!] SHELLCODE -> ");
                 fgets(input, sizeof(input), stdin);

                // cycle through hexadecimal until the loop stops

                char *p = input;
                while((sscanf(p, "\\x%2hhx", &shellcode[len]) == 1)){
                        len++;
                        p += 4;
                }

                // show obfuscated shellcode

                printf("[#] Shellcode obfuscate\n");
                obfuscate(shellcode, len, key);
                printf(RED "\nSIZE SHELLCODE -> %i\n" RESET, len);

                return 0;
}
