#include <cstdio>

#include "double_linked_list.h"

int main() {
    sieve::DoubleLinkedList dll(1);
    printf("%s\n", dll.ToString().c_str());
    return 0;
}