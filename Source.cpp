#include<iostream>
#include"mygraphics.h"
#include<windows.h>
//#include "Cars.h"

int globalTime = 0;
int g_time = 0;
int clk = 0;

using namespace std;

class road {
public:

    void generateRoad()
    {
        // road bg grey color 
        drawRectangle(200, 100, 600, 400, 126, 126, 126, 126, 126, 126);



        // green path left side upper 
        drawRectangle(200, 100, 350, 200, 68, 252, 141, 68, 252, 141);
        // green path left side down 
        drawRectangle(200, 300, 350, 400, 68, 252, 141, 68, 252, 141);

        // green path right side up 
        drawRectangle(450, 100, 600, 200, 68, 252, 141, 68, 252, 141);
        // green path right side down 
        drawRectangle(450, 300, 600, 400, 68, 252, 141, 68, 252, 141);


        // ROAD ARROWS 
        // left side arrow
        drawLine(290, 275, 330, 275, 255);
        drawLine(310, 265, 330, 275, 255);
        drawLine(310, 285, 330, 275, 255);

        // right side arrow 
        drawLine(470, 225, 510, 225, 255);
        drawLine(490, 215, 470, 225, 255);
        drawLine(490, 235, 470, 225, 255);

        // Up side arrow 
        drawLine(425, 140, 425, 180, 255);
        drawLine(415, 155, 425, 180, 255);
        drawLine(435, 155, 425, 180, 255);

        // DOWN ROAD ARROW 
        drawLine(375, 310, 375, 350, 255);
        drawLine(365, 330, 375, 310, 255);

        drawLine(400, 100, 400, 180, 255); // vertical line upper road mark  
        drawLine(400, 320, 400, 400, 255); // vertical line lower road mark

        drawLine(350, 100, 350, 200, 255); // vertical line left  left side  upper
        drawLine(450, 100, 450, 200, 255); // vertical line right right side upper  
        drawLine(450, 300, 450, 400, 255); // vertical line right side down  
        drawLine(350, 300, 350, 400, 255); // vertical line left side down  

        drawLine(200, 250, 310, 250, 255); // horizontal line left side road mark
        drawLine(460, 250, 600, 250, 255); // horizontal line right side road mark

        drawLine(200, 200, 350, 200, 255); // horizontal line up left side
        drawLine(450, 200, 600, 200, 255); // horizontal line up right side
        drawLine(200, 300, 350, 300, 255); // horizontal line down left side  
        drawLine(450, 300, 600, 300, 255); // horizontal line down right side

       // Traffic lines

        drawLine(330, 170, 330, 200, 0); // left upper side

        drawLine(330, 300, 330, 330, 0); // left lower side

        drawLine(467, 170, 467, 200, 0); // right upper side

        drawLine(467, 300, 467, 330, 0); // right lower side





    }
};


class trafficlight : public road {
public:

    int t;

    trafficlight() {
        t = 0;
    }

    void generategreenlight(int color,int side,int position) {

        //1.Green  
        //2.Yellow
        //3.Red

        //1.Left side
        //2.Right side
        
        //1.Up 
        //2.Down

        //For upper leftside
        if (color == 1 && side == 1 && position == 1) {
          drawEllipse(338, 155, 322, 170, 255, 255, 255, 0, 128, 0); // GREEN left upper side
        }
        if (color == 2 && side == 1 && position == 1) {
          drawEllipse(338, 155, 322, 170, 255, 255, 255, 255, 255, 0); // YELLOW
        }
        if (color == 3 && side == 1 && position == 1) {
          drawEllipse(338, 155, 322, 170, 255, 255, 255, 255, 0, 0); // RED
        }

        //For upper rightside
        if (color == 1 && side == 2 && position == 1) {
            drawEllipse(474, 155, 458, 170, 255, 255, 255, 0, 128, 0); // GREEN right upper side
        }
        if (color == 2 && side == 2 && position == 1) {
            drawEllipse(474, 155, 458, 170, 255, 255, 255, 255, 255, 0); // YELLOW
        }
        if (color == 3 && side == 2 && position == 1) {
            drawEllipse(474, 155, 458, 170, 255, 255, 255, 255, 0, 0); // RED 
        }

        //For lower leftside
        if (color == 1 && side == 1 && position == 2) {
            drawEllipse(338, 345, 322, 330, 255, 255, 255, 0, 128, 0); // GREEN left lower side
        }
        if (color == 2 && side == 1 && position == 2) {
            drawEllipse(338, 345, 322, 330, 255, 255, 255, 255, 255, 0); // YELLOW
        }
        if (color == 3 && side == 1 && position == 2) {
            drawEllipse(338, 345, 322, 330, 255, 255, 255, 255, 0, 0); // RED
        }

        //For right lowerside
        if (color == 1 && side == 2 && position == 2) {
            drawEllipse(474, 345, 458, 330, 255, 255, 255, 0, 128, 0); // GREEN right lower side
        }
        if (color == 2 && side == 2 && position == 2) {
            drawEllipse(474, 345, 458, 330, 255, 255, 255, 255, 255, 0); // YELLOW 
        }
        if (color == 3 && side == 2 && position == 2) {
            drawEllipse(474, 345, 458, 330, 255, 255, 255, 255, 0, 0); // RED 
        }
        
    }

    ~trafficlight() {

    }
    
};

class vehicle :public trafficlight {
public:
    int size;
    vehicle(int s) {
        size = s;
    }

    ~vehicle() {

    }

 
};


class intersection : public trafficlight {
public:
      int selection;
      int strategy;

      intersection() {

      }

    intersection(const int s, const int stra) {
        selection = s;
        strategy = stra;
    }

    virtual void generatecarSTRATEGY1(const int selection, const int strategy) = 0; 
    virtual void generatecarSTRATEGY2(const int selection, const int strategy) =0;

    ~intersection() {

       }
};

class strategyies : public intersection {
public:

