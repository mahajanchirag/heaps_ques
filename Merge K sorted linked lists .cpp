class Solution{
  public:
    //Function to merge K sorted linked list.
    struct compare {
    bool operator()(
         Node* a,  Node* b)
    {
        return a->data > b->data;
    }
    };
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
            priority_queue<Node*, vector<Node*>, compare> pq;
            Node *head=NULL,*tail;
            
            for(int i=0;i<K;i++)
            {
                if(arr[i]!=NULL)
                {
                    pq.push(arr[i]);
                }
            }
            
            
            while(!pq.empty())
            {
                Node *top=pq.top();
                pq.pop();
                
                if(top->next!=NULL)
                {
                    pq.push(top->next);
                }
                
                if(head==NULL)
                {
                    head=top;
                    tail=top;
                }
                
                else
                {
                    tail->next=top;
                    tail=top;;
                }
            }
            
            return head;
    }
};
