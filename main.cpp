#include <iostream>
#include <vector>
#include "Astar/astar.h"
int main() {
    std::cout << "Hello World!\n";
    std::vector<std::vector<int>>map{{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                                    {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                                    {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                                    {0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0},
                                    {0 , 0 , 0 , 1 , 0 , 1 , 1 , 1 , 0 , 0},
                                    {0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1},
                                    {0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0},
                                    {0 , 0 , 0 , 1 , 0 , 1 , 1 , 1 , 0 , 0},
                                    {0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0},
                                    {0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0}};
    int start_x = 0;
    int start_y = 0;
    int end_x = 9;
    int end_y = 9;
    Astar astar_serch(map,start_x,start_y,end_x,end_y);
    auto path = astar_serch.search();
    std::cout<<path.size()<<std::endl;
    for(const auto& node :path){
        map[node->x_][node->y_]  = 9;
    }
    for(int row = 0 ; row < map.size();++row){
        for(int col  = 0 ; col <map.at(0).size();++col){

            std::cout<< map[row][col]<<" , ";
        }
        std::cout<< std::endl;
    }
    
  
}
