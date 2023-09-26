#include "functions.h"

int main()
{

    int **a;
    Point head(5,5);
    char c = '\0';
    bool end = false;
    int score = 0;
    int fruit_x = rand()%10, fruit_y = rand()%10;
    Point tail[100];
    int tailLenght=0;

    while(fruit_x == 0 || fruit_x == 9) fruit_x = rand()%10;
    while(fruit_y == 0 || fruit_y == 9) fruit_y = rand()%10;

    Point fruit(fruit_x, fruit_y);

    a = new int*[10];

    for(int i = 0 ; i < 10; i ++)
        a[i] = new int[10];

    while(!end)
    {

    system("cls");
    displayGround(a, head, fruit, tail, tailLenght);
    cout<<endl<<"Position: ("<<head.getX()<<","<<head.getY()<<")"<<endl;
    cout<<endl<<"Score: "<<score;

    c = getch();

    for(int i = tailLenght; i > 0; i --)
    {
        tail[i].setX('n', tail[i-1].getX());
        tail[i].setY('n', tail[i-1].getY());
    }

    if(tailLenght > 0)
    {
    tail[0].setX('n', head.getX());
    tail[0].setY('n', head.getY());
    }    

    switch(c)
    {
        case 'd': 
            head.setX('a',0);
            break;
        
        case 'a': 
            head.setX('d',0);
            break;

        case 's': 
            head.setY('a',0);
            break;
        
        case 'w': 
            head.setY('d',0);
            break;
    }


    if(fruit.getX() == head.getX() && fruit.getY() == head.getY())
    {
    
    fruit_x = rand()%10;
    fruit_y = rand()%10;

    while(fruit_x == 0 || fruit_x == 9) fruit_x = rand()%10;
    while(fruit_y == 0 || fruit_y == 9) fruit_y = rand()%10;

    fruit.setX('n',fruit_x);
    fruit.setY('n',fruit_y);
    score ++;

    tailLenght++;

    }

    end = checkEnd(head, tail, tailLenght);

    }

    for(int i = 0; i < 10; i ++)
        delete []a[i];

    delete []a;

    cout<<endl<<"Game over!";

    return 0;
}