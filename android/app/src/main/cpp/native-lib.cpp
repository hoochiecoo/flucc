#include <jni.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_native_1camera_NativeDetector_detectLine(
        JNIEnv* env,
        jobject,
        jobject yBuffer,
        jint width,
        jint height,
        jint rowStride
) {
    uint8_t* y = (uint8_t*) env->GetDirectBufferAddress(yBuffer);
    if (!y) return JNI_FALSE;

    // Zero-copy: создаем Mat на основе переданного буфера
    cv::Mat gray(height, width, CV_8UC1, y, rowStride);

    // Пример логики: поиск линии через среднюю яркость ряда
    cv::Mat row;
    cv::reduce(gray, row, 0, cv::REDUCE_AVG);
    cv::threshold(row, row, 160, 255, cv::THRESH_BINARY);

    int count = cv::countNonZero(row);
    return count > width * 0.3;
}