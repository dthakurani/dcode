class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedListOperations:
    def __init__(self):
        self.head = None

    def isEmpty(self):
        if self.head == None:
            return True
        return False

    def insertNode(self, data):
        newNode = Node(data)
        if self.isEmpty():
            self.head = newNode
            self.end = self.head
            return
        self.end.next = newNode
        self.end = self.end.next

    def printList(self):
        if self.isEmpty():
            print("Empty Linked List")
            return
        temp = self.head
        print("LinkedList --> ", end='')
        while temp != None:
            print(temp.data, end=' ')
            temp = temp.next

        print(" ")

    def middleOfList(self):
        if self.isEmpty():
            print("Empty Linked List")
            return
        slow = fast = self.head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        print("Middle of LinkedList -->", slow.data)


if __name__ == '__main__':
    lList = LinkedListOperations()

    for i in range(1, 7):
        lList.insertNode(i)

    lList.printList()
    lList.middleOfList()