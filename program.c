/* EECE259 Homework 4 Solution
 * Date: April 8, 2011
 *
 * Student1Name: Kevin Shiah
 * Student1Number: 70572094
 * Student1UserID: l7j7
 * Student1Email: aganwon@hotmail.com
 *
 * Student2Name: Gary Tse
 * Student2Number: 12013074
 * Student2UserID: t2v7
 * Student2Email: garytse89@gmail.com
 */

#include "259macros.h"

int moveBall_y( int position, int x, int *pVelocity, int min_pos, int max_pos, int c1_x, int c2_x)
//pass in y position, x position, velocity, min position and max position
//control the ball's y direction
{
  position += *pVelocity;
   if( position < 0 || position > 216 || (x <= 164 && x >= 140 && position <= 162 && position >= 159) || (position<=199 && position>= 196 && x>= c1_x-20 && x<= c1_x+20)|| (position<=199 && position>= 196 && x>= c2_x-20 && x<= c2_x+20) ) {

       *pVelocity = -*pVelocity; /* change sign of velocity */
       position += *pVelocity;      /* return pixel to previous location */
   }
      /* if pixel moves off screen */
  return position;
}

int moveBall_x( int position, int y, int *pVelocity, int min_pos, int max_pos, int c1_x, int c2_x )
//pass in x position, y position, velocity, min position and max position
//control the ball's x direction
{
  position += *pVelocity;
   if( position < 0 || position > 303 || (y <= 240 && y >= 159 && position <= 142 &&position>=140) || (y <= 240 && y >= 159 && position >= 162 && position <=164) ) {

       *pVelocity = -*pVelocity; /* change sign of velocity */
       position += *pVelocity;      /* return pixel to previous location */
   }
   if((y<=199 && y>= 196 && position>= c2_x && position<= c2_x+20) ||(y<=199 && y>= 196 && position>= c2_x-20 && position<= c2_x)){
  	*pVelocity = -*pVelocity; /* change sign of velocity */ //when the ball hit the front part of pikachu the ball
       position += *pVelocity;      /* return pixel to previous location */
   }
      /* if pixel moves off screen */
  return position;
}

// draws all the background elements: the net, the beach (ground), and the sky
void drawBackground(){
	unsigned short lightbeach = makeColour( 255/4, 255/4, 176/4 );
	unsigned short brightbeach = makeColour( 255/4, 255/4, 64/4 );
	unsigned short GRAY = makeColour( 128/4, 128/4, 128/4 );
	unsigned short cyan = makeColour( 128/4, 255/4, 255/4 );
	fillScreen( cyan );	
	int i,j;
	for( i=0; i<=320; i++ ){ 
     for( j=240; j>=232; j-- ){
          drawPixel(i,j, brightbeach);
          }
    }
	for( i=0; i<=320; i++ ){
     for( j=231; j>=227; j-- ){
          drawPixel(i,j, lightbeach);
          }
    }
	for( i=158; i <= 162; i++){
         for( j=235; j>= 180; j--){
                 drawPixel(i,j, GRAY);
         }
	}
}

// flashes the screen whenever a point is scored
void flash_screen(int c1, int c2){ 
	 
     
     fillScreen(c1);
     timedDelay( ONE_MS * 20 );
     fillScreen(c2);
     timedDelay( ONE_MS * 20 );       
}

// changes the score on the HEX display every time a point is scored
void changeScore(int score_2, int score_1){
	
	int hexnum; // We need this intermediate variable for addition so that when we display the score on HEX2, the one on HEX0 won't be deleted
				// shift left logical is performed for all player 2 scores (score_2) in order to display 2 displays left of player 1 score
	
	if(score_1==0){
		*pHEX7SEG = DIGIT0;
		hexnum = *pHEX7SEG;}
	if(score_1==1){
		*pHEX7SEG = DIGIT1;
		hexnum = *pHEX7SEG;}
	if(score_1==2){
		*pHEX7SEG = DIGIT2;
		hexnum = *pHEX7SEG;}
	if(score_1==3){
		*pHEX7SEG = DIGIT3;
		hexnum = *pHEX7SEG;}
	if(score_1==4){
		*pHEX7SEG = DIGIT4;
		hexnum = *pHEX7SEG;}
	if(score_1==5){
		*pHEX7SEG = DIGIT5;
		hexnum = *pHEX7SEG;}
	if(score_1==6){
		*pHEX7SEG = DIGIT6;
		hexnum = *pHEX7SEG;}
	if(score_1==7){
		*pHEX7SEG = DIGIT7;
		hexnum = *pHEX7SEG;}
	if(score_1==8){
		*pHEX7SEG = DIGIT8;
		hexnum = *pHEX7SEG;}
	if(score_1==9){
		*pHEX7SEG = DIGIT9;
		hexnum = *pHEX7SEG;}
	if(score_1==10){
		*pHEX7SEG = DIGIT1;
		hexnum = *pHEX7SEG;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT0;
		hexnum = *pHEX7SEG;}
	
	if(score_2==0){
		hexnum = hexnum<<8;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT0;}
	if(score_2==1){
	hexnum = hexnum<<8;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT1;}
	if(score_2==2){
		hexnum = hexnum<<8;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT2;}
	if(score_2==3){
		hexnum = hexnum<<8;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT3;}
	if(score_2==4){
		hexnum = hexnum<<8;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT4;}
	if(score_2==5){
		hexnum = hexnum<<8;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT5;}
	if(score_2==6){
		hexnum = hexnum<<8;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT6;}
	if(score_2==7){
		hexnum = hexnum<<8;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT7;}
	if(score_2==8){
		hexnum = hexnum<<8;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT8;}
	if(score_2==9){
		hexnum = hexnum<<8;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT9;}
	if(score_2==10){
		hexnum = hexnum<<8;
		hexnum = hexnum<<8;
		*pHEX7SEG = DIGIT1;
		hexnum=*pHEX7SEG;
		hexnum = hexnum<<8;
		*pHEX7SEG = hexnum+DIGIT0;
		hexnum = *pHEX7SEG;
	}
	
}

