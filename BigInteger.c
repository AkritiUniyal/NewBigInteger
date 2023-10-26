#include<stdlib.h>
#include<stdio.h>
#include"BigInteger.h"
#include<string.h>

//function to create node of given value
struct node* CreateNode(int val)
{
   struct node*newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=val;;
   newnode->next=NULL;  
   return newnode;
}

//function to insert node at the beginning
struct node* insertBeg(struct node*newnode,struct node* l)
{
  newnode->next= l;
  l=newnode;
  return l;
}


//display function
void display(struct node*l)
    {
      while(l)
      {
        printf("%d",l->data); 
        l=l->next;
      }
      printf("\n");
    }

    
// reverse
struct BigInteger rev(struct BigInteger p)
{
    struct node *cur,*prev,*nex;
    cur=p.l;
    prev=nex=NULL;
    while(cur!=NULL)
    {
        nex=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nex;
    }
    p.l=prev;
    return p;
}
   
// isGreater function
int isGreater(struct BigInteger a,struct BigInteger b)
{

  if(a.length>b.length)
  return 1;
  if(a.length<b.length)
  return 0;
  if(a.length==b.length)
  {
    a=rev(a);
    b=rev(b);
    struct node* itr=a.l;
    struct node*itr1=b.l;
    while(itr)
    {
      if(itr->data>itr1->data)
      {
       a=rev(a);
       b=rev(b);
        return 1;
      }
      else if(itr->data<itr1->data)
      {
        a=rev(a);
       b=rev(b);
      
      return 0;
      }
        else{
      itr=itr->next;
      itr1=itr1->next;
     }
   }
    return 2;
  }
}
  
//initialize function
struct BigInteger initialize(char *s)
{
    struct BigInteger num;
    num.l=NULL;
   int c=0;
    int len;
    len=strlen(s);
    num.length=len;
    int i;
    for(i=0;i<len;++i)
    {
        struct node*newnode=CreateNode(s[i]-'0');
      
        num.l=insertBeg(newnode,num.l);
    }
   
    return num;
}

//add function
struct BigInteger add(struct BigInteger a, struct BigInteger b)
{
   // display(a.l);
   // display(b.l);
    if(!a.l)
    return b;
    if(!b.l)
    return a;
    if (b.length>a.length)
  {
    struct node* temp=b.l;
    b.l=a.l;
    a.l=temp;
    int templen=b.length;
    b.length=a.length;
    a.length=templen;
  }
  struct BigInteger sum;
  sum.l=NULL;
  sum.length=0;
  int c=0,s=0;
  while(b.l)
  {
     s=((a.l)->data+(b.l)->data+c);
     
    if((a.l)->next==NULL&&s>9)
    {
       struct node *newn=CreateNode(s%10);
       sum.l=insertBeg(newn,sum.l);
       sum.length=sum.length+1;
       struct node *newnode=CreateNode(s/10);
       sum.l=insertBeg(newnode,sum.l);
       sum.length=sum.length+1;
    }
  else
  {
    struct node*newnode=CreateNode(s%10);
     sum.l=insertBeg(newnode,sum.l);
     sum.length=sum.length+1;
  if(s>9)
   c=1;
   else c=0;
}
a.l=(a.l)->next;
b.l=(b.l)->next;
//display(a.l);
   // display(b.l);
  }
  while(a.l)
   {
    s=(a.l)->data+c; 
    if((a.l)->next==NULL&&s>9)
    {
      struct node *newn=CreateNode(s%10);
       sum.l=insertBeg(newn,sum.l);
       sum.length=sum.length+1;
       struct node *newnode=CreateNode(s/10);
       sum.l=insertBeg(newnode,sum.l);
       sum.length=sum.length+1;
       }
    
else{
    struct node*newnode=CreateNode(s%10);
     sum.l=insertBeg(newnode,sum.l);
     sum.length=sum.length+1;
        if(s>9)
   c=1;
   else c=0;
    }
    //displayf("yo");
    //display(a.l);
    //display(b.l);
a.l=(a.l)->next;
 }
  //display(sum.l);
 return sum;

}

struct BigInteger removeZero(struct BigInteger d)
{
  
  struct node * temp;
  while((d.l)->data==0)
  {
    temp=d.l;
    d.l=(d.l)->next;
    free(temp);
    d.length=(d.length)-1;
}
if(!d.l)
{
  struct node *newnode=CreateNode(0);
       d.l=insertBeg(newnode,d.l);
       d.length=(d.length)+1;
}

return d;
}

//subtract function
struct BigInteger sub(struct BigInteger a,struct BigInteger b)
{
  

  

    if(!a.l)
    return b;
    if(!b.l)
    return a;
 struct BigInteger diff;
  diff.l=NULL;
  diff.length=0;
  
  int borrow=0;
  int d=0;
   a=rev(a);
   b=rev(b);
if(isGreater(a,b)==2)
 {
  struct node *newnode=CreateNode(0);
       diff.l=insertBeg(newnode,diff.l);
       diff.length=diff.length+1;
      return diff;
 }
  
    if ((b.length>a.length)||((a.length==b.length)&&(a.l)->data<(b.l)->data))
  {
    struct node* temp=b.l;
    b.l=a.l;
    a.l=temp;
    int templen=b.length;
    b.length=a.length;
    a.length=templen;
  }
  
  a=rev(a);
  b=rev(b);

