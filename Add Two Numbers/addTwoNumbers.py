# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        result = end = ListNode(0)
        carry = 0
        if not (l1 and l2):
            return l1 or l2
        while l1 and l2:
            tmp = ListNode((l1.val + l2.val+carry) % 10)
#            print "line 16:", tmp.val
            end.next = tmp
            end = tmp
            carry = (l1.val+l2.val+carry)/10
            l1 = l1.next
            l2 = l2.next
        else:
            if l1:
                while l1:
                    tmp = ListNode((l1.val+carry) % 10)
                    end.next = tmp
                    end = tmp
                    carry = (l1.val+carry)/10
                    l1 = l1.next
            elif l2:
                while l2:
                    tmp = ListNode((l2.val+carry) % 10)
                    end.next = tmp
                    end = tmp
                    carry = (l2.val+carry)/10
                    l2 = l2.next
            if carry:
                tmp = ListNode(carry)
                end.next = tmp
                end = tmp
        return result.next

if __name__ == "__main__":
    a = [7, 0, 3, 6, 7, 3, 2, 1, 5]
    b = [9, 2, 5, 5, 6, 1, 2, 2, 4]
    l1 = end1 = ListNode(a[0])
    for i in a[1:]:
        tmp = ListNode(i)
        end1.next = tmp
        end1 = tmp
    l2 = end2 = ListNode(b[0])
    for i in b[1:]:
        tmp = ListNode(i)
        end2.next = tmp
        end2 = tmp

    s = Solution()
    r = s.addTwoNumbers(l1, l2)
    while r:
        print r.val,
        r = r.next
