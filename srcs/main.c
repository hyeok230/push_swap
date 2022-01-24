#include "push_swap.h"

int main(int argc, char** argv) {
    int start;
    t_LinkedDeque   *a;
    t_LinkedDeque   *b;

    if (argc < 2)
        return (1);
    start = 0;
    a = createLinkedDeque();
    init_a(a, argc, argv);
    b = createLinkedDeque();
    if (a->currentElementCount == 5) 
        sort_five(a, b);
    else
        a_to_b(a->currentElementCount, a, b, &start);
    free_all(a, b);
}