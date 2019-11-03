#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

int main() {
    cv::Mat src_img = cv::imread("../src.png"), tmp_img, dst_img;
    dst_img = src_img;
    cv::cvtColor(src_img, tmp_img, cv::COLOR_BGR2GRAY);
    cv::medianBlur(tmp_img, tmp_img, 3);
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(tmp_img, circles, cv::HOUGH_GRADIENT, 1, tmp_img.rows/5, 60, 30, 0, 0);
    for (size_t i = 0; i < circles.size(); i++) {
        // 提取圆心
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        // 提取半径
        int radius = cvRound(circles[i][2]);
        // 绘制圆心
        circle(dst_img, center, 3, cv::Scalar(0, 255,0), -1, 8, 0 );
        // 绘制圆
        circle(dst_img, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
    }
    cv::imwrite("../dst.png", dst_img);
    return 0;
}