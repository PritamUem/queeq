Queue Implementation Algorithm using an Array
Data Structure
Define the Queue Structure:
An array items of fixed size MAX.
Two integers: front and rear to track the positions of the front and rear elements.
Initialization
Create Queue:
Initialize front and rear to -1 to indicate that the queue is empty.
Operations
Check if Full:

Function isFull():
Return true if (rear + 1) % MAX == front; otherwise, return false.
Check if Empty:

Function isEmpty():
Return true if front == -1; otherwise, return false.
Enqueue (Insert an Element):

Function enqueue(value):
Check if the queue is full using isFull().
If true, print "Queue is full!" and return.
If the queue is empty (i.e., front == -1):
Set front to 0.
Update rear to the next position using circular indexing: rear = (rear + 1) % MAX.
Insert the value at items[rear].
Print "Enqueued: value".
Dequeue (Remove an Element) (optional):

Function dequeue():
Check if the queue is empty using isEmpty().
If true, print "Queue is empty!" and return.
Store the value at items[front] to return later.
If front equals rear (queue becomes empty after this operation):
Set both front and rear to -1.
Otherwise, update front to the next position using circular indexing: front = (front + 1) % MAX.
Return the stored value.
Display Queue:

Function displayQueue():
Check if the queue is empty using isEmpty().
If true, print "Queue is empty".
Print elements from items[front] to items[rear] using a loop that handles circular indexing.
Example of Usage
Initialize the queue.
Use enqueue() to add elements.
Use displayQueue() to show the current elements.
Optionally use dequeue() to remove elements.
