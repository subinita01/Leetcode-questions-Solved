class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def reverse_linked_list(head):
    prev = None
    current = head

    while current:
        nxt = current.next      # Save next node
        current.next = prev     # Reverse the pointer
        prev = current          # Move prev forward
        current = nxt           # Move current forward
    
    return prev  # New head after reversal

# Helper function to print list
def print_list(head):
    current = head
    while current:
        print(current.value, end=" -> ")
        current = current.next
    print("None")

# Example
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)

print("Original list:")
print_list(head)

head = reverse_linked_list(head)
print("Reversed list:")
print_list(head)
