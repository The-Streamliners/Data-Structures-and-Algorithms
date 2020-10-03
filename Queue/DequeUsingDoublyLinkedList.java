import java.util.NoSuchElementException;

final class DoublyLinkedListDeque<T> {
    private static class Node<T> {
        T data;
        Node<T> prev;
        Node<T> next;

        public Node(T data) {
            this.data = data;
        }
    }

    private Node<T> front;
    private Node<T> rear;
    private int size;

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public void clear() {
        front = null;
        rear = null;
        size = 0;
    }

    public void addFirst(T ele) {
        Node<T> node = new Node<>(ele);
        if (isEmpty()) {
            rear = node;
        } else {
            front.prev = node;
        }
        node.next = front;
        front = node;
        size++;
    }

    public void addLast(T ele) {
        Node<T> node = new Node<>(ele);
        if (isEmpty()) {
            front = node;
        } else {
            rear.next = node;
        }
        node.prev = rear;
        rear = node;
        size++;
    }

    public T getFirst() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
        return front.data;
    }

    public T getLast() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
        return rear.data;
    }

    public T removeFirst() {
        T ele = getFirst();
        if (size() == 1) {
            rear = null;
        } else {
            front.next.prev = null;
        }
        front = front.next;
        size--;
        return ele;
    }

    public T removeLast() {
        T ele = getLast();
        if (size() == 1) {
            front = null;
        } else {
            rear.prev.next = null;
        }
        rear = rear.prev;
        size--;
        return ele;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder("[");
        if (!isEmpty()) {
            builder.append(front.data);
            Node<T> cur = front.next;
            while (cur != null) {
                builder.append(", " + cur.data);
                cur = cur.next;
            }
        }
        return builder.append("]").toString();
    }
}

public final class DequeUsingDoublyLinkedList {
    public static void main(String[] args) {
        DoublyLinkedListDeque<Integer> deque = new DoublyLinkedListDeque<>();
        deque.addFirst(5);
        deque.addFirst(3);
        deque.addLast(2);
        deque.addFirst(9);
        deque.removeLast();
        deque.addLast(1);
        deque.removeFirst();
        System.out.println(deque);
    }
}
