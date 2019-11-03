#include <opencv2/opencv.hpp>
#include <string>

//给原图像增加椒盐噪声
//图象模拟添加椒盐噪声是通过随机获取像素点,并设置为高亮度点和低亮度点来实现的
//src_image为源图像，n为椒/盐像素点个数，返回含噪图像
cv::Mat add_salt_noise(const cv::Mat src_image, int n) {
    cv::Mat dstImage = src_image.clone();

    for (int k = 0; k < n; k++) {
        //随机取值行列，得到像素点(i,j)
        int i = rand() % dstImage.rows;
        int j = rand() % dstImage.cols;

        //图像通道判定
        if (dstImage.channels() == 1)//修改像素点(i,j)的像素值
        {
            dstImage.at<uchar>(i, j) = 255;     //盐噪声
        } else {
            dstImage.at<cv::Vec3b>(i, j)[0] = 255;
            dstImage.at<cv::Vec3b>(i, j)[1] = 255;
            dstImage.at<cv::Vec3b>(i, j)[2] = 255;
        }
    }

    for (int k = 0; k < n; k++) {
        //随机取值行列
        int i = rand() % dstImage.rows;
        int j = rand() % dstImage.cols;
        //图像通道判定
        if (dstImage.channels() == 1) {
            dstImage.at<uchar>(i, j) = 0;       //椒噪声
        } else {
            dstImage.at<cv::Vec3b>(i, j)[0] = 0;
            dstImage.at<cv::Vec3b>(i, j)[1] = 0;
            dstImage.at<cv::Vec3b>(i, j)[2] = 0;
        }
    }
    return dstImage;
}

//生成高斯噪声
double generate_gaussian_noise(double mu, double sigma) {
    //定义小值
    const double epsilon = std::numeric_limits<double>::min();
    static double z0, z1;
    static bool flag = false;
    flag = !flag;
    //flag为假构造高斯随机变量X
    if (!flag)
        return z1 * sigma + mu;
    double u1, u2;
    //构造随机变量
    do {
        u1 = rand() * (1.0 / RAND_MAX);
        u2 = rand() * (1.0 / RAND_MAX);
    } while (u1 <= epsilon);
    //flag为真构造高斯随机变量
    z0 = sqrt(-2.0 * log(u1)) * cos(2 * CV_PI * u2);
    z1 = sqrt(-2.0 * log(u1)) * sin(2 * CV_PI * u2);
    return z0 * sigma + mu;
}

cv::Mat add_gaussian_noise(cv::Mat &src_img) {
    cv::Mat dst_img = src_img.clone();
    int channels = dst_img.channels();
    int row_n = dst_img.rows;
    int col_n = dst_img.cols * channels;
    if (dst_img.isContinuous()) {
        col_n *= row_n;
        row_n = 1;
    }
    for (int i = 0; i < row_n; i++) {
        for (int j = 0; j < col_n; j++) {
            int val = dst_img.ptr<uchar>(i)[j] + generate_gaussian_noise(2, 0.8) * 32;
            if (val < 0)
                val = 0;
            if (val > 255)
                val = 255;
            dst_img.ptr<uchar>(i)[j] = static_cast<uchar>(val);
        }
    }
    return dst_img;
}

int main() {
    std::string salt_out = "../salt.jpg", gassi_out = "../gaussi.jpg";
    std::string salt_median_out = "../salt_median.jpg", salt_gaussi_out = "../salt_gaussi.jpg";
    std::string salt_mean_out = "../salt_mean.jpg", gaussi_median_out = "../gaussi_median.jpg";
    std::string gaussi_gaussi_out = "../gaussi_gaussi.jpg", gaussi_mean_out = "../gaussi_mean.jpg";
    cv::Mat img = cv::imread("../test.jpg");
    // 加噪声
    cv::Mat img_salt = add_salt_noise(img, 10000);
    cv::Mat img_gaussi = add_gaussian_noise(img);

    // 输出噪声图
    cv::imwrite(salt_out, img_salt);
    cv::imwrite(gassi_out, img_gaussi);

    // 椒盐-中值滤波
    cv::Mat img_salt_median;
    cv::medianBlur(img_salt, img_salt_median, 3);
    cv::imwrite(salt_median_out, img_salt_median);

    // 椒盐-高斯滤波
    cv::Mat img_salt_gaussi;
    cv::GaussianBlur(img_salt, img_salt_gaussi, cv::Size(5, 5), 3, 3);
    cv::imwrite(salt_gaussi_out, img_salt_gaussi);

    // 椒盐-均值滤波
    cv::Mat img_salt_mean;
    cv::blur(img_salt, img_salt_mean, cv::Size(5, 5));
    cv::imwrite(salt_mean_out, img_salt_mean);

    // 高斯-中值滤波
    cv::Mat img_gaussi_median;
    cv::medianBlur(img_gaussi, img_gaussi_median, 3);
    cv::imwrite(gaussi_median_out, img_gaussi_median);

    // 高斯-高斯滤波
    cv::Mat img_gaussi_gaussi;
    cv::GaussianBlur(img_gaussi, img_gaussi_gaussi, cv::Size(5, 5), 3, 3);
    cv::imwrite(gaussi_gaussi_out, img_gaussi_gaussi);

    // 高斯-均值滤波
    cv::Mat img_gaussi_mean;
    cv::blur(img_gaussi, img_gaussi_mean, cv::Size(5, 5));
    cv::imwrite(gaussi_mean_out, img_gaussi_mean);
    return 0;
}