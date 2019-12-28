#include "LinkList.h"

int main() {
	LinkList WCH;
	InitLinklist(WCH,6);
	SortLinkList(WCH);
	DisplayLinkList(WCH);

	for(LinkList p=WCH->next; p; p=p->next) {
		cout << p->data<<endl;
		if(!(p->next)) {
			p->next = WCH->next;
			break;
		}
	}

	//Step lenjgth
	int jump = 2;
	int init = 1;

	LinkList p;
	cout <<endl;
	for(p=WCH; p->next->next!=p->next; p=p->next) {
		if(init%2==0) {
			cout << p->next->data << endl;
			p->next=p->next->next;
		} else {
			init++;
		}
	}
	cout << p->data << endl;

	return 0;
}
