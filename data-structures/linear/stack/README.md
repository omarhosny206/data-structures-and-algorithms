# Stack

A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle. It means that the last element added to the stack will be the first one to be removed. Think of a stack as a collection of items arranged like a stack of plates, where you can only add or remove plates from the top.

## Basic Operations

A stack typically supports the following basic operations:

1. **push**: Add an element to the top of the stack.
2. **pop**: Remove and return the element at the top of the stack.
3. **peek (or top)**: View the element at the top of the stack without removing it.
4. **size**: Get the number of elements in the stack.
5. **isEmpty**: Check if the stack is empty.

## Implementation

The stack can be implemented using various data structures like arrays or linked lists. In C++, you can use the `std::stack` container from the Standard Library, which provides a convenient implementation of a stack.

## Usage

Stacks are commonly used in DSA problems for:

- **Function Call Management**: Maintaining function call history in recursive algorithms.

- **Expression Evaluation**: Converting infix expressions to postfix and evaluating them.

- **Balancing Parentheses**: Checking the validity of parentheses in expressions.

- **DFS & Backtracking Algorithms**: Implementing depth-first search (DFS) for graph traversal.

- **Undo and Redo Functionality**: Implementing undo and redo functionality in software applications.


## Best Practices

When working with stacks, keep in mind the following best practices:

- Use a stack when you need to maintain a last-in, first-out order of elements.
- Ensure that you always check if the stack is empty before popping an element to avoid stack underflow.
- Be mindful of the stack's size to prevent stack overflow, especially in resource-constrained environments.

## Complexity

| Operation   | Time Complexity | Space Complexity |
|:------------:|:----------------:|:-----------------:|
| push         | O(1)           | O(1)             |
| pop          | O(1)           | O(1)             |
| search       | O(N)           | O(1)             |
| getTop       | O(1)           | O(1)             |
| isEmpty      | O(1)           | O(1)             |
| getSize      | O(1)           | O(1)             |
| print        | O(N)           | O(1)             |