  while(b.l)
  {
    d=(a.l)->data-(b.l)->data+borrow;
    if(d<0)
    {
        d=d+10;
    borrow=-1;
    }
    else borrow=0;
    struct node *newnode=CreateNode(d);
    diff.l=insertBeg(newnode,diff.l);
    diff.length=diff.length+1;
    
    a.l=(a.l)->next;
    b.l=(b.l)->next;
  }
  while(a.l)
  {
    d=(a.l)->data-0+borrow;;
        if(d<0)
    {
        d=d+10;
       borrow=-1;
    }
    else borrow=0;
    struct node *newnode=CreateNode(d);
    diff.l=insertBeg(newnode,diff.l);
    diff.length=diff.length+1;
    a.l=(a.l)->next;
  }
  
  

  diff=removeZero(diff);
  return diff;
}





//Multiply 1 linked list with 1 digit of another  linkd list
struct BigInteger multiply(struct BigInteger p,int val)
{
   int product=0,carry=0;
    struct BigInteger prod;
    prod.l=NULL;
    prod.length=0;
  while(p.l!=NULL)
  {
    product=(p.l->data)*val+carry;

if(product>9)
{
  carry=product/10;
  product=product%10;
}
else{
  carry=0;
  
}

struct node*newnode=CreateNode(product);
prod.l=insertBeg(newnode,prod.l);
prod.length=prod.length+1;
p.l=p.l->next;
}
if(carry!=0)
  {
    struct node*newnode=CreateNode(carry);
    prod.l=insertBeg(newnode,prod.l);
    prod.length=prod.length+1;
   }
  return prod;
}

//Adding extra 0 to roduct;
struct BigInteger addzero(struct BigInteger pro,int c)
{
  int i=0;
  while(i<c)
  {
     struct node*newnode=CreateNode(0);
     pro.l=insertBeg(newnode,pro.l);
     pro.length=pro.length+1;
     
     ++i;
    
  }
  return pro;
}
  //multiply function
struct BigInteger mul(struct BigInteger a, struct BigInteger b)
{
  struct BigInteger product;
    product.l=NULL;
    product.length=0;
    struct BigInteger prod;
    prod.l=NULL;
    product.length=0;
    struct BigInteger product1;
    product1.l=NULL;
    product1.length=0;

    if(!a.l||!b.l||((a.length==1)&&(a.l)->data==0)||((b.length==1)&&(b.l)->data==0))
    {
      struct node *newnode=CreateNode(0);
       product1.l=insertBeg(newnode,product1.l);
       product1.length=product1.length+1;
       return product1;
  }
    
   
  
 
    
    if (b.length>a.length)
  {
    struct node* temp=b.l;
    b.l=a.l;
    a.l=temp;
    int templen=b.length;
    b.length=a.length;
    a.length=templen;
  }

 
    product=multiply(a,(b.l)->data);
    if(b.length==1)
    return product;
    product=rev(product);
  // display(product.l);
   b.l=(b.l)->next;
    int c=1;
    while(b.l)
    {
        
       
        prod=multiply(a,(b.l)->data);
        prod=rev(prod);
       // display(prod.l);
        prod=addzero(prod,c);
       //display(prod.l);
        c=c+1;
        
        product1=add(product,prod);
        product1=rev(product1);
       //display(product1.l);
        product.l=product1.l;
       //display(product.l);
      
        b.l=(b.l)->next;
    }
    product1=rev(product1);
return product1;
}

// Convert Number to Linked List
struct BigInteger numToLinkedList(long long int n)
{
   struct BigInteger divide;
   divide.l=NULL;
   divide.length=0;
    while(n!=0)
    {
            struct node *newnode=CreateNode(n%10);
            divide.l=insertBeg(newnode,divide.l);
            divide.length=divide.length+1;
            n=n/10;
    }

    return divide;
}

// Divide function
struct BigInteger div1(struct BigInteger a,struct BigInteger b)
{
   struct BigInteger divide;
   divide.l=NULL;
   divide.length=0;
   long long int c=0;
   int i=0;
   
  if(isGreater(b,a)==1)
  {
  struct node *newnode=CreateNode(0);
       divide.l=insertBeg(newnode,divide.l);
       divide.length=divide.length+1;
       return divide;
  }
 
   if(isGreater(a,b)==2)
 {
  struct node *newnode=CreateNode(1);
       divide.l=insertBeg(newnode,divide.l);
       divide.length=divide.length+1;
       return divide;
      
 }
    while(isGreater(a,b)==1)
    {
        c=c+1;
       a=sub(a,b);
      
       a=rev(a);
      
    }
    
    if(isGreater(a,b)==2)
 
      divide=numToLinkedList(c+1);
    else
     divide=numToLinkedList(c);
    
 return divide;
}

//modulus function

struct BigInteger mod(struct BigInteger a,struct BigInteger b)
{
     struct BigInteger modulus;
     modulus.l=NULL;
     modulus.length=0;

struct BigInteger divide;
   divide.l=NULL;
   long long int c=0;
   if(isGreater(a,b)==2)
 {
  struct node *newnode=CreateNode(0);
       modulus.l=insertBeg(newnode,modulus.l);
       modulus.length=modulus.length+1;
      return modulus;
 }
  if(isGreater(b,a))
  {
    a=rev(a);
     return a;
  }
 
   
    while(isGreater(a,b)==1)
    {
        c=c+1;
       a=sub(a,b);
      
       a=rev(a); 
       
      
    }
      if(isGreater(a,b)==2)
 {
  struct node *newnode=CreateNode(0);
       modulus.l=insertBeg(newnode,modulus.l);
        modulus.length=modulus.length+1;
      return modulus;
 }
a=rev(a);
 modulus.l=a.l;    
 return modulus;
}

