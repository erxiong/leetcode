# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        tmp = 0

        head = ListNode(0)
        node_tmp = head

        while l1 is not None or l2 is not None:
            n1, l1 = self.getNextNumber(l1)
            n2, l2 = self.getNextNumber(l2)

            tmp = tmp + n1 + n2

            node1 = ListNode(tmp % 10)
            node_tmp.next = node1
            node_tmp = node1
            tmp /= 10

        if tmp > 0:
            node1 = ListNode(tmp % 10)
            node_tmp.next = node1

        return head.next

    def getNextNumber(self, l):
        x = 0
        if l is not None:
            x = l.val
            l = l.next
        return x, l


if __name__ == "__main__":
    so = Solution()
    note0 = ListNode(5)
    note1 = ListNode(6)
    note0.next = note1

    note5 = ListNode(6)
    note6 = ListNode(9)
    note5.next = note6

    notes = so.addTwoNumbers(note0, note5)

    while notes:
        print notes.val
        notes = notes.next
