#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node {
	int a,b;
	node *next;
};

// fonction pour inserer un element à la liste.
node * insert(node *L,int a,int b)
{
	node *elem=(node *)malloc(sizeof(node *));
	node *cur=L;
	elem->a=a;
	elem->b=b;
	elem->next=NULL;
	if (L==NULL)
		L=elem;
	else
		{
		while (cur->next!=NULL)
		cur=cur->next;
		cur->next=elem;
		}
	return L;
}
// fonction pour calculer la taille d'une liste.
int sizeList(node *L)
{
	node *cur=L;
	int nb=0;
	while(cur!=NULL)
	{
		nb++;
		cur=cur->next;
	}
	return nb;
}
// fonction pour donner un element dans la liste
node * getElem(node *L,int index)
{
	node *cur=L;
	int nb=0;
	while(cur!=NULL && nb!=index)
	{
		cur=cur->next;
		nb++;
	}
	return cur;
}
// fonction pour supprimer un element dans la liste
node * deleteElem(node *L,node *elem)
{
	node *cur=L;
	node *prev=L;
	while(cur!=NULL)
	{
		if(cur==elem)
		{
			prev->next=cur->next;
			free(cur);
			break;
		}
		prev=cur;
		cur=cur->next;
	}
	return L;
}

// fonction pour fusionner entre deux liste.
node * merge(node *L,node *L1)
	{
		node *cur=L;
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cur->next=L1;
		return L;		
	}

// fonction pour afficher les elements de la liste.
void affiche(node *L)
{
	node *cur=L;
	while(cur!=NULL)
	{
		cout<<cur->a<<"\t";
		cout<<cur->b<<"\t";
		cur=cur->next;
	}
	
}
    

int main()
	{
		node *L=NULL;
		node *L1=NULL;
		L=insert(L,4,5);
		L=insert(L,8,5);
		L=insert(L,9,7);
		L1=insert(L1,2,3);
		affiche(L);
		affiche(L1);
		cout<<endl;
		L=merge(L,L1);
		affiche(L);
		cout<<sizeList(L);
	
	}
