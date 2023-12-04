#include <iostream>

using namespace std;

class Queue {
private:
	int front, rear, capacity;
	int* arr;
public:
	Queue(int capacity);
	~Queue();
	void enqueue(int item);
	int dequeue();
	bool isFull();
	bool isEmpty();
	void display();
};

Queue::Queue(int capacity) {
	this->capacity = capacity;
	front = -1;
	rear = -1;
	this->arr = new int[capacity];
}

Queue::~Queue() {
	delete[] arr;
}

void Queue::enqueue(int item) {
	if (isFull()) {
		cout << "Queue is full" << endl;
		return;
	}
	if (isEmpty()) {
		front = rear = 0;
	}
	else {
		rear = (rear + 1) % capacity; //because queue is circular
	}
	arr[rear] = item;
	cout << "Inserted " << item << " to queue" << endl;
}

int Queue::dequeue() {
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
		return -1;
	}
	int item = arr[front];
	if (front == rear) {
		front = rear = -1;
	}
	else {
		front = (front + 1) % capacity;
	}
	cout << "Removed " << item << " from queue" << endl;
	return item;
}

bool Queue::isFull() {
	return (rear + 1) % capacity == front;
}

bool Queue::isEmpty() {
	return front == -1;
}

void Queue::display() {
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
		return;
	}
	cout << "Front: " << front << ", Rear: " << rear << endl;
	cout << "Elements in queue: ";
	for (int i = front; i != rear; i = (i + 1) % capacity) {
		cout << arr[i] << " ";
	}
	cout << arr[rear] << endl;
}

int main() {
	Queue q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.display();
	q.dequeue();
	q.dequeue();
	q.display();
	q.enqueue(50);
	q.enqueue(60);
	q.display();
	return 0;
}
