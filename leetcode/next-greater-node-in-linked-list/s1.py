from typing import List
from collections import deque
from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        cur = head
        n = 0
        while cur:
            n += 1
            cur = cur.next
        stack = deque()
        ans = [0] * n
        i = 0
        cur = head
        while cur:
            if not stack or stack[-1][1] >= cur.val:
                stack.append((i, cur.val))
                cur = cur.next
                i += 1
            else:
                t = stack.pop()
                ans[t[0]] = cur.val
        return ans
