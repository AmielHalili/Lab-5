#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
    int num = 0;
    node* temp = head;
    while (temp != NULL)
    {
        num++;
        temp = temp->next;
    }
    return num;
}
// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function will return "abc"
char* toCString(node* head)
{
    node* temp = head;
    int sL = length(head);
    char* string = malloc((sL) * sizeof(char));

    int i;
    for (i = 0; i < sL; i++)
    {
        string[i] = temp->letter;
        temp = temp->next;
    }
    return string;

}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* blah = malloc(sizeof(node));

    blah->letter = c;
    blah->next = NULL;

    if (*pHead == NULL)
    {
        *pHead = blah;
    }
    else
    {
        node* temp = *pHead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = blah;
    }
}
// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* tmp = *pHead;

    while (tmp != NULL)
    {
        *pHead = tmp->next;
        free(tmp);
        tmp = *pHead;
    }
    *pHead = NULL;
}
int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}