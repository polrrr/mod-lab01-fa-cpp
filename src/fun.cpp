// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char* str) {
    int i = 0;
    int wordCount = 0;
    bool inWord = false;
    bool isNumber = false;

    while (str[i] != 0) {
        char c = str[i];
        if (c != ' ' && !inWord) {
            inWord = true;
        }

        if (c >= '0' && c <= '9') {
            isNumber = true;
        }

        if (c == ' ' && inWord && !isNumber) {
            inWord = false;
            wordCount++;
        } else if (c == ' ' && inWord) {
            inWord = false;
            isNumber = false;
        }

        i++;
    }
    if (inWord && !isNumber) {
        wordCount++;
    }

    return wordCount;
}

unsigned int faStr2(const char* str) {
    int i = 0;
    int wordCount = 0;
    bool inWord = false;
    bool notWord = false;

    while (str[i] != 0) {
        char c = str[i];

        if (c != ' ') {
            if (c >= 'A' && c <= 'Z' && !inWord && !notWord)
                inWord = true;
            else if (c >= 'A' && c <= 'Z' && inWord && !notWord)
                notWord = true;
            else if ((c < 'a' || c > 'z') && inWord && !notWord)
                notWord = true;
        }

        if (c == ' ' && inWord && !notWord) {
            inWord = false;
            wordCount++;
        }
        if (c == ' ' && inWord && notWord) {
            inWord = false;
            notWord = false;
        }

        i++;
    }
    if (inWord && !notWord) {
        wordCount++;
    }

    return wordCount;
}

unsigned int faStr3(const char* str) {
    int i = 0;
    int wordCount = 0;
    int sumLength = 0;
    bool inWord = false;

    while (str[i] != 0) {
        if (str[i] != ' ' && !inWord) {
            inWord = true;
        }

        if (str[i] == ' ' && inWord) {
            inWord = false;
            wordCount++;
        }
        if (inWord) {
            sumLength++;
        }
        i++;
    }
    if (inWord) {
        wordCount++;
    }
    return static_cast<int>(static_cast<double>(sumLength) / wordCount + 0.5);
}