// shows GAME OVER on the screen after game ends
void drawWord(){  
	drawChar( 15, 5, 71 );
	drawChar( 16, 5, 65 );
	drawChar( 17, 5, 77 );
	drawChar( 18, 5, 69 );
	drawChar( 19, 5, 32 );
	drawChar( 20, 5, 32);
	drawChar( 21, 5, 79);
	drawChar( 22, 5, 86);
	drawChar( 23, 5, 69);
	drawChar( 24, 5, 82);
}

// erases the GAME OVER words on the screen
void eraseWord(){
	drawChar( 15, 5, 32 );
	drawChar( 16, 5, 32 );
	drawChar( 17, 5, 32 );
	drawChar( 18, 5, 32 );
	drawChar( 19, 5, 32 );
	drawChar( 20, 5, 32);
	drawChar( 21, 5, 32);
	drawChar( 22, 5, 32);
	drawChar( 23, 5, 32);
	drawChar( 24, 5, 32);
	drawChar( 8, 8, 32);
	drawChar( 9, 8, 32);
	drawChar( 10, 8, 32);
	drawChar( 11, 8, 32);	
	drawChar( 31, 8, 32);
	drawChar( 32, 8, 32);
	drawChar( 33, 8, 32);
	drawChar( 34, 8, 32);
}

