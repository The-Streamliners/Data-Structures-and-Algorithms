public class QueueUsingArray {

    int[] data;
    int front; // index of the element at front of the queue
    int rear; // index of the element at rear of the queue
    int count; // size of queue

    public QueueUsingArray(int capacity) {
        data = new int[capacity];
        front = -1;
        rear = -1;
    }

    public QueueUsingArray() {
        data = new int[5];
        front = -1;
        rear = -1;
    }

    // Time Complexity : O(1)
    public int size() {
        return count;
    }

    // Time Complexity : O(1)
    public boolean isEmpty() {
        return count == 0;
    }

    // Time Complexity : O(1)
    public int front() {
        // if queue is empty
        if (count == 0) {
            return -1;
        }
        return data[front];
    }

    // Time Complexity : O(1)
    public void enqueue(int ele) {

        // if queue is full
        if (count == data.length) {
            //throw new QueueFullException();
            doubleCapacity();
        }
        // if queue is empty
        if (count == 0) {
            front++;
        }
//        rear++;
//        if (rear == data.length){
//            rear = 0;
//        }
        rear = (rear + 1) % data.length;

        data[rear] = ele;
        count++;
    }

    // Time Complexity : O(n)
    private void doubleCapacity() {

        int[] temp = data;
        data = new int[2 * temp.length];
        int index = 0;
        for (int i = front; i < temp.length; i++){

            data[index] = temp[i];
            index++;
        }

        for (int j = 0; j < front; j++){

            data[index] = temp[j];
            index++;
        }
        front = 0;
        rear = temp.length-1;
    }

    // Time Complexity : O(1)
    public int dequeue() {

        // if queue is empty
        if (count == 0) {
            return -1;
        }
        int temp = data[front];
//        front++;
//        if (front == data.length){
//            front = 0;
//        }
        front = (front + 1) % data.length;

        count--;
        if (count == 0) {
            front = -1;
            rear = -1;
        }
        return temp;

    }
}
