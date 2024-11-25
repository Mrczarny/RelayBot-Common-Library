#ifndef _path_h
#define _path_h

#include "Arduino.h"

struct Map
{
    int width;
    int height;
    Node* nodes;
};

struct Node
{
    /// @brief all the possible openings of the node, if there is no opening, the pointer is NULL
    /// @details openings[0] is the opening to the left looking from first recorded node, openings[3] is the opening to the right etc.
    Node* openings[4];
    bool visited;
    bool deadEnd;
    bool crossroad;
    bool turn;
    bool start;
    bool end;
};


class Path {
  public:
    Path() {}
    Map _map;
    void addTurn(int direction);
    void addCrossroad(bool options[4]); 
    void addDeadEnd();
    void addStart();
    void addEnd();
    void setCurrentNode(Node* node);
    void searchNearestUnvisited();
    void visited();
  private:
    Node* _currentNode;
    /// @brief HAS TO BE RELATIVE TO STARTING POINT!!!
    /// @details 0 is left, 1 is forward, 2 is right, 3 is backward
    int _currentDirection;
    Node* _startNode;
    Node* _endNode;
    int _unvisitedNodes;
    int getOpositeDirection(int direction);
};

#endif