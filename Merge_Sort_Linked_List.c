#include <stdio.h>
#include <stdlib.h>

// Cau truc Node cua danh sach lien ket don
struct Node
{
    int data;              // Gia tri cua node
    struct Node* next;     // Con tro den node ke tiep
};

// Ham in danh sach lien ket
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d -> ", ptr->data); // In gia tri cua tung node
        ptr = ptr->next;
    }
    printf("NULL\n"); // Ket thuc danh sach lien ket
}

// Ham them node moi vao cuoi danh sach lien ket
void append(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Neu danh sach lien ket rong
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Duyet den node cuoi cung cua danh sach
    struct Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode; // Them node moi vao cuoi
}

// Ham hop nhat hai danh sach da duoc sap xep
// Tra ve mot danh sach moi da sap xep
struct Node* sortedMerge(struct Node* a, struct Node* b)
{
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    struct Node* result = NULL;

    // Chon node co gia tri nho hon va tiep tuc de quy
    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

// Ham chia danh sach thanh hai phan bang nhau
void frontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef)
{
    // Neu danh sach co it hon 2 phan tu
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    struct Node* slow = source;
    struct Node* fast = source->next;

    // Duyet danh sach: fast di nhanh gap doi slow
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Cat danh sach tai vi tri cua slow
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Ham sap xep danh sach lien ket bang Merge Sort
void mergesort(struct Node** head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct Node* a;
    struct Node* b;

    // Chia danh sach thanh hai phan
    frontBackSplit(*head, &a, &b);

    // De quy sap xep tung phan
    mergesort(&a);
    mergesort(&b);

    // Hop nhat hai phan da sap xep
    *head = sortedMerge(a, b);
}

int main(void)
{
    struct Node* head = NULL;
    int n;

    // Nhap kich thuoc cua danh sach lien ket
    printf("Nhap so phan tu cua danh sach lien ket: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Danh sach lien ket phai co it nhat mot phan tu.\n");
        return 0;
    }

    // Nhap gia tri cua tung phan tu
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &data);
        append(&head, data);
    }

    // Sap xep danh sach lien ket
    mergesort(&head);

    // In danh sach da sap xep
    printf("Danh sach lien ket da sap xep: ");
    printList(head);

    return 0;
}