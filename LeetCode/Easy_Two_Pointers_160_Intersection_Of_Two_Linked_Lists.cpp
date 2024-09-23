#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* crearNuevoNodo(int valor) {
    ListNode* nuevoNodo = new ListNode(valor);
    return nuevoNodo;
}

void insertarNodo(ListNode *head, ListNode *nodo){
    if(head == nullptr){
        head = nodo;
    }
    else{
        ListNode *cur = head;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = nodo;
    }
}

void revertirLista(ListNode *head, ListNode *reversed){
    if(head == nullptr) return;
    revertirLista(head->next, reversed);
    insertarNodo(reversed, head);
}

void imprimirLista(ListNode* head){
    ListNode *cur = head;
    while(cur){
        cout << cur->val << "->";
        cur = cur->next;
    }
}

void imprimirReverse(ListNode *head){
    if(head == nullptr) return;
    imprimirReverse(head->next);
    cout << "<-" << head->val;
}

void reverseDoble(ListNode *headA, ListNode *headB){
    if(headA == nullptr){
        
    }
    cout << headA->val << " - " << headB->val << endl;
}

int main(){
    ListNode *headA = new ListNode(4);
    ListNode *nodo1 = new ListNode(1);
    ListNode *nodo2 = new ListNode(8);
    ListNode *nodo3 = new ListNode(4);
    ListNode *nodo4 = new ListNode(5);

    ListNode *headB = new ListNode(5);
    ListNode *nodo5 = new ListNode(6);
    ListNode *nodo6 = new ListNode(1);
    
    insertarNodo(headA, nodo1);
    insertarNodo(nodo1, nodo2);
    insertarNodo(nodo2, nodo3);
    insertarNodo(nodo3, nodo4);

    insertarNodo(headB, nodo5);
    insertarNodo(nodo5, nodo6);
    insertarNodo(nodo6, nodo2);
    
    imprimirLista(headA);
    cout << endl;
    imprimirLista(headB);
    cout << endl;

    imprimirReverse(headA);
    cout << endl;
    imprimirReverse(headB);
    cout << endl;
    
    reverseDoble(headA, headB);
    cout << endl;
    return 0;
}