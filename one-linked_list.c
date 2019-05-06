#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int value;
    struct node *next;    
} node;



typedef struct list
{
    node *head;
	node *tail;	
} list;


// ������������� ������� ������
void init (list* l)
{
    l->head = NULL;  
	l->tail = l->head;
}


// ������� �������� � ����� ������, ������� 0 ���� �������
int push_back(list* l, int value)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = value;
	if (l->tail != NULL)
	{
	    l->tail->next = new_node;
	}
	else 
	{
		l->head = new_node;
	}
	l->tail = new_node;
	if (new_node != NULL) return 0; // if new_node = 0 => allocation failed
}



// ������� �������� � ������ ������, ������� 0 ���� �������
int push_front(list* l, int value)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = value;
	if (l->head==NULL)
	{
		l->tail = new_node;
		l->head = new_node;
	}
	else
	{
		new_node->next = l->head;
		l->head = new_node;
	}
	if (new_node != NULL) return 0; // if new_node = 0 => allocation failed
}



// ������� �������� ����� ���������� ����, ������� 0 ���� �������
int insertAfter(node* n, int value)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = value;
	new_node->next = n->next;
	n->next = new_node;
}



// �������� �� ������� ������
int isEmpty(list* l)
{
	if (l->head == NULL /*& l->tail == NULL*/) return 1;	// 1 -empty
	else return 0;
}



// ������� ��� �������� �� ������ � ������ �������, �����
//������, ����� ��������� ������ ������� �� ����� ������
void print(list* l)	
{
    if (isEmpty(l) == 0)
    {
        node* tmp = l->head;
	    while (tmp != NULL)
	    {
		    if (tmp->next == NULL)
		    {
			    printf("%d", tmp->value);
			    tmp = tmp->next;
		    }
		    else
		    {
		    	printf("%d ", tmp->value);
		    	tmp = tmp->next;
		    }
    	}
	    printf("\n");
    }
//	else printf("������ ����!\n");	//qw


}



// ����� �������� �� ��������. ������� NULL ���� ������� �� ������
node* find(list* l, int value)	
{
	node* tmp = l->head;
	while (tmp != NULL)
	{
		if (tmp->value == value)
		{
			return tmp;	// ������
		}
		tmp = tmp->next;
	}
	return NULL;	// �� ������
}



// ������� ������ ������� �� ������ � ��������� ���������,
// ������� 0 ���� �������
int removeNode(list* l, int value)
{
	node* found = find(l, value);	// ������� ���� � ������ ���������
	node* tmp = l->head;		//������� ���������� ����
	if (found != NULL)
	{
		while(tmp->next != found)	// ���� ���������� ����
		{
			tmp = tmp->next;
		}
		tmp->next = found->next;
		free(found);
		return 0;
	}
	else return 1; // �� ������� � �� �������
}




//������� ��� �������� �� ������
void clear (list* l)
{
    node *tmp1 = l->head;
	node *tmp2 /*= tmp1->next*/;
    while (tmp1 != NULL)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
    }
	l->head = NULL;
	l->tail = NULL;

}


// ������� �������� ����� j-�� ����
void insertAfterJ(list* l, int j, int value)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = value;
	node* tmp = l->head;
	int count = 1;
	while (count != j)
	{
		tmp = tmp->next;
		count++;
	}
	new_node->next = tmp->next;
	tmp->next = new_node;
}




int main()
{
    list* l = (list*)malloc(sizeof(list));
    init(l);
	int n, val;
	scanf("%d", &n); //�-�� ���������
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		push_back(l, val);
	}
	print(l);
	for(int i = 0; i < 3; i++)
	{
		scanf("%d", &val);
		if (find(l, val)!= NULL) {
			printf("%d", 1);
		}
		else {
			printf("%d", 0);
		}
	}
	printf("\n");
	scanf("%d", &val);
	push_back(l,val);
	print(l);
	scanf("%d", &val);
	push_front(l,val);
	print(l);	
	int j, x;
	scanf("%d", &j);
	scanf("%d", &x);
	insertAfterJ(l, j, x);
	print(l);
	scanf("%d", &val);
	removeNode(l, val);
	print(l);
	clear(l);
}