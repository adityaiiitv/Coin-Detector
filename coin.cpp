#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
 
using namespace cv;
using namespace std;
 
int main()
{
	Mat image;
	image=imread("IMG-20160425-WA0002.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	vector<Vec3f> coin;
	HoughCircles(image,coin,CV_HOUGH_GRADIENT,2,20,450,60,0,0 );
	int l=coin.size();
	cout<<"\n The number of coins is: "<<l<<"\n\n";
	for( size_t i = 0; i < coin.size(); i++ )
	{
		Point center(cvRound(coin[i][0]),cvRound(coin[i][1]));
		int radius=cvRound(coin[i][2]);     
		circle(image,center,3,Scalar(0,255,0),-1,8,0);// circle center     
		circle(image,center,radius,Scalar(0,0,255),3,8,0);// circle outline
		cout<< " Center location for circle "<<i+1<<" : "<<center<<"\n Diameter : "<<2*radius<<"\n";
	}
	cout<<"\n";
	namedWindow("Coin Counter",CV_WINDOW_AUTOSIZE);
	imshow("Coin Counter",image);
	waitKey(0);
	return 0;
}
