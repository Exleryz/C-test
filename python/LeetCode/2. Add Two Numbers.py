"""
2. Add Two Numbers
Medium

4858

1228

Favorite

Share
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
"""

# Definition for singly-linked list.


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # l3 = None
        # list30 = None
        # temp0 = 0
        # while l1 is None or l2 is None or temp0 = 1:
        #     if l1 is None:
        #         temp1 = 0
        #     else:
        #         temp1 = l1.val
        #         l1 = l1.next
        #     if l2 is None:
        #         temp2 = 0
        #     else:
        #         temp2 = l2.val
        #         l2 = l2.next

        #     temp = temp1 + temp2 + temp0
        #     if temp >= 10:
        #         temp0 = 1
        #         temp -= 10
        #     else:
        #         temp0 = 0
        #     list3 = ListNode(temp)
        #     if l3 is None:
        #         list30 = list3
        #         l3 = list30
        #     else:
        #         list30.next = list3
        #         list30 = list30.next
        # return l3
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        carry = 0
        to_return = l1

        while True:
            ans = l1.val + l2.val + carry
            carry = 0
            if ans > 9:
                carry = ans//10
                ans = ans % 10
            l1.val = ans
            if l1.next == None or l2.next == None:
                break
            l1 = l1.next
            l2 = l2.next

        if l1.next == None and l2.next == None:
            if carry > 0:
                l1.next = ListNode(carry)
                l1 = l1.next
                carry = 0
                return to_return

        while l1.next != None:
            l1 = l1.next
            ans = l1.val + carry
            carry = 0
            if ans > 9:
                carry = ans // 10
                ans = ans % 10
            l1.val = ans
            print(l1.val)

        while l2.next != None:
            l2 = l2.next
            ans = l2.val + carry
            carry = 0
            l1.next = ListNode(ans)
            l1 = l1.next
            if ans > 9:
                carry = ans // 10
                ans = ans % 10
                l1.val = ans

        if carry > 0:
            l1.next = ListNode(carry)
            l1 = l1.next
            carry = 0

        return to_return


s = Solution()
list10 = ListNode(2)
list11 = ListNode(4)
list12 = ListNode(3)
list10.next = list11
list11.next = list12

list20 = ListNode(5)
list21 = ListNode(6)
list22 = ListNode(4)
list20.next = list21
list21.next = list22
s.addTwoNumbers(list10, list20)
