#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* =========================================================
   UNSORTED ARRAY
========================================================= */

int uarr[MAX], usize = 0;

void u_insert(int x) {
    uarr[usize++] = x;
}

int u_search(int key) {
    for (int i = 0; i < usize; i++)
        if (uarr[i] == key) return i;
    return -1;
}

void u_delete(int key) {
    int idx = u_search(key);
    if (idx == -1) return;
    uarr[idx] = uarr[usize - 1];
    usize--;
}

int u_min() {
    int m = uarr[0];
    for (int i = 1; i < usize; i++)
        if (uarr[i] < m) m = uarr[i];
    return m;
}

int u_max() {
    int m = uarr[0];
    for (int i = 1; i < usize; i++)
        if (uarr[i] > m) m = uarr[i];
    return m;
}

int u_pred(int key) {
    int pred = -1;
    for (int i = 0; i < usize; i++)
        if (uarr[i] < key && (pred == -1 || uarr[i] > pred))
            pred = uarr[i];
    return pred;
}

int u_succ(int key) {
    int succ = -1;
    for (int i = 0; i < usize; i++)
        if (uarr[i] > key && (succ == -1 || uarr[i] < succ))
            succ = uarr[i];
    return succ;
}

/* =========================================================
   SORTED ARRAY
========================================================= */

int sarr[MAX], ssize = 0;

void s_insert(int x) {
    int i = ssize - 1;
    while (i >= 0 && sarr[i] > x) {
        sarr[i + 1] = sarr[i];
        i--;
    }
    sarr[i + 1] = x;
    ssize++;
}

int s_search(int key) {
    int l = 0, r = ssize - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (sarr[m] == key) return m;
        else if (sarr[m] < key) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

void s_delete(int key) {
    int idx = s_search(key);
    if (idx == -1) return;
    for (int i = idx; i < ssize - 1; i++)
        sarr[i] = sarr[i + 1];
    ssize--;
}

int s_min() { return sarr[0]; }
int s_max() { return sarr[ssize - 1]; }

int s_pred(int key) {
    int idx = s_search(key);
    if (idx <= 0) return -1;
    return sarr[idx - 1];
}

int s_succ(int key) {
    int idx = s_search(key);
    if (idx == -1 || idx == ssize - 1) return -1;
    return sarr[idx + 1];
}

/* =========================================================
   SINGLY LINKED LIST (UNSORTED)
========================================================= */

struct node {
    int data;
    struct node *next;
};

struct node* sll = NULL;

void sll_insert(int x) {
    struct node* n = malloc(sizeof(struct node));
    n->data = x;
    n->next = sll;
    sll = n;
}

struct node* sll_search(int key) {
    struct node* t = sll;
    while (t) {
        if (t->data == key) return t;
        t = t->next;
    }
    return NULL;
}

void sll_delete(int key) {
    struct node *t = sll, *p = NULL;
    while (t && t->data != key) {
        p = t;
        t = t->next;
    }
    if (!t) return;
    if (!p) sll = t->next;
    else p->next = t->next;
    free(t);
}

int sll_min() {
    struct node* t = sll;
    int m = t->data;
    while (t) {
        if (t->data < m) m = t->data;
        t = t->next;
    }
    return m;
}

int sll_max() {
    struct node* t = sll;
    int m = t->data;
    while (t) {
        if (t->data > m) m = t->data;
        t = t->next;
    }
    return m;
}

int sll_pred(int key) {
    struct node* t = sll;
    int pred = -1;
    while (t) {
        if (t->data < key && (pred == -1 || t->data > pred))
            pred = t->data;
        t = t->next;
    }
    return pred;
}

int sll_succ(int key) {
    struct node* t = sll;
    int succ = -1;
    while (t) {
        if (t->data > key && (succ == -1 || t->data < succ))
            succ = t->data;
        t = t->next;
    }
    return succ;
}

/* =========================================================
   DOUBLY LINKED LIST (UNSORTED)
========================================================= */

struct dnode {
    int data;
    struct dnode *prev, *next;
};

struct dnode* dll = NULL;

void dll_insert(int x) {
    struct dnode* n = malloc(sizeof(struct dnode));
    n->data = x;
    n->prev = NULL;
    n->next = dll;
    if (dll) dll->prev = n;
    dll = n;
}

struct dnode* dll_search(int key) {
    struct dnode* t = dll;
    while (t) {
        if (t->data == key) return t;
        t = t->next;
    }
    return NULL;
}

void dll_delete(int key) {
    struct dnode* t = dll;
    while (t && t->data != key) t = t->next;
    if (!t) return;

    if (t->prev) t->prev->next = t->next;
    else dll = t->next;

    if (t->next) t->next->prev = t->prev;

    free(t);
}

int dll_min() {
    struct dnode* t = dll;
    int m = t->data;
    while (t) {
        if (t->data < m) m = t->data;
        t = t->next;
    }
    return m;
}

int dll_max() {
    struct dnode* t = dll;
    int m = t->data;
    while (t) {
        if (t->data > m) m = t->data;
        t = t->next;
    }
    return m;
}

int dll_pred(int key) {
    struct dnode* t = dll;
    int pred = -1;
    while (t) {
        if (t->data < key && (pred == -1 || t->data > pred))
            pred = t->data;
        t = t->next;
    }
    return pred;
}

int dll_succ(int key) {
    struct dnode* t = dll;
    int succ = -1;
    while (t) {
        if (t->data > key && (succ == -1 || t->data < succ))
            succ = t->data;
        t = t->next;
    }
    return succ;
}

/* =========================================================
   MAIN (DEMO)
========================================================= */

int main() {

    printf("=== Dictionary Full Implementation Demo ===\n\n");

    // Unsorted Array
    u_insert(10); u_insert(5); u_insert(20);
    printf("Unsorted Array Min: %d\n", u_min());
    printf("Unsorted Array Max: %d\n", u_max());
    printf("Pred(10): %d Succ(10): %d\n\n", u_pred(10), u_succ(10));

    // Sorted Array
    s_insert(10); s_insert(5); s_insert(20);
    printf("Sorted Array Min: %d\n", s_min());
    printf("Sorted Array Max: %d\n", s_max());
    printf("Pred(10): %d Succ(10): %d\n\n", s_pred(10), s_succ(10));

    // Singly Linked List
    sll_insert(10); sll_insert(5); sll_insert(20);
    printf("SLL Min: %d Max: %d\n", sll_min(), sll_max());

    // Doubly Linked List
    dll_insert(10); dll_insert(5); dll_insert(20);
    printf("DLL Min: %d Max: %d\n", dll_min(), dll_max());

    return 0;
}