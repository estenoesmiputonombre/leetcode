using namespace std;

int getNthFib(int n) {
    if (n == 2) return 1;
    if (n == 1) return 0;
    return getNthFib(n-1) + getNthFib(n-2);
}
