#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node *left;
    struct node *right;
};
struct node *root,*temp;
int a,ch,x=0,y=0,s,m,n,k;


struct node *create(struct node *root,int a)
{root=(struct node*)malloc(sizeof(struct node));
    root->d=a;
    root->left=NULL;
    root->right=NULL;
    return root;

};

struct node *insert(struct node *root,int a)
{
    if(root==NULL)
    {
        root=create(root,a);
    }
    else if(a>root->d)
        root->right=insert(root->right,a);
    else if(a<root->d)
        root->left=insert(root->left,a);
    return root;
};
void preorder(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->d);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if(root==NULL)
        return;
        preorder(root->left);
    printf("%d ",root->d);

    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root==NULL)
        return;
        preorder(root->left);


    preorder(root->right);
    printf("%d ",root->d);
}

int search(struct node *root,int a)
{
    if(root==NULL)
        return;
    if(root->d==a)
    {
       printf("key is found\n");
       return -1;
    }

    else if(a>root->d)
        temp=search(root->right,a);
    else if(a<root->d)
        temp=search(root->left,a);

}

void maxmin(struct node *root)
{
    temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    printf("max=%d\n",temp->d);

    temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    printf("min=%d\n",temp->d);

};

void topview(struct node *root)
{
   if(root==NULL)
    return;

      printf("%d ",root->d);
      topview(root->left);
      topview(root->right);

}

void rightview(struct node *root)
{


     if(root->right!=NULL)
    {
        printf("%d ",root->d);
      rightview(root->right);
    }
    else if(root->right==NULL&&root->left==NULL)
    {
        printf("%d ",root->d);
         return;
    }

    else if(root->right==NULL&&root->left!=NULL)
    {
         printf("%d ",root->d);
         rightview(root->left);
    }
     else if(root->left==NULL&&root->right!=NULL)
     {
         printf("%d ",root->d);
         rightview(root->right);
     }


}

int height(struct node *root)
{int x=0,y=0;
    if(root==NULL)
    return;

    temp=root;
    while(temp->left!=NULL)
        {
            x++;
            temp=temp->left;
        }
        if(temp->left==NULL&&temp->right!=NULL)
        {
            x++;
            temp=temp->right;
        }
        if(temp->left!=NULL)
        {
            x++;
            temp=temp->right;
        }

        return x+1;




}

void ancestors(struct node *root,int m ,int n)
{
    if(root==NULL)
       return;
    if(m<root->d&&n<root->d)
    {
        printf("%d ",root->d);
        ancestors(root->left,m,n);
    }
    else if(m>root->d&&n>root->d)
    {
         printf("%d ",root->d);
        ancestors(root->right,m,n);
    }
    else if(m<root->d&&n>root->d)
    {
         printf("%d ",root->d);
       return;
    }

    else if(m>root->d&&n<root->d)
    {
         printf("%d ",root->d);
       return;
    }

}

void leafnodes(struct node *root)
{if(root==NULL)
return;
    if(root->left==NULL&&root->right==NULL)
    printf("%d ",root->d);
    else if(root->left==NULL&&root->right!=NULL)
        leafnodes(root->right);
    else if(root->left!=NULL&&root->right==NULL)
        leafnodes(root->left);
    else
    {
        leafnodes(root->left);
        leafnodes(root->right);
    }
}
int getmindata(struct node *root)
{
    temp=root;
    while(temp->left!=NULL);
    {
        temp=temp->left;
    }
    return temp->d;
}

struct node *deletenode(struct node *root,int k)
{
    if(root==NULL)
    return NULL;
    if(k>root->d)
     root->right=deletenode(root->right,k);
    else if(k<root->d)
       root->left=deletenode(root->left,k);
    else
    {
        if(root->left==NULL)
        {
           struct node *temp;
        temp=root->right;
        free(root);
        return temp;
        }
       else if(root->right==NULL)
        {
           struct node *temp;
        temp=root->left;
        free(root);
        return temp;
        }

            int mindata=getmindata(root->right);
            root->d=mindata;
            root->right=deletenode(root->right,mindata);
    }
        return root;
    }





main()
{root=NULL;
    while(1)
    {
        printf("1--for insert\n");
        printf("2--for preorder\n");
        printf("3--for in order\n");
        printf("4--for postorder\n");
        printf("5--for search\n");
        printf("6--for max min\n");
        printf("7--for top view\n");
        printf("8--right view\n");
        printf("9--for height of tree\n");
        printf("10--for ancestors\n");
        printf("11---for leaf nodes\n");
        printf("12--for delete node\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                  printf("enter data\n");
                  scanf("%d",&a);
                  root=insert(root,a);
                  break;
            case 2:preorder(root);
                   printf("\n");
                   break;
            case 3:inorder(root);
                   printf("\n");
                   break;
            case 4:postorder(root);
                   printf("\n");
                   break;
            case 5:printf("enter the value to be searched\n");
                   scanf("%d",&a);
                   x=search(root,a);
                   if(x!=-1)
                   {
                       root=insert(root,a);
                   }
                   break;
            case 6:maxmin(root);
                  break;
            case 7:topview(root);
                   printf("\n");
                  break;
            case 8:rightview(root);
                    printf("\n");
                  break;
            case 9:s=height(root);
                   printf("height=%d",s);
                   printf("\n");
                   break;
            case 10:printf("enter the values m,n\n");
                    scanf("%d%d",&m,&n);
                    printf("ancestors are\n");
                    ancestors(root,m,n);
                    printf("\n");
                    break;
            case 11:leafnodes(root);
                    printf("\n");
                    break;
            case 12:printf("enter the node to be deleted\n");
                     scanf("%d",&k);
                    deletenode(root,k);
                     preorder(root);
                     break;

    }
    }
}
