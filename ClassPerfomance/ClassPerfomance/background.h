#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

/*char BackgroundPicture[1][50]={"images\\farback.bmp"};
#define backgroundSpeed 10;
struct background
{
	int x;
	int y;

}BackGround[1];
void background() 
{
	for(int i=0; i<1; i++)
	{
		iShowBMP(BackGround[i].x,BackGround[i].y,BackgroundPicture[i]);
	}
}
void setBackground()
{
	int sum= 0;
	for(int i =0; i<1; i++)
	{
		BackGround[i].y = 120;
		BackGround[i].y = 0;
		BackGround[i].x = sum;
		BackGround[i].x = sum;
		sum+=120;
	}
}
void changebackground()
{
	for(int i=0; i<1; i++)
	{
		BackGround[i].x -= backgroundSpeed;
		if(BackGround[i].x<=0)
			BackGround[i].x = 1000;
	}
}*/
void setBackground()
{

	iShowBMP(0,0,"images\\farback.bmp");
}
#endif // BACKGROUND_H_INCLUDED
