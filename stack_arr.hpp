/*
 * Array implementation of stack
 * constructor:
 * put the default argument on the declaration, not the definition.
 * error: redeclaration of Stack<T>::Stack(int) may not have default arguments
 * destructor:
 * call destructor in template object.~T()
 */

template <class T>
class Stack
{
 private: 
   T *stackarr;
   T end; // the index of top element
   int capacity; // length of stackarr
 public:
   Stack(int stackCapacity=10);
   ~Stack();
   bool isempty() const;
   T& top() const; // return top element of stack
   void push(const T& item); // insert item into the top of the stack
   void pop(); // delete the top element of the stack
};

// constructor
template <class T>
Stack<T>:: Stack(int stackCapacity): capacity(stackCapacity)
{
 stackarr= new T[capacity];
 end= -1;
}

// destructor
template <class T>
Stack<T>:: ~Stack()
{
 delete [] stackarr;
}

template <class T>
inline bool Stack<T>:: isempty() const
{
 return end == -1;
}

template <class T>
inline T& Stack<T>:: top() const
{
 if (isempty()) throw "Stack is empty";
 return stackarr[end];
}

template <class T>
void Stack<T>:: push(const T& x)
{
 if (end == capacity-1)
   throw "Stack Overflows";
 stackarr[++end]=x;
}

template <class T>
void Stack<T>:: pop()
{
 if (isempty())
   throw "Stack is empty. Cannot delete.";
 stackarr[end--].~T();
}

