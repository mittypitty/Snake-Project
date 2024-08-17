#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "clui.h"                                          // Sara Shiri - Snake Project - SBU CE - 402243078
#include <vector>                                    // life gets hard sometimes, insead of being sad enjoy this game.
#include <string>
#include <chrono>
#include <thread>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;
using namespace std;

std::vector<std::string> players;

bool gameover;
int colorcode;
int c;
int speed = 0;
const int height = 20;
const int width = 20;
int prevx;
int prevy;
int prev2x, prev2y;
int prevx2;
int prevy2;
int prev2x2, prev2y2;
int x, y, score = 0, fruitx, fruity, bombx, bomby;
int x2, y2, score2 = 0; 
int tailx[100], taily[100];
int tailx2[100], taily2[100];
int tailnumber = 3;
int tailnumber2 = 3;
int scores[100];
int num;

string playername_1, playername_2;

enum eDirection {STOP = 0, UP, DOWN, LEFT, RIGHT};
eDirection dir, dir2;

const int KEY_CHAR1 = 224;
const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;



void Setup()
{
    gameover = false;
    dir = STOP;
    dir2 = STOP;
    x = width / 3;
    y = height / 3;
    x2 = 2 * width / 3;
    y2 = 2 * height / 3;
    fruitx = rand() % width;
    fruity = rand() % height;
    bombx = rand() % width;
    bomby = rand() % height;
    prevx2 = tailx2[0];
    prevy2 = taily2[0];
    tailx2[0] = x2;
    taily2[0] = y2;
    prevx = tailx[0];
    prevy = taily[0];
    tailx[0] = x;
    taily[0] = y;
    score = 0;
    score2 = 0;
    tailnumber = 3;
    tailnumber2 = 3; 

}


void swap(int &x, int &y) 
{
    int temp = x; 
    x = y; /* put y into x */
    y = temp; /* put x into y */
}

void bubble_sort(int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - 1 - i; j++) 
        {
            if (scores[j + 1] > scores[j]) 
            { 
                swap(scores[j+1] , scores[j]);
                swap(players[j + 1], players[j]);
               
            }
        }
    }
}


void Draw()
{
    system("CLS");

    for( int i = 0 ; i < width ; i++)
    {
        change_color_rgb(255, 255, 255);
        cout << "X";
    }
    cout << endl;

    for(int i = 0 ; i < height ; i++)
    {
       for(int j = 0 ; j < width ; j++)
       {
            if(j == 0 || j == width - 1)
            {
                change_color_rgb(255, 255, 255);
                cout << "X";
            }
            else if(i == y && j == x)
            {
                if(colorcode == 1)
                {
                    change_color_rgb(249, 76, 76);
                    cout << "O";
                }
                else if(colorcode == 2)
                {
                    change_color_rgb(76, 76, 249);
                    cout << "O";
                }
                else
                {
                    change_color_rgb(255,255,255);
                    cout << "O";
                }
            }
            else if(i == y2 && j == x2)
            {
                if(colorcode == 1)
                {
                    change_color_rgb(76, 76, 249);
                    cout << "@";
                }
                else if(colorcode == 2)
                {
                    change_color_rgb(249, 76, 76);
                    cout << "@";
                }
                else
                {
                    change_color_rgb(255,255,255);
                    cout << "@";
                }

            }
            else if(i == fruity && j == fruitx)
            {
                change_color_rgb(255, 255, 255);
                cout << "F";
            }
            else if(i == bomby && j == bombx)
            {
                change_color_rgb(255, 255, 255);
                cout << "B";
            }
            else
            {
                bool print = false;

                //First Snake
                for(int k = 0 ; k < tailnumber ; k++)
                {
                    if(i == taily[k] && j == tailx[k])
                    {
                        if(colorcode == 1)
                        {
                            change_color_rgb(249, 76, 76);
                            cout << "O";
                            print = true;
                        }
                        else if(colorcode == 2)
                        {
                            change_color_rgb(76, 76, 249);
                            cout << "O";
                            print = true;
                        }
                        else
                        {
                            change_color_rgb(255,255,255);
                            cout << "O";
                            print = true;
                        }
                    }
                }
                // ------------

                // Second Snake
                for(int k = 0 ; k < tailnumber2 ; k++)
                {
                    if(i == taily2[k] && j == tailx2[k])
                    {
                        if(colorcode == 1)
                        {
                            change_color_rgb(76, 76, 249);
                            cout << "@";
                            print = true;
                        }
                        else if(colorcode == 2)
                        {
                            change_color_rgb(249, 76, 76);
                            cout << "@";
                            print = true;
                        }
                        else
                        {
                            change_color_rgb(255,255,255);
                            cout << "@";
                            print = true;
                        }
                    }
                }
                // ------------

                if(!print)
                cout << " ";
            }
        }
        cout << endl;
    }
    
    for( int i = 0 ; i < width ; i++)
    {
        change_color_rgb(255,255,255);
        cout << "X";
    }
    cout << endl;

    cout << endl;
    change_color_rgb(132, 153, 161);
    cout << "First player score: " << score << endl;
    cout << "Second player score: " << score2 << endl;
    reset_color();
}

