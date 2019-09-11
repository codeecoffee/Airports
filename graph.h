//Fellipe F Lopes
//CS163 - assingment 5
/* this file contains the function declarations,
   class and struct used in this program */

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//size of the array
const int DEF_SIZE = 5;

//vertex struct 
struct vertex
{
  char* cityname;
  struct node* head;
};

//node struct
struct node 
{
  char* road;
  vertex* adjacent;
  node* next;
};
//class to manage the table 
//each function is commented individually in the cpp file. 
class table
{
    public: 
            table();
//            table(int size);
            ~table();
            int insert_v(char city[]);
            int display_all();
            int add_edge(char citystart[], char cityend[], char road[]);

    private:
            vertex* adjacency_list;
            int list_size;
            int citycount;
            void delete_all(node*&ice);
            int display_all(node*ice);
};
