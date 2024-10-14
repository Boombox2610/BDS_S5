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
2. Otherwise, Store head in temporary node variable temp = head | Set head = temp->next
3. If new head == NULL, list was of one element, now empty. Terminate (Prevent null pointer dereference)
4. Otherwise, head->prev = NULL.
5. Delete temp

# Delete At End
1. If head = NULL, list is empty. Terminate
2. If head->next = NULL, list has only 1 element. Delete head, head = NULL, terminate
3. Otherwise, store head in temporary node variable temp = head.
4. Traverse till end of list. while temp->next != NULL, temp = temp->next
5. Set temp->prev = NULL | delete temp

# Delete By Val
1. Input: value val to be deleted
2. If head = NULL, list is empty, terminate
3. If head->value = val, delete at start.
4. temp = head | head = temp->next | if head != NULL then head->prev = NULL | delete temp
5. Otherwise, iterate through whole list from start to value.
6. Create temporary node temp pointing to head. while temp->value != val && temp != NULL, temp = temp->next
7. If temp == NULL, terminate. Value not found
8. Otherwise, temp->prev->next = temp->next
9. If temp->next != NULL, temp->next->prev = temp->prev (prevent null pointer deref)
10. Delete temp

# Display
1. If head = NULL, list is empty. Terminate
2. Traverse whole list till end. Create temporary node temp = head
3. While temp != NULL, print temp->value \ temp = temp->next
4. Delete temp

# Display Reverse
1. If head = NULL, list is empty. Terminate
2. Traverse whole list till end. Create temporary node temp = head
3. while temp->next != NULL, temp = temp->next
4. Once reached at end, print values from end to start
5. While temp != NULL, print temp->val | temp = temp->prev
6. Delete temp



