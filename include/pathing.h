#ifndef _path_h
#define _path_h

#include "Arduino.h"

struct Map
{
    int width;
    int height;
    Node* nodes;
};

struct path
{
  Node* startNode;
  Node* endNode;
  int directions[];
};


struct Node
{
    /// @brief all the possible openings of the node, if there is no opening, the pointer is NULL
    /// @details openings[0] is the opening to the left looking from first recorded node, openings[1] is forward one, openings[2] is the opening to the right.
    Node* openings[4];
    bool visited;
    bool deadEnd;
    bool crossroad;
    bool turn;
    bool start;
    bool end;
};


class Pathing {
  public:
    Pathing() {}
    Map _map;
    Node* currentNode;
    /// @brief HAS TO BE RELATIVE TO STARTING POINT!!!
    /// @details 0 is left, 1 is forward, 2 is right, 3 is backward
    int currentDirection;
    void addTurn(int direction);
    void addCrossroad(bool options[4]); 
    void addDeadEnd();
    void addStart();
    void addEnd();
    void setCurrentNode(Node* node);
    path searchForNearestUnvisited(Node* startNode, int directions[]);
    void visited();
  private:
    Node* _startNode;
    Node* _endNode;
    int _unvisitedNodes;
    int getOpositeDirection(int direction);
};

#endif