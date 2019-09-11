//Fellipe F Lopes 
//CS163 - Assingment 5
/*
   This file includes all the func implementations.
  The data abstraction was inforced by having wrapper functions
  to be called in main */

#include "graph.h"
// default constructor 
table::table()
{
    list_size= DEF_SIZE;
    adjacency_list = new vertex[list_size];
    citycount= 0;
    for(int i=0; i<list_size; ++i)
    {
        adjacency_list[i].head= NULL;
    }
    
}
/*
table::table(int size)
{
    adjacency_list = new vertex[size];
    citycount= 0;
    for(int i=0; i<size; ++i)
    {
        adjacency_list[i].head= NULL;
    }
    
    list_size= size;
}
*/
//defualt destructor 
table::~table()
{
    for(int i=0; i<citycount; ++i)
    {
        //TODO delete name
        delete [] adjacency_list[i].cityname;
        //then traverse edge list and delete everything
        delete_all(adjacency_list[i].head);
    }

}
//delete all items in the vertex 
void table::delete_all(node*&ice)//displays chains
{
    if(!ice)
        return;

    display_all(ice->next);
    //TODO delete the name of road
    delete [] ice->road;
    //and then node itself
    delete ice;
    //set it to null
    ice= NULL;
}
//insert an item 
int table::insert_v(char city[])
{
    adjacency_list[citycount].cityname = new char[strlen(city)];
    strcpy(adjacency_list[citycount].cityname, city);
    citycount++;
    return citycount; 
}
// insert an edge
int table::add_edge(char citystart[], char cityend[], char road[])
{
    int startnum= -1;
    int endnum= -1;

    for(int i=0; i< citycount; ++i)
    {
        if(strcmp(adjacency_list[i].cityname, citystart)==0)
        {   
            startnum= i;
        }
        else if(strcmp(adjacency_list[i].cityname, cityend)==0)
        {   
            endnum= i;
        }
    }
    if(startnum != -1 && endnum !=-1)
    {
        node* head= new node;
        head->road= new char[strlen(road) + 1];
        strcpy(head->road, road);

        head->next = adjacency_list[startnum].head;
        adjacency_list[startnum].head= head;

        head->adjacent= &(adjacency_list[endnum]);
        return 1;

    }
    return 0;
}
int table::display_all() //displays city only
{
    for(int i=0; i<citycount; ++i)
    {
        //cout name
        cout <<"The city "<< adjacency_list[i].cityname;
        display_all(adjacency_list[i].head);
    }
}
//disdplay all chains
int table::display_all(node*ice)
{
    if(!ice)
        return 0;

    //cout stuff about road and adjacent city
    cout <<" is connected to " << ice->adjacent->cityname;    
    cout <<" by " <<  ice->road <<endl;

    display_all(ice->next);
    return 1;
}

