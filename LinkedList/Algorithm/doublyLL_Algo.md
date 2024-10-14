# Creation
1. Make a Node structure that stores the value, pointer to next node, pointer to previous node
2. Make a constructor that takes value val as argument and initiallizes a node with value val, next and prev as NULL
3. Make a doublyLinkedList Class that has private variable head of type node.

# Insert At Start
1. Input: Take value val from user
2. Make a new Node newNode with value val.
3. If head == NULL, the list is empty. Set head = newNode
4. Otherwise, add new node before head.
5. set newNode->next = head | head->prev = newNode
6. Head = newNode

# Insert At End
1. Input: Take value val from user
2. Make a new Node newNode with value val
3. If head == NULL, list is empty. Set head = newNode
4. Otherwise, traverse through the list to reach till the end
5. Initialize a new variable temp pointing to head
6. while temp->next != NULL | temp = temp->next
7. Set temp->next = newNode | newNode->prev = temp

# Insert At Nth Position
1. Tnput: Take value val and position pos from the user
2. Make a new Node newNode with value val
3. If head == NULL, list is empty. Assign head = newNode
4. Otherwise, if position pos == 1, insert at start
5. Insert At Start: head->prev = newNode | newNode->next = head | head = newNode
6. Otherwise, traverse till position pos reaches, or end of list is encountered
7. Initialize temporary pointer variable temp pointing to head to traverse list, and int i = 0
8. while i != pos and temp != NULL, i++ | temp->next = temp
9. If temp == NULL, list ended and position not found. Terminate
10. Otherwise, node with value found.
11. Set newNode->next = temp->next | newNode->prev = temp | temp->next = newNode
12. To set the next node of newNode's prev pointer: If newNode->next == NULL, terminate
13. Otherwise newNode->next->prev = newNode.

# Delete At Start
1. If head == NULL, list is empty. Terminate
2. 





