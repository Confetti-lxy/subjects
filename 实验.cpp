#include <iostream>
#include <climits>
using namespace std;

struct node
{
    int to, length, index;
    node() : to(0), length(0), index(0) {}
    node(int to, int length, int index) : to(to), length(length), index(index) {}
};

struct point
{
    long dis, index;
    point() : dis(0), index(0) {}
    point(int dis, int index) : dis(dis), index(index) {}
};

int dijkstra(int start, int end);
