#include <stdio.h>
#include "protected_list.h"

int main(void) {
    ProtectedList *pl = plist_create();
    if (!pl) return 1;

    plist_append(pl, 1);
    plist_append(pl, 2);
    plist_append(pl, 2);
    plist_append(pl, 3);
    plist_append(pl, 4);
    plist_append(pl, 5);
    plist_append(pl, 5);

    printf("Original: ");
    plist_print(pl);

    plist_remove_duplicates(pl);

    printf("After removing duplicates: ");
    plist_print(pl);

    plist_destroy(pl);
    return 0;
}
