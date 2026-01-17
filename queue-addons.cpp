#include <queue>
using namespace std;

template <typename T>
void clearq(queue<T>& q) 
{
    queue<T> empty;
    swap(q, empty);
}