#ifndef PROTECTED_LIST_H
#define PROTECTED_LIST_H

typedef struct ProtectedList ProtectedList;

ProtectedList *plist_create(void);
void plist_destroy(ProtectedList *pl);
void plist_append(ProtectedList *pl, int value);
void plist_remove_duplicates(ProtectedList *pl);
void plist_print(const ProtectedList *pl);

#endif // PROTECTED_LIST_H
