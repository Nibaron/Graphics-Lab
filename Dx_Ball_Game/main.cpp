#include "LOpenGL.h"

//Useful reference link
//http://cse.csusb.edu/tongyu/courses/cs420/notes/drawing.php

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 200;

//starting values for (bottom left) for the bricks
const int yCoordinateGlobal = -180;                        //hardcoded, since the axis will stay in the middle for every screen it will too
const int xCoordinateGlobal = -(SCREEN_WIDTH - 50);        //-590; -50 considering the walls too
const int xBrickLength = (SCREEN_WIDTH - 50) * 2 / 10;     //10 is the noble of bricks from left to right
const int yBrickHeight = ((SCREEN_HEIGHT - 50) - 180) / 5; //-50 for accounting the wall; -180 for bottom most brick height; 5 because no. of bricks will be 5 from bottom to up.

//Step size
const float STEP_SIZE = (SCREEN_WIDTH - 50) / 5;

//Ball radii
const float BALL_RADII = 15;

//paddle size
const int PADDLE_WIDTH = SCREEN_WIDTH / 5;
const int PADDLE_HEIGHT = 30;

//color modes
const int COLOR_MODE_CYAN = 0;
const int COLOR_MODE_MULTI = 1;

//bricks array

bool initGL();
/*
Pre Condition:
 -A valid OpenGL context
Post Condition:
 -Initializes matrices and clear color
 -Reports to console if there was an OpenGL error
 -Returns false if there was an error in initialization
Side Effects:
 -Projection matrix is set to identity matrix
 -Modelview matrix is set to identity matrix
 -Matrix mode is set to modelview
 -Clear color is set to black
*/

void update();
/*
Pre Condition:
 -None
Post Condition:
 -Does per frame logic
Side Effects:
 -None
*/

void render();
/*
Pre Condition:
 -A valid OpenGL context
 -Active modelview matrix
Post Condition:
 -Renders the scene
Side Effects:
 -Clears the color buffer
 -Swaps the front/back buffer
*/

void handleKeys(unsigned char key, int x, int y);
/*
Pre Condition:
 -None
Post Condition:
 -Toggles the color mode when the user presses q
 -Cycles through different projection scales when the user presses e
Side Effects:
 -If the user presses e, the matrix mode is set to projection
*/

int random_number_in_range(int start, int end);
/*
Utility Function to generate random numbers in a range
*/

void collisionDetection();
/*
fuction to detecte collsion of the ball with bricks
used in LUtil.cpp
*/

void DrawBricks();
/*
function used to draw bricks
*/

void welcomeDisplay();
/*
Opening Screen
*/

void endGameDisplay();
/*
Game over screen
*/
void runMainLoop(int val);
/*
Pre Condition:
 -Initialized freeGLUT
Post Condition:
 -Calls the main loop functions and sets itself to be called back in 1000 / SCREEN_FPS milliseconds
Side Effects:
 -Sets glutTimerFunc
*/

int main( int argc , char* args[] )
{
    //Initialize FreeGLUT
    glutInit(&argc,args);

    int game_state = 0;

    /*
    In this application, we're going to use a double buffered window.
    What this means is that we have two buffers, a front and back buffer.
    The front buffer is what the user sees. The back buffer is in memory.
    When we make rendering calls in a double buffered window, they are rendered to the back buffer.
    After we're done rendering what we want to show to the user,we swap the front buffer with
    the back buffer so the user sees what we originally rendered to the back buffer.
    Now in a single buffered window, everything is draw directly to the front buffer.
    This means the user will see geometry as it's being rendered, which means we may see unfinished
    rendering and tearing.
    */

    glutInitDisplayMode( GLUT_SINGLE );

    glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
    glutCreateWindow("Breakout");

    if(!initGL())
    {
        printf("Unable to initalize graphics library!\n");
        return 1;
    }


    //Set keyboard handler
    glutKeyboardFunc(handleKeys);


    glutDisplayFunc(welcomeDisplay);


    //Set main loop
    runMainLoop(game_state);

    //glutTimerFunc(5,runMainLoop,0);

    //Start GLUT main loop
    glutMainLoop();//This runs freeGLUT's internal main loop not our main loop

    return 0;
}
