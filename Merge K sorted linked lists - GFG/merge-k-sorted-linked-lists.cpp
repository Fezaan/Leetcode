//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node * left, Node* right){
        Node* dummy= new Node(0);
        Node* tmp=dummy;
        while(left&&right){
            if(left->data > right->data){
                tmp->next=right;
                right=right->next;
            }
            else{
                tmp->next=left;
                left=left->next;
            }
            tmp=tmp->next;
        }
        tmp->next=left? left:right;
        return dummy->next;
    }
    Node* div(Node* arr[],int l,int r){
        if(l==r)    return arr[l];
        if(l+1==r)  return merge(arr[l],arr[r]);
        int mid=l+(r-l)/2;
        Node* left=div(arr,l,mid);
        Node* right=div(arr,mid+1,r);
        return merge(left,right);
    }
    Node * mergeKLists(Node *arr[], int k)
    {
           // Your code here
        //   if(arr.size()==0)  return nullptr;
           return div(arr,0,k-1);
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends