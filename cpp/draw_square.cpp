/* modify from 'Learning OpenCV' Example code
 * and a code from blog: http://minus9d.hatenablog.com/entry/2014/03/21/003350
 * Draw boxes on the screen
 * a toycode to use mouse callback
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#define CV_RGB(r , g, b) cv::Scalar(b, g, r)
#define RED CV_RGB( 255, 0, 0)

#define N 4

using namespace cv;
using namespace std;

Point *lst = new Point[4];
int flag = 0;
bool finish = false;

void draw_polygon(Mat *img, Point *lst)
{
	fillConvexPoly(*img, lst, N, RED);
}

void my_mouse_callback(int event, int x, int y, int flags, void *param)
{
	//Mat* image = static_cast<Mat*>(param);
	switch(event){
		case EVENT_LBUTTONDOWN:
			finish = false;
			lst[flag] = Point(x, y);
			flag++;
			if(flag == N){
				finish = true;
				flag = 0;
			}
			break;

//		case EVENT_LBUTTONUP:
//			drawing = false;
//			if(box.width < 0){
//				box.x += box.width;
//				box.width *= -1;
//			}
//			if(box.height < 0){
//				box.y += box.height;
//				box.height *= -1;
//			}
//			draw_box(image, box);
//			break;
	}
}

int main(void)
{
	String name = "Box Example";
	Mat image(Size(600, 600), CV_8UC3, Scalar(0, 0, 0));
	Mat temp = image.clone();
	namedWindow(name);
	setMouseCallback(name, my_mouse_callback, (void *)&temp);

	while(1){

		if(finish) image.copyTo(temp);
		if(finish) draw_polygon(&temp, lst);

		imshow(name, temp);

		if(waitKey(15) == 27) break;
	}

	return 0;
}
