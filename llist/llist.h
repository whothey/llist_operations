typedef struct list_node {
    int n;
    struct list_node* next;
} llist;

/**
 * Starts the list pointers with NULL
 */
void start_list(llist** list);

/**
 * Initialize the llist with default values
 * Also prevent Memcheck to be angry with pointers without initilization
 */
void init_list_node(llist** list);

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
 * Insert an element "n" in list with ascending order
 */
void list_insert_ordered(llist** list, int n);

/**
 * Free a single element
 */
void list_free_element(llist* elem);

/**
 * Free all elements within a list
 */
void list_free_all(llist** list);

/**
 * Print all elements of the list
 */
void print_list(llist* list);

/**
 * Print all elements of the list as a numeric set
 */
void print_list_as_numeric_set(llist* list);
