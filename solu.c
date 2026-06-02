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
    
     turtleSetColor(turtle,255 - 60 * depth, 0 ,60 * depth);

     turtleForward(turtle, length);
     
     turtleLeft(turtle, angulo);
     fractalTree(turtle, length * 0.62, depth - 1, angulo);

     turtleRight(turtle, angulo);
     fractalTree(turtle, length * 0.7, depth - 1, angulo);

     turtleRight(turtle, angulo);
     fractalTree(turtle, length * 0.88, depth - 1, angulo);

     turtleLeft(turtle, angulo);
     
     turtlePenUp(turtle);
     turtleBackward(turtle, length);
     turtlePenDown(turtle);
     
}

int main(void){
  TurtleApp *app = turtleAppCreate(800, 600, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtleSetColor(t, 57, 255, 20);
  turtleSetSpeed(t, 30.0f);

  turtlePenUp(t);
  turtleGoTo(t, 400, 550);
  turtlePenDown(t);
  
  turtleLeft(t, 90);
  fractalTree(t, 180, 5, 45);
  //levy(t, 200, 8);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

