#include <iostream>
using namespace std;

// Estrutura do nó da lista
struct Node {
    int value;      // valor do nó
    Node* next;     // ponteiro para o próximo nó

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head; // Ponteiro para o primeiro nó da lista
    Node* tail; // Ponteiro para o último nó da lista

    // Inicializa head e tail como nullptr
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // O(1) -> Insere no início da lista
    void push_front(int val) {
        Node* new_node = new Node(val); // cria novo nó
        new_node->next = head;          // novo nó aponta para o antigo head
        head = new_node;                // head passa a ser o novo nó

        // Se a lista estava vazia, tail também aponta para o novo nó
        if (tail == nullptr) {
            tail = new_node;
        }
    }

    // O(1) -> Insere no fim da lista
    void push_back(int val) {
        Node* new_node = new Node(val); // cria novo nó

        // Lista vazia
        if (!head) {
            head = tail = new_node;
            return;
        }

        tail->next = new_node; // último nó aponta para o novo nó
        tail = new_node;       // tail atualiza para o novo nó
    }

    // O(N) -> Procura todos os nós com valor igual a target
    void search_targets(int target) {
        Node* current = head; // ponteiro que percorre a lista
        bool found = false;

        while (current) {
            if (current->value == target) {
                cout << current->value << " ";
                found = true;
            }
            current = current->next; // vai para o próximo nó
        }

        if (!found) {
            cout << "Valor não encontrado";
        }
        cout << endl;
    }

    // O(N) -> Imprime todos os elementos da lista
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destrutor -: libera toda memória alocada
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(1000);

    list.push_back(2000);
    list.push_back(3);

    list.push_front(3);
    list.push_back(3);

    cout << "Valores encontrados: ";
    list.search_targets(3);

    cout << "Lista completa: ";
    list.print();

    return 0;
}
