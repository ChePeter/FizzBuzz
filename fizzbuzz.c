/* ============================================================================
 Name        : fizzbuzz.c
 Author      : Peter Che 7210208@gmail.com
 Version     :
 Copyright   : Your copyright notice
 Description : FizzBuzz in C, Ansi-style
 ============================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LIMIT 1000000000
#define CHUNK_SIZE  330 //??

int main(void) {
        int i;
        int ii;
        int carry;

        const char* buff;
        buff = "11\nFizz\n13\n14\nFizzBuzz\n16\n17\nFizz\n19\nBuzz\nFizz\n22\n23\nFizz\nBuzz\n26\nFizz\n28\n29\nFizzBuzz\n31\n32\nFizz\n34\nBuzz\nFizz\n37\n38\nFizz\nBuzz\n";
        int buff_len = 126;
        int l[30];
        char* s;
        char* ss;
        char* t_ss;
        char* buf_s;
        int l0;
        char* src;
        char* dst;
        char buf[CHUNK_SIZE];
        char *buf_0;
        buf_0 = "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n";


        l[0] = 3;
        l[1] = -5;
        l[2] = 3;
        l[3] = 3;
        l[4] = -9;
        l[5] = 3;
        l[6] = 3;
        l[7] = -5;
        l[8] = 3;
        l[9] = -5;
        l[10] = -5;
        l[11] = 3;
        l[12] = 3;
        l[13] = -5;
        l[14] = -5;
        l[15] = 3;
        l[16] = -5;
        l[17] = 3;
        l[18] = 3;
        l[19] = -9;
        l[20] = 3;
        l[21] = 3;
        l[22] = -5;
        l[23] = 3;
        l[24] = -5;
        l[25] = -5;
        l[26] = 3;
        l[27] = 3;
        l[28] = -5;
        l[29] = -5;

//        fwrite(buf_0, 35, 1, stdout);

        memcpy(buf + CHUNK_SIZE - buff_len, buff, buff_len);
        buf_s = buf + CHUNK_SIZE -buff_len;

//        fwrite(buf_s, buff_len, 1, stdout);

        l0 = 115;
        for (int j = 0; j < 33333332; j++) {
        //for (int j = 0; j < 16; j++) {
                ss = buf + CHUNK_SIZE - 10;
                i = 27;
                while (i >= 0)
                {
                        if (l[i] < 0) {
                                ss = ss + l[i--];
                                continue;
                        }
                        carry = 0;
                        s = ss - 3;
                        *s = *s + 3;
                        ss = ss - l[i];
                        do {
                                *s = *s + carry;
                                if (*s > '9') {
                                        carry = 1;
                                        *s = *s - 10;
                                        s--;
                                }
                                else {
                                        carry = 0;
                                        break;
                                }
                        } while (s >= ss);

                        if (carry > 0) {
                                src = buf_s--;
                                dst = buf_s;
                                l[i] = l[i] + carry;
                                l0++;
                                while (dst < s)
                                        *dst++ = *src++;
                                *(--ss) = '1';
                        }
                        i--;
                }
//                fwrite(buf_s, buf + CHUNK_SIZE - buf_s, 1, stdout);
        }
        return EXIT_SUCCESS;
}