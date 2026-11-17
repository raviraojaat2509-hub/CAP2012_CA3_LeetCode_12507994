class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* previous = &dummy;

        for (int i = 1; i < left; i++) {
            previous = previous->next;
        }

        ListNode* current = previous->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = current->next;

            current->next = nextNode->next;
            nextNode->next = previous->next;
            previous->next = nextNode;
        }

        return dummy.next;
        
    }
};
