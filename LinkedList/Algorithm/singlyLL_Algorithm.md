# Insert At Start
1. Take input of value val from user
2. Create new node NewNode with value val and next pointer to NULL
3. If head of linked list is NULL, set head = newNode
4. Otherwise, set newNode->next = head, set head = newNode

# Insert At End
1. Take input of value from user
2. Create new node newNode with value val and next pointer to NULL
3. If head of LL is NULL, set head = newNode
4. Otherwise, create temporary node temp pointing to head
5. Traverse till temp->next is NULL, to reach at the last element
6. Set next pointer of temp (last node) to newNode

# Insert At Nth Position
1. Take input of value and position to insert from user
2. Create new node newNode with value val and next pointer to NULL
3. If head of LL is NULL, set head = newNode
4. If n == 1 (insert at start), newNode->next = head, head = newNode
5. Otherwise, create temporary node temp pointing to head, initialize i = 0
6. Traverse till i < n - 1, and temp != NULL
7. If node at ith position found, set newNode->next = temp->next, set temp->next = newNode
8. Otherwise, if temp == NULL, INVALID position

# Delete At Start
1. If head == NULL, list is empty, terminate
2. Store head in temporary variable temp
3. set head = temp->next. Delete temp to free memory

# Delete At End
1. If head == NULL, list is empty, terminate
2. If head->next == NULL, list has only one node. Delete head, set head == NULL
3. Otherwise, initialize pointer temp pointing to head.
4. Traverse temp until temp->next->next == NULL
5. Delete temp->next
6. Set temp->next = NULL

# Delete By Val
1. Take input of the Value val to delete from user
2. If head == NULL, terminate
3. If head->value is val (first node of LL)
4. Store head in temporary variable temp. head = head->next. Delete temp, terminate
5. Otherwise, initialize temp pointing to head
6. Traverse temp until temp->next->val == VAL or temp->next != NULL
7. If temp->next == NULL, terminate.
8. Otherwise, Initialize temp2. temp2 = temp->next
10. Set temp->next = temp->next->next
11. Delete temp2

# Traverse
1. If head == NULL, terminate. List is empty
2. Initialize temporary variable temp pointing to head
3. Traverse till temp != NULL
4. Print temp->val. Set temp = temp -> next


