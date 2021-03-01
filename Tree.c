#include<stdio.h>
#include<stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Root,int value)
{
	PNODE newn = NULL;
	PNODE temp = *Root;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn->data = value;
	newn->lchild = NULL;
	newn->rchild = NULL;
	
	if(*Root == NULL)
	{
		*Root = newn;
	}
	else
	{
		while(1)
		{
			if(temp->data == value)
			{
				printf("Element already present: Unable to insert \n");
				free(newn);
				break;
			}
			if(value < (temp->data))
			{
				if((temp->lchild) == NULL)
				{
					temp->lchild = newn;
					break;
				}
				temp = temp->lchild;
			}
			else if(value > (temp->data))
			{
				if((temp->rchild) == NULL)
				{
					temp->rchild = newn;
					break;
				}
				temp = temp->rchild;
			}
		}
	}
}

BOOL Search(PNODE Root,int value)
{
  while(Root != NULL)
  {
     if(Root->data == value)
	 {
		 break;
	 }
	 if(value < Root->data)
	 {
		 Root = Root->lchild;
	 }
	 else
	 {
		 Root = Root->rchild;
	 }
  }
  
  if(Root == NULL)
  {
	  return FALSE;
  }
  else
  {
	  return TRUE;
  }
    
}

void Inorder(PNODE Root)
{
  if(Root != NULL)
  {
     Inorder(Root->lchild);
     printf("%d\t", Root->data);
     Inorder(Root->rchild);
  }  
}

void Preorder(PNODE Root)
{
	if(Root != NULL)
	{
		 printf("%d\t", Root->data); 
		 Inorder(Root->lchild);
		 Inorder(Root->rchild);
	}
}

void Postorder(PNODE Root)
{
   if(Root != NULL)
   {
       	Inorder(Root->lchild);
		Inorder(Root->rchild);
		printf("%d\t", Root->data); 
   }	   
}

int main()
{
	
	PNODE First = NULL;
	int no = 0;
	int choice = 1;
	BOOL bRet = FALSE;
	
	while(choice != 0)
	{
	  printf("Enter your choice :\n");
	  printf("1 : Insert into BST\n");
	  printf("2 : search the element in BST\n");
	  printf("3 : Inorder display \n");
	  printf("4 : preorder display \n");
	  printf("5 : postorder display\n");
	  printf("0 : Exit the application \n");
	  
	  scanf("%d",&choice);
	  switch(choice)
	  {
		  case 1:
	              printf("Enter number to insert\n");
	              scanf("%d",&no);
	              Insert(&First,no);
	              break;
		  case 2:
	              printf("Enter Element to search\n");
	              scanf("%d",&no);
	              bRet = Search(First,no);
	              if(bRet == TRUE)
	             {
		               printf("Element is there in BST \n");
	             }
	             else
	             {
		               printf("There is no element in BST \n");
	             }
				 break;
		 case 3:
	          Inorder(First);
			  break;
		case 4:
	           Preorder(First);
			   break;
		case 5:
	            Postorder(First);
				break;
		default:
		        printf("Wrong choice");
				break;
	  }
	}
}

/*
output

D:\ProgramTopicWise\DataStructure>gcc Tree.c -o myexe

D:\ProgramTopicWise\DataStructure>myexe
Enter your choice :
1 : Insert into BST
2 : search the element in BST
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the application
1
Enter number to insert
10
Enter your choice :
1 : Insert into BST
2 : search the element in BST
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the application
1
Enter number to insert
20
Enter your choice :
1 : Insert into BST
2 : search the element in BST
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the application
1
Enter number to insert
30
Enter your choice :
1 : Insert into BST
2 : search the element in BST
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the application
2
Enter Element to search
55
There is no element in BST
Enter your choice :
1 : Insert into BST
2 : search the element in BST
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the application
2
Enter Element to search
20
Element is there in BST
Enter your choice :
1 : Insert into BST
2 : search the element in BST
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the application
3
10      20      30      Enter your choice :
1 : Insert into BST
2 : search the element in BST
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the application
4
10      20      30      Enter your choice :
1 : Insert into BST
2 : search the element in BST
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the application
5
20      30      10      Enter your choice :
1 : Insert into BST
2 : search the element in BST
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the application
0
Wrong choice
*/
