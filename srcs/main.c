#include "push_swap.h"

t_DoublyList* createDoublyList() {
	t_DoublyList*	pList;

	pList = (t_DoublyList*)malloc(sizeof(t_DoublyList));
	if (pList == NULL)
		ft_malloc_error();
	pList->currentElementCount = 0;
	pList->headerNode.data = -1;
	pList->headerNode.pLLink = &(pList->headerNode);
	pList->headerNode.pRLink = &(pList->headerNode);
	return (pList);	
}

int main(int argc, char** argv) {
    t_DoublyList    *a;
    t_DoublyList    *b;


    if (argc < 2)
        return (1);
    a = createDoublyList();
    b = createDoublyList();
    
}