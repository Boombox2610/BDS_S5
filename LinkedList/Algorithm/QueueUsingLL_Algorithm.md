# Creation
1. Create node structure with value val and node pointer next
2. Initialize using constructor with value val and next to NULL
3. Create Queue class with private variables front and rear, of type node pointer
4. Initialize using constructor front = rear = NULL

# Enqueue (insert at End)
1. Input: Take value val from user
2. Create a new node newNode with value val
3. If front = NULL, queue is empty. make front = rear = newNode
4. Otherwise rear->next = newNode | rear = newNode

# Dequeue (delete at Start)
1. If front = rear = NULL, queue is empty. Terminate
2. Make temporary node temp = front. Store value of front in dequedVal = front->value
3. front = temp->next | delete temp | return dequedVal

# Display 
1. If front == NULL, queue is empty. Terminate
2. Make temporary node temp = front to traverse. While temp != NULL :
3. Print temp->val | temp = temp->next
