#include "../turtlec.h"

void fractalTree(Turtle *turtle, int length, int depth){
     if(depth == 0 || length < 5)
         return;
     
     turtleForward(turtle, length);
     
     turtleLeft(turtle, 30);
     fractalTree(turtle, length * 0.7, depth - 1);

     turtleRight(turtle, 60);
     fractalTree(turtle, length * 0.7, depth - 1);

     turtleLeft(turtle, 30);
     turtleBackward(turtle, length);
}

int main(void){
  TurtleApp *app = turtleAppCreate(800, 600, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);

  turtlePenUp(t);
  turtleGoTo(t, 400, 550);
  turtlePenDown(t);
  
  turtleLeft(t, 90);
  fractalTree(t, 100, 5);
  
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

