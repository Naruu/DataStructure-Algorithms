# Linked List

- Array Style
- Singly
- Circular

> Init  
Insert on head  
Insert on tail  
Search  
remove by position  
remove by data  
sort(sort when inserting)  

<pre><code>typdef struct _node{
  LData data;
  struct _node* next;
} Node;
</code></pre>

<pre><code>typdef struct _linkedList{
  Node* head;
  Node* cur;
  //node* before;
  int numOfData;
  //int (*comp)(LData d1, LData d2);
} LinkedList;
</code></pre>

### Notes
- Head node points dummy node  
- Circular linked list - point tail
