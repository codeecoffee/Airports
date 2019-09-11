//Fellipe F Lopes
//CS163 - Assingment 5
/*This is the client program. function calls are done by using 
  the obj table; */
#include "graph.h"


int main()
{
    table table;
    int decision = 0;
    
    do
    {
                cout<< '\t'<< '\t'<< "================================"     <<'\n'
                        << '\t'<< '\t'<< "       Main menu"                 <<'\n'
                        << '\t'<< '\t'<< "1 - Insert city"                  <<'\n'
                        << '\t'<< '\t'<< "2 - Insert road"                  <<'\n'
                        << '\t'<< '\t'<< "3 - Display all"                  <<'\n' 
                        << '\t'<< '\t'<< "4 - Exit"                         <<'\n'
                        << '\t'<< '\t'<< "==========================="      << endl;
                
                cin >> decision;
                cin.ignore(100, '\n');
                
                switch(decision)
                {
                    case 1://add an item 
                    {
                        
                        char static1[100];

                        cout<< '\t'<< "What is the city you are going to travel to?  " <<endl;
                        cin.get(static1, 100, '\n');                              
                        cin.ignore(100, '\n');

                        cout<< "Now you have: " <<table.insert_v(static1)<< " cities added" <<endl;

                        break;
                    }

                    case 2://insert road - vertex
                    {
                        char citystart[100];
                        char cityend[100];
                        char road[100];
                        cout<< '\t'<< "What is the city to start from? " <<endl;
                        cin.get(citystart, 100, '\n');
                        cin.ignore(100, '\n');
                        
                        cout<< '\t'<< "What is the ending city? " <<endl;
                        cin.get(cityend, 100, '\n');
                        cin.ignore(100, '\n');
 
                        cout<< '\t'<< "What is the highway that connects the two cities? " <<endl;
                        cin.get(road, 100, '\n');
                        cin.ignore(100, '\n');
                       
                        table.add_edge(citystart, cityend, road);                        

                        break;
                    }

                    case 3://view all items
                    {
                        if(table.display_all()==0)
                        {
                            cout<< "No items to display" <<endl;
                        }
                  
                        break;
                    }

                    case 4: //exit
                    {
                        break;
                    }
                }

    }while(decision!=4);

    return 0;
}