void Input()
{
    //Array keys for Snakes
    if(kbhit())
    {
        switch(getche())
        {
            case KEY_UP :
            dir2 = UP;
            break;
            case KEY_DOWN :
            dir2 = DOWN;
            break;
            case KEY_LEFT :
            dir2 = LEFT;
            break;
            case KEY_RIGHT :
            dir2 = RIGHT;
            break;
            case 'w':
            dir = UP;
            break;
            case 's':
            dir = DOWN;
            break;
            case 'd':
            dir = LEFT;
            break;
            case 'a':
            dir = RIGHT;
            break;
            default :
            break;

        }
    }
}

void Logic()
{
    // First Snake
    prevx = tailx[0];
    prevy = taily[0];
    tailx[0] = x;
    taily[0] = y;
    

    for( int i = 1 ; i < tailnumber ; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    // ------------

    // Second Snake 
    prevx2 = tailx2[0];
    prevy2 = taily2[0];
    tailx2[0] = x2;
    taily2[0] = y2;
    

    for( int i = 1 ; i < tailnumber2 ; i++)
    {
        prev2x2 = tailx2[i];
        prev2y2 = taily2[i];
        tailx2[i] = prevx2;
        taily2[i] = prevy2;
        prevx2 = prev2x2;
        prevy2 = prev2y2;
    }
    // ------------

    // First Snake
    switch(dir)
    {
        case UP:
        y--;
        break;
        case DOWN:
        y++;
        break;
        case RIGHT:
        x--;
        break;
        case LEFT:
        x++;
        break;
        default :
        break;
    }
    // ------------

    // Second snake
    switch(dir2)
    {
        case UP:
        y2--;
        break;
        case DOWN:
        y2++;
        break;
        case LEFT:
        x2--;
        break;
        case RIGHT:
        x2++;
        break;
        default :
        break;
    }
    // ------------

    // Both Snakes
    if(x < 0 || x > width || y < 0 || y > height || x2 < 0 || x2 > width || y2 < 0 || y2 > height)
    {
        gameover = true;
        change_color_rgb(255, 0, 0);
        cout << " GAME OVER ";
        if(score > score2)
        cout << playername_1 << " is Winner !! \n";
        else if( score2 > score)
        cout << playername_2 << "is Winner !! \n";
        else
        cout << "No One is Winner !! \n";
        Beep(523,500);
        reset_color();
        system("CLS");
        scores[num-2] = score;
        scores[num-1] = score2;
    }
    // ------------

    // First Snake 
    if(x == bombx && y == bomby)
    {
        gameover = true;
        change_color_rgb(255, 0, 0);
        cout << " GAME OVER ";
        if(score > score2)
        cout << playername_1 << " is Winner !! \n";
        else if( score2 > score)
        cout << playername_2 << "is Winner !! \n";
        else
        cout << "No One is Winner !! \n";
        Beep(523,500);
        reset_color();
        system("CLS");
        scores[num-2] = score;
        scores[num-1] = score2;
    }
    // ------------

    // Second Snake 
    if(x2 == bombx && y2 == bomby)
    {
        gameover = true;
        change_color_rgb(255, 0, 0);
        cout << " GAME OVER ";
        if(score > score2)
        cout << playername_1 << " is Winner !! \n";
        else if( score2 > score)
        cout << playername_2 << "is Winner !! \n";
        else
        cout << "No One is Winner !! \n";
        reset_color();
        system("CLS");
        scores[num-2] = score;
        scores[num-1] = score2;
    }
    // ------------

    // First Snake
    for(int i = 3 ; i <tailnumber ; i++)
    {
        if(x == tailx[i] && y == taily[i])
        {
            gameover = true;
            change_color_rgb(255, 0, 0);
            cout << " GAME OVER ";
            if(score > score2)
            cout << playername_1 << " is Winner !! \n";
            else if( score2 > score)
            cout << playername_2 << "is Winner !! \n";
            else
            cout << "No One is Winner !! \n";
            reset_color();
            Beep(523,500);
            system("CLS");
            scores[num-2] = score;
            scores[num-1] = score2;
        }
    }
    // ------------

    // First Snake hits Second one 
    for(int i = 0 ; i <tailnumber2 ; i++)
    {
        if(x == tailx2[i] && y == taily2[i])
        {
            gameover = true;
            change_color_rgb(255, 0, 0);
            cout << " GAME OVER ";
            if(score > score2)
            cout << playername_1 << " is Winner !! \n";
            else if( score2 > score)
            cout << playername_2 << "is Winner !! \n";
            else
            cout << "No One is Winner !! \n";
            reset_color();
            Beep(523,500);
            system("CLS");
            scores[num-2] = score;
            scores[num-1] = score2;
        }
    }
    // ---------------------------

    // Second Snake
    for(int i = 3 ; i <tailnumber2 ; i++)
    {
        if(x2 == tailx2[i] && y2 == taily2[i])
        {
            gameover = true;
            change_color_rgb(255, 0, 0);
            cout << " GAME OVER ";
            if(score > score2)
            cout << playername_1 << " is Winner !! \n";
            else if( score2 > score)
            cout << playername_2 << "is Winner !! \n";
            else
            cout << "No One is Winner !! \n";
            reset_color();
            Beep(523,500);
            system("CLS");
            scores[num-2] = score;
            scores[num-1] = score2;
        }
    }
    // ------------

    // Second Snake hits First one 
    for(int i = 0 ; i <tailnumber ; i++)
    {
        if(x2 == tailx[i] && y2 == taily[i])
        {
            gameover = true;
            change_color_rgb(255, 0, 0);
            cout << " GAME OVER ";
            if(score > score2)
            cout << playername_1 << " is Winner !! \n";
            else if( score2 > score)
            cout << playername_2 << "is Winner !! \n";
            else
            cout << "No One is Winner !! \n";
            reset_color();
            Beep(523,500);
            system("CLS");
            scores[num-2] = score;
            scores[num-1] = score2;
        }
    }
    // ---------------------------


    // First Snake
    if( x == fruitx && y == fruity)
    {
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        tailnumber++;
        Beep(523,500);
    }
    // ------------

    // Second Snake 
    if( x2 == fruitx && y2 == fruity)
    {
        score2 += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        tailnumber2++;
        Beep(523,500);
    }
    // ------------
}

void startting_game()
{


    Setup();
    while(!gameover)
    {
        
        if(speed == 0 || speed == 2)
        delay(40);
        else if(speed == 1)
        delay(400);
        else if(speed == 3)
        delay(5);


        Draw();
        Input();
        Logic();
        
    } 
    gameover = false;
}

void change_snake_color()
{   
    change_color_rgb(132, 153, 161);
    int choice2;
    cout << "Player One:" ;
    cin >>  playername_1;
    players.push_back(playername_1);
    cout << "\nPlayer Two:" ;
    cin >>  playername_2;
    players.push_back(playername_2);
    num +=2;
    cout << "1 - Player 1 --> Red \n Player 2 --> Blue \n" << "2 - Player1 --> Blue \n Player 2 --> Red \n" << " Enter your choice and press enter: ";
    
    cin >> choice2;
    
    switch (choice2)
    {
    case 1:
    colorcode = 1;
    startting_game();
    break;
    case 2:
    colorcode = 2;
    startting_game();
    break;
    // it will start after player press 1 or 2 button
    default:
    cout << "Not a Valid Choice. \n" << "Choose again.\n";
    break;
    }
    reset_color();
}

void game_speed()
{
    change_color_rgb(132, 153, 161);
    int choice4;
    cout << "Player One:" ;
    cin >>  playername_1;
    players.push_back(playername_1);
    cout << "\nPlayer Two:" ;
    cin >>  playername_2;
    players.push_back(playername_2);
    num +=2;
    cout << endl << " 1 - Slow.\n" << " 2 - Medium.\n" << " 3 - Fast.\n" << " Enter your choice and press enter: ";
    cin >> choice4;
    switch(choice4)
    {
        case 1:
        {
            speed = 1;
            startting_game();

        }
        break;
        case 2:
        {
            speed = 2;
            startting_game();
        }
        break;
        case 3:
        {
            speed = 3;
            startting_game();
        }
        break;
        default :
         cout << "Not a Valid Choice. \n" << "Choose again.\n";
        break;
    reset_color();
    }
}

void game_menu()
{

    int choice;
    do
    {
        change_color_rgb(223, 173, 245);
        cout << endl << " 1 - Start the game.\n\n" << " 2 - Score.\n\n" << " 3 - Speed.\n\n" << " 4 - Color.\n\n" << " 5 - Exit.\n\n" << " Enter your choice and press enter: ";
        cin >> choice;
        
            switch (choice)
            {
                case 1:
                // getting players names 
                {
                    cout << "Player One:" ;
                    cin >>  playername_1;
                    players.push_back(playername_1);
                    cout << "\nPlayer Two:" ;
                    cin >>  playername_2;
                    players.push_back(playername_2);
                    num +=2;
                }
                startting_game();
                break;
                case 2:
                {
                    if(num == 0)
                    {
                        system("CLS");
                        cout <<"\n\n There is no players!.\n";
                        game_menu();
                    }
                    bubble_sort(num);
                    for (size_t i = 0; i < players.size(); ++i) 
                    {
                        std::cout  << i + 1 << ". " << players[i] <<" : "<< scores[i] << std::endl;
                    }
                    sleep_until(system_clock::now() + seconds(5));
                    system("CLS");
                    game_menu();
                }
                break;
                case 3:
                game_speed();
                break;
                case 4:
                change_snake_color();
                break;
                case 5:
                c = -1;
                cout << "End of Program.\n";
                break;
                default:
                cout << "Not a Valid Choice. \n" << "Choose again.\n";
                break;
                
            }
        reset_color();
    } while(choice != 5);

}

int main()
{
    change_color_rgb(223, 173, 245);
    cout << "\n                             SNAKE GAME  " ;
    cout << endl;

    c = 1;
    while (c > 0)
     game_menu();

    return 0;
}
