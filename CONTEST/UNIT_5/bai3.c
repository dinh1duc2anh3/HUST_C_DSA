#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct Queue
{
	int x, y;
	struct Queue * next;
	struct Queue * prev;
	int dis;
}

Queue;

Queue *head, *tail;
Queue *nodeList[MAX_SIZE *MAX_SIZE];

int nodeListSize = 0;
int grid[MAX_SIZE][MAX_SIZE];
int Rows, Cols;
int Xbegin, Ybegin;
int Xend, Yend;
int visited[MAX_SIZE][MAX_SIZE];
const int dx[4] = { 1, -1, 0, 0 };

const int dy[4] = { 0, 0, 1, -1 };

Queue * endNode;

Queue* createNode(int x, int y, int dis, Queue *prev)
{
	Queue *node = (Queue*) malloc(sizeof(Queue));
	node->x = x;
	node->y = y;
	node->next = NULL;
	node->prev = prev;
	node->dis = dis;
	return node;
}

void initializeQueue()
{
	head = NULL;
	tail = NULL;
}

int isQueueEmpty()
{
	return head == NULL && tail == NULL;
}

void enqueue(Queue *node)
{
	if (isQueueEmpty())
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}
}

Queue* dequeue()
{
	if (isQueueEmpty()) return NULL;
	Queue *node = head;
	head = node->next;
	if (head == NULL) tail = NULL;
	return node;
}

void readInput()
{
	scanf("%d%d%d%d%d%d", &Rows, &Cols, &Xbegin, &Ybegin, &Xend, &Yend);
	for (int i = 1; i <= Rows; i++)
	{
		for (int j = 1; j <= Cols; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}
}

int isValid(int x, int y)
{
	return x >= 1 && x <= Rows && y >= 1 && y <= Cols && grid[x][y] == 0 && !visited[x][y];
}

int isTarget(int x, int y)
{
	return (x == Xend && y == Yend);
}

void freeQueue()
{
	for (int i = 0; i < nodeListSize; i++)
	{
		free(nodeList[i]);
	}
}

void addNodeToList(Queue *node)
{
	nodeList[nodeListSize] = node;
	nodeListSize++;
}

int main()
{
	readInput();
	for (int x = 1; x <= Rows; x++)
		for (int y = 1; y <= Cols; y++)
			visited[x][y] = 0;
	initializeQueue();
	Queue *startNode = createNode(Xbegin, Ybegin, 0, NULL);
	addNodeToList(startNode);
	enqueue(startNode);
	visited[Xbegin][Ybegin] = 1;
	while (!isQueueEmpty())
	{
		Queue *node = dequeue();
		for (int i = 0; i < 4; i++)
		{
			int nx = node->x + dx[i];
			int ny = node->y + dy[i];
			if (isValid(nx, ny))
			{
				visited[nx][ny] = 1;
				Queue *newNode = createNode(nx, ny, node->dis + 1, node);
				addNodeToList(newNode);
				if (isTarget(nx, ny))
				{
					endNode = newNode;
					break;
				}
				else
					enqueue(newNode);
			}
		}

		if (endNode != NULL) break;
	}

	Queue *s = endNode;
	if (s == NULL) printf("-1");
	int count = 0;
	while (s != NULL)
	{
		count++;
		s = s->prev;
	}

	if (count > 0) printf("%d", count - 1);
	freeQueue();
	return 0;
}