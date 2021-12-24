/**
 * C++ example to demonstrate the circular list
 */
#include <iostream>
using namespace std;

// Linked list node representation
struct Node
{
    int element;
    Node* next;
};

/**
 * Circular linked list implementation
 */
class CircularList
{
    // Head of the list
    Node* head;

public:
    // Constructor
    CircularList() : head(NULL) {}

    // Insert an element in front of the list
    // Returns the new node inserted
    Node* insert_front(int element);

    // Insert an element after the given node
    // Returns the new node inserted
    Node* insert_after(Node* prev, int element);
    
    // Insert an element at the end of the list
    // Returns the new node inserted
    Node* insert_back(int element);

    // Delete the front element
    // Returns the next node if available, NULL otherwise.
    Node* delete_front();

    // Delete the element after the given node
    // Returns the next node if available, NULL otherwise.
    Node* delete_after(Node* prev);

    // Delete the rear element
    // Returns the previous node if available, NULL otherwise.
    Node* delete_back();
    
    // Search and delete the given element
    // Returns true on success, false otherwise.
    bool remove(int element);
    
    // Search an element from the list
    // Returns the matching node if found, NULL otherwise.
    Node* search(int element);
    
    // Traverse the list and print the elements
    void traverse(const std::string& msg);
};

Node* CircularList::insert_front(int element)
{
    // Step 1. Create the new node
    Node* new_node = new Node();
    new_node->element = element;

    // Step 2. Check if the list is empty. If true, make the new node
    // as head and point itself to form the one node circle.
    if (head == NULL) {
        new_node->next = new_node;
        head = new_node;
        return new_node;
    }
    
    // Step 3. Find the last node which is required to form the new circle.
    Node *last_node = head;
    while (last_node->next != head) {
        last_node = last_node->next;
    }

    // Step 4. Connect the new node before the head node.
    new_node->next = head;
    last_node->next = new_node;
    
    // Step 5. Change the head to point the new node.
    head = new_node;

    return new_node;
}

Node* CircularList::insert_after(Node* prev, int element)
{
    // Step 1. Create the new node
    Node *new_node = new Node();
    new_node->element = element;

    // Step 2. Link the new node after the given node
    new_node->next = prev->next;
    prev->next = new_node;

    return new_node;
}

Node* CircularList::insert_back(int element) {
    // Step 1. Create the new node
    Node *new_node = new Node();
    new_node->element = element;
    
    // Step 2. Check if the list is empty. If true, make the new node
    // as head and point itself to form the one node circle.
    if (head == NULL) {
        new_node->next = new_node;
        head = new_node;
        return new_node;
    }
    
    // Step 3. Iterate the list and find the last node
    Node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    // Step 4. Link the new node after the last node
    new_node->next = last->next;
    last->next = new_node;
    
    return new_node;
}

Node* CircularList::delete_front()
{
    // Step 1. Check if the list is empty. If true, return.
    if (head == NULL) {
        return NULL;
    }

    // Step 2. Check if the list has single node. If true, delete the node,
    // reset the head to NULL, and return.
    if (head->next == head) {
        delete head;
        head = NULL;
        return NULL;
    }
    
    // Step 3. Iterate the list and find the last node.
    Node* last = head->next;
    while (last->next != head) {
        last = last->next;
    }
    
    // Step 4. Store the reference to head node as target node and
    // move the head to next node.
    Node* target = head;
    head = head->next;
    
    // Step 5. Connect the last node with the new head to alter the circle.
    last->next = head;
    
    // Step 6. Delete the target node
    delete target;

    return head;
}

Node* CircularList::delete_after(Node* prev)
{
    // Step 1. Initialize target with the reference to target node
    Node* target = prev->next;

    // Step 2. Check if the target node is NULL and return if true
    if (target == NULL) {
        return NULL;
    }

    // Step 3. Disconnect the target node by directly linking its
    // previous and next node.
    prev->next = target->next;

    // Step 4. Delete the target node
    delete target;

    return prev->next;
}

Node* CircularList::delete_back()
{
    // Step 1. Check if the list is empty. If true, return.
    if (head == NULL) {
        return NULL;
    }
    
    // Step 2. Check if the list has single node. If true, delete the node,
    // reset the head to NULL, and return.
    if (head->next == head) {
        delete head;
        head = NULL;
        return NULL;
    }
    
    // Step 3. Iterate the list and find the last and its previous node.
    Node* prev = head;
    Node* last = head->next;
    while (last->next != head) {
        prev = last;
        last = last->next;
    }
    
    // Step 4. Disconnect the target node by directly linking its
    // previous and next node.
    prev->next = last->next;

    // Step 5. Delete the target node
    delete last;

    return prev;
}

bool CircularList::remove(int element)
{
    // Step 1. Check if the list is empty and return if true.
    if (head == NULL) {
        return false;
    }
    
    // Step 2. Check if the front node matches the element. If true,
    // invoke the delete_front() operation and return.
    if (head->element == element) {
        delete_front();
        return true;
    }
        
    // Step 3. Otherwise, iterate the linked list from start to end,
    // and search if the element is found.
    for (Node* node = head ; node->next != NULL ; node = node->next) {
        
        if (node->next->element == element) {
            // Step 4. If found, set the node as target node and disconnect
            // it by directly linking its previous and next node.
            Node* target = node->next;
            node->next = node->next->next;
            
            // Step 5. Delete the target node
            delete target;
            return true;
        }
    }
    
    return false;
}

Node* CircularList::search(int element)
{
    // Check if the list is empty
    if (head == NULL) {
        return NULL;
    }
    
    // Iterate the linked list from start to end
    for (Node* node = head ; node->next != head ; node = node->next) {
        if (node->element == element) {
            return node; // Found element
        }
    }
    return NULL; // Not found
}

// Tranverse and print the linked list
void CircularList::traverse(const std::string& msg)
{
    cout << msg << endl;
    cout << "HEAD ==> ";
    if (head == NULL ) {
        cout << "NULL" << endl << endl;
        return;
    }
    
    // Iterate the linked list from start to end
    cout << head->element << " ==> ";
    for (Node* node = head->next ; node != head ; node = node->next) {
        cout << node->element << " ==> ";
    }
    cout << "HEAD" << endl << endl;
}

int main()
{
    // Create a linked list
    CircularList list;
    list.traverse("initial list");

    // Insert elements
    list.insert_front(20);
    list.traverse("insert_front(20)");

    Node *node_10 = list.insert_front(10);
    list.traverse("insert_front(10)");
    
    list.insert_after(node_10, 15);
    list.traverse("insert_after(node_10, 15)");
    
    list.insert_back(30);
    list.traverse("insert_back(30)");

    // Search an element
    Node *node_15 = list.search(15);
    cout << "search(15) matches node " << node_15->element << endl << endl;

    // Delete elements
    list.delete_front();
    list.traverse("delete_front()");
    
    list.delete_after(node_15);
    list.traverse("delete_after(node_15)");
    
    list.delete_back();
    list.traverse("delete_back()");
    
    list.remove(15);
    list.traverse("remove(15)");
}
