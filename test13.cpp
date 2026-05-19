class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

    def __repr__(self):
        return f"Node({self.value})"


class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def prepend(self, value):
        self.head = Node(value, self.head)

    def find(self, value):
        current = self.head
        while current:
            if current.value == value:
                return current
            current = current.next
        return None

    def delete(self, value):
        current = self.head
        previous = None
        while current:
            if current.value == value:
                if previous:
                    previous.next = current.next
                else:
                    self.head = current.next
                return True
            previous = current
            current = current.next
        return False

    def reverse(self):
        previous = None
        current = self.head
        while current:
            next_node = current.next
            current.next = previous
            previous = current
            current = next_node
        self.head = previous

    def __iter__(self):
        current = self.head
        while current:
            yield current.value
            current = current.next

    def __repr__(self):
        return "->".join(str(value) for value in self)


if __name__ == "__main__":
    ll = LinkedList()
    ll.append(1)
    ll.append(2)
    ll.append(3)
    ll.prepend(0)
    print("List:", ll)
    print("Find 2:", ll.find(2))
    ll.delete(2)
    print("After delete 2:", ll)
    ll.reverse()
    print("Reversed:", ll)
