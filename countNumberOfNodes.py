import time
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

    def numberOfNodes(self):
        if self.isEmpty():
            print("Linked List is Empty")
            return
        count = 0
        temp = self.head
        while temp != None:
            count += 1
            temp = temp.next
        return count


if __name__ == '__main__':
    lList = LinkedListOperations()

    for i in range(1, 7):
        lList.insertNode(i)

    lList.printList()
    print("The Number of Nodes -->", lList.numberOfNodes())