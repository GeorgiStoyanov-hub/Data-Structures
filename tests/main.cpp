#include <iostream>
#include <vector>

struct ListNode {
public:
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class NodeOperations{
public:

	NodeOperations() {}

	ListNode* convertArrToLL(const std::vector<int>& arr) {
		if (arr.empty()) return nullptr;

		ListNode* head = new ListNode(arr[0]);
		ListNode* current = head;

		for (size_t i = 1; i < arr.size(); ++i) {
			current->next = new ListNode(arr[i]);
			current = current->next;
		}

		return head;
	};
	void print(ListNode* head) {
		while (head != nullptr) {
			std::cout << head->val << " ";
			head = head->next;
		}
		std::cout << std::endl;
	};

	ListNode* deleteHead(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		ListNode* temp = head;
		head = head->next;
		//free(temp);
		delete temp;
		return head;
	};

	ListNode* deleteTail(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return nullptr;
		}
		ListNode* temp = head;
		while (temp->next->next != nullptr) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;
		return head;
	};

	ListNode* deleteK(ListNode* head, int k) {
		if (head == nullptr) {
			return head;
		}
		if (k == 1) {
			ListNode* temp = head;
			head = head->next;
			delete temp;
			return head;
		}

		int count = 0;
		ListNode* temp = head;
		ListNode* prev = nullptr;
		while (temp != nullptr) {
			count++;
			if (count == k) {
				prev->next = prev->next->next;
				delete temp;
				break;
			}
			prev = temp;
			temp = temp->next;
 		}
		return head;
	}

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == nullptr) return list2;
		if (list2 == nullptr) return list1;

		ListNode* head;
		if (list1->val <= list2->val) {
			head = list1;
			list1 = list1->next;
		}
		else {
			head = list2;
			list2 = list2->next;
		}

		ListNode* current = head;
		while (list1 && list2) {
			if (list1->val <= list2->val) {
				current->next = list1;
				list1 = list1->next;
			}
			else {
				current->next = list2;
				list2 = list2->next;
			}
			current = current->next;
		}

		if (!list1) {
			current->next = list2;
		}
		if (!list2) {
			current->next = list1;
		}
		return head;
	};

};

int main() {
	std::vector<int> arr = { 12, 5, 8 ,7 };
	NodeOperations _operator_;
	ListNode* head = _operator_.convertArrToLL(arr);

	std::cout << "Initial Linked List: ";
	_operator_.print(head);
	_operator_.deleteK(head, 3);
	_operator_.print(head);
}