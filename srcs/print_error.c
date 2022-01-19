#include "push_swap.h"

void malloc_error() {
    write(2, "malloc ERROR\n", 13);
    exit(1);
}

void insert_error() {
    write(2, "insert ERROR\n", 13);
    exit(1);
}

void arg_error() {
    write(2, "argument ERROR\n", 15);
    exit(1);
}

void int_error() {
    write(2, "integer range ERROR\n", 20);
    exit(1);
}

void duplicate_error(){
    write(2, "argument duplicate ERROR\n", 25);
    exit(1);
}
