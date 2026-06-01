#include <math.h>
#include "../turtlec.h"

void levy(Turtle *turtle, float length, int depth){
     if(depth == 0){
         turtleForward(turtle, length);
         return;
     }

     turtleLeft(turtle, 45);
     levy(turtle, length / sqrt(2), depth - 1);

     turtleRight(turtle, 90);
     levy(turtle, length / sqrt(2), depth - 1);

     turtleLeft(turtle, 45);
}

void fractalTree(Turtle *turtle, int length, int depth, int angulo){
     if(depth == 0 || length < 5)
         return;
    
     if (depth > 5)
         turtleSetColor(turtle, 120, 70, 20);
     else
         turtleSetColor(turtle, 0, 200, 0);

     turtleForward(turtle, length);
     
     turtleLeft(turtle, angulo);
     fractalTree(turtle, length * 0.7, depth - 1, angulo);

     turtleRight(turtle, 2 * angulo);
     fractalTree(turtle, length * 0.7, depth - 1, angulo);

     turtleLeft(turtle, angulo);
     turtleBackward(turtle, length);
}

int main(void){
  TurtleApp *app = turtleAppCreate(800, 600, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtleSetColor(t, 57, 255, 20);
  turtleSetSpeed(t, 10.0f);

  turtlePenUp(t);
  turtleGoTo(t, 400, 550);
  turtlePenDown(t);
  
  //turtleLeft(t, 90);
  //fractalTree(t, 170, 6, 30);
  levy(t, 200, 8);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

