#include <iostream>

using namespace std;

class bas {
public:
	string data;
	bas* next;
	bas(const string& data) : data(data), next(nullptr) {}
};

class krab {
	bas* head = nullptr;
public:
	void addfront(const string& value) {
		bas* newbas = new bas(value);
		newbas->next = head;
		head = newbas;
	}

	void addend(const string& value) {
		bas* newbas = new bas(value);
		if (head == nullptr) {
			head = newbas;
			return;
		}
		bas* temp = head;

		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = newbas;
		temp = nullptr;
	}

	void deletefront() {
		if (head != nullptr) {
			bas* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void deleteend() {
		if (head != nullptr) {
			bas* temp = head;
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}
	}

	void print() {

		bas* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void addelementbefore(const string& x, const string value) {
		bas* newbas = new bas(value);
		if (head != nullptr) {
			bas* temp = head;
			if (x == head->data)
			{
				addfront(value);
				return;
			}
			while (temp->next->data != x) {
				temp = temp->next;
			}
			newbas->next = temp->next;
			temp->next = newbas;
		}
	}
	void addelementafter(const string& x, const string value) {
		bas* newbas = new bas(value);
		if (head != nullptr) {
			bas* temp = head;
			while (temp->data != x) {
				temp = temp->next;
			}
			newbas->next = temp->next;
			temp->next = newbas;
		}
	}
	void deletebyvalue(const string& value)
	{
		bas* temp = head;
		bas* prev = nullptr;
		if (head->data == value)
		{
			head = temp->next;
			delete temp;
			return;
		}
		while (temp->data != value) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		delete temp;
	}

};

void main() {
	krab sl;
	sl.addfront("Kenan");
	sl.addfront("Behruz");
	sl.addfront("Sahin");
	sl.addfront("Elgun");
	sl.deletebyvalue("Shamil");
	cout << endl;
	sl.print();
}