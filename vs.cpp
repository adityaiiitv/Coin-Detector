#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
 
using namespace cv;
using namespace std;
 
int main()
{
  Mat src, gray;
  src = imread( "IMG-20160425-WA0000.jpg", CV_LOAD_IMAGE_GRAYSCALE );//resize(src,src,Size(640,480));
  //cvtColor( src, src, CV_BGR2GRAY );
 
  // Reduce the noise so we avoid false circle detection
 // GaussianBlur( gray, gray, Size(9, 9), 2, 2 );
  //blur(gray,gray,Size(1,1));
// cvThreshold( src, src, 1, 255, CV_THRESH_BINARY );
  vector<Vec3f> circles;
 
  // Apply the Hough Transform to find the circles
  HoughCircles( src, circles, CV_HOUGH_GRADIENT, 2, 20, 450, 60, 0, 0 );
 int count=0;
  // Draw the circles detected
  for( size_t i = 0; i < circles.size(); i++ )
  {
	  count++;
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);     
      circle( src, center, 3, Scalar(0,255,0), -1, 8, 0 );// circle center     
      circle( src, center, radius, Scalar(0,0,255), 3, 8, 0 );// circle outline
      cout << "center : " << center << "\nradius : " << radius << endl;
   }
 
  // Show your results
  namedWindow( "Hough Circle Transform Demo", CV_WINDOW_AUTOSIZE );
  imshow( "Hough Circle Transform Demo", src );
 
  waitKey(0);
  cout<<"\n"<<count<<"\n";
  return 0;
}
