#include "iostream"
#include "vector"

using namespace std;

// O(1) - Executa sempre a mesma quantidade de operações, independente do tamanho do vetor
void o1() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << nums[0] << endl;
    int lastindex = nums.size() - 1;
    cout << nums[lastindex] << endl;
}

// O(N) - Percorre N elementos; o tempo cresce proporcionalmente ao tamanho da entrada
void oN(int n) {
    vector<int> nums = {};

    for (int i = 0; i < n; i++) {
        nums.push_back(i);
    }

    // Percorre o vetor inteiro -> O(N)
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}

// O(N²) - Loop dentro de loop; para cada elemento, percorre todos os outros
void oN2(int n) {
    vector<int> nums = {};
    for (int i = 0; i < n; i++) {
        nums.push_back(i);
    }

    // Loop duplo -> O(N²)
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            cout << nums[i] << " " << nums[j] << endl;
        }
    }
}

// O(log N) -
void oLogN(int n, int target) {
    vector<int> nums = {};

    for (int i = 0; i < n; i++) {
        nums.push_back(i);
    }

    // Busca binaria -> O(log N)
    int head = 0;
    int tail = nums.size() - 1;

    while (head <= tail) {
        int meio = (head + tail) / 2; // meio

        if (nums[meio] == target) {
            cout << "Achou: " << nums[meio] << endl;
            return; // O(1) -> acabou
        }
        else if (nums[meio] < target) {
            head = meio + 1; // busca na metade direita
        } else {
            tail = meio - 1; // busca na metade esquerda
        }
    }

    cout << "Não encontrado" << endl;
}

int main() {
    oLogN(100, 67);
    return 0;
}