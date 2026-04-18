#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../MD5.h"

void test_make_digest_empty() {
    printf("Testing empty digest... ");
    unsigned char digest[1] = {0};
    char* result = MD5::make_digest(digest, 0);
    assert(strcmp(result, "") == 0);
    free(result);
    printf("PASSED\n");
}

void test_make_digest_single_byte() {
    printf("Testing single byte digest... ");
    unsigned char digest1[] = {0x00};
    char* result1 = MD5::make_digest(digest1, 1);
    assert(strcmp(result1, "00") == 0);
    free(result1);

    unsigned char digest2[] = {0xff};
    char* result2 = MD5::make_digest(digest2, 1);
    assert(strcmp(result2, "ff") == 0);
    free(result2);

    unsigned char digest3[] = {0x12};
    char* result3 = MD5::make_digest(digest3, 1);
    assert(strcmp(result3, "12") == 0);
    free(result3);
    printf("PASSED\n");
}

void test_make_digest_standard_length() {
    printf("Testing 16-byte digest... ");
    unsigned char digest[] = {
        0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10
    };
    char* result = MD5::make_digest(digest, 16);
    assert(strcmp(result, "0123456789abcdeffedcba9876543210") == 0);
    free(result);
    printf("PASSED\n");
}

void test_make_digest_all_values() {
    printf("Testing all byte values... ");
    unsigned char digest[256];
    char expected[513];
    for (int i = 0; i < 256; i++) {
        digest[i] = (unsigned char)i;
        sprintf(expected + (i * 2), "%02x", i);
    }
    expected[512] = '\0';

    char* result = MD5::make_digest(digest, 256);
    assert(strcmp(result, expected) == 0);
    free(result);
    printf("PASSED\n");
}

int main() {
    test_make_digest_empty();
    test_make_digest_single_byte();
    test_make_digest_standard_length();
    test_make_digest_all_values();
    printf("All MD5::make_digest tests passed!\n");
    return 0;
}
