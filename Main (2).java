package myds;

final class DoublyLinkedList<E> {
    private static final class Node<E> {
        E data;
        Node<E> prev, next;
        Node(E d) { data = d; }
    }

    private Node<E> head, tail;
    private int size;

    int size() { return size; }
    boolean isEmpty() { 
        return head == null; 
    }

    E first() { return head == null ? null : head.data; }

    void addFirst(E x) {
        Node<E> n = new Node<>(x);
        if (head == null) {
            head = tail = n;
        } else {
            n.next = head;
            head.prev = n;
            head = n;
        }
        size++;
    }

    void addLast(E x) {
        Node<E> n = new Node<>(x);
        if (tail == null) {
            head = tail = n;
        } else {
            tail.next = n;
            n.prev = tail;
            tail = n;
        }
        size++;
    }

    E removeFirst() {
        if (head == null) return null;
        E val = head.data;
        if (head == tail) {
            head = tail = null;
        } else {
            head = head.next;
            head.prev = null;
        }
        size--;
        return val;
    }

    E removeLast() {
        if (tail == null) return null;
        E val = tail.data;
        if (head == tail) {
            head = tail = null;
        } else {
            tail = tail.prev;
            tail.next = null;
        }
        size--;
        return val;
    }

    boolean remove(E x) {
        Node<E> current = head;
        while (current != null) {
            if ((x == null && current.data == null) || (x != null && x.equals(current.data))) {
                if (current == head) {
                    removeFirst();
                } else if (current == tail) {
                    removeLast();
                } else {
                    current.prev.next = current.next;
                    current.next.prev = current.prev;
                    size--;
                }
                return true;
            }
            current = current.next;
        }
        return false;
    }
}