#include "stdio.h"   
#include "string.h"   
#include "stdlib.h"   

struct dictree   
{   
    struct dictree *child[26];   
    int n;   
};   
struct dictree *root;   

void insert (char *source)   
{   
    int len,i,j;   
    struct dictree *current,*newnode;   
    len=strlen(source);   
    if(len==0) return;   
    current=root;   
    for(i=0;i<len;i++)   
    {   
        if(current->child[source[i]-'a']!=0)   
        {
            current=current->child[source[i]-'a'];
            current->n=current->n+1; 
        }
        else   
        {   
            newnode=(struct dictree *)malloc(sizeof(struct dictree));   
            for(j=0;j<26;j++)   
                newnode->child[j]=0; 
            current->child[source[i]-'a']=newnode;   
            current=newnode;
            current->n=1;    
        }   
    }   
}   
int find(char *source)   
{   
    int i,len;   
    struct dictree *current;  
    len=strlen(source);
    if(len==0) return 0;   
    current=root;   
    for(i=0;i<len;i++)   
    {   
        if(current->child[source[i]-'a']!=0)   
            current=current->child[source[i]-'a'];   
        else return 0;   
    }   
    return current->n;   
}   
int main()
{
    char temp[11];
    int i,j;
    root=(struct dictree *)malloc(sizeof(struct dictree));   
    for(i=0;i<26;i++)   
        root->child[i]=0;   
    root->n=2; 
    while(gets(temp),strcmp(temp,"")!=0)
        insert(temp);
    while(scanf("%s",temp)!=EOF)
    {
        i=find(temp);
        printf("%d\n",i);
    }
}