    void generatecarSTRATEGY1(const int selection, const int strategy) {

        if (selection == 1 && strategy == 1)
        {
            int t1 = 0, t2 = 0;

            // if selection is 1 then one car will be generated on every road 
            // strategy 1 means two signals will be green at a time 	
            int temp = 1;
            int t_1 = 0;
            int x_c1, x_c2, y_c1, y_c2;

            x_c1 = 240;  // car coming from left 
            x_c2 = 0;

            y_c1 = 0; // car coming from top 
            y_c2 = 0; // car coming from bottom 


            for (int i = 0; x_c1 < 350; i += 3)
            {
                {   // traffic lights
                    generategreenlight(1, 1, 1);
                    generategreenlight(1, 2, 1);
                    generategreenlight(1, 1, 2);
                    generategreenlight(1, 2, 2);
                }

                cls();
                generateRoad();
                //  generateTrafficlight();
                    // car coming from the left side 
                drawRectangle(200 + i, 260, x_c1 = 240 + i, 290, 244, 242, 1, 244, 242, 1);  // left , top , right , bottom , rectangle( car ) // car coming from the left side 
                // car coming from the  right side 
                drawRectangle(600 - i, 210, x_c2 = 560 - i, 240, 244, 242, 1, 244, 242, 1);

                if (y_c1 < 190 && y_c2 < 400)
                {
                    //	generatecarVertical(1,1,1,1,1) ;  
                     // car coming from the top 
                    drawRectangle(410, 100 + temp, 440, y_c1 = 140 + temp, 244, 242, 1, 244, 242, 1);
                    drawRectangle(360, 350 - temp, 390, y_c2 = 400 - temp, 244, 242, 1, 244, 242, 1); // second car
                    temp += 3;
                }
                else if (y_c1 > 190)
                {
                    drawRectangle(410, 160, 440, y_c1 = 200, 244, 242, 1, 244, 242, 1);
                    drawRectangle(360, 300, 390, y_c2 = 350, 244, 242, 1, 244, 242, 1); // second car	
                }
                delay(0);

            }
            globalTime = 0;
            for (int i = 0; i < 400; i++)
            {

                cls();
                generateRoad();
                //   generateTrafficlight();
                drawRectangle(410, 160, 440, y_c1 = 200, 244, 242, 1, 244, 242, 1); // top car 
                drawRectangle(360, 300, 390, y_c2 = 350, 244, 242, 1, 244, 242, 1); // down car 
                drawRectangle(x_c1 - 40, 260, x_c1, 290, 244, 242, 1, 244, 242, 1);  // left , top , right , bottom , rectangle( car ) // car coming from the left side 
                // car coming from the  right side 
                drawRectangle(x_c2 + 40, 210, x_c2, 240, 244, 242, 1, 244, 242, 1);

                clk = 0;
                while (clk < 15)
                {
                    {   // traffic lights
                        generategreenlight(3, 1, 1);
                        generategreenlight(3, 2, 1);
                        generategreenlight(3, 1, 2);
                        generategreenlight(3, 2, 2);
                    }

                    globalTime++;
                    clk++;
                    delay(150);
                }

                for (int clOk = 0; clOk <= 15; clOk++) // for red signal
                {
                    {   // traffic lights
                        generategreenlight(2, 1, 1); // YELLOW left upper side
                        generategreenlight(3, 2, 1);; // Red right upper side
                        generategreenlight(3, 1, 2); // Red left lower side
                        generategreenlight(2, 2, 2); // YELLOW right lower side
                    }
                    drawRectangle(410, 160, 440, y_c1 = 200, 244, 242, 1, 244, 242, 1); // top car 
                    drawRectangle(360, 300, 390, y_c2 = 350, 244, 242, 1, 244, 242, 1); // down car 

                    globalTime++;
                    delay(150);
                }

                for (int xy = 0; x_c1 < 600; xy++)
                {

                    {   // traffic lights
                        generategreenlight(1, 1, 1); // GREEN left upper side
                        generategreenlight(3, 2, 1); // RED right upper side
                        generategreenlight(3, 1, 2); // RED left lower side
                        generategreenlight(1, 2, 2); // GREEN right lower side
                    }


                    cls();
                    generateRoad();
                    // generateTrafficlight();
                    drawRectangle(410, 160, 440, y_c1 = 200, 244, 242, 1, 244, 242, 1); // top car 
                    drawRectangle(360, 300, 390, y_c2 = 350, 244, 242, 1, 244, 242, 1); // down car

                    delay(0);

                    if (x_c1 < 598) {
                        drawRectangle(x_c1 - 40, 260, x_c1 += 4, 290, 244, 242, 1, 244, 242, 1);  // left , top , right , bottom , rectangle( car ) // car coming from the left side 
            // car coming from the  right side 
                        drawRectangle(x_c2 + 40, 210, x_c2 -= 4, 240, 244, 242, 1, 244, 242, 1);
                    }
                    else {
                        break;
                    }

                }

                for (int clOk = 0; clOk <= 15; clOk++) // for red signal
                {
                    {   // traffic lights
                        generategreenlight(1, 1, 1); // GREEN left upper side
                        generategreenlight(2, 2, 1);; // YELLOW right upper side
                        generategreenlight(2, 1, 2); // YELLOW left lower side
                        generategreenlight(1, 2, 2); // GREEN right lower side
                    }
                    drawRectangle(410, 160, 440, y_c1 = 200, 244, 242, 1, 244, 242, 1); // top car 
                    drawRectangle(360, 300, 390, y_c2 = 350, 244, 242, 1, 244, 242, 1); // down car 

                    globalTime++;
                    delay(150);
                }

                for (int xz = 0; y_c1 < 400; xz++)
                {

                    {
                        // Traffic lights
                        generategreenlight(1, 1, 1);
                        generategreenlight(1, 2, 1);
                        generategreenlight(1, 1, 2);
                        generategreenlight(1, 2, 2);
                    }

                    cls();
                    generateRoad();
                    //if (x_c1 < 600)
                    //{
                    //    drawRectangle(x_c1 - 40, 260, x_c1 += 3, 290, 244, 242, 1, 244, 242, 1);  // left , top , right , bottom , rectangle( car ) // car coming from the left side 
                    //// car coming from the  right side 
                    //    drawRectangle(x_c2 + 40, 210, x_c2 -= 3, 240, 244, 242, 1, 244, 242, 1);

                    //}

                    // drawRectangle(x_c1 - 40, 260, x_c1, 290, 244, 242, 1, 244, 242, 1);  // left , top , right , bottom , rectangle( car ) // car coming from the left side 
                     // car coming from the  right side 
                  //   drawRectangle(x_c2 + 40, 210, x_c2, 240, 244, 242, 1, 244, 242, 1);

                    drawRectangle(410, y_c1 - 40, 440, y_c1 += 3, 244, 242, 1, 244, 242, 1); // top car 
                    drawRectangle(360, y_c2 - 50, 390, y_c2 -= 3, 244, 242, 1, 244, 242, 1); // down car


                }
                if (clk < 16)
                {
                    drawRectangle(x_c1 - 40, 260, x_c1, 290, 244, 242, 1, 244, 242, 1);  // left , top , right , bottom , rectangle( car ) // car coming from the left side 
                    // car coming from the  right side 
                    drawRectangle(x_c2 + 40, 210, x_c2, 240, 244, 242, 1, 244, 242, 1);
                    //   drawRectangle(410, y_c1 - 40, 440, y_c1, 244, 242, 1, 244, 242, 1); // top car 
                    //   drawRectangle(360, y_c2 - 50, 390, y_c2, 244, 242, 1, 244, 242, 1); // down car
                    clk++;

                    break;
                }



            }

            //     cout << "Selection : " << selection << endl ; 
        }
        else if (selection == 2 && strategy == 1)
        {
        cls(); // to clear the screen 
        generateRoad(); // to generate the road 

        // First loop will move all the cars to the intersection point 
        int x_c1 = 0; // to get the x location of the car 1 ( from left side ) // horizontal 
        int x_c2 = 0; // 
        int temp_loc = 0;
        int y_c1 = 0; // top car 1
        int y_c2 = 0;  // top car 2 
        int y_c3 = 400; // bottom car 1
        int y_c4 = 400; // bottom car 2 
        int x_c3 = 600;  // right side car ( 1 ) 
        int x_c4 = 600;

        int temp_loc2 = 0;
        int temp_loc3 = 0;
        int temp_loc4 = 0;
        int temp_loc5 = 0;
        int temp_loc6 = 0;
        int temp_loc7 = 0; // for right side car ( 1 ) 
        int temp_loc8 = 0; // for right side car ( 2 ) 



        for (int i = 0; i < 200; i++)
        {
            cls(); // to clear the screen 
            generateRoad(); // to generate the road 


            {//traffic lights
                generategreenlight(1, 1, 1);
                generategreenlight(1, 2, 1);
                generategreenlight(1, 1, 2);
                generategreenlight(1, 2, 2);
            }


            if (x_c1 < 350) {


                drawRectangle(200 + i, 260, x_c1 = 240 + i, 290, 244, 242, 1, 244, 242, 1); // car(1) coming from the left 
            //	cout << x_c2 ; 


            }
            else {
                generategreenlight(3, 1, 1); // RED left upper side
            }


            if (y_c1 < 200)
            {
                drawRectangle(410, 100 + temp_loc2, 440, y_c1 = 140 + temp_loc2, 244, 242, 1, 244, 242, 1); // car(1) coming from the top 
                temp_loc2++;

            }
            else {
                generategreenlight(3, 2, 1); // RED right upper side
            }


            if (y_c1 > 190 && y_c2 < 150)
            {
                drawRectangle(410, 100 + temp_loc3, 440, y_c2 = 140 + temp_loc3, 244, 242, 1, 244, 242, 1); // car(2) coming from the top 	
                temp_loc3++;
            }


            if (x_c1 > 290 && x_c2 < 300)
            {

                drawRectangle(200 + temp_loc, 260, x_c2 = 240 + temp_loc, 290, 244, 242, 1, 244, 242, 1); // car(2) coming from the left 					
                temp_loc++;
            }



            // cars coming from the bottom 

            if (y_c3 > 350)
            {
                drawRectangle(360, 350 - temp_loc4, 390, y_c3 = 400 - temp_loc4, 244, 242, 1, 244, 242, 1); // bottom car 1 
                temp_loc4++;
            }
            else {
                generategreenlight(3, 1, 2); // RED left lower side
            }
            if (y_c3 < 360)
            {
                drawRectangle(360, y_c4 = y_c3 + 10, 390, y_c4 + 38, 244, 242, 1, 244, 242, 1);
                temp_loc5++;
            }

            if (x_c3 > 460)
            {
                drawRectangle(x_c3 = 560 - temp_loc7, 210, 600 - temp_loc7, 240, 255, 0, 0);  // car(1) right side 
                temp_loc7++;
            }
            else {
                generategreenlight(3, 2, 2); // RED right lower side
            }

            if (x_c3 < 500 && ((x_c4)-(600 - temp_loc7)) > 10)
            {
                drawRectangle(x_c4 = 560 - temp_loc8, 210, 600 - temp_loc8, 240, 255, 0, 0); // car ( 2 ) right side 
                temp_loc8++;
            }




            // fixed positions of the cars  
            drawRectangle(x_c1 - 40, 260, x_c1, 290, 244, 242, 1, 244, 242, 1); // car(1) coming from the left 
            drawRectangle(x_c2 - 40, 260, x_c2, 290, 244, 242, 1, 244, 242, 1); // car(2) coming from the left 					
            drawRectangle(410, y_c1 - 40, 440, y_c1, 244, 242, 1, 244, 242, 1); // car(1) coming from the top 
            drawRectangle(410, y_c2 - 40, 440, y_c2, 244, 242, 1, 244, 242, 1); // car(2) coming from the top 
            drawRectangle(360, y_c3 - 50, 390, y_c3, 244, 242, 1, 244, 242, 1); // car(1) coming from the bottom
            drawRectangle(360, y_c4 - 10, 390, y_c4 - 38, 244, 242, 1, 244, 242, 1);
            drawRectangle(x_c3, 210, 600 - temp_loc7, 240, 255, 0, 0);  // right side car ( 1) 
            drawRectangle(x_c4, 210, 600 - temp_loc8, 240, 255, 0, 0); // right side car ( 2 ) 
     //  	delay(10); 
        }

        for (int clik = 0; clk <= 15; clk++) // for red signal
        {
            {   // traffic lights
                generategreenlight(3, 1, 1);
                generategreenlight(3, 2, 1);
                generategreenlight(3, 1, 2);
                generategreenlight(3, 2, 2);
            }

            globalTime++;
            delay(150);
        }

        // to move the car to the end point 
        //	temp_loc7 = 0 ;
        int temp_loc7_1 = 0;
        int temp_loc8_1 = 0;
        int temp_x_c_1 = 0;
        int temp_x_c_2 = 0;
        // for right side cars and left side cars 

        for (int clk = 0; clk <= 10; clk++)// for yellow signal
        {
            {   // traffic lights
                generategreenlight(2, 1, 1); // Yellow left upper side
                generategreenlight(3, 2, 1); // RED right upper side
                generategreenlight(3, 1, 2); // RED left lower side
                generategreenlight(2, 2, 2); // Yellow right lower side
            }

            globalTime++;
            delay(150);
        }



        for (int i = 0; i < 400; i++)
        {

            {//traffic lights
                generategreenlight(1, 1, 1); // GREEN left upper side
                generategreenlight(1, 2, 2); // GREEN right lower side
                generategreenlight(3, 2, 1); // RED right upper side
                generategreenlight(3, 1, 2); // RED left lower side
            }

            cls();
            generateRoad();
            if (x_c3 > 230) {
                drawRectangle(x_c3 - 40, 210, x_c3 -= 3, 240, 255, 0, 0);  // right side car ( 1) 
            }

            if (x_c4 > 230) {
                drawRectangle(x_c4 - 40, 210, x_c4 -= 3, 240, 255, 0, 0); // right side car(2)
            }

            if (x_c1 < 580) {
                drawRectangle(x_c1 + 40, 260, x_c1 += 3, 290, 244, 242, 1, 244, 242, 1); // car(1) coming from left
            }
            if (x_c2 < 580) {
                drawRectangle(x_c2 + 40, 260, x_c2 += 3, 290, 244, 242, 1, 244, 242, 1); // car(2) coming from left
            }
            else {
                break;
            }




            drawRectangle(410, y_c1 - 40, 440, y_c1, 244, 242, 1, 244, 242, 1); // car(1) coming from the top 
            drawRectangle(410, y_c2 - 40, 440, y_c2, 244, 242, 1, 244, 242, 1); // car(2) coming from the top 
            drawRectangle(360, y_c3 - 40, 390, y_c3, 244, 242, 1, 244, 242, 1); // car(1) coming from the bottom
           /* drawRectangle(360, 397, 390, 360 , 244, 242, 1, 244, 242, 1);*/
            drawRectangle(360, y_c4 + 40, 390, y_c4, 244, 242, 1, 244, 242, 1); // car(2) coming from the bottom

        }

        delay(10);

        for (int clk = 0; clk <= 10; clk++)// for yellow signal
        {
            {   // traffic lights
                generategreenlight(1, 1, 1); // Green left upper side
                generategreenlight(2, 2, 1);; // Yellow right upper side
                generategreenlight(2, 1, 2); // Yellow left lower side
                generategreenlight(1, 2, 2); // Green right lower side
            }

            {
                //printing cars;
                drawRectangle(410, y_c1 - 40, 440, y_c1, 244, 242, 1, 244, 242, 1); // car(1) coming from the top 
                drawRectangle(410, y_c2 - 40, 440, y_c2, 244, 242, 1, 244, 242, 1); // car(2) coming from the top 
                drawRectangle(360, y_c3 - 40, 390, y_c3, 244, 242, 1, 244, 242, 1); // car(1) coming from the bottom
               /* drawRectangle(360, 397, 390, 360 , 244, 242, 1, 244, 242, 1);*/
                drawRectangle(360, y_c4 + 40, 390, y_c4, 244, 242, 1, 244, 242, 1); // car(2) coming from the bottom
            }

            globalTime++;
            delay(150);
        }


        for (int i = 0; i < 400; i++)
        {

            {
                //traffic lights
                generategreenlight(1, 1, 1); // Green left upper side
                generategreenlight(1, 2, 1);; // Green right upper side
                generategreenlight(1, 1, 2); // Green left lower side
                generategreenlight(1, 2, 2); // Green right lower side
            }

            cls();
            generateRoad();
            if (y_c3 > 120) {
                drawRectangle(360, y_c3 - 40, 390, y_c3 -= 3, 255, 0, 0);  // right side car ( 1) 
            }

            if (y_c4 > 110) {
                drawRectangle(360, y_c4 + 40, 390, y_c4 -= 3, 255, 0, 0); // right side car(2)
            }
            else {
                break;
            }

            if (y_c1 < 380) {
                drawRectangle(410, y_c1 + 40, 440, y_c1 += 3, 244, 242, 1, 244, 242, 1); // car(1) coming from left
            }

            if (y_c2 < 380) {
                drawRectangle(410, y_c2 + 40, 440, y_c2 += 3, 244, 242, 1, 244, 242, 1); // car(1) coming from left
            }

        }

        delay(10);

        }


    }

