#include "RedBlackTree.h"
#include <iostream>
using namespace std;

int main()
{


        RBTree rbt;
       for(int i = 1; i < 5; i++)
        {
            rbt.Insert(i);
        }
        rbt.Display();
		cout<<rbt.FindNode(3)->parent->nData<<endl;
  	

}