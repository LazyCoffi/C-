#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {

struct NumNode {
    int val;
    ListNode* node;
    bool operator < (const NumNode a) const{
        return val > a.val;
    }
};

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head, *tail = &head;
        priority_queue<NumNode> que;
        int list_len = lists.size();
        for (int i = 0; i < list_len; i ++) {
            if (lists[i] == nullptr) continue;
            que.push((NumNode){lists[i]->val, lists[i]});
        }

        while (!que.empty()) {
            ListNode *new_node = que.top().node;
            que.pop();
            tail->next = new_node;
            tail = new_node;

            if (new_node->next == nullptr) continue;
            que.push((NumNode){new_node->next->val, new_node->next});
        }

        return head.next;
    }
};

int main() {

}
