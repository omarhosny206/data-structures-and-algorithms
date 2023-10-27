# Queue

A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle. It means that the first element added to the queue will be the first one to be removed. Think of a queue as a line of people waiting for a service, where the person who arrived first will be the first to be served.

## Basic Operations

A queue typically supports the following basic operations:

1. **enqueue**: Add an element to the rear of the queue.
2. **dequeue**: Remove and return the element at the front of the queue.
3. **peek (or front)**: View the element at the front of the queue without removing it.
4. **size**: Get the number of elements in the queue.
5. **isEmpty**: Check if the queue is empty.

## Implementation

Queues can be implemented using various data structures, such as arrays or linked lists. In C++, you can use the `std::queue` container from the Standard Library, which provides a convenient implementation of a queue.

## Usage

Queues are commonly used in DSA problems for:

- **Breadth-First Search (BFS)**: Exploring nodes level by level in graph traversal algorithms.

- **Task Scheduling**: Managing tasks in a way that ensures tasks are executed in the order they are received.

- **Print Queue**: Simulating a print queue where print jobs are processed in the order they are submitted.

- **Buffering**: Implementing a buffer to store data temporarily, for example, in data streaming applications.

## Best Practices

When working with queues, keep in mind the following best practices:

- Use a queue when you need to maintain a first-in, first-out order of elements.
- Ensure that you always check if the queue is empty before dequeuing to avoid dequeuing from an empty queue.
- Be mindful of the queue's size to prevent overflow, especially in resource-constrained environments.

## Complexity

| Operation   | Time Complexity | Space Complexity |
|:------------:|:----------------:|:-----------------:|
| enqueue      | O(1)           | O(1)             |
| dequeue      | O(1)           | O(1)             |
| search       | O(N)           | O(1)             |
| getFront     | O(1)           | O(1)             |
| getBack      | O(1)           | O(1)             |
| isEmpty      | O(1)           | O(1)             |
| size         | O(1)           | O(1)             |
| print        | O(N)           | O(1)             |