#include "pathing.h"

void Pathing::addTurn(int direction)
{
    currentNode->openings[currentDirection] = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = true,
        .deadEnd = false,
        .crossroad = false,
        .turn = true,
        .start = false,
        .end = false
    };

    currentNode->openings[currentDirection]
    ->openings[getOpositeDirection(direction)] = currentNode;

    currentNode->openings[direction] = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = false,
        .deadEnd = false,
        .crossroad = false,
        .turn = false,
        .start = false,
        .end = false
    };
    currentNode->openings[direction]->openings[getOpositeDirection(direction)] = currentNode;

}


void Pathing::addCrossroad(bool options[4])
{
    currentNode->openings[currentDirection] = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = true,
        .deadEnd = false,
        .crossroad = true,
        .turn = false,
        .start = false,
        .end = false
    };
    currentNode->openings[currentDirection]->openings[getOpositeDirection(currentDirection)] = currentNode;

    currentNode = currentNode->openings[currentDirection];

    currentNode->crossroad = true;

    
    for (int i = 0; i < 4; i++)
    {
        if (options[i] && currentNode->openings[i] == NULL)
        {
            currentNode->openings[i] = new Node {
                .openings = {NULL, NULL, NULL, NULL},
                .visited = false,
                .deadEnd = false,
                .crossroad = false,
                .turn = false,
                .start = false,
                .end = false
            };
            currentNode->openings[i]->openings[getOpositeDirection(i)] = currentNode;
        }
    }
}


void Pathing::addDeadEnd()
{
    currentNode->openings[currentDirection] = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = true,
        .deadEnd = true,
        .crossroad = false,
        .turn = false,
        .start = false,
        .end = false
    };
    currentNode->openings[currentDirection]->openings[getOpositeDirection(currentDirection)] = currentNode;
    currentNode = currentNode->openings[currentDirection];
}


void Pathing::addStart()
{
    currentNode = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = true,
        .deadEnd = false,
        .crossroad = false,
        .turn = true,
        .start = true,
        .end = false
    };
    _startNode = currentNode;
    _map.nodes = currentNode;
}

void Pathing::addEnd()
{
    currentNode->openings[currentDirection] = new Node {
        .openings = {NULL, NULL, NULL, NULL},
        .visited = true,
        .deadEnd = false,
        .crossroad = false,
        .turn = true,
        .start = false,
        .end = true
    };
    currentNode->openings[currentDirection]->openings[getOpositeDirection(currentDirection)] = currentNode;
    _endNode = currentNode;
}


/// @brief HIGHLY RECOMMENDED TO NOT USE THIS FUNCTION AT ALL
/// @param node the node to set as current
void Pathing::setCurrentNode(Node* node)
{
    currentNode = node;
}

path Pathing::searchForNearestUnvisited(Node* node, int directions[])
{
    for (int  i = 0; i < 4; i++)
    {
        if (node->openings[i] != NULL && !node->openings[i]->visited)
        {
            return path {
                .startNode = node,
                .endNode = node->openings[i],
                .directions = {i}
            };
        }
        int previousArrayLength = sizeof(directions) / sizeof(directions[0]);
        int newDirections[previousArrayLength + 1];
        for (int j = 0; j < previousArrayLength; j++)
        {
            newDirections[j] = directions[j];
        }
        newDirections[previousArrayLength] = i;
        path discoveredPath = searchForNearestUnvisited(node->openings[i], newDirections);
        discoveredPath.startNode = node;
        return discoveredPath;
    }

    
}

void Pathing::visited()
{
    currentNode->visited = true;
}

int Pathing::getOpositeDirection(int direction)
{
    switch (direction)
    {
    case 0:
        return 2;
        break;
    case 1:
        return 3;
        break;
    case 2:
        return 0;
        break;
    case 3:
        return 1;
        break;
    default:
        return -1;
        break;
    }
}