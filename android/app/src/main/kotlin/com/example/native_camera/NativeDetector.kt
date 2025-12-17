package com.example.native_camera
import java.nio.ByteBuffer

object NativeDetector {
    init { System.loadLibrary("native-lib") }

    external fun detectLine(
        yBuffer: ByteBuffer,
        width: Int,
        height: Int,
        rowStride: Int
    ): Boolean
}