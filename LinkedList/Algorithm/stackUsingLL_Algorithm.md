# Creation
1. Make a node structure with int value and node pointer next
2. Constructor for node with value as argument, and next as NULL
3. Make stack class with private variable top of data type node
4. Constructor for stack with no argument, and top as NULL

# Push (insert at start)
1. Input: take value val to push
2. Make a new Node newNode with value val
3. Set newNode->next = top | Set top = newNode

# Pop (delete at start)
1. If top = NULL, stack is empty. Terminate
2. Otherwise, store top->value in integer poppedValue
3. Create temporary node temp, Set top = temp->next
5. Delete temp
6. Return poppedValue

# Peek (print top)
1. If top == NULL, stack is empty. Terminate
2. Otherwise, return top->value
