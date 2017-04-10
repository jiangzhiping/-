#include<iostream>
using namespace std;

typedef int ElemType;
struct NodeType
{
	ElemType data;
	NodeType *lch;
	NodeType *rch;
};

class BiTree
{
public:
	BiTree()
	{
		root = NULL;
	}
	~BiTree()
	{
		destory(root);
		root = NULL;
	}
	void create();
protected:
	NodeType *root;
private:
	void destory(NodeType *p);
};

void BiTree::create()
{
	NodeType *q, *s[20];
	ElemType x;
	int i, j;
	cin >> i >> x;
	while ((i != 0) && (x != 0))
	{
		q = new NodeType;
		q->data = x;
		q->lch = NULL;
		q->rch = NULL;
		s[i] = q;
		if (i == 1)
			root = q;
		else
		{
			j = i / 2;
			if ((i % 2 == 0))
				s[j]->lch = q;
			else
				s[j]->rch = q;
		}
		cin >> i >> x;
	}
}

void BiTree::destory(NodeType *p)
{
	if (p != NULL)
	{
		destory(p->lch);
		destory(p->rch);
		delete p;
	}
}

int main()
{
	BiTree bitree = BiTree();
	bitree.create();
}