package com.example.native_camera
import androidx.camera.core.ImageAnalysis
import androidx.camera.core.ImageProxy

class LineAnalyzer(private val onResult: (Boolean) -> Unit) : ImageAnalysis.Analyzer {
    override fun analyze(image: ImageProxy) {
        val yPlane = image.planes[0]
        val detected = NativeDetector.detectLine(
            yPlane.buffer,
            image.width,
            image.height,
            yPlane.rowStride
        )
        onResult(detected)
        image.close()
    }
}