package com.programming.cmaketest


import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.programming.cmaketest.databinding.ActivityMainBinding

/*
* MainActivity File
*      ✅ 1. Received Int, Print it
*      ✅ 2. Received String, Print it
*      ✅ 3. Received Float, Print it
*      ✅ 4. Received Char, Print it
*      ✅ 5. Received Array, Print it
*      ✅ 6. Received Object, Print it
*
*      1. Send Int
*      2. Send String
*      3. Send Float
*      4. Send Char
*      5. Send Array
*      6. Send Object
*
*/

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val fromCpp = "String: ${getString()}\n" +
                "Int: ${getInt()}\n" +
                "Float: ${getFloat()}\n" +
                "Char: ${getChar()}\n" +
                "getList: ${getList().toTypedArray().contentToString()}\n" +
                "Person: ${getPersonInfo()}"
        binding.sampleText.text = fromCpp

        receivedInt(1234)
        receivedString("String from MainActivity Class")
        receivedFloat(3.145f)
        receivedChar('X')
        receivedList(intArrayOf(10,20,30,40,50,60))

    }

    //Received
    external fun getString(): String
    external fun getInt(): Int
    external fun getFloat(): Float
    external fun getChar(): Char
    external fun getList(): IntArray
    external fun getPersonInfo(): String


    //Send
    external fun receivedInt(num:Int)
    external fun receivedString(name: String)
    external fun receivedFloat(num: Float)
    external fun receivedChar(ch: Char)
    external fun receivedList(list: IntArray)
    //external fun receivedPerson(flt:)


    companion object {
        // Used to load the 'cmaketest' library on application startup.
        init {
            System.loadLibrary("cmaketest")
        }
    }
}