#include "functions.h"

void displayGround(int **a, Point head, Point fruit, Point *tail, int tailLenght)
{
    int head_x = head.getX();
    int head_y = head.getY();
    int fruit_x = fruit.getX();
    int fruit_y = fruit.getY();


    cout<<endl<<endl;
    for(int i = 0; i < 10; i ++) cout<<"# ";
    cout<<endl;
    bool flag = false;

    for(int i = 1; i < 9; i ++)
    {
        for(int j = 0; j < 10; j ++)
        {
        flag = false;
            if(j == head_x && i ==head_y) cout<<" 0";
                else if(j == fruit_x && i == fruit_y) cout<<" P";
                    else if(j == 0) cout<<"#";
                        else if(j == 9) cout<<" #";
                            else 
                                {
                                 for(int k = 0 ; k < tailLenght; k ++)
                                     if(tail[k].getX() == j && tail[k].getY() == i)
                                          {
                                            flag = true;
                                             cout<<" o";
                                          }
                                     if(flag == false) cout<<"  ";
                                }
        }
        cout<<endl;
    }

    for(int i = 0; i < 10; i ++) cout<<"# ";
    cout<<endl;
}

bool checkEnd(Point head, Point *tail, int tailLenght)
{
    int head_x = head.getX();
    int head_y = head.getY();

    if(head_x < 1 || head_y < 1 || head_x > 8 || head_y > 8) return true;

    for(int i = 0; i < tailLenght; i++)
        if(head_x == tail[i].getX() && head_y == tail[i].getY()) return true;

    return false;
}