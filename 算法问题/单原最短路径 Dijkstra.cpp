#include <iostream>
#define MAX_FLOT_NUM 3.14E38
using namespace std;
struct adj_list{
    int v_num;//邻接点定点的编号
    float len;//邻接点顶点与该结点的距离
    struct adj_list *next;
    };
    typedef struct adj_list NODE;
void dijkstra(NODE node[],int n,int u,float d[],int p[])
{
float temp;
int i,j,t;
bool *s=new bool[n];
NODE *pnode;
    for(i=0;i<n;i++)
    {
        d[i]=MAX_FLOT_NUM;
        s[i]=false;
        p[i]=-1;
    }
    if(!(pnode=node[u].next))
    return;
    while(pnode){
        d[pnode->v_num]=pnode->len;
        p[pnode->v_num]=u;
        pnode =pnode->next;
        }
        d[u]=0;s[u]=true;
        for(i=1;i<n;i++)
        {
            temp=MAX_FLOT_NUM;
            t=u;
            for(j=0;j<n;j++)
                if(!s[j]&&d[j]<temp){
                    t=j;temp=d[j];
                    }
                    if(t==u) break;
                    s[t]=true;
                    pnode=node[t].next;
                    while(pnode){
                        if(!s[pnode->v_num]&&d[pnode->v_num]>d[t]+pnode->len){
                            d[pnode->v_num]=d[t]+pnode->len;
                            p[pnode->v_num]=t;
                            }
                            pnode=pnode->next;
                        }
            }
     delete s;
}
int main()
{
    int n；
    cin>>n;
    return 0;
}