int main( int argc, char *argv[] )
{
    
    
    unsigned short BLACK= makeColour( 0,  0,  0 );
    unsigned short RED = makeColour( 63,  0,  0 );
    unsigned short GREEN = makeColour( 0,  63,  0 );
    unsigned short BLUE = makeColour( 0,  0,  63 );
    unsigned short GRAY = makeColour( 128/4, 128/4, 128/4 );
    unsigned short WHITE = makeColour( 63, 63, 63 );
	unsigned short DARKGRAY = makeColour( 25, 25, 25);
	unsigned short lightbeach = makeColour( 255/4, 255/4, 128/4 );
	unsigned short brightbeach = makeColour( 255/4, 255/4, 64/4 );
	unsigned short cyan = makeColour( 128/4, 255/4, 255/4 );

    int x=50, y=50, vx=3, vy=2; //initializes the position and the speed of the ball
    int i,j;
    initScreen();
	drawBackground();
	double score_1 =0; //declare score variable
	double score_2 =0;
	int c2_x = 100;    //x position for character 2
	int c1_x = 200;    //x position for character 1
	int KeyBoardValue2 = 0xff;  //temporarily store the value of keyboard for each player
	int KeyBoardValue1 = 0xff;
	drawPikachu2(c2_x, 213);
	drawPikachu(c1_x, 213);

// big fat loop starts here       
	while ( 1 ){
	
		eraseWord();
		eraseBall(x, y);
		 
		x = moveBall_x( x, y, &vx, 0, MAX_X_PIXELS-1, c1_x, c2_x );  //get x position for next cycle
		y = moveBall_y( y, x, &vy, 0, MAX_Y_PIXELS-1, c1_x, c2_x );  //get y position for next cycle y position, x position, velocity, min, max, pika1 position, pika2 position
			
		drawBall(x, y);
		timedDelay( ONE_MS * 15 );          // one second delay
		
		
		// the below code is for reading the keyboard
		
		KeyBoardValue2 = getPS2_nowait();
		KeyBoardValue2 = KeyBoardValue2 & 0xFF;
		if(KeyBoardValue2 == 0x23&& c2_x<=140){
			erasePikachu2(c2_x, 213); //earse the previous drawn pikachu, if this is outside, it will erase even if pikachu is not moving
			c2_x = c2_x +3;
			drawPikachu2(c2_x, 213);
				KeyBoardValue2 = getPS2_nowait();
				KeyBoardValue2 = KeyBoardValue2 & 0xFF;
				if(KeyBoardValue2 == 0x23&& c2_x<=140){
					erasePikachu2(c2_x, 213); //erase the previous drawn pikachu, if this is outside, it will erase even if pikachu is not moving
					c2_x = c2_x +3;
					drawPikachu2(c2_x, 213);
				    }
			putcharPS2(0xF4);
		}
		if(KeyBoardValue2 == 0x1C&& c2_x >=0){
			erasePikachu2(c2_x, 213);  //erase the previous drawn pikachu
			c2_x = c2_x -3;
			drawPikachu2(c2_x, 213);
				KeyBoardValue2 = getPS2_nowait();
				KeyBoardValue2 = KeyBoardValue2 & 0xFF;
				if(KeyBoardValue2 == 0x1C&& c2_x >=0){
					erasePikachu2(c2_x, 213);  //erase the previous drawn pikachu
					c2_x = c2_x -3;
					drawPikachu2(c2_x, 213);
				}
			putcharPS2(0xF4);
		}
		KeyBoardValue1 = getPS2_nowait();
		KeyBoardValue1 = KeyBoardValue1 & 0xFF;
		if(KeyBoardValue1 == 0x74 && c1_x<=303){
			erasePikachu(c1_x, 213); //erase the previous drawn pikachu, if this is outside, it will erase even if pikachu is not moving
			c1_x = c1_x +3;
			drawPikachu(c1_x, 213);
				KeyBoardValue1 = getPS2_nowait();
				KeyBoardValue1 = KeyBoardValue1 & 0xFF;
				if(KeyBoardValue1 == 0x74 && c1_x<=303){
					erasePikachu(c1_x, 213); //erase the previous drawn pikachu, if this is outside, it will erase even if pikachu is not moving
			c1_x = c1_x +3;
			drawPikachu(c1_x, 213);
			}
			putcharPS2(0xF4);
		}
		if(KeyBoardValue1 == 0x6B && c1_x>=165){
			erasePikachu(c1_x, 213);  //erase the previous drawn pikachu
			c1_x = c1_x -3;
			drawPikachu(c1_x, 213);
				KeyBoardValue1 = getPS2_nowait();
				KeyBoardValue1 = KeyBoardValue1 & 0xFF;
				if(KeyBoardValue1 == 0x6B && c1_x>=165){
					erasePikachu(c1_x, 213);  //erase the previous drawn pikachu
			c1_x = c1_x -3;
			drawPikachu(c1_x, 213);
			}
			putcharPS2(0xF4);
		}
		
		
		
	    // code for when the ball hits the ground
		if( y > 213 ){         //when the ball hits the ground 
		putcharPS2(0xF4);
    			if(x<=142){
					score_1 = score_1+0.5;
					}
				if(x>142){
					score_2 = score_2+0.5;
					}
				flash_screen(WHITE,GREEN);// flash screen whenever point is scored
				drawBackground();
				putcharPS2(0xF4);
				drawPikachu2(c2_x, 213); //keep the pikachu2 after refreshing the screen
				drawPikachu(c1_x, 213);  //keep the pikachu1 after refreshing the screen
				if(x<=142){
					score_1 = score_1+0.5;
					x=c1_x+10; //set ball position to serve
					y=195;
					drawBall(x, y);
					KeyBoardValue1 = getPS2_nowait();//read keyboard value again to input service key
					KeyBoardValue1 = KeyBoardValue1 & 0xFF;
					do{   //wait until keyboard is hitted
					//putcharPS2(0xF4);
					KeyBoardValue1 = getPS2_nowait();//read keyboard value again to input service key
					KeyBoardValue1 = KeyBoardValue1 & 0xFF;
									}while(KeyBoardValue1 != 0x75 );
					}
				else if(x>142){
					score_2 = score_2+0.5;
					x=c2_x-10; //set ball position to serve
					y=195;
					drawBall(x, y);
					KeyBoardValue2 = getPS2_nowait();//read keyboard value again to input service key
					KeyBoardValue2 = KeyBoardValue2 & 0xFF;
					do {  //wait until keyboard is hitted
					//putcharPS2(0xF4);
					KeyBoardValue2 = getPS2_nowait();//read keyboard value again to input service key
					KeyBoardValue2 = KeyBoardValue2 & 0xFF;
								}while(KeyBoardValue2 != 0x1D );
					}
					putcharPS2(0xF4);
					
			}
			
		changeScore(score_1, score_2);       //display score on the 7 seg LED 
		
		if(score_2>=9 ||score_1>=9){  //if any play reaches 10 point, display gameover on the screen
			drawWord();
			if(score_2 ==10){
				drawChar( 8, 8, 87);//W
				drawChar( 9, 8, 73);//I
				drawChar( 10, 8, 78);//N
				
				drawChar( 31, 8, 76);//L
				drawChar( 32, 8, 79);//O
				drawChar( 33, 8, 83);//S
				drawChar( 34, 8, 69);//E
			}
			else{
				drawChar( 31, 8, 87);//W
				drawChar( 32, 8, 73);//I
				drawChar( 33, 8, 78);//N
				
				drawChar( 8, 8, 76);//L
				drawChar( 9, 8, 79);//O
				drawChar( 10, 8, 83);//S
				drawChar( 11, 8, 69);//E
			}
			timedDelay( ONE_MS * 3500 ); //delay for next game
			score_2=0;  //set score to 0 to start a new game
			score_1=0;  //set score to 0 to start a new game
			x=10;       //new start position for the ball
			y=10;		//new start position for the ball
		}
		
		
	

	} 
	

}

        


