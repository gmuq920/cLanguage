#define _CRT_SECURE_NO_WARNINGS

//142
//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，
// 评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 - 1，
// 则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//不允许修改 链表。


 // Definition for singly-linked list.
  

//struct ListNode {
//      int val;
//      struct ListNode *next;
//  };
// 
//struct ListNode* detectCycle(struct ListNode* head)
//{
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast) {
//            while (head != slow) {
//                head = head->next;
//                slow = slow->next;
//            }
//            return head;
//
//        }
//    }
//    return NULL;
//}


//138. 随机链表的复制
//已解答
//中等
//相关标签
//premium lock icon
//相关企业
//提示
//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
//
//构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。
//
//例如，如果原链表中有 X 和 Y 两个节点，其中 X.random-- > Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random-- > y 。
//
//返回复制链表的头节点。
//
//用一个由 n 个节点组成的链表来表示输入 / 输出中的链表。每个节点用一个[val, random_index] 表示：
//
//val：一个表示 Node.val 的整数。
//random_index：随机指针指向的节点索引（范围从 0 到 n - 1）；如果不指向任何节点，则为  null 。
//你的代码 只 接受原链表的头节点 head 作为传入参数。
//
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     struct Node *next;
// *     struct Node *random;
// * };
// */
//
//struct Node* copyRandomList(struct Node* head)
//{
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    else if (head->next == NULL)
//    {
//        struct Node* newHead = malloc(sizeof(struct Node));
//        newHead->val = head->val;
//        newHead->next = NULL;
//        if (head->random == head) {
//            newHead->random = newHead;
//        }
//        else {
//            newHead->random = NULL;
//        }
//
//        return newHead;
//
//    }
//    else {
//
//        struct Node* cur = head;
//
//        while (cur) {
//            struct Node* newNode = malloc(sizeof(struct Node));
//            newNode->val = cur->val;
//            newNode->next = cur->next;
//            cur->next = newNode;
//            cur = newNode->next;
//        }
//
//        cur = head;
//        while (cur) {
//            if (cur->random)
//                cur->next->random = cur->random->next;
//            else
//                cur->next->random = NULL;
//            cur = cur->next->next;
//        }
//
//        struct Node* copyCur = head->next;
//        struct Node* newHead = copyCur;
//        cur = head;
//
//        while (cur) {
//            cur->next = copyCur->next;
//            cur = cur->next;
//            if (cur) {
//                copyCur->next = cur->next;
//                copyCur = copyCur->next;
//            }
//        }
//        return newHead;
//
//    }
//
//}