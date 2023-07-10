#include <vector>
#include <queue>
#include <cmath>
#include <memory>
class Node{
    public:
    Node(int x, int y):x_(x),y_(y),gn_(0),hn_(0),parent(nullptr){
    }
    int fn()const{
        return gn_ + hn_;
    }
    int x_;
    int y_;
    int gn_;
    int hn_;
    Node* parent ;
    bool operator <(const Node& other)const{
        return fn()>other.fn();
    }
};  

class Astar{
    public:
    Astar(const std::vector<std::vector<int>>& map,int start_x,int start_y,int end_x,int end_y);
    
    std::vector<std::shared_ptr<Node>>search();
    private: 
    int start_x_;
    int start_y_;
    int end_x_;
    int end_y_;
    int map_rows_;
    int map_cols_;
    std::vector<std::vector<int>> map_;
    std::priority_queue<Node> open_list_;
    std::vector<std::vector<bool>> closed_list;
    int heuristic(int x,int y)const{
        return std::sqrt((end_x_ - x)*(end_x_ - x) + (end_y_ - y)*(end_y_ - y));
    }
};

// };
// class Astar {
// public:
// Astar();


// void add();

// };







// #include <iostream>
// #include <vector>
// #include <queue>
// #include <cmath>

// using namespace std;

// // 定义一个节点类
// class Node {
// public:
//     int x, y; // 节点的坐标
//     int g, h; // g 代表从起点到当前节点的代价，h 代表从当前节点到终点的估价
//     Node* parent; // 指向父节点的指针

//     Node(int x, int y) {
//         this->x = x;
//         this->y = y;
//         g = h = 0;
//         parent = nullptr;
//     }

//     int f() const { // f = g + h
//         return g + h;
//     }

//     bool operator<(const Node& other) const { // 用于 priority_queue 的比较函数
//         return f() > other.f();
//     }
// };

// // 定义一个 AStar 类
// class AStar {
// public:
//     AStar(vector<vector<int>>& grid, int start_x, int start_y, int end_x, int end_y) {
//         this->grid = grid;
//         this->start_x = start_x;
//         this->start_y = start_y;
//         this->end_x = end_x;
//         this->end_y = end_y;
//         rows = grid.size();
//         cols = grid[0].size();
//         open_list = priority_queue<Node>();
//         closed_list = vector<vector<bool>>(rows, vector<bool>(cols, false));
//     }

//     vector<Node*> search() {
//         Node* start_node = new Node(start_x, start_y);
//         start_node->h = heuristic(start_x, start_y);
//         open_list.push(*start_node);

//         while (!open_list.empty()) {
//             Node current = open_list.top();
//             open_list.pop();

//             if (current.x == end_x && current.y == end_y) {
//                 vector<Node*> path;
//                 while (current.parent != nullptr) {
//                     path.push_back(&current);
//                     current = *current.parent;
//                 }
//                 path.push_back(&current);
//                 return path;
//             }

//             closed_list[current.x][current.y] = true;

//             for (int i = -1; i <= 1; i++) {
//                 for (int j = -1; j <= 1; j++) {
//                     if (i == 0 && j == 0) continue;
//                     int x = current.x + i;
//                     int y = current.y + j;
//                     if (x < 0 || x >= rows || y < 0 || y >= cols) continue;
//                     if (grid[x][y] == 1) continue;
//                     if (closed_list[x][y]) continue;

//                     Node* neighbor = new Node(x, y);
//                     neighbor->g = current.g + 1;
//                     neighbor->h = heuristic(x, y);
//                     neighbor->parent = &current;

//                     open_list.push(*neighbor);
//                 }
//             }
//         }

//         return vector<Node*>();
//     }

// private:
//     vector<vector<int>> grid; // 地图
//     int start_x, start_y; // 起点坐标
//     int end_x, end_y; // 终点坐标
//     int rows, cols; // 地图的行数和列数
//     priority_queue<Node> open_list; // 开放列表
//     vector<vector<bool>> closed_list; // 关闭列表

//     int heuristic(int x, int y) const { // 曼哈顿距离作为估价函数
//         return abs(x - end_x) + abs(y - end_y);
//     }
// };