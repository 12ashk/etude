/* modify from 'Learning OpenCV' Example code
 * and a code from blog: http://minus9d.hatenablog.com/entry/2014/03/21/003350
 * Draw boxes on the screen
 * a toycode to use mouse callback
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#define CV_RGB(r , g, b) cv::Scalar(b, g, r)
#define RED CV_RGB( 255, 0, 0)

using namespace cv;

Rect box;
bool drawing_box = false;

void draw_box(Mat *img, Rect box)
{
	rectangle(
			*img,
			Point2d(box.x, box.y),
			Point2d(box.x+box.width, box.y+box.height),
			Scalar(RED)
			);
}

void my_mouse_callback(int event, int x, int y, int flags, void *param)
{
	Mat* image = static_cast<Mat*>(param);
	switch(event){
		case EVENT_MOUSEMOVE:
			if(drawing_box){
				box.width = x - box.x;
				box.height = y - box.y;
			}
			break;

		case EVENT_LBUTTONDOWN:
			drawing_box = true;
			box = Rect(x, y, 0, 0);
			break;
	
		case EVENT_LBUTTONUP:
			drawing_box = false;
			if(box.width < 0){
				box.x += box.width;
				box.width *= -1;
			}
			if(box.height < 0){
				box.y += box.height;
				box.height *= -1;
			}
			draw_box(image, box);
			break;
	}
}

int main(void)
{
	String name = "Box Example";
	box = Rect(-1, -1, 0, 0);
	Mat image(Size(600, 600), CV_8UC3, Scalar(100, 100, 100));
	Mat temp = image.clone();
	namedWindow(name);
	setMouseCallback(name, my_mouse_callback, (void *)&temp);

	while(1){

		if(drawing_box) image.copyTo(temp);
		if(drawing_box) draw_box(&temp, box);

		imshow(name, temp);

		if(waitKey(15) == 27) break;
	}

	return 0;
}
