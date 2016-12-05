/*
 * Circular queue
 * Array implementation of queue
 */

template <class T>
class Queue
{
 private:
   T *queue; // array of queue
   int first; //front pointer
   int end; // rear pointer
   int capacity; // size of queue
 public:
   Queue(int queueCapacity=10);
   ~Queue();
   bool isempty() const;
   T& front() const; // return the front element of the queue
   T& rear() const; // return the rear element of the queue
   void push(const T& item); // insert item at the rear
   void pop(); // delete the front element
};

// constructor
template<class T>
Queue<T>:: Queue(int queueCapacity): capacity(queueCapacity)
{
 queue=new T[capacity];
 first=0;
 end=0;
}

// destructor
template<class T>
Queue<T>:: ~Queue()
{
 delete [] queue;
}

template<class T>
inline bool Queue<T>:: isempty() const
{
 return first == end;
}

template<class T>
inline T& Queue<T>:: front() const
{
 if (isempty())
   throw "Queue is empty.";
 // remember the index first does not point to element 
 return queue[(first+1) % capacity]; // % operator for circular relation
}

template<class T>
inline T& Queue<T>:: rear() const
{
 if (isempty()) 
   throw "Queue is empty.";
 return queue[end];
}

template<class T>
void Queue<T>:: push(const T& x)
{
 if ((end+1) % capacity == first)
   throw "Queue is full.";
 end=(first+1) % capacity;
 queue[end]=x;
}

template<class T>
void Queue<T>:: pop()
{
 if (isempty())
   throw "Queue is empty.";
 first=(first+1) % capacity;
 queue[first].~T();
}
