package com.reproducerapp

import android.os.Handler
import android.os.Looper
import android.util.Log

class MyEmitter {

    init {
        // Simulate some future update
        Handler(Looper.getMainLooper()).postDelayed({
            // At this point I want to call back into C++. Ideally into the static
            // library
            Log.d("TestProject", "MyEmitter Update")

            notifyNative()
        }, 2_000)
    }

    external fun notifyNative()

    companion object {
        init {
            System.loadLibrary("appmodules")
        }
    }

}