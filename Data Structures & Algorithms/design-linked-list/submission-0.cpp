class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int val = 0, ListNode* next = nullptr, ListNode* prev = nullptr) {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
    };
public:
    ListNode* head;   // dummy sentinel BEFORE the first real node (holds no real data)
    ListNode* tail;   // dummy sentinel AFTER the last real node (holds no real data)
    int size;         // count of REAL nodes only (sentinels don't count)

    MyLinkedList() {
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;   // empty list: sentinels point directly at each other
        tail->prev = head;
        size = 0;
        // Using two dummy nodes means every real node ALWAYS has a valid
        // prev and next to link to, even at the boundaries. This removes
        // the need for special-case code when inserting/deleting at the
        // very front, very back, or in an empty list.
    }

    // Returns the node that comes BEFORE logical position `index`
    // (index is 0-based among the real nodes).
    // Everything else in this class is built on top of this function.
    ListNode* getPrev(int index) {
        if (index <= size / 2) {
            // index is in the first half -> walk forward from head.
            // Starting at head and taking `index` steps forward lands
            // exactly on the node before position `index`.
            // e.g. index=0 -> 0 steps -> stay at head, correctly "before" node0.
            ListNode* cur = head;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            return cur;
        } else {
            // index is in the second half -> walk backward from tail instead,
            // since that's fewer steps. This is what gives O(min(index, size-index))
            // instead of always O(index).
            // To land on "node before index" walking backward from tail,
            // you need (size - index + 1) steps.
            // Check: size=5, index=4 (last element) -> steps = 5-4+1 = 2
            //   tail -(1)-> node4 -(2)-> node3   <- node3 is indeed before node4 ✓
            ListNode* cur = tail;
            for (int i = 0; i < size - index + 1; i++) {
                cur = cur->prev;
            }
            return cur;
        }
    }

    int get(int index) {
        if (index >= size) return -1;         // out of bounds
        return getPrev(index)->next->val;     // node before index, step forward once = node AT index
    }

    void addAtHead(int val) {
        addAtIndex(0, val);   // inserting at position 0 = new head
    }

    void addAtTail(int val) {
        addAtIndex(size, val);   // inserting at position `size` = past the last element = new tail
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;   // can't insert beyond one-past-the-end

        ListNode* node = new ListNode(val);
        ListNode* prev = getPrev(index);   // node currently sitting before position `index`
        ListNode* next = prev->next;       // node currently sitting AT position `index`

        // splice `node` in between prev and next (standard 4-pointer rewire)
        prev->next = node;
        node->prev = prev;
        node->next = next;
        next->prev = node;
        // Because of the sentinels, `prev` could be `head` itself (inserting
        // at front) and `next` could be `tail` itself (inserting at back) —
        // the exact same 4 lines handle every case with no branching.

        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size) return;   // out of bounds

        ListNode* prev = getPrev(index);   // node before the one being deleted
        ListNode* cur = prev->next;        // the node to delete (at position `index`)
        ListNode* next = cur->next;        // node after the one being deleted

        // bypass `cur` entirely by linking prev and next directly
        prev->next = next;
        next->prev = prev;

        delete cur;   // free the removed node's memory
        size--;
    }

    // Note: no destructor is defined, so when a MyLinkedList object is
    // destroyed, all its `new`'d nodes (including head/tail sentinels)
    // are leaked. Fine for LeetCode, but a real implementation should
    // walk the list and `delete` every node in a destructor.
};