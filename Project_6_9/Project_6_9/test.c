#define _CRT_SECURE_NO_WARNINGS

//142
//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ���
// ����ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ������� pos �� - 1��
// ���ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
//�������޸� ����


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


//138. �������ĸ���
//�ѽ��
//�е�
//��ر�ǩ
//premium lock icon
//�����ҵ
//��ʾ
//����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣
//
//������������ ����� ���Ӧ�������� n �� ȫ�� �ڵ���ɣ�����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ���½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬�����������е�ָ�붼��Ӧָ��ԭ�����еĽڵ� ��
//
//���磬���ԭ�������� X �� Y �����ڵ㣬���� X.random-- > Y ����ô�ڸ��������ж�Ӧ�������ڵ� x �� y ��ͬ���� x.random-- > y ��
//
//���ظ��������ͷ�ڵ㡣
//
//��һ���� n ���ڵ���ɵ���������ʾ���� / ����е�����ÿ���ڵ���һ��[val, random_index] ��ʾ��
//
//val��һ����ʾ Node.val ��������
//random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n - 1���������ָ���κνڵ㣬��Ϊ  null ��
//��Ĵ��� ֻ ����ԭ�����ͷ�ڵ� head ��Ϊ���������
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