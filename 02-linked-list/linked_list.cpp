/**
 * C++ example to demonstrate Linked List
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
 * Linked list implementation
 */
class List
{
    // Head of the list
    Node* head;

public:
    // Constructor
    List() : head(NULL) {}

    // Insert an element in front of the list
    // Returns the new node inserted
    Node* insert_front(int element);

    // Insert an element after the given node
    // Returns the new node inserted
    Node* insert_after(Node* prev, int element);

    // Delete the front element
    // Returns the next node if available, NULL otherwise.
    Node* delete_front();

    // Delete the element after the given node
    // Returns the next node if available, NULL otherwise.
    Node* delete_after(Node* prev);

    // Search and delete the given element
    void remove(int element);
    
    // Search an element from the list
    // Returns the matching node if found, NULL otherwise.
    Node* search(int element);

    // Print the elements
    void print(const std::string& msg);
};

Node* List::insert_front(int element)
{
    // Step 1. Create the node
    Node* new_node = new Node();
    new_node->element = element;

    // Step 2. Link before the head node
    new_node->next = head;

    // Step 3. Change the head to point the new node
    head = new_node;

    return new_node;
}

Node* List::insert_after(Node* prev, int element)
{
    // Step 1. Create the new node
    Node *new_node = new Node();
    new_node->element = element;

    // Step 2. Link the new node after the given node
    new_node->next = prev->next;
    prev->next = new_node;

    return new_node;
}

Node* List::delete_front()
{
    // Step 1. Check if the list is empty and return if true.
    if (head == NULL) {
        return NULL;
    }

    // Step 2. Store the reference to front node as target node and
    // move the head to next node if available or NULL.
    Node* target = head;
    head = head->next;

    // Step 3. Delete the target node
    delete target;

    return head;
}

Node* List::delete_after(Node* prev)
{
    // Step 1. Store the reference to target node
    Node* target = prev->next;

    // Step 2. Check if the target node is NULL and return if true
    if (target == NULL) {
        return NULL;
    }

    // Step 3. Disconnect the target node by linking its previous and next
    // node directly
    prev->next = target->next;

    // Step 4. Delete the target node
    delete target;

    return prev->next;
}

void List::remove(int element)
{
    // Step 1. Check if the list is empty and return if true.
    if (head == NULL) {
        return;
    }
    
    // Step 2. Check if the front node matches the element. If true,
    // invoke the delete_front() operation and return.
    if (head->element == element) {
        delete_front();
        return;
    }
        
    // Step 3. Otherwise, iterate the linked list from start to end,
    // and search if the element is found.
    for (Node* node = head ; node->next != NULL ; node = node->next) {
        
        if (node->next->element == element) {
            // Step 4. If found, set the node as target node and disconnect
            // it by directly linking the previous and next node.
            Node* target = node->next;
            node->next = node->next->next;
            
            // Step 5. Delete the target node
            delete target;
            return;
        }
    }
    
    return;
}

Node* List::search(int element)
{
    // Iterate the linked list from start to end
    for (Node* node = head ; node != NULL ; node = node->next) {
        if (node->element == element) {
            return node; // Found element
        }
    }
    return NULL; // Not found
}

// Print the linked list
void List::print(const std::string& msg)
{
    cout << msg << endl;
    cout << "HEAD ==> ";
    // Iterate the linked list from start to end
    for (Node* node = head ; node != NULL ; node = node->next) {
        cout << node->element << " ==> ";
    }
    cout << "NULL" << endl << endl;
}

int main()
{
    // Create a linked list
    List list;
    list.print("initial list");

    // Insert elements
    list.insert_front(20);
    list.print("insert_front(20)");

    Node *node_10 = list.insert_front(10);
    list.print("insert_front(10)");
    
    list.insert_after(node_10, 15);
    list.print("insert_after(node_10, 15)");

    // Search an element
    Node *node_15 = list.search(15);
    cout << "search(15) matches node " << node_15->element << endl << endl;

    // Delete elements
    list.delete_front();
    list.print("delete_front()");
    
    list.delete_after(node_15);
    list.print("delete_after(node_15)");
    
    list.remove(15);
    list.print("remove(15)");
}
