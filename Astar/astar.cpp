#include "Astar/astar.h"
#include <exception>
#include <memory>
#include <queue>
#include <vector>
#include <iostream>
Astar::Astar(const std::vector<std::vector<int>>& map,int start_x,int start_y,int end_x,int end_y):map_(map),start_x_(start_x),start_y_(start_y),end_x_(end_x),end_y_(end_y),map_rows_(map.size()),map_cols_(map.at(0).size()),open_list_(std::priority_queue<Node>()),closed_list(std::vector<std::vector<bool>>(map_rows_,std::vector<bool>(map_cols_,false))){
    std::cout<<"init a star algorithm"<<std::endl;
    }
std::vector<std::shared_ptr<Node>> Astar::search(){
    auto start_node = std::make_shared<Node>(start_x_,start_y_);
    open_list_.emplace(*start_node);
    // closed_list.at(start_x_).at(start_y_) = true;
    std::vector<std::shared_ptr<Node>> path;
    std::cout<<"here"<<std::endl;
    while (!open_list_.empty()) {
        auto curr_node = open_list_.top();
        open_list_.pop();
        closed_list.at(curr_node.x_).at(curr_node.y_) = true;
        std::cout<<"x : "<<curr_node.x_<<" y :"<<curr_node.y_<<std::endl;
        if(curr_node.x_ == end_y_&&curr_node.y_ == end_y_){
            std::cout<<"find path"<<std::endl;
            while (curr_node.parent!=nullptr) {
                path.emplace_back(&curr_node);
                curr_node = *curr_node.parent;
            }
            return path;
        }else{
            std::cout<<"here 1"<<std::endl;
            int center_x = curr_node.x_;
            int center_y = curr_node.y_;

            for(int x = -1;x<=1;++x){
                for(int y = -1;y<=1;++y){
                    if(x==0&&y==0)continue;
                    int explored_x = center_x+x;
                    int explored_y = center_y+y;
                    if(explored_x<0||explored_x>map_rows_||explored_y<0||explored_y>map_cols_)continue;
                    if(map_[explored_x][explored_y] == 1||closed_list[explored_x][explored_y]) continue;//障碍物
                    auto temp_node = std::make_shared<Node>(explored_x,explored_y);
                    
                    // std::cout<<"explore path"<<std::endl;
                    temp_node->gn_+=1;
                    temp_node->gn_ = heuristic(explored_x, explored_y); //计算h值
                    temp_node->parent = &curr_node;
                    open_list_.emplace(*temp_node);
                }
            }

        }
    }
return std::vector<std::shared_ptr<Node>>();
}
