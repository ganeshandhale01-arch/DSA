#include "protected_list.h"
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

struct ProtectedList {
    struct Node *head;
};

ProtectedList *plist_create(void) {
    ProtectedList *pl = malloc(sizeof(ProtectedList));
    if (!pl) return NULL;
    pl->head = NULL;
    return pl;
}

static struct Node *create_node(int value) {
    struct Node *n = malloc(sizeof(struct Node));
    if (!n) return NULL;
    *n = (struct Node){ .data = value, .next = NULL };
    return n;
}

void plist_append(ProtectedList *pl, int value) {
    if (!pl) return;
    struct Node *n = create_node(value);
    if (!n) return;
    if (!pl->head) {
        pl->head = n;
        return;
    }
    struct Node *cur = pl->head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

void plist_remove_duplicates(ProtectedList *pl) {
    if (!pl) return;
    struct Node *cur = pl->head;
    while (cur && cur->next) {
        if (cur->data != cur->next->data) {
            cur = cur->next;
        } else {
            struct Node *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        }
    }
}

void plist_print(const ProtectedList *pl) {
    if (!pl) return;
    struct Node *cur = pl->head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void plist_destroy(ProtectedList *pl) {
    if (!pl) return;
    struct Node *cur = pl->head;
    while (cur) {
        struct Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(pl);
}
