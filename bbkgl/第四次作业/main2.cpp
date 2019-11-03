#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

// BGR
// 黄色：28 196 227
// 红色：70 55 193

// 黄色的G通道必然大于100
bool judge(const cv::Mat src_img, cv::Point pt) {
    cv::Vec3b v = src_img.at<cv::Vec3b>(pt);
    if (v.val[1] > 100)
        return false;
    else return true;
}

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
        if (judge(src_img, center)) {
            // 绘制圆心
            circle(dst_img, center, 3, cv::Scalar(0, 255,0), -1, 8, 0 );
            // 绘制圆
            circle(dst_img, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
        }
    }
    cv::imwrite("../dst_2.png", dst_img);
    return 0;
}