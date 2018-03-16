# Stack  
LIFO  

- Array  
- LinkedList
  
>Init  
IsEmpty  
Push  
Pop  
Peek  

## Array
<pre><code>
typedef struct _Stack{
  Data Array[STACK_LEN];
  int top;
} Stack;
<\code><\pre>

## LinkedList
<pre><code>
typedef struct _node{
  Data data;
  struct _node* next;
} Node;
<\code><\pre>

<pre><code>
typedef struct _Stack{
  Node* top;
  int numOfData;
} Stack;
<\code><\pre>


### Notes
- Check whether stack is empty when pop, peek
