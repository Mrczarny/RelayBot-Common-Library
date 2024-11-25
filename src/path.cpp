#include "path.h"

void Path::addTurn(int direction)
{
    _currentNode->openings[_currentDirection] = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = true,
        .deadEnd = false,
        .crossroad = false,
        .turn = true,
        .start = false,
        .end = false
    };

    _currentNode->openings[_currentDirection]
    ->openings[getOpositeDirection(direction)] = _currentNode;

    _currentNode->openings[direction] = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = false,
        .deadEnd = false,
        .crossroad = false,
        .turn = false,
        .start = false,
        .end = false
    };
    _currentNode->openings[direction]->openings[getOpositeDirection(direction)] = _currentNode;

}


void Path::addCrossroad(bool options[4])
{
    _currentNode->openings[_currentDirection] = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = true,
        .deadEnd = false,
        .crossroad = true,
        .turn = false,
        .start = false,
        .end = false
    };
    _currentNode->openings[_currentDirection]->openings[getOpositeDirection(_currentDirection)] = _currentNode;

    _currentNode = _currentNode->openings[_currentDirection];

    _currentNode->crossroad = true;

    
    for (int i = 0; i < 4; i++)
    {
        if (options[i] && _currentNode->openings[i] == NULL)
        {
            _currentNode->openings[i] = new Node {
                .openings = {NULL, NULL, NULL, NULL},
                .visited = false,
                .deadEnd = false,
                .crossroad = false,
                .turn = false,
                .start = false,
                .end = false
            };
            _currentNode->openings[i]->openings[getOpositeDirection(i)] = _currentNode;
        }
    }
}


void Path::addDeadEnd()
{
    _currentNode->openings[_currentDirection] = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = true,
        .deadEnd = true,
        .crossroad = false,
        .turn = false,
        .start = false,
        .end = false
    };
    _currentNode->openings[_currentDirection]->openings[getOpositeDirection(_currentDirection)] = _currentNode;
    _currentNode = _currentNode->openings[_currentDirection];
}


void Path::addStart()
{
    _currentNode = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = true,
        .deadEnd = false,
        .crossroad = false,
        .turn = true,
        .start = true,
        .end = false
    };
    _startNode = _currentNode;
    _map.nodes = _currentNode;
}

void Path::addEnd()
{
    _currentNode->openings[_currentDirection] = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = true,
        .deadEnd = false,
        .crossroad = false,
        .turn = true,
        .start = false,
        .end = true
    };
    _currentNode->openings[_currentDirection]->openings[getOpositeDirection(_currentDirection)] = _currentNode;
    _endNode = _currentNode;
}


/// @brief HIGHLY RECOMMENDED TO NOT USE THIS FUNCTION AT ALL
/// @param node the node to set as current
void Path::setCurrentNode(Node* node)
{
    _currentNode = node;
}

void Path::searchNearestUnvisited()
{
    //TODO
}

void Path::visited()
{
    _currentNode->visited = true;
}

int Path::getOpositeDirection(int direction)
{
    //TODO
}