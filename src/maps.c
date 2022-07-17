#include <stdlib.h>
#include "maps.h"

unsigned char* CreateMap1() {
    unsigned char* Map1 = (unsigned char*) malloc(1024*sizeof(unsigned char));
    for (int i = 0; i < 64; i++) {
        Map1[i] = 0x01;
    }
    for (int i = 2; i < 30; i++) {
        Map1[32*i] = 0x01;
        Map1[32*i + 1] = 0x01;
        for (int j = 2; j < 30; j++) {
            Map1[32*i + j] = 0x00;
        }
        Map1[32*i + 30] = 0x01;
        Map1[32*i + 31] = 0x01;
    }
    for (int i = 0; i < 64; i++) {
        Map1[960 + i] = 0x01;
    }
    return Map1;
}

unsigned char* CreateMap2() {
    unsigned char* Map1 = (unsigned char*) malloc(1024*sizeof(unsigned char));
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 32; x++) {
            Map1[32*y + x] = 0x01;
        }
    }
    for (int y = 2; y < 20; y++) {
        for (int x = 0; x < 2; x++) {
            Map1[32*y + x] = 0x01;
        }
        for (int x = 2; x < 30; x++) {
            Map1[32*y + x] = 0x00;
        }
        for (int x = 30; x < 32; x++) {
            Map1[32*y + x] = 0x01;
        }
    }
    for (int y = 20; y < 30; y++) {
        for (int x = 0; x < 2; x++) {
            Map1[32*y + x] = 0x01;
        }
        for (int x = 2; x < 20; x++) {
            Map1[32*y + x] = 0x00;
        }
        for (int x = 20; x < 22; x++) {
            Map1[32*y + x] = 0x01;
        }
        for (int x = 22; x < 30; x++) {
            Map1[32*y + x] = 0x00;
        }
        for (int x = 30; x < 32; x++) {
            Map1[32*y + x] = 0x01;
        }
    }
    for (int y = 30; y < 32; y++) {
        for (int x = 0; x < 32; x++) {
            Map1[32*y + x] = 0x01;
        }
    }
    return Map1;
}
