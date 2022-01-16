#include "push_swap.h"

// void push_swap() {

// }

void init_a(t_LinkedDeque *a, int argc, char** argv) {
    t_Heap *pHeap;
    t_HeapNode element;
    t_HeapNode* result;
    int i;
    int num;

    pHeap = createHeap(argc);
    i = 1;
    while (i < argc) {
        num = ft_atoi(argv[i]);
        element.data = num;
        if (insertMinHeap(pHeap, element) == FALSE)
            ft_malloc_error();
        i++;
    }
    while (pHeap->currentElementCount) {
        result = deleteMinHeapNode(pHeap);

    }

}

int main(int argc, char** argv) {
    t_LinkedDeque   *a;
    t_LinkedDeque    *b;

    if (argc < 2)
        return (1);
    a = createDoublyList();
    b = createDoublyList();
    init_a(a, argc, argv);
    // push_swap(a, b);
    // delete a, b
}