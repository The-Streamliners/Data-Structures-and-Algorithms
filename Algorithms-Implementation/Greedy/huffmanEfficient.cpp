// C++ Program for Efficient Huffman Coding for Sorted input 
#include <bits/stdc++.h>
using namespace std;
#define MAX_TREE_HT 100

class QueueNode {
	public:
	char data;
	unsigned freq;
	QueueNode *left, *right;
};

class Queue {
	public:
	int front, rear, capacity;
	QueueNode **array;
};

QueueNode* newNode(char data, unsigned freq) {
	QueueNode* temp = new QueueNode[(sizeof(QueueNode))];
	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
}

Queue* createQueue(int capacity) {
	Queue* queue = new Queue[(sizeof(Queue))];
	queue->front = queue->rear = -1;
	queue->capacity = capacity;
	queue->array = new QueueNode*[(queue->capacity * sizeof(QueueNode*))];
	return queue;
}

int isSizeOne(Queue* queue) {
	return queue->front == queue->rear && queue->front != -1;
}

int isEmpty(Queue* queue) {
	return queue->front == -1;
}

int isFull(Queue* queue) {
	return queue->rear == queue->capacity - 1;
}

void enQueue(Queue* queue, QueueNode* item) {
	if (isFull(queue)) return;
	queue->array[++queue->rear] = item;
	if (queue->front == -1) ++queue->front;
}

QueueNode* deQueue(Queue* queue) {
	if (isEmpty(queue)) return NULL;
	QueueNode* temp = queue->array[queue->front];
	if (queue->front == queue->rear) queue->front = queue->rear = -1;
	else ++queue->front;
	return temp;
}

QueueNode* getFront(Queue* queue) {
	if (isEmpty(queue)) return NULL;
	return queue->array[queue->front];
}

QueueNode* findMin(Queue* firstQueue, Queue* secondQueue) {
	if (isEmpty(firstQueue)) return deQueue(secondQueue);
	if (isEmpty(secondQueue)) return deQueue(firstQueue);
	if (getFront(firstQueue)->freq < getFront(secondQueue)->freq) return deQueue(firstQueue);
	return deQueue(secondQueue);
}

int isLeaf(QueueNode* root) {
	return !(root->left) && !(root->right) ;
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i) cout<<arr[i];
	cout<<endl;
}

QueueNode* buildHuffmanTree(char data[], int freq[], int size) {
	QueueNode *left, *right, *top;
	Queue* firstQueue = createQueue(size);
	Queue* secondQueue = createQueue(size);
	for (int i = 0; i < size; ++i) enQueue(firstQueue, newNode(data[i], freq[i]));
	while (!(isEmpty(firstQueue) && isSizeOne(secondQueue))) {
		left = findMin(firstQueue, secondQueue);
		right = findMin(firstQueue, secondQueue);
		top = newNode('$' , left->freq + right->freq);
		top->left = left;
		top->right = right;
		enQueue(secondQueue, top);
	}
	return deQueue(secondQueue);
}

void printCodes(QueueNode* root, int arr[], int top) {
	if (root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}
	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	if (isLeaf(root)) {
		cout<<root->data<<": ";
		printArr(arr, top);
	}
}

void HuffmanCodes(char data[], int freq[], int size) {
    QueueNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main() {
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};
	int size = sizeof(arr)/sizeof(arr[0]);
	HuffmanCodes(arr, freq, size);
	return 0;
}

// by rathbhupendra & harisfi