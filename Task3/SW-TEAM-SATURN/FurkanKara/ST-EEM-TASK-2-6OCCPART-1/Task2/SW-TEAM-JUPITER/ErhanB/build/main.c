#include "..\inc\task.h"


int main()
{
    linkedList_t *list1 = (linkedList_t *)malloc(sizeof(linkedList_t));
    if(!list1)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
    float valueFloat = 6.35;
    int itgr1 = 5;
    int itgr2 = 10;
    int itgr3 = 456;
    char buff = 'a';
    double dbl = 7864354;

    initList(list1);
    addNode(list1, &itgr1, INT_TYPE);
    addNode(list1, &buff, CHAR_TYPE);
    addNode(list1, &itgr2, INT_TYPE);
    addNode(list1, &valueFloat, FLOAT_TYPE);
    addNode(list1, &dbl, DOUBLE_TYPE);

    printAll(list1);

    deleteNode(list1, &itgr1);

    addNode(list1, &itgr3, INT_TYPE);

    printAll(list1);

    deleteNode(list1, &valueFloat);

    printAll(list1);

    deleteList(list1);

    printAll(list1);

    deleteNode(list1, &itgr2);

    return 0;
}