typedef struct list_node {
    int n;
    struct list_node* next;
} llist;

/**
 * Initialize the llist
 */
void init_list(llist* list);

/**
 * Insert an element "n" at the beggining of the "list"
 * and returns the new pointer of the list, where it begins
 */
void list_insert_beg(llist** list, int n);

/**
 * Insert an element "n" after the value "v" in
 * "list"
 */
void list_insert_after(llist** list, int n, int v);

/**
 * Insert an element "n" at the ending of the list "list"
 */
void list_insert_end(llist** list, int n);

/**
 * Free a single element
 */
void list_free_element(llist* elem);

/**
 * Free all elements within a list
 */
void list_free_all(llist* list);

/**
 * Print all elements of the list
 */
void print_list(llist* list);
