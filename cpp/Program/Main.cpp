#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<list>
#include<string>
#include<cmath>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#define CV_RGB(r, g, b) cv::Scalar(b, g, r)
#define RED CV_RGB(255, 0, 0)
#define WHITE CV_RGB(255, 255, 255)
#define BLACK CV_RGB(0, 0, 0)

using namespace cv;
using namespace std;

class Pictures
{
private:
	Point **lst;
	int flag;
	bool finish;
	Mat *image;
	int picnum;
	int picindx;

public:
	int slider;
	Pictures(int picnum, string adress);
	static void MouseCall(int event, int x, int y, int flags, void *param);
	void doMouseCall(int event, int x, int y, int flags);
	void main();
	static void on_trackbar(int val, void *data);
	void on_trackbar1(int val);
};

Pictures::Pictures(int picnum, string adress){
	lst = new Point*[picnum];
	slider = 0;
	for(int i = 0; i < picnum; i++) lst[i] = new Point[2];
	finish = false;
	this->picnum = picnum;
	picindx = 0;
	image = new Mat[2];
	image[0] = imread("~/pic/140507_1_B0L000.TIF");
	image[1] = imread("~/pic/140507_1_B0L000.TIF");

//	int a = (int)log10(picnum) + 1;
//	char *str = new char[100];
//	char *index = new char[a];
//	for(int i = 0; i < picnum; i++){
//		sprintf(index, str, i);
//		cout << str <<endl;
//		cout << adress + index << endl;
//		image = imread(adress + "B0L" + index, 0);
//	}
 }

void Pictures::MouseCall(int event, int x, int y, int flags, void *param)
{
//	Pictures *self = static_cast<Pictures*>(param);
	this->doMouseCall(event, x, y, flags);
}

void Pictures::doMouseCall(int event, int x, int y, int flags)
{
	/* value of Pictures::flag is strange here */
	switch(event){
		case EVENT_LBUTTONDOWN:
			finish = false;
			lst[picindx][flag] = Point(x, y);
			flag++;
			if(flag == 2){
				finish = true;
				flag = 0;
			}
			break;
	}
}

void Pictures::on_trackbar(int val, void *data){
	Pictures *self = static_cast<Pictures*>(data);
	self->on_trackbar1(val);
}

void Pictures::on_trackbar1(int val){
//	if(finish) picindx = val;
}

void Pictures::main(void)
{
	string name = "main window";
	Mat temp = image[picindx].clone();
	namedWindow(name, 1);
//	createTrackbar("< >", name, &slider, picnum-1, on_trackbar, (void *)this);
//	setMouseCallback(name, MouseCall, (void *)this);
	setMouseCallback(name, MouseCall, (void *)temp);
//	on_trackbar(0, (void *)this);
	while(1){
		picindx=0;
		if(finish){
			image[0].copyTo(temp);
			rectangle(temp, lst[picindx][0], lst[picindx][1], RED);
		}
		imshow(name, temp);
		if(waitKey(15) == 27) break;
	}
}

int main(void)
{
	string adress;
	int num = 2;
//	cout << "Direcory Name: ";
//	cin >> adress;
//	cout << "number of pictures: ";
//	cin >> num;
	Pictures a(num, adress);
	a.main();
	return 0;
}
