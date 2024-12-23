#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>  //for mathematic opeations
#include<math.h>   //for mathematic opeations

// s for circle radios
double s = .3;

//ازاحه المركب و الغيوم 
float  tx = 10, bx = 10;


void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // start with white color
    gluOrtho2D(-210, 210, -220, 310);     //setup a 2D orthographic projection

}

void circle(double x, double y)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); //center point
    for (int i = 0; i < 360; i++)
    {
        x = x + cos((i * 3.14) / 180) * s;
        y = y + sin((i * 3.14) / 180) * s;

        glVertex2d(x, y); 
    }
    glEnd();
}


void fence(int x)
{
    glBegin(GL_QUADS);
    glColor3ub(184, 134, 11);

    glVertex2i(190 - x, 130);
    glVertex2i(190 - x, 70);
    glVertex2i(187 - x, 70);
    glVertex2i(187 - x, 130);
    glVertex2i(190 - x, 130);

    glEnd();
}

void quads(int top_left, int top_right, int bottom_left, int bottom_right)
{
    glBegin(GL_QUADS);
    glVertex2i(top_left , top_right);  // النقطة العلوية اليسرى
    glVertex2i(bottom_left, top_right);   // النقطة العلوية اليمنى
    glVertex2i(bottom_left, bottom_right);   // النقطة السفلية اليمنى
    glVertex2i(top_left, bottom_right);  // النقطة السفلية اليسرى

    glEnd();
    /* Y(300)
        | ---------------------------- - | (-200, 300)
        |                             |
        |                             |
        |                             |
        |---------------------------- - | (200, 100)
        X(-200)                       X(200)     */
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);


    //-----------------------sky--------------------------------
    glColor3ub(135, 206, 250);//light blue
    // بدء رسم مضلع رباعي للسما
    quads(-200, 300, 200, 100);


    //-------------------circle-------------------------
    glColor3ub(255, 215, 0);//yellow
    circle(90, 250);


    //-------------------------------------------circle-------------------------------------------------
    glPushMatrix();
    glColor3ub(220, 220, 220); //light grey
    glTranslatef(tx, 0, 0);

    //first could
    circle(0, 250);
    circle(15, 245);
    circle(10, 240);
    circle(-2, 243);

    //second could
    circle(-80, 250);
    circle(-95, 245);
    circle(-90, 240);
    circle(-90, 243);
    circle(-75, 243);

    glPopMatrix();
    tx += .01;
    if (tx > 200)  
        tx = -200;


    //-----------------------field------------------------------
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);//green

    glVertex2i(-200, 100);
    glVertex2i(-100, 160);
    glVertex2i(0, 100);
    glVertex2i(50, 70);
    glVertex2i(100, 180);
    glVertex2i(200, 100);

    glColor3ub(255, 215, 0);//gold
    glVertex2i(200, -200);
    glVertex2i(-200, -200);
    glVertex2i(-200, 100);
    glEnd();

    

    // -----------------fence--------------------------
    // | | | | | | | | | first part of fence

    int x = 0;
    for (int i = 0; i < 39; i++)
    {
        fence(x);
        x += 10;
    }

    // second part of fence _ _ _ _ 

    glColor3ub(184, 134, 11);//brown color
    quads(-200, 100, 200, 95);
    quads(-200, 85, 200, 80);
    quads(-200, 120, 200, 115);

    //-------------------------------------TREE------------------------

    // first tree 
    glColor3ub(139, 69, 19); //brown 
    quads(-20, 200, -13, 140); // first tree trunk |

    glColor3ub(0, 100, 0);//green 
    circle(-30, 190); //first tree leaves
    circle(0, 190);
    circle(-10, 210);
    circle(-30, 175);
    circle(-0, 170);
   


    //second tree 
    glBegin(GL_POLYGON);  // second tree trunk first part
    glColor3ub(139, 69, 19); // brown
    glVertex2i(-170, 160);
    glVertex2i(-168, 120);
    glVertex2i(-178, 40);
    glVertex2i(-145, 40);
    glVertex2i(-153, 120);
    glVertex2i(-150, 160);
    glVertex2i(-170, 160);
    glEnd();


    glBegin(GL_POLYGON);  // second tree trunk second part
    glColor3ub(139, 69, 19);//brown
    glVertex2i(-153, 100);
    glVertex2i(-100, 200);
    glVertex2i(-95, 200);
    glVertex2i(-153, 80);
    glVertex2i(-153, 100);
    glEnd();

    glBegin(GL_POLYGON);  // second tree trunk third part
    glColor3ub(139, 69, 19);//brown
    glVertex2i(-170, 160);
    glVertex2i(-185, 210);
    glVertex2i(-190, 210);
    glVertex2i(-168, 90);
    glVertex2i(-170, 160);
    glEnd();


    glBegin(GL_POLYGON);  // second tree trunk fourth part
    glColor3ub(139, 69, 19);//brown
    glVertex2i(-160, 160);
    glVertex2i(-150, 210);
    glVertex2i(-140, 210);
    glVertex2i(-150, 160);
    glVertex2i(-160, 160);
    glEnd();

    glColor3ub(0, 128, 0);//green
    //second tree leaves
    
    //second part leaves
    circle(-95, 200);
    circle(-80, 180);
    circle(-110, 180);
    circle(-120, 200);

    //fourth part leaves
    circle(-150, 200);
    circle(-130, 180);
    circle(-125, 220);
    circle(-140, 230);

    //third part leaves
    circle(-190, 210);
    circle(-180, 200);
    circle(-175, 225);
    circle(-195, 190);


    // --------------------------------------- HOUSE one----------------------------
    glBegin(GL_POLYGON);  // first Part of the roof
    glColor3ub(128, 0, 0);//red
    glVertex2i(-58, 115);
    glVertex2i(-75, 145);

    glVertex2i(-115, 150);
    glVertex2i(-90, 100);
    glVertex2i(-62, 100);
    glVertex2i(-58, 115);
    glEnd();

    glBegin(GL_POLYGON);  // second Part of the roof
    glColor3ub(120, 0, 0);// red  
    glVertex2i(-115, 150);
    glVertex2i(-130, 100);
    glVertex2i(-120, 100);//point
    glVertex2i(-108, 137);//point
    glVertex2i(-115, 150);
    glEnd();


    glBegin(GL_POLYGON);  // first part of the wall
    glColor3ub(46, 139, 87);//light green 
    glVertex2i(-108, 137);
    glVertex2i(-120, 100);
    glVertex2i(-120, 45);
    glVertex2i(-90, 40);//point
    glVertex2i(-90, 100);
    glVertex2i(-108, 137);
    glEnd();


    glBegin(GL_POLYGON);  // second part of the wall
    glColor3ub(143, 188, 143);// 
    glVertex2i(-90, 40);
    glVertex2i(-60, 45);
    glVertex2i(-60, 100);
    glVertex2i(-90, 100);
    glEnd();


    glColor3ub(120, 0, 0);//red
    quads(-75, 80, -65, 40);//Door One

    glColor3ub(120, 0, 0);//red 
    quads(-110, 90, -100, 70); //window


    glBegin(GL_POLYGON);  // third Part (lower part 1)
    glColor3ub(0, 0, 0);//black
    glVertex2i(-90, 40);
    glVertex2i(-123, 45);
    glVertex2i(-123, 35);
    glVertex2i(-90, 30);
    glVertex2i(-90, 40);
    glEnd();


    glBegin(GL_POLYGON);  // third Part (lower part 2)
    glColor3ub(0, 0, 0);//black
    glVertex2i(-90, 40);
    glVertex2i(-55, 45);
    glVertex2i(-55, 35);
    glVertex2i(-90, 30);
    glVertex2i(-90, 40);
    glEnd();


    //-------------------------------------------  HOUSE  two  -------------------------------------------------
    glBegin(GL_POLYGON);  // First part of the roof
    glColor3ub(25, 25, 112);//midnight blue
    glVertex2i(-50, 140);
    glVertex2i(0, 149);
    glVertex2i(-12, 88);
    glVertex2i(-65, 89);
    glVertex2i(-50, 140);
    glEnd();





    glBegin(GL_POLYGON);  // first Part of the wall
    glColor3ub(70, 130, 180);// blue
    glVertex2i(-60, 90);
    glVertex2i(-60, 30);
    glVertex2i(-10, 25);
    glVertex2i(-10, 95);
    glEnd();

    glColor3ub(25, 25, 112);//midnight blue
    quads(-45, 70, -30, 27); //first door


    glBegin(GL_POLYGON);   //second part of the wall
    glColor3ub(95, 158, 160);//light blue
    glVertex2i(-10, 25);
    glVertex2i(18, 35);
    glVertex2i(18, 100);
    glVertex2i(0, 148);
    glVertex2i(-10, 100);
    glVertex2i(-10, 25);
    glEnd();

    glBegin(GL_POLYGON);// second part of the roof
    glColor3ub(25, 25, 112);//midnight blue
    glVertex2i(-1, 150);
    glVertex2i(20, 100);
    glVertex2i(17, 90);
    glVertex2i(-4, 140);
    glVertex2i(-1, 150);

    glEnd();


    glBegin(GL_POLYGON);  // door
    glColor3ub(25, 25, 112);//midnight blue
    glVertex2i(0, 70);
    glVertex2i(10, 73);
    glVertex2i(10, 32);
    glVertex2i(0, 29);
    glVertex2i(0, 70);
    glEnd();

    glBegin(GL_POLYGON);  // (lower part 1)
    glColor3ub(0, 0, 0);//black
    glVertex2i(-10, 25);
    glVertex2i(-10, 15);
    glVertex2i(20, 27);
    glVertex2i(20, 37);
    glVertex2i(-10, 25);
    glEnd();

    glBegin(GL_POLYGON);  // (lower part 2)
    glColor3ub(0, 0, 0);//black
    glVertex2i(-10, 25);
    glVertex2i(-62, 30);
    glVertex2i(-62, 20);
    glVertex2i(-10, 15);
    glVertex2i(-10, 25);
    glEnd();



    //------------------------------------------RIVER--------------------------------------------------  
    glBegin(GL_POLYGON);
    glColor3ub(30, 144, 255);//blue
    glVertex2i(-200, -50);
    glVertex2i(200, -30);

    glColor3ub(0, 0, 128);//light blue
    glVertex2i(200, -200);
    glVertex2i(-200, -200);
    glVertex2i(-200, -50);
    glEnd();

    glBegin(GL_POLYGON); // border
    glColor3ub(128, 128, 0);//orange
    glVertex2i(-200, -45);
    glVertex2i(200, -25);
    glVertex2i(200, -30);
    glVertex2i(-200, -50);
    glVertex2i(-200, -45);
    glEnd();

    
    //-------------------------------------------BOAT-------------------------------------------------
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glTranslatef(bx, 0, 0);
    glBegin(GL_POLYGON); //first part of boat base
    glVertex2i(-180, -70);
    glVertex2i(-165, -100);
    glVertex2i(-150, -120);
    glVertex2i(-150, -100);
    glVertex2i(-180, -70);
    glEnd();


    glBegin(GL_POLYGON);//second part of boat base
    glVertex2i(-150, -100);
    glVertex2i(-150, -120);
    glVertex2i(-120, -125);
    glVertex2i(-90, -120);
    glVertex2i(-85, -100);
    glVertex2i(-150, -100);
    glEnd();

    glBegin(GL_POLYGON);//third part of home base
    glVertex2i(-85, -100);
    glVertex2i(-90, -120);
    glVertex2i(-75, -105);
    glVertex2i(-60, -70);
    glVertex2i(-85, -100);
    glEnd();

    //third cloud
    glColor3ub(211, 211, 211);
    circle(-165, 260);
    circle(-185, 245);
    circle(-180, 240);
    circle(-152, 243);



    glBegin(GL_POLYGON); //first flag part
    glColor3ub(173, 216, 230);
    glVertex2i(-57, -40);
    glVertex2i(-50, -10);
    glVertex2i(-49, 10);
    glVertex2i(-50, 30);
    glVertex2i(-55, 45);
    glVertex2i(-63, 57);
    glVertex2i(-73, 68); // end
    glVertex2i(-105, 45);
    glVertex2i(-50, -10);
    glEnd();


    glBegin(GL_POLYGON); //second flag part
    glColor3ub(173, 216, 230);
    glVertex2i(-68, -70);
    glVertex2i(-57, -40);
    glVertex2i(-85, 10);
    glVertex2i(-68, -70);
    glEnd();


    glBegin(GL_POLYGON);//third flag part
    glColor3ub(173, 216, 230);
    glVertex2i(-85, -100);
    glVertex2i(-68, -70);
    glVertex2i(-80, -10);
    glVertex2i(-85, -100);
    glEnd();


    glColor3ub(139, 69, 19);
    quads(-88, 80, -86, -100);  // Boat stand
    glBegin(GL_POLYGON);
    glColor3f(0.55, 0.27, 0.0745);//wood color
    glVertex2i(-85, -100);
    glVertex2i(-87, -80);
    glVertex2i(-93, -62);
    glVertex2i(-97, -55);
    glVertex2i(-105, -50);
    glVertex2i(-120, -48);
    glVertex2i(-120, -100);
    glVertex2i(-85, -100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.55, 0.27, 0.0745);//wood color
    glVertex2i(-150, -100);
    glVertex2i(-148, -80);
    glVertex2i(-142, -62);
    glVertex2i(-138, -55);
    glVertex2i(-130, -50);
    glVertex2i(-115, -48);
    glVertex2i(-115, -100);
    glVertex2i(-150, -100);
    glEnd();

    
    glBegin(GL_LINE_STRIP); //حبل اللي ماسك الشراع
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-142, -62);
    glVertex2i(-73, 68);
    glVertex2i(-73, 63);
    glVertex2i(-142, -62);
    glVertex2i(-105, 45);
    glEnd();


    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-148, -80);
    glVertex2i(-87, -80);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-142, -62);
    glVertex2i(-93, -62);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-115, -48);
    glVertex2i(-115, -100);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-130, -50);
    glVertex2i(-130, -100);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-100, -52);
    glVertex2i(-100, -100);
    glEnd();

    glPopMatrix();
    bx += .03;
    if (bx > 270)
        bx = -180;


    glutPostRedisplay(); //اعادز رسم الاطار فس المشهد التالي
    glColor3ub(255, 255, 255);//white
    quads(-210, 310, -200, -210); //اطار ابيض جانبي
    quads(200, 310, 210, -210);
    

    glFlush();
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow(" village scenery ");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
