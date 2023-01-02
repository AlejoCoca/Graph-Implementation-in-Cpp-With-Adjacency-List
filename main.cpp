#include<graphics.h>
#include<windows.h>
#include <vector>
#include<cstdlib>
#include<iostream>
#include<dos.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include <sstream>
#include <string>
#include<stdlib.h>
#include<time.h>

using namespace std;

main()
{
	srand(time(NULL));	
	vector<int> v;
	vector< pair<int,int> > cv, a;
    int ventanax, ventanay, mY, mX, prev_mY=0, prev_mX=0, aux=-1, color;
    char seleccion;
    bool adentro;
    string texto;

    
    /*cout<<"Ingresa el ancho de la ventana"<<endl;
	cin>>ventanax;
	if(ventanax%2==!0)
	{
		ventanax-=1;
	}
	cout<<"Ingresa el alto de la ventana"<<endl;
	cin>>ventanay;
	if(ventanay%2==!0)
	{
		ventanay-=1;
	}*/
	//int gdriver=DETECT,gmode;
	//initgraph(&gdriver,&gmode,"C:\\tc\\bgi");
	DWORD AnchoPantalla = GetSystemMetrics(SM_CXSCREEN);
 	DWORD AltoPantalla = GetSystemMetrics(SM_CYSCREEN);
	initwindow(AnchoPantalla, AltoPantalla, "Ventana");
	POINT PosicionMouse;

 
 while(1)
 {
  GetCursorPos(&PosicionMouse);
  
  mX = PosicionMouse.x;
  mY = PosicionMouse.y-25;
  
  if(GetAsyncKeyState(VK_LBUTTON)){
  	adentro=false;
	for(int i=0, d=0;i<v.size();i++)
  	{
		d=sqrt(pow((cv[i].first-mX),2)+pow((cv[i].second-mY),2));
		if(d<100)
  		{
  			if(d<50)
  			{
  		
				if(aux==-1)
  				{
					aux=i;
	 			}
	 	 		else
	 	 		{
					a.push_back(make_pair(aux, i));
					line(cv[aux].first, cv[aux].second, cv[i].first, cv[i].second);
					for(int j=0;j<a.size();j++)
  					{
				   		cout<<"Adyacencias: "<<a[j].first<<" "<<a[j].second<<endl;
  					}
  					cout<<endl<<endl; 
					aux=-1;
		  		}
		  	}
		  	adentro=true;
		  	break;
		}
	}
  	if(!adentro)
  	{
  	 color=(rand()%14)+1;
  	 int color2=(rand()%14)+1;
  	 int  color3=(rand()%14)+1;
  	v.push_back(v.size());
  	cv.push_back(make_pair(mX,mY));
  	//setfillstyle(color,color2);

    stringstream str1;
    int n=v.size()-1;
    str1 << n;
    texto = str1.str();
    cout<<"ACA: "<<texto<<endl;
    char *txt = const_cast<char*>(texto.c_str());
    
    //setcolor(color);
  	circle(mX, mY, 50);
  	floodfill(mX,mY,15);
  	outtextxy(mX-3,mY,txt);
  	cout<<v[0]<<" "<<v[1]<<endl;
  	cout<<v.size()<<endl;
  	/*if(prev_mX==0 && prev_mY == 0){
  		prev_mX=mX;
  		prev_mY=mY;
	  }
  	line(mX,mY-25,prev_mX,prev_mY-25);
  	prev_mX=mX;
  	prev_mY=mY;
  	}*/
   }
  
  }
  
  delay(100);
}
 
	getch();
	closegraph();
}
