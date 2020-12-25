#ifndef KEYAIR_H_INCLUDED
#define KEYAIR_H_INCLUDED

//char KeyAirPic[][]={"images\\f11.bmp","images\\f12.bmp","images\\f13.bmp","images\\f14.bmp"};
//char Bullet[1][20]={"images\\bullet1.bmp"};
//int KeyAirX = 100;
//int KeyAirY = 120;
int i = 0;
int x=0,y=0,z=850,n=250;
void KeyAirMove()
{	
		if (i == 5)
			i = 0;
		i++;
}

void KeyAir_change()
{

	iShowBMP2(x+10, y+0, "bmp1\\keyair.bmp" , 0);
	
	
}





#endif // KEYAIR_H_INCLUDED
