#include <iostream>
#include <opencv2/opencv.hpp>
#include <algorithm>

double WienerFilterImpl(const cv::Mat &src, cv::Mat &dst, double noiseVariance, const cv::Size &block) {

    assert(("Invalid block dimensions", block.width % 2 == 1 && block.height % 2 == 1 && block.width > 1 &&
                                        block.height > 1));
    assert(("src and dst must be one channel grayscale images", src.channels() == 1, dst.channels() == 1));

    int h = src.rows;
    int w = src.cols;

    dst = cv::Mat1b(h, w);

    cv::Mat1d means, sqrMeans, variances;
    cv::Mat1d avgVarianceMat;

    cv::boxFilter(src, means, CV_64F, block, cv::Point(-1, -1), true, cv::BORDER_REPLICATE);
    cv::sqrBoxFilter(src, sqrMeans, CV_64F, block, cv::Point(-1, -1), true, cv::BORDER_REPLICATE);

    cv::Mat1d means2 = means.mul(means);
    variances = sqrMeans - (means.mul(means));

    if (noiseVariance < 0) {
        // I have to estimate the noiseVariance
        cv::reduce(variances, avgVarianceMat, 1, CV_REDUCE_SUM, -1);
        cv::reduce(avgVarianceMat, avgVarianceMat, 0, CV_REDUCE_SUM, -1);
        noiseVariance = avgVarianceMat(0, 0) / (h * w);
    }

    for (int r = 0; r < h; ++r) {
        // get row pointers
        uchar const *const srcRow = src.ptr<uchar>(r);
        uchar *const dstRow = dst.ptr<uchar>(r);
        double *const varRow = variances.ptr<double>(r);
        double *const meanRow = means.ptr<double>(r);
        for (int c = 0; c < w; ++c) {
            dstRow[c] = cv::saturate_cast<uchar>(
                    meanRow[c] +
                    std::max(0., varRow[c] - noiseVariance) / std::max(varRow[c], noiseVariance) *
                    (srcRow[c] - meanRow[c])
            );
        }
    }

    return noiseVariance;
}

void WienerFilter(const cv::Mat &src, cv::Mat &dst, double noiseVariance = 10000, const cv::Size &block = cv::Size(3, 3)) {
    WienerFilterImpl(src, dst, noiseVariance, block);
    return ;
}

int main() {
    cv::Mat1b src_img = cv::imread("../src.png", CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat1b dst_img, temp;
    cv:: bilateralFilter(src_img, temp, 25, 25 * 2, 25 / 2);
    WienerFilter(temp, dst_img);
    cv::imwrite("../dst.png", dst_img);
    return 0;
}