#include <stdio.h>
#include <string.h>

// ptr takes up 8 bytes (64 bits)

void explorePointer() {
    // string literal, list of chars:
    // |t|e|s|t|\o|
    // each char is 1 byte (8 bits)
    // has pointer (char *) named example
    char *example = "test";

    // value of the address stored in the pointer is the first char in the string literal
    // it prints out 't'
    printf("Value of ptr: %c\n", *example); // %c lets you get the char

    // now we are getting the address stored in pointer 
    // this will be the address of the first char in the string liteal ('t')
    // (void *) casts the pointer to void
    // %p format specifier expects a pointer to void
    // address stored in hexadecimal (0xXXXXXXXX)
    // each hexadecimal digit represents 4 bits of the address (ex: 'D'=1101)
    printf("Address stored in ptr: %p\n", (void *)example); 

    // doing & in front of the pointer, gets the address of that pointer
    printf("Address of the ptr: %p\n", (void *)&example);

    // loop through the string literal
    // In a loop that iterates over the characters of the string literal using array indexing or pointer arithmetic, ...
    // the pointer example is not modified. It continues to point to the same memory address where the first character of ...
    // the string literal is stored.
    // prints the memory address of the character itself
    for(int i = 0; example[i] != '\0'; i++) {
        printf("Address of the %d char ~ value: %c ~ address: %p\n", i, example[i], (void *)&example[i]);
    }
}

void printStringLiteralArray(char *strings[], int arrayLength) {
    printf("%s", strings[0]);
    for(int i = 1; i < arrayLength - 1; i++) {
        printf(" %s", strings[i]);
    }
    printf("%s\n", strings[arrayLength - 1]);
}

int main() {
    explorePointer();

    char *exampleArray[] = {"I", "want", "food", "because", "I'm", "hungry", "."};
    int exampleArrayLength = sizeof(exampleArray) / sizeof(exampleArray[0]);

    printf("Array length: %d\n", exampleArrayLength);
    printStringLiteralArray(exampleArray, exampleArrayLength);

    // getting the address of the array itself
    // this points to the address of the first pointer in the array of pointers
    printf("Address exampleArray: %p\n", (void *)exampleArray);
    printf("Address exampleArray: %p\n", (void *)&exampleArray);

    // address of the first pointer, should match above
    printf("Address of the first pointer in the array: %p\n", (void *)&exampleArray[0]);

    // print out the address stored in each pointer
    for(int i = 0; i < exampleArrayLength; i++) {
        printf("Address stored in exampleArray[%d]: %p\n", i, (void *)exampleArray[i]);
        // should match what is above
        printf("Address of the first char in the string literal ~ %c: %p\n", exampleArray[i][0], (void *)&exampleArray[i][0]);
    }

    printf("Size of I: %lu\n", sizeof(&exampleArray[0]));

    return 0;
}