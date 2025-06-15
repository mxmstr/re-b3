#pragma once

enum class EActiveBodyType : unsigned char {
    Type0 = 0,
    Type1 = 1,
    Type2 = 2,
    Type3 = 3,
    Type4 = 4,
    Type5 = 5,
    Type6 = 6,
    Type7 = 7,
    Type8 = 8
};

// Add these declarations at the end of the file, after EActiveBodyType
extern bool kaabCanFatal[100];      // Assumed bool, size 10x10
extern int  kaaePhysicsType[400];   // Assumed int, size 10x10 with strides of 40 and 4
