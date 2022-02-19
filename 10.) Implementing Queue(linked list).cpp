#include <iostream>

using namespace std;
struct Node
{
  int data;
  Node *next;
    Node (int x)
  {
    data = x;
    next = NULL;
  }
};
class MyQueue
{
  Node *front;
  Node *back;

public:
    MyQueue ()
  {
    front = back = NULL;
  }
  void Enqueue (int d)
  {
    Node *curr = new Node (d);
    if (back == NULL)

      front = back = curr;
    else
      back->next = curr;
    back = curr;
    cout << "Enqueued " << back->data << "\t";

  }
  void dequeue ()
  {
    Node *curr = front;
    front = front->next;
    cout << "Dequeued " << curr->data << endl;
    delete (curr);
  }
  bool isEmpty ()
  {
    if (front == NULL)
      return true;
    else
      return false;
  }
  int peek ()
  {
    return front->data;
  }

};

int main ()
{
  MyQueue qu;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;

      qu.Enqueue (a);

    }
  cout << endl;
  qu.dequeue ();
  cout << "Peek " << qu.peek ();

  return 0;
}