    void generatecarSTRATEGY2(const int selection, const int strategy) {
        if (selection == 2 && strategy == 2)
        {
        cls(); // to clear the screen 
        generateRoad(); // to generate the road 

        // First loop will move all the cars to the intersection point 
        int x_c1 = 0; // to get the x location of the car 1 ( from left side ) // horizontal 
        int x_c2 = 0; // 
        int temp_loc = 0;
        int y_c1 = 0; // top car 1
        int y_c2 = 0;  // top car 2 
        int y_c3 = 400; // bottom car 1
        int y_c4 = 400; // bottom car 2 
        int x_c3 = 600;  // right side car ( 1 ) 
        int x_c4 = 600;

        int temp_loc2 = 0;
        int temp_loc3 = 0;
        int temp_loc4 = 0;
        int temp_loc5 = 0;
        int temp_loc6 = 0;
        int temp_loc7 = 0; // for right side car ( 1 ) 
        int temp_loc8 = 0; // for right side car ( 2 ) 



        for (int i = 0; i < 200; i++)
        {
            cls(); // to clear the screen 
            generateRoad(); // to generate the road 


            {//traffic lights
                generategreenlight(1, 1, 1); // Green left upper side
                generategreenlight(1, 2, 1);; // Green right upper side
                generategreenlight(1, 1, 2); // Green left lower side
                generategreenlight(1, 2, 2); // Green right lower side
            }


            if (x_c1 < 350) {


                drawRectangle(200 + i, 260, x_c1 = 240 + i, 290, 244, 242, 1, 244, 242, 1); // car(1) coming from the left 
            //	cout << x_c2 ; 


            }
            else {
                generategreenlight(3, 1, 1); // RED left upper side
            }


            if (y_c1 < 200)
            {
                drawRectangle(410, 100 + temp_loc2, 440, y_c1 = 140 + temp_loc2, 244, 242, 1, 244, 242, 1); // car(1) coming from the top 
                temp_loc2++;

            }
            else {
                generategreenlight(3, 2, 1); // RED right upper side
            }


            if (y_c1 > 190 && y_c2 < 150)
            {
                drawRectangle(410, 100 + temp_loc3, 440, y_c2 = 140 + temp_loc3, 244, 242, 1, 244, 242, 1); // car(2) coming from the top 	
                temp_loc3++;
            }


            if (x_c1 > 290 && x_c2 < 300)
            {

                drawRectangle(200 + temp_loc, 260, x_c2 = 240 + temp_loc, 290, 244, 242, 1, 244, 242, 1); // car(2) coming from the left 					
                temp_loc++;
            }



            // cars coming from the bottom 

            if (y_c3 > 350)
            {
                drawRectangle(360, 350 - temp_loc4, 390, y_c3 = 400 - temp_loc4, 244, 242, 1, 244, 242, 1); // bottom car 1 
                temp_loc4++;
            }
            else {
                generategreenlight(3, 1, 2); // RED left lower side
            }

            if (y_c3 < 360)
            {
                drawRectangle(360, y_c4 = y_c3 + 10, 390, y_c4 + 38, 244, 242, 1, 244, 242, 1);
                temp_loc5++;
            }

            if (x_c3 > 460)
            {
                drawRectangle(x_c3 = 560 - temp_loc7, 210, 600 - temp_loc7, 240, 255, 0, 0);  // car(1) right side 
                temp_loc7++;
            }
            else {
                generategreenlight(3, 2, 2); // RED right lower side
            }

            if (x_c3 < 500 && ((x_c4)-(600 - temp_loc7)) > 10)
            {
                drawRectangle(x_c4 = 560 - temp_loc8, 210, 600 - temp_loc8, 240, 255, 0, 0); // car ( 2 ) right side 
                temp_loc8++;
            }




            // fixed positions of the cars  
            drawRectangle(x_c1 - 40, 260, x_c1, 290, 244, 242, 1, 244, 242, 1); // car(1) coming from the left 
            drawRectangle(x_c2 - 40, 260, x_c2, 290, 244, 242, 1, 244, 242, 1); // car(2) coming from the left 					
            drawRectangle(410, y_c1 - 40, 440, y_c1, 244, 242, 1, 244, 242, 1); // car(1) coming from the top 
            drawRectangle(410, y_c2 - 40, 440, y_c2, 244, 242, 1, 244, 242, 1); // car(2) coming from the top 
            drawRectangle(360, y_c3 - 50, 390, y_c3, 244, 242, 1, 244, 242, 1); // car(1) coming from the bottom
            drawRectangle(360, y_c4 - 10, 390, y_c4 - 38, 244, 242, 1, 244, 242, 1);
            drawRectangle(x_c3, 210, 600 - temp_loc7, 240, 255, 0, 0);  // right side car ( 1) 
            drawRectangle(x_c4, 210, 600 - temp_loc8, 240, 255, 0, 0); // right side car ( 2 ) 
     //  	delay(10); 
        }

        for (int clik = 0; clk <= 15; clk++) // for red signal
        {
            {   // traffic lights
                generategreenlight(3, 1, 1); // Red left upper side
                generategreenlight(3, 2, 1);; // Red right upper side
                generategreenlight(3, 1, 2); // Red left lower side
                generategreenlight(3, 2, 2); // Red right lower side
            }

            globalTime++;
            delay(150);
        }

        // to move the car to the end point 
        //	temp_loc7 = 0 ;
        int temp_loc7_1 = 0;
        int temp_loc8_1 = 0;
        int temp_x_c_1 = 0;
        int temp_x_c_2 = 0;

        {
            for (int clk = 0; clk <= 10; clk++)// for yellow signal
            {
                {   // traffic lights
                    generategreenlight(2, 1, 1); // Yellow left upper side
                    generategreenlight(3, 2, 1); // Red right upper side
                    generategreenlight(3, 1, 2); // Red left lower side
                    generategreenlight(3, 2, 2); // Red right lower side
                }

                globalTime++;
                delay(150);
            }
        }

        for (int i = 0; i < 400; i++)
        {


            {//traffic lights
                generategreenlight(1, 1, 1); // GREEN left upper side
                generategreenlight(3, 2, 2); // RED right lower side
                generategreenlight(3, 2, 1); // RED right upper side
                generategreenlight(3, 1, 2); // RED left lower side
            }

            cls();
            generateRoad();


            if (x_c1 < 580) {
                drawRectangle(x_c1 + 40, 260, x_c1 += 3, 290, 244, 242, 1, 244, 242, 1); // car(1) coming from left
            }
            if (x_c2 < 580) {
                drawRectangle(x_c2 + 40, 260, x_c2 += 3, 290, 244, 242, 1, 244, 242, 1); // car(2) coming from left
            }
            else {
                break;
            }


            drawRectangle(x_c3, 210, x_c3 + 40, 240, 255, 0, 0);  // right side car ( 1) 
            drawRectangle(x_c4, 210, x_c4 + 40, 240, 255, 0, 0); // right side car(2)
            drawRectangle(410, y_c1 - 40, 440, y_c1, 244, 242, 1, 244, 242, 1); // car(1) coming from the top 
            drawRectangle(410, y_c2 - 40, 440, y_c2, 244, 242, 1, 244, 242, 1); // car(2) coming from the top 
            drawRectangle(360, y_c3 - 40, 390, y_c3, 244, 242, 1, 244, 242, 1); // car(1) coming from the bottom
           /* drawRectangle(360, 397, 390, 360 , 244, 242, 1, 244, 242, 1);*/
            drawRectangle(360, y_c4 + 40, 390, y_c4, 244, 242, 1, 244, 242, 1); // car(2) coming from the bottom

        }

        for (int clk = 0; clk <= 10; clk++)// for yellow signal
        {
            {   // traffic lights
                generategreenlight(1, 1, 1); // GREEN left upper side
                generategreenlight(3, 2, 1); // RED right upper side
                generategreenlight(3, 1, 2); // RED left lower side
                generategreenlight(2, 2, 2); // Yellow right lower side
            }

            {//printing cars
                drawRectangle(x_c3, 210, x_c3 + 40, 240, 255, 0, 0);  // right side car ( 1) 
                drawRectangle(x_c4, 210, x_c4 + 40, 240, 255, 0, 0); // right side car(2)
                drawRectangle(410, y_c1 - 40, 440, y_c1, 244, 242, 1, 244, 242, 1); // car(1) coming from the top 
                drawRectangle(410, y_c2 - 40, 440, y_c2, 244, 242, 1, 244, 242, 1); // car(2) coming from the top 
                drawRectangle(360, y_c3 - 40, 390, y_c3, 244, 242, 1, 244, 242, 1); // car(1) coming from the bottom
               /* drawRectangle(360, 397, 390, 360 , 244, 242, 1, 244, 242, 1);*/
                drawRectangle(360, y_c4 + 40, 390, y_c4, 244, 242, 1, 244, 242, 1); // car(2) coming from the bottom
            }

            globalTime++;
            delay(150);
        }


        for (int i = 0; i < 400; i++)
        {

            {//traffic lights
                generategreenlight(1, 1, 1); // GREEN left upper side
                generategreenlight(1, 2, 2); // GREEN right lower side
                generategreenlight(3, 2, 1); // RED right upper side
                generategreenlight(3, 1, 2); // RED left lower side
            }

            cls();
            generateRoad();


            if (x_c3 > 230) {
                drawRectangle(x_c3 - 40, 210, x_c3 -= 3, 240, 255, 0, 0);  // right side car ( 1) 
            }

            if (x_c4 > 230) {
                drawRectangle(x_c4 - 40, 210, x_c4 -= 3, 240, 255, 0, 0); // right side car(2)
            }
            else {
                break;
            }


            //printing cars
            drawRectangle(410, y_c1 - 40, 440, y_c1, 244, 242, 1, 244, 242, 1); // car(1) coming from the top 
            drawRectangle(410, y_c2 - 40, 440, y_c2, 244, 242, 1, 244, 242, 1); // car(2) coming from the top 
            drawRectangle(360, y_c3 - 40, 390, y_c3, 244, 242, 1, 244, 242, 1); // car(1) coming from the bottom
           /* drawRectangle(360, 397, 390, 360 , 244, 242, 1, 244, 242, 1);*/
            drawRectangle(360, y_c4 + 40, 390, y_c4, 244, 242, 1, 244, 242, 1); // car(2) coming from the bottom

        }
        delay(10);

        for (int clk = 0; clk <= 10; clk++)// for yellow signal
        {
            {   // traffic lights
                generategreenlight(1, 1, 1); // Green left upper side
                generategreenlight(2, 2, 1); // Yellow right upper side
                generategreenlight(3, 1, 2); // RED left lower side
                generategreenlight(1, 2, 2); // GREEN right lower side
            }
            {
                //printing cars
                drawRectangle(410, y_c1 - 40, 440, y_c1, 244, 242, 1, 244, 242, 1); // car(1) coming from the top 
                drawRectangle(410, y_c2 - 40, 440, y_c2, 244, 242, 1, 244, 242, 1); // car(2) coming from the top 
                drawRectangle(360, y_c3 - 40, 390, y_c3, 244, 242, 1, 244, 242, 1); // car(1) coming from the bottom
               /* drawRectangle(360, 397, 390, 360 , 244, 242, 1, 244, 242, 1);*/
                drawRectangle(360, y_c4 + 40, 390, y_c4, 244, 242, 1, 244, 242, 1); // car(2) coming from the bottom

            }
            globalTime++;
            delay(150);
        }

        for (int i = 0; i < 400; i++)
        {

            {
                //traffic lights
                generategreenlight(1, 1, 1); // Green left upper side
                generategreenlight(1, 2, 1); // Green right upper side
                generategreenlight(3, 1, 2); // RED left lower side
                generategreenlight(1, 2, 2); // GREEN right lower side
            }

            cls();
            generateRoad();


            if (y_c1 < 380) {
                drawRectangle(410, y_c1 + 40, 440, y_c1 += 3, 244, 242, 1, 244, 242, 1); // car(1) coming from left
            }

            if (y_c2 < 380) {
                drawRectangle(410, y_c2 + 40, 440, y_c2 += 3, 244, 242, 1, 244, 242, 1); // car(1) coming from left
            }
            else {
                break;
            }

            drawRectangle(360, y_c3 - 40, 390, y_c3, 244, 242, 1, 244, 242, 1); // car(1) coming from the bottom
           /* drawRectangle(360, 397, 390, 360 , 244, 242, 1, 244, 242, 1);*/
            drawRectangle(360, y_c4 + 40, 390, y_c4, 244, 242, 1, 244, 242, 1); // car(2) coming from the bottom

        }

        delay(10);

        for (int clk = 0; clk <= 10; clk++)// for yellow signal
        {
            {   // traffic lights
                generategreenlight(1, 1, 1); // Green left upper side
                generategreenlight(1, 2, 1); // Green right upper side
                generategreenlight(2, 1, 2); // YELLOW left lower side
                generategreenlight(1, 2, 2); // GREEN right lower side
            }
            {
                //printing cars
                drawRectangle(360, y_c3 - 40, 390, y_c3, 244, 242, 1, 244, 242, 1); // car(1) coming from the bottom
          /* drawRectangle(360, 397, 390, 360 , 244, 242, 1, 244, 242, 1);*/
                drawRectangle(360, y_c4 + 40, 390, y_c4, 244, 242, 1, 244, 242, 1); // car(2) coming from the bottom

            }
            globalTime++;
            delay(150);
        }

        for (int i = 0; i < 400; i++)
        {

            {
                //traffic lights
                generategreenlight(1, 1, 1); // Green left upper side
                generategreenlight(1, 2, 1); // Green right upper side
                generategreenlight(1, 1, 2); // GREEN left lower side
                generategreenlight(1, 2, 2); // GREEN right lower side
            }

            cls();
            generateRoad();

            if (y_c3 > 120) {
                drawRectangle(360, y_c3 - 40, 390, y_c3 -= 3, 255, 0, 0);  // right side car ( 1) 
            }

            if (y_c4 > 110) {
                drawRectangle(360, y_c4 + 40, 390, y_c4 -= 3, 255, 0, 0); // right side car(2)
            }

            else {
                break;
            }


        }

        delay(10);

        }


        else if (selection == 1 && strategy == 2)
        {


        int t1 = 0, t2 = 0;

        // if selection is 1 then one car will be generated on every road 
        // strategy 1 means two signals will be green at a time 	
        int temp = 1;
        int t_1 = 0;
        int x_c1, x_c2, x_c3, x_c4, y_c1, y_c2, y_c3, y_c4;



        x_c1 = 240;  // car coming from left 
        x_c2 = 0;

        y_c1 = 0; // car coming from top 
        y_c2 = 0; // car coming from bottom 



        for (int i = 0; x_c1 < 350; i += 3)
        {

            cls();
            generateRoad();

            {
                //traffic lights
                generategreenlight(1, 1, 1); // Green left upper side
                generategreenlight(1, 2, 1); // Green right upper side
                generategreenlight(1, 1, 2); // GREEN left lower side
                generategreenlight(1, 2, 2); // GREEN right lower side

            }

            /* generateTrafficlight();*/
               // car coming from the left side 
            drawRectangle(200 + i, 260, x_c1 = 240 + i, 290, 244, 242, 1, 244, 242, 1);  // left , top , right , bottom , rectangle( car ) // car coming from the left side 
            // car coming from the  right side 
            drawRectangle(600 - i, 210, x_c2 = 560 - i, 240, 244, 242, 1, 244, 242, 1);

            if (y_c1 < 190 && y_c2 < 400)
            {
                //	generatecarVertical(1,1,1,1,1) ;  
                 // car coming from the top 
                drawRectangle(410, 100 + temp, 440, y_c1 = 140 + temp, 244, 242, 1, 244, 242, 1);
                drawRectangle(360, 350 - temp, 390, y_c2 = 400 - temp, 244, 242, 1, 244, 242, 1); // second car
                temp += 3;
            }
            else if (y_c1 > 190)
            {
                drawRectangle(410, 160, 440, y_c1 = 200, 244, 242, 1, 244, 242, 1);
                drawRectangle(360, 300, 390, y_c2 = 350, 244, 242, 1, 244, 242, 1); // second car	
            }
            delay(0);

        }
        globalTime = 0;
        for (int i = 0; i < 400; i++)
        {


            cls();
            generateRoad();
            //   generateTrafficlight();
            drawRectangle(410, 160, 440, y_c1 = 200, 244, 242, 1, 244, 242, 1); // top car 
            drawRectangle(360, 300, 390, y_c2 = 350, 244, 242, 1, 244, 242, 1); // down car 
            drawRectangle(x_c1 - 40, 260, x_c1, 290, 244, 242, 1, 244, 242, 1);  // left , top , right , bottom , rectangle( car ) // car coming from the left side 
            // car coming from the  right side 
            drawRectangle(x_c2 + 40, 210, x_c2, 240, 244, 242, 1, 244, 242, 1);

            clk = 0;
            while (clk < 15)
            {
                {   //Traffic light
                    generategreenlight(3, 1, 1); // RED left upper side
                    generategreenlight(3, 2, 1); // RED right upper side
                    generategreenlight(3, 1, 2); // RED left lower side
                    generategreenlight(3, 2, 2); // RED right lower side
                }

                globalTime++;
                clk++;
                delay(150);
            }

            for (int clik = 0; clik <= 15; clik++) // for red signal
            {
                {   // traffic lights
                    generategreenlight(2, 1, 1); // Yellow left upper side
                    generategreenlight(3, 2, 1); // RED right upper side
                    generategreenlight(3, 1, 2); // RED left lower side
                    generategreenlight(3, 2, 2); // RED right lower side
                }

                globalTime++;
                delay(150);
            }

            for (int xy = 0; x_c1 < 600; xy++)
            {
                {   //Traffic lights
                    generategreenlight(1, 1, 1); // GREEN left upper side
                    generategreenlight(3, 2, 1); // RED right upper side
                    generategreenlight(3, 1, 2); // RED left lower side
                    generategreenlight(3, 2, 2); // RED right lower side
                }
                cls();
                generateRoad();
                // generateTrafficlight();
                if (x_c1 < 598) {
                    drawRectangle(x_c1 - 40, 260, x_c1 += 4, 290, 244, 242, 1, 244, 242, 1);  // left , top , right , bottom , rectangle( car ) // car coming from the left side 
                }
                else {
                    break;
                }
                drawRectangle(410, 160, 440, y_c1 = 200, 244, 242, 1, 244, 242, 1); // top car 
                drawRectangle(360, 300, 390, y_c2 = 350, 244, 242, 1, 244, 242, 1); // down car

                // car coming from the  right side 
                drawRectangle(x_c2 + 40, 210, x_c2, 240, 244, 242, 1, 244, 242, 1);
                delay(0);



            }

            for (int clik = 0; clik <= 15; clik++) // for red signal
            {
                {   // traffic lights
                    generategreenlight(1, 1, 1); // GREEN left upper side
                    generategreenlight(3, 2, 1); // RED right upper side
                    generategreenlight(3, 1, 2); // RED left lower side
                    generategreenlight(2, 2, 2); // YELLOW right lower side
                }
                {
                    drawRectangle(410, 160, 440, y_c1 = 200, 244, 242, 1, 244, 242, 1); // top car 
                    drawRectangle(360, 300, 390, y_c2 = 350, 244, 242, 1, 244, 242, 1); // down car

                    // car coming from the  right side 
                    drawRectangle(x_c2 + 40, 210, x_c2, 240, 244, 242, 1, 244, 242, 1);
                    delay(0);
                }
                globalTime++;
                delay(150);
            }

            for (int xy = 0; x_c2 > 200; xy++)
            {
                {
                    // Traffic lights
                    generategreenlight(1, 1, 1); // GREEN left upper side
                    generategreenlight(3, 2, 1); // RED right upper side
                    generategreenlight(3, 1, 2); // RED left lower side
                    generategreenlight(1, 2, 2); // GREEN right lower side
                }


                cls();
                generateRoad();
                // generateTrafficlight();
                drawRectangle(410, 160, 440, y_c1 = 200, 244, 242, 1, 244, 242, 1); // top car 
                drawRectangle(360, 300, 390, y_c2 = 350, 244, 242, 1, 244, 242, 1); // down car

                if (x_c2 > 202) {
                    // car coming from the  right side 
                    drawRectangle(x_c2 + 40, 210, x_c2 -= 4, 240, 244, 242, 1, 244, 242, 1);
                    delay(0);
                }
                else {
                    break;
                }


            }

            for (int clik = 0; clik <= 15; clik++) // for red signal
            {
                {   // traffic lights

                    generategreenlight(1, 1, 1); // GREEN left upper side
                    generategreenlight(2, 2, 1); // YELLOW right upper side
                    generategreenlight(3, 1, 2); // RED left lower side
                    generategreenlight(1, 2, 2); // GREEN right lower side
                }
                {
                    drawRectangle(410, 160, 440, y_c1 = 200, 244, 242, 1, 244, 242, 1); // top car 
                    drawRectangle(360, 300, 390, y_c2 = 350, 244, 242, 1, 244, 242, 1); // down car



                    delay(0);
                }
                globalTime++;
                delay(150);
            }

            for (int xz = 0; y_c1 < 400; xz++)
            {
                {
                    // Traffic lights
                    generategreenlight(1, 1, 1); // GREEN left upper side
                    generategreenlight(1, 2, 1); // GREEN right upper side
                    generategreenlight(3, 1, 2); // RED left lower side
                    generategreenlight(1, 2, 2); // GREEN right lower side
                }

                cls();
                generateRoad();
                if (y_c1 < 398) {
                    drawRectangle(410, y_c1 - 40, 440, y_c1 += 3, 244, 242, 1, 244, 242, 1); // top car 
                }
                else {
                    break;
                }

                drawRectangle(360, y_c2 - 50, 390, y_c2, 244, 242, 1, 244, 242, 1); // down car

            }

            for (int clik = 0; clik <= 15; clik++) // for red signal
            {
                {   // traffic lights

                    generategreenlight(1, 1, 1); // GREEN left upper side
                    generategreenlight(1, 2, 1); // GREEN right upper side
                    generategreenlight(2, 1, 2); // YELLOW left lower side
                    generategreenlight(1, 2, 2); // GREEN right lower side
                }
                drawRectangle(360, y_c2 - 50, 390, y_c2, 244, 242, 1, 244, 242, 1); // down car
                globalTime++;
                delay(150);
            }

            for (int xz = 0; y_c2 > 150; xz++)
            {
                {
                    // Traffic lights
                    generategreenlight(1, 1, 1); // GREEN left upper side
                    generategreenlight(1, 2, 1); // GREEN right upper side
                    generategreenlight(1, 1, 2); // GREEN left lower side
                    generategreenlight(1, 2, 2); // GREEN right lower side
                }

                cls();
                generateRoad();
                if (y_c2 > 152) {
                    drawRectangle(360, y_c2 - 50, 390, y_c2 -= 3, 244, 242, 1, 244, 242, 1); // down car
                }
                else { break; }


            }

            if (clk < 16)
            {

                // drawRectangle(x_c1 - 40, 260, x_c1, 290, 244, 242, 1, 244, 242, 1);  // left , top , right , bottom , rectangle( car ) // car coming from the left side 
                 // car coming from the  right side 
                drawRectangle(x_c2 + 40, 210, x_c2, 240, 244, 242, 1, 244, 242, 1);
                drawRectangle(410, y_c1 - 40, 440, y_c1, 244, 242, 1, 244, 242, 1); // top car 
                drawRectangle(360, y_c2 - 50, 390, y_c2, 244, 242, 1, 244, 242, 1); // down car
                clk++;



                break;
            }


        }

        }
    }

};


int main()
{
    int w = 0, h = 0;
    getWindowDimensions(w, h);
    getConsoleWindowDimensions(w, h);

   /* intersection c;*/
    int selection;
    int strategy ;

    selection = 1;
    // selection is the number of cars 
    
    vehicle v(40);
   /* intersection obj(selection, strategy);*/
    cout << "enter strategy number 1 or 2  : " << endl;
    cin >> strategy;
    strategyies obj1;
    while (true)
    {
        if (strategy == 1) {
            obj1.generatecarSTRATEGY1(selection, strategy);
        }
        if (strategy == 2) {
            obj1.generatecarSTRATEGY2(selection, strategy);
        }

        delay(5);
    }

    cin.get();

    return 0;
